module main
import readline {read_line}

fn main()
{
 	 mut a := read_line('Give me number: ')!  
 	 mut b := read_line('Now a 2nd one: ')!

 	 

	c,d,e,f := bmath(a.f64(),b.f64())
	
	eprintln('')
	eprintln('The sum of numbers is ${c}')
	eprintln('The difference of numbers is ${d}')
	eprintln('The product of numbers is ${e}')
	eprintln('The quotient of numbers is ${f}')


return
}


fn bmath(x f64, y f64) (f64, f64, f64, f64)
{
	return x+y, x-y, x*y,x/y
}