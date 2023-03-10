module main

import os
import flag
import rand {i64_in_range}

fn main()
{
	mut flagman := flag.new_flag_parser(os.args)
	argss := flagman.finalize()!

	mut a := [0,100]

	if argss.len >2
	{
		a[0], a[1] = arguments()
	}
	
	if a[0] > a[1]
	{
		a[0], a[1] = a[1], a[0]
	}

	println(i64_in_range(a[0],a[1]+1)!)
	return
}


fn arguments() (int, int)
{ 
	return os.args[1].int(), os.args[2].int() 
}