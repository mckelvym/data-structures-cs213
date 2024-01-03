#include <iostream>
#include <conio.h>

int binary_search(int list, int n, int target);
int binary_search_aux(int list, int low, int high, int target);

int main()
{
	int list[] = {12, 34, 67, 89, 113, 125, 169, 180, 191, 201, 225, 237, 256, 270, 299, 304};
	              0    1   2   3   4    5     6   7    8    9    10   11   12   13   14   15
	int anint;
	cout << list[4] << endl;
	getch();
	anint = binary_search(list[16], 16, 191);
	return 0;
}

int binary_search(int list[16], int n, int target)
{
	return binary_search_aux(list[16], 0, n, target);
}

int binary_search_aux(int list[16], int low, int high, int target)
{
	int middle;

	cout << low << " " << high << endl;
	if (low >= high)
		return -1;
	else
	{
		middle = (low + high) / 2;
		if (list[middle] == target)
			return middle;
		else if (list[middle] > target)
			return binary_search_aux(list[16], low, middle - 1, target);
		else
			return binary_search_aux(list[16], middle + 1, high, target);
	}
}
