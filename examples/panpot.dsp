//-------------------------------------------------
// Stereo panpot
//-------------------------------------------------

panpot(x) 	= (1-c)*x, c*x 
			with { 
				c=(nentry("pan",0,-8,8,1)-8)/-16; 
			};

process		= panpot;
