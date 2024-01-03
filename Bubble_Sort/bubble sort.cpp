#include <iostream>
#include <fstream.h>

int main()
{
	ofstream fout;
	int counter = 7;
	int list[7];
	list[0] = 43;
	list[1] = 40;
	list[2] = 18;
	list[3] = 24;
	list[4] = 39;
	list[5] = 60;
	list[6] = 12;

	fout.open("data.txt", ios::out);

	cout << "The list (before sorting) is as follows: " << endl << endl;
	fout << "The list (before sorting) is as follows: " << endl << endl;

	for (int i = 0; i < counter; i++)
	{
		cout << "list[" << i << "] = " << list[i] << endl;
		fout << "list[" << i << "] = " << list[i] << endl;
	}

	int j,k;
	bool exchange_made = 1;
	typedef int element;
	element temp;

	int	n = counter;
	k = 0;

	// make up to n-1 passes through the array, exit
	// early if no exchanges are made on previous pass

	while ((k < n - 1) && (exchange_made == 1))
	{
		exchange_made = 0;
		++k;
		// number of comparisons on kth pass
		for (j = 0; j < n - k; ++j)
		{
			if (list[j] > list[j + 1])
			{
				// there must be an exchange
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
				exchange_made = 1;
			}
		}
		cout << endl << endl << "Pass " << k << " looks like this:" << endl << endl;
		fout << endl << endl << "Pass " << k << " looks like this:" << endl << endl;
		for (i = 0; i < counter; i++)
		{
			cout << "list[" << i << "] = " << list[i] << endl;
			fout << "list[" << i << "] = " << list[i] << endl;
		}

	}

	cout << endl;
	fout << endl;
	fout.close();
	return 0;
}
