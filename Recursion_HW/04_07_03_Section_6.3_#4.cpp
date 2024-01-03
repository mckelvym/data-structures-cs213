#include <iostream>

void y(int a, int b, int c);

int main()
{
	y(16, 1, 4);
	return 0;
}

void y(int a, int b, int c)
{
	int k;

	if (b <= c)
	{
		cout << a << endl;
		for ( k = b; k <= c; k++)
			y(k, b + 1, c);
	}
}
