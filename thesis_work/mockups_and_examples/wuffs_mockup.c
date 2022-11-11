// This file contains a mock-up of a potential Wuffs-like extension of parsing.
// For more information on Wuffs, see the Wuffs repository from Google:
// github.com/google/wuffs

// This code will not compile, as it is simply a mock-up of ideal syntax

// Some may ask, "why not just use Wuffs in C?" Perhaps Wuffs is not runable on
// whatever server you are using. Perhaps you are worried about overhead with
// using something originally in Go. This extension would allow the niceties of
// Wuffs to be built and transpiled into raw C on test machines, and then the
// server or whatever cannot run Go only needs to run C code, as opposed to Go,
// C, and whatever else may be needed.

// This is the code from the project for parsing messages
// It is rather tedious, including a lot of checking for null characters and
// messy C pointer witchcraft
GLOBAL bool
Parse_Request( CONN_ID Idx, char *Request )
{
	REQUEST req;
	char *start, *ptr;
	bool closed;

	assert( Idx >= 0 );
	assert( Request != NULL );

#ifdef SNIFFER
	if( NGIRCd_Sniffer ) Log( LOG_DEBUG, " <- connection %d: '%s'.", Idx, Request );
#endif

	Init_Request( &req );

	/* remove leading & trailing whitespace */
	ngt_TrimStr( Request );

	if (Conf_ScrubCTCP && ScrubCTCP(Request))
		return true;

	if (Request[0] == ':') {
		/* Prefix */
		req.prefix = Request + 1;
		ptr = strchr( Request, ' ' );
		if( ! ptr )
		{
			LogDebug("Connection %d: Parse error: prefix without command!?", Idx);
			return Conn_WriteStr(Idx, "ERROR :Prefix without command");
		}
		*ptr = '\0';
#ifndef STRICT_RFC
		/* ignore multiple spaces between prefix and command */
		while( *(ptr + 1) == ' ' ) ptr++;
#endif
		start = ptr + 1;
	}
	else start = Request;

	ptr = strchr( start, ' ' );
	if( ptr )
	{
		*ptr = '\0';
#ifndef STRICT_RFC
		/* ignore multiple spaces between parameters */
		while( *(ptr + 1) == ' ' ) ptr++;
#endif
	}
	req.command = start;

	/* Arguments, Parameters */
	if( ptr )
	{
		start = ptr + 1;
		while( start )
		{
			if( start[0] == ':' )
			{
				req.argv[req.argc] = start + 1;
				ptr = NULL;
			}
			else
			{
				req.argv[req.argc] = start;
				ptr = strchr( start, ' ' );
				if( ptr )
				{
					*ptr = '\0';
#ifndef STRICT_RFC
					while( *(ptr + 1) == ' ' ) ptr++;
#endif
				}
			}

			req.argc++;

			if( start[0] == ':' ) break;
			if( req.argc > 14 ) break;

			if( ptr ) start = ptr + 1;
			else start = NULL;
		}
	}

	if(!Validate_Prefix(Idx, &req, &closed))
		return !closed;
	if(!Validate_Command(Idx, &req, &closed))
		return !closed;
	if(!Validate_Args(Idx, &req, &closed))
		return !closed;

	return Handle_Request(Idx, &req);
} /* Parse_Request - Old */

// Wuffs code here for building the parser:
WUFFS {
    pub struct parser?(
        //Prefix if it exists
        prefix: slice base.u8,

        //Enumerate the commands, each one gets some number from 0 to 55
        cmd : base.u32[..= 56],
       
        // args is a 15 element array of byte slices (essentially array of
        // pointers)
        args : array[15] slice base.u8,

        argc : base.u32[..=15] // The number of arguments
    )
    
    pub func parser.parse?(src: base.io_reader) {
        var c : base.u8
        var i : base.u32[..15]
        var s : slice base.u8
        this.argc = 0 //Set argc to 0, we will count number of args later
        c = args.src.read_u8?()
        if c = ' ' {
            while true {
                c = args.src.read_u8?()
                if c <> ' ' {
                    break
                }
            }

        if c == ':' { //Not actual string comparison, Wuffs doesn't do strings
            //Handle prefix here
            // Need some way of copying next few letters into this.prefix
            // Not sure exactly what the syntax is, need to look into docs
            // Want to slice from next byte until a space is input
            this.prefix = args.src.read_u8?().slice_until(' ')
            this.cmd = args.src.slice_until(' ')
        }
        else {
            // Not a prefix, figure out what command it is, assign to this.cmd
            // Can leave this.prefix as default initialization (0 or null)
            this.cmd = args.src.slice_until(' ')
        }
        while true {
            s = args.src.slice_until(' ')
            if s == 0 { //Null byte, finished
                return ok
            }
            else {
                this.args[i] = s
                this.argc += 1
                if i < 14 {
                    i = i+1
                }
                else {
                    // Can't have i outside bounds of array
                    // If i == 14, we have filled all 15 args of the struct and
                    // we can return having filled the fields
                    return ok
                }
            }
        } endwhile
    }
} WUFFS_END


// Wuffs extension:
// Shovel code to Wuffs compiler
// Take generated C code, put it back into file in same location
//
// Note the above example code. This builds a basic parser with fields
// corresponding to the fields in our Command struct (NGIRCd)
// We begin by removing any leading space characters (optional, may just ignore
// this depending on time crunch) then read in a character. If the character
// indicates we are dealing with a prefix, then we handle the prefix. We must
// get the full prefix, which involves getting all the bytes until we find
// another space (' '), at which point we assign that string (slice in Wuffs) to
// the this.prefix field. We then assign the next set of bytes until a space to
// the this.command field. If there is no prefix, we simply leave the prefix
// field blank and fill in the command field. Then, we move on to populating the
// arguments. We add each argument as a slice. Note that this parse coroutine
// does not return anything. We instead are utilizing the Wuffs compiler to
// generate parse code we know is checked safe at compile time, which then
// populates our REQUEST struct. 
