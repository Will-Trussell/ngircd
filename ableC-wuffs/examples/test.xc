int main (){
    WUFFS
        pri status "#not a digit"
        pri status "#too large"

        pub struct parser?(
	        val : base.u32,
        )

        pub func parser.parse?(src: base.io_reader) {
    	    var c : base.u8
	        while true {
		        c = args.src.read_u8?()
		        if c == 0 {
			        return ok
		        }
		        if (c < 0x30) or (0x39 < c) {  // '0' and '9' are ASCII 0x30 and 0x39.
			        return "#not a digit"
    		    }
	    	    // Rebase from ASCII (0x30 ..= 0x39) to the value (0 ..= 9).
		        c -= 0x30

    		    if this.val < 429_496729 {
	    	    	this.val = (10 * this.val) + (c as base.u32)
	        		continue
    		    } else if (this.val > 429_496729) or (c > 5) {
			        return "#too large"
    		    }
	        	// Uncomment this assertion to see what facts are known here.
    	    	// assert false
		        this.val = (10 * this.val) + (c as base.u32)
    	    } endwhile
        }

        pub func parser.value() base.u32 {
	        return this.val
        }
    WUFFS_END
}
