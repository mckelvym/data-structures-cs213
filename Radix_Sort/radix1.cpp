// Mark McKelvy
// Data Structures 3:00 MWF
// 2/15/03
// Radix Sort


// *** Include Files ***
#include <conio.h>
#include <fstream.h>
#include <iomanip.h>
#include <math.h>
#include <stdlib.h>

// *** Global Variables *** 
int array[10];
int bin[10][10];

// *** Functions ***
void create_file();				
void welcome();
void driver();
void display_pass(const int &j);
void default_array_values(int &a, int &b);
void infile(int &num_elements);
void press_any_key();
void move_to_bin (const int &num_elements, int &divisor, int &j, int &i, int &b, const int &increase);
void cout_bins(int &a, int &b, const int &num_elements);
void collect_from_bins(const int &j, const int &num_elements, int &a, int &b);
void output_to_file(int &a, const int &num_elements);
int num_passes(int array[10], const int &increase);

// *** Main Function ***
int main()
{
	create_file();			// create data file
	welcome();				// display welcome screen
	driver();				// begin the program

	return 0;
}


// creates a data file with numbers to be sorted
void create_file()
{
	double rand_num;
	int num = 0, x = 0, y = 0;
	ofstream fout;

	rand_num = ((rand() * rand()) / (3 * rand()));
	num = int(rand_num);
	num = num % 10;

	fout.open("data.txt", ios::out);
	for (x = 0; x < 9; x++)
	{
		for (y = 0; y < 5; y++)
		{
			num;
			while ((y == 0) && (num == 0))
			{
				num;
			}
			fout << num;
		}
		fout << endl;
	}
	for (x = 0; x < 5; x++)
	{
		num;
		while ((x == 0) && (num == 0))
		{
			num;
		}
		fout << num;
	}
	fout.close();
/*
	fout.open("data.txt", ios::out);
	fout << "71895" << endl;
	fout << "13457" << endl;
	fout << "25188" << endl;
	fout << "10728" << endl;
	fout << "99314" << endl;
	fout << "14801" << endl;
	fout << "31471" << endl;
	fout << "57919" << endl;
	fout << "45152" << endl;
	fout << "65338";
	fout.close();
*/	
	return;
}

// displays a welcome screen
void welcome()
{
	char tab = '\t';
	
	cout.setf(ios::right);
	cout << setw(80) << "Radix v1.1";
	cout << endl << endl << endl;
	cout << tab << tab << tab << "     ----------------------" << endl << endl;
	cout << tab << tab << tab << "     Welcome to RaDiX Sort!" << endl << endl;
	cout << tab << tab << tab << "     ----------------------" << endl << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << "Press any key:" << endl;
	getch();

	return;
}

// function from which all other functions are called
void driver()
{
	int a = 0, b = 0, i = 0, j = 0, x = 1;
	int num_elements = 0, divisor = 1;
	const int increase = 10;

	// goes through the sort j < x times, running at least once, then changing
	// x to a new value according to the length of the numbers in the array
	for (j = 0; j < x; j++)
	{	
		display_pass(j);
		default_array_values(a = 0, b = 0);
		infile(num_elements = 0);
		x = num_passes(array, increase);
		press_any_key();
		move_to_bin (num_elements, divisor, j, i = 0, b = 0, increase);		
		cout_bins(a = 0, b = 0, num_elements);
		press_any_key();
		collect_from_bins(j, num_elements, a = 0, b = 0);
		output_to_file(a = 0, num_elements);
	}
	// this 'for' loop is one iteration of the radix sort

	return;
}

// displays the current pass number (centered)
void display_pass(const int &j)
{
	char center[] = "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ";
	
	system("CLS");
	cout << center << "Pass " << j + 1 << ":\n\n\n\n\n\n\n\n\n" << endl;
	getch();
	
	return;
}

// before data is put into the array, each receives default values of NULL
void default_array_values(int &a, int &b)
{
	for (a = 0; a <= 10; a++)
	{
		for (b = 0; b <= 10; b++)
		{
			bin[a][b] = '\0';
		}
		array[a] = '\0';			
	}

	return;
}

// read the data from a file and put it into int array[];
void infile(int &num_elements)
{
	ifstream fin;

	system("CLS");
	cout << endl << endl << "Array[] Before Sorting: " << endl << endl;
	fin.open("data.txt", ios::in);
	while (!fin.eof())
	{
		fin >> array[num_elements];
		cout << "array[" << num_elements << "] = " << array[num_elements] << endl;
		num_elements++;
	}
	fin.close();

	return;
}

// waits for user to press a key and then clears screen
void press_any_key()
{
	cout << endl << "Press Any Key: " << endl;
	getch();
	system("CLS");
	
	return;
}

// sorts numbers from array[] to their correct position in bin[][]
void move_to_bin (const int &num_elements, int &divisor, int &j, int &i, int &b, const int &increase)
{
	bool used = false;
	int temp = 0;

	cout << "Bin[][] for Pass " << j + 1 << ":" << endl << endl;
	for (i = 0; i < (num_elements); i++)
	{
		temp = ((array[i] / divisor) % (increase));
		used = false;
		for (b = 0; b < (num_elements - 1); b++)
		{
			if ((bin[temp][b] == '\0') && (!used))
			{
				bin[temp][b] = array[i];
				used = true;
			}
		}		
	}
	divisor *= increase;
	return;
}

// output the data in the bins
void cout_bins(int &a, int &b, const int &num_elements)
{
	char tab = '\t';

	for (a = 0; a < (num_elements); a++)
	{
		for (b = 0; b < (num_elements); b++)
		{
			if (bin[a][b] == '\0')
			{
				cout << tab;
			}
			else
			{
				cout << bin[a][b] << tab;
			}
		}
		cout << endl;
	}

	return;
}

// collects the data from bin[][] and puts it back into array[]
void collect_from_bins(const int &j, const int &num_elements, int &a, int &b)
{
	int pass = 0;
			
	cout << endl << endl << "Pass " << j + 1 << " (Sorted):" << endl << endl;
	pass = 0;
	for (a = 0; a < (num_elements); a++)
	{
		for (b = 0; b < (num_elements); b++)
		{
			if (bin[a][b] != '\0')
			{
				array[pass] = bin[a][b];
				pass++;
			}
		}
	}
	
	return;
}

// outputs the data from array[] to the data file
void output_to_file(int &a, const int &num_elements)
{
	ofstream fout;

	fout.open("data.txt", ios::out);
	while (a < (num_elements - 1))
	{
		fout << array[a] << endl;
		cout << "array[" << a << "] = " << array[a] << endl;
		a++;
	}
	cout << "array[" << a << "] = " << array[num_elements - 1] << endl << endl;
	cout << "Press any key:" << endl;
	fout << array[num_elements - 1];
	fout.close();
	getch();

	return;
}

// finds the length of the data elements
int num_passes(int array[10], const int &increase)
{
	bool used = false;
	int x = 1;
	double test = 0, test2 = 1;

	while (!used)
	{
		test = ((array[0]) / (test2));
		if (test < 1)
		{
			do
			{
				test = pow(10, x);
				x++;					
			}while (test2 != test);	
			used = true;
			x--;
		}
		test2 *= increase;
	}

	return (x);
}
