#include <iostream.h>
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

	cout << "Selection Sort: " << endl << endl;
	fout << "Selection Sort: " << endl << endl;
	cout << "The list (before sorting) is as follows: " << endl << endl;
	fout << "The list (before sorting) is as follows: " << endl << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "list[" << i << "] = " << list[i] << endl;
		fout << "list[" << i << "] = " << list[i] << endl;
	}

	int index;
	typedef int element;
	element temp;
	int k,j, pass = 1;

	// make n-1 passes through successively smaller segments

	for (j=0; j<n-1; j++)
	{
		index=j;
		//find index of the smallest element
		for (k=j+1; k<n; k++)
		{
			if (list[k] < list[index])
			{
				index = k;
			}
		}
		if (index != j)
		{
			//exchange must be made
			temp = list[index];
			list[index] = list[j];
			list[j] = temp;
		}
		cout << endl << endl << "Pass " << pass << " looks like this:" << endl << endl;
		fout << endl << endl << "Pass " << pass << " looks like this:" << endl << endl;
		for (i = 0; i < n; i++)
		{
			cout << "list[" << i << "] = " << list[i] << endl;
			fout << "list[" << i << "] = " << list[i] << endl;
		}
		pass++;
	}

	cout << endl;
	fout << endl;
	fout.close();
	return 0;
}