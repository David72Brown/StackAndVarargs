#include <iostream>
#include <sstream>
#include <stdarg.h>
#include "cstring"
#include "misc.h"
#include "assert.h"

using namespace std;

unsigned int SomeValue = 0x77777777;

// Here we accidentally overwrite the return address.
void CantGetBack(uint x, uint y)
{
	uint Vals[3];

	// !!! Whoops! This writes to a location beyond the end of the array and corrupts the return address.
	Vals[5] = 0x12345678;

	// Now take a look at the stack to see what has happened.
}

// Here we write values beyond the end of the array (which you must never do, of course).
void OverrunArray(uint x, uint y)
{
	uint HopeThisDoesNotChange = 0x99;
	uint Vals[3];
	uint i;

	// !!! Whoops! This overruns the array Vals and corrupts the stack.
	for (i = 0; i < 10; i++)
	{
		Vals[i] = SomeValue;
	}

	printf ("Number of Vals[] values set: %d\n", i);

	// Now take a look at the stack to see what has happened.
}

void NeverCalledFn(void)
{
	printf("This function is never called.\n");
}

void ProcessNumbers(uint NumNumbers, ...)
{
	va_list args;
	va_start(args, NumNumbers);
	printf ("Numbers to be procesed:");
	for (uint i = 0; i < NumNumbers; i++)
	{
		printf (" 0x%08x", va_arg(args, uint));
	}
	printf ("\n\n");
	va_end(args);
}

int main()
{
	uint a, b, c, d;
	char Name[] = "Fred";

	// This overruns an array so you can see how it corrupts other data on the stack.
	OverrunArray(0x11223344, 0x55667788);

	CantGetBack(0x11223344, 0x55667788);

	// This passes a, b, c & d into ProcessNumbers() - a function which does not know how many arguments we are passing in.
	a = 0x1111;
	b = 0x2222;
	c = 0x3333;
	d = 0x4444;
	ProcessNumbers(4, a, b, c, d);

	// This TRACE statements can be compiled in (or out) by #define-ing (or not #define-ing) TRACE_IN_USE in misc.h.
	TRACE_OUTPUT("Program running OK");
	TRACE_WITH_UINT("I am in main(). Var a is: ", a);
	TRACE_WITH_STR("Name is: ", Name);

	// printf() is a versatile function for printing stuff out.
	printf("Here is some data: %d, %c, %04x\n", a, 'g', b);

	TRACE(("Program running OK.\n"));
	TRACE(("a, b are: %d, %d\n", a, b));
	TRACE(("And here are an integer, a character and a string: %d, %c, %s\n", a, 'z', Name));

	return 0;
}
