// Mark McKelvy
// Data Structures 3:00 MWF
// 2/15/03
// Radix Sort Program


// *** Include Header Files ***
#include <conio.h>
#include <fstream.h>
#include <iomanip.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// *** Declare Global Variables *** 
int array[50];
int bin[10][50];

// *** Declare Functions ***
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
int rand_num();
int num_passes(int array[10], const int &increase);

// *** Begin Main Function ***
int main()
{
	create_file();			// create data file
	welcome();				// display welcome screen
	driver();				// begin the program

	return 0;
}

// *** Begin Supplementary Functions ***

// creates a data file with numbers to be sorted
void create_file()
{
	int num = 0, a = 0, b = 0;
	ofstream fout;

	fout.open("data.dat", ios::out);
	// generates ten different numbers, each of five digits,
	// using random integers
	for (a = 0; a < 9; a++)
	{
		for (b = 0; b < 5; b++)
		{
			num = rand_num();
			// if the leading integer is '0', then get a new one
			while ((b == 0) && (num == 0))
			{
				num = rand_num();
			}
			fout << num;
		}
		fout << endl;
	}
	for (a = 0; a < 5; a++)
	{
		num = rand_num();
		// if the leading integer is '0', then get a new one
		while ((a == 0) && (num == 0))
		{
			num = rand_num();
		}
		fout << num;
	}
	fout.close();

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
	// this 'for' loop is one iteration of radix

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
	fin.open("data.dat", ios::in);
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
	bool used = false;		// flag
	int temp = 0;			// current isolated number & bin[row]

	cout << "Bin[][] for Pass " << j + 1 << ":" << endl << endl;
	for (i = 0; i < (num_elements); i++)
	{
		// isolate the kth digit and set it to temp
		temp = ((array[i] / divisor) % (increase));
		used = false;
		// find a place in the bin for it
		for (b = 0; b < (num_elements - 1); b++)
		{
			// start on row temp, and move across the row until '\0' is found
			if ((bin[temp][b] == '\0') && (!used))
			{
				// copy the number from the array to that spot
				bin[temp][b] = array[i];
				// set of the 'used' flag and exit loop
				used = true;
			}
		}		
	}
	// increase the divisor & prepare to isolate the next digit to the left
	divisor *= increase;
	
	return;
}

// output the data in the bins
void cout_bins(int &a, int &b, const int &num_elements)
{
	char tab = '\t';
	
	// go across each [row], [column] and output the data there
	for (a = 0; a < (num_elements); a++)
	{
		for (b = 0; b < (num_elements); b++)
		{
			// if there is no data in the current spot, tab over and check the next
			if (bin[a][b] == '\0')
			{
				cout << "." << tab;
			}
			// if there is data, output it to the screen, tab over, and check next
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
	// collect data from bins and put back into the array
	for (a = 0; a < (num_elements); a++)
	{
		for (b = 0; b < (num_elements); b++)
		{
			// if there is data, put it into the array and increment pass
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

	// write the data in array[] back to the text file
	fout.open("data.dat", ios::out);
	while (a < (num_elements - 1))
	{
		fout << array[a] << endl;
		cout << "array[" << a << "] = " << array[a] << endl;
		a++;
	}
	cout << "array[" << a << "] = " << array[num_elements - 1] << endl << endl;
	fout << array[num_elements - 1];
	fout.close();
	press_any_key();

	return;
}

// creates a random single integer
int rand_num()
{	
	int new_rand_num;
	double rand_num;
		
	rand_num = ((rand() * rand()) / (3.1415f * rand()));
	new_rand_num = int(rand_num);
	new_rand_num = (new_rand_num % 10);

	return new_rand_num;
}

// finds the amount of digits (of an element in the array),
// so that the loop can be iterated enough times
int num_passes(int array[10], const int &increase)
{
	bool used = false;
	int x = 1;
	double test = 0, test2 = 1;

	while (!used)
	{
		// divides powers of ten into the first element into the array
		test = ((array[0]) / (test2));
		// when the value is less than one
		if (test < 1)
		{
			do
			{
				// check the power of ten divided by the pow(x,y) function
				// and set the test variable to the power it was raised to
				test = pow(10, x);
				x++;					
			}while (test2 != test);	
			// set off the 'used' flag, and exit the loop
			used = true;
			x--;
		}
		test2 *= increase;
	}
	// return the number of digits
	return (x);
}

// *** End Code ***