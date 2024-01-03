mark mckelvy
data structures 3:00 mwf
april 2, 2003
HW: fibonacci sequence program
	p273, questions 4 & 5

// fibonacci program
#include <iostream>
#include <stdlib.h>

int a = 0;
int b = 1;
int counter = 0;

int next(int a, int b);

int main()
{
	a = next(a, b);
	cout << b << endl;

	return 0;
}

int next(int a, int b)
{
	if (b == 1)
		cout << a << "  ";
	else
		cout << b << "  ";
	if (counter % 5 == 0)
		cout << endl;
	if (counter > 24)
		exit(0);
	counter++;
	b = next(b, a+b);

	return a;
}


P 273 Questions 4 & 5

4. function (c) is tail recursive because it it the last line in the function
   and it calls itself.

5. a.	Achieve intent? Yes

		Why? Since the 'ch' is locally declared, upon each recursion, a 'new'
			 char is created and saved in the compliler stack. When the recursion
			 finishes, each character is correctly placed on the stack and then
			 the output is correct.

		Output of 'MADAM': MADAM

   b.	Achieve intent? No

		Why? Since the 'ch' is globally declared, upon each recursion, the char
			 read is replaced and lost. The last character is the one that gets
			 saved in the compiler stack. When the recursion is finished, the
			 last character gets pushed five times and therefore the output
			 is incorrect.

		Output of 'MADAM': MMMMM
