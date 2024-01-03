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
