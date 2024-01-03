#include <iostream>
#include <fstream.h>

int main()
{
	ofstream fout;
	int n = 7;
	int list[7];
	list[0] = 43;
	list[1] = 40;
	list[2] = 18;
	list[3] = 24;
	list[4] = 39;
	list[5] = 60;
	list[6] = 12;

	fout.open("data.txt", ios::out);

	cout << "Insertion Sort: " << endl << endl;
	fout << "Insertion Sort: " << endl << endl;
	cout << "The list (before sorting) is as follows: " << endl << endl;
	fout << "The list (before sorting) is as follows: " << endl << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "list[" << i << "] = " << list[i] << endl;
		fout << "list[" << i << "] = " << list[i] << endl;
	}

	int j, k;
	typedef int element;
	element item_to_insert;
	bool still_looking;

	// on the kth pass, insert item k into its correct position among
	// the first k entries in the array.

	for (k = 1; k < n; k++)
	{
	// walk backwards through the list, looking for slot to insert list[k]
		item_to_insert = list[k];
		j = k - 1;
		still_looking = true;
		while ((j >= 0) && still_looking)
		{
			if (item_to_insert < list[j])
			{
				list[j + 1] = list[j];
				j--;
			}
			else
			{
				still_looking = false;
			}
		}
		// upon leaving loop, j + 1 is the index
		// where item_to_insert belongs
		list[j + 1] = item_to_insert;

		cout << endl << endl << "Pass " << k << " looks like this:" << endl << endl;
		fout << endl << endl << "Pass " << k << " looks like this:" << endl << endl;
		for (i = 0; i < n; i++)
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
