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

//Below is what the ideal new extension would look like, using concepts from
//Wuffs for better parsing than raw C provides
bool Parse_Request (CONN_ID Idx, char *Request) {
    //Asserts here for checking for nonnulls
    REQUEST req;
    Init_Request(&req);

    char c = read_char(Request);
    if (c==0)
        // Fail, Request is empty?
        return false;
    if (c==':'){
        //Handle prefix
    }
    while (1) {
        c = read_char(Request);
        if (c == 0){
            return true;
        }
        if (c == ':'){
            //Handle prefix
        }

    }
}











