// Mark McKelvy
// Data Structures 3:00 MWF
// 3/10/03
// Game Of Life

// *** Header Files ***
#include <conio.h>
#include <fstream.h>
#include <iomanip.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "random.h"

// *** Global Variables ***
const int size = 11;
int matrix[size][size];
int new_matrix[size][size];

// *** Function Declarations ***
void initial_matrix(int &a, int &b);
void random_matrix(const int &a, int &counter);
void reset_new_matrix(int &a, int &b);
void display_matrix(int &a, int &b, int &pass);
void get_sequence(int &a);
void get_iterations(int &iterations);
void waitforuser(int &wait);
void next_generation(int &a, int &b, int &current_iteration, int &iterations);
void pause(int &a, int &b, int &speed);
void input_matrix(int &a, int &b);
void output_matrix(int &a, int &b);
void output_new_matrix(int &a, int &b);
bool delay();

// *** Main Function ***
int main()
{
	int a, b;
	int counter;
	int current_iteration = 0;
	int iterations = 0;
	int speed = 0;
	int wait = -1;
				
	initial_matrix(a, b);
	get_sequence(a);
	get_iterations(iterations);
	waitforuser(wait);
	random_matrix(a, counter);
	output_matrix(a, b);
	do
	{
		input_matrix(a, b);
		if (wait == 3)
		{
			display_matrix(a, b, current_iteration);
			getch();
		}
		else if (wait == 2)
		{
			if (delay() == true)
				display_matrix(a, b, current_iteration);
		}
		else if (wait == 1)
		{
			display_matrix(a, b, current_iteration);
			pause(a, b, speed = 1);
		}
		next_generation(a, b, current_iteration, iterations);
		output_new_matrix(a, b);
		matrix[size][size] = new_matrix[size][size];
		reset_new_matrix(a, b);
		current_iteration++;
	}while (current_iteration < iterations);

	return 0;
}

// Initializes the matrix with NULL
void initial_matrix(int &a, int &b)
{
	ofstream fout;

	fout.open("MATRIX.TXT", ios::out);
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < 6; b++)
		{
			matrix[a][b] = 0;
			new_matrix[a][b] = 0;
			fout << matrix[a][b] << " ";
		}
		fout << endl;
	}
	fout.close();
	
	return;
}

// Generates random living cells based on user input
void random_matrix(const int &a, int &counter)
{
	random_gen position;

	srand(a);
	for (counter = 0; counter < (size * 3); counter++)
	{	
		matrix[position.bounds(0, (size - 1))][position.bounds(0, (size - 1))] = 1;
	}

	return;
}

// Resets the new_matrix and prepares it for the next generation
void reset_new_matrix(int &a, int &b)
{
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			new_matrix[a][b] = 0;
		}
	}
	
	return;
}

// Displays the matrix on the screen and waits for user to press any key
void display_matrix(int &a, int &b, int &pass)
{
	char tab[] = " ";

	system("CLS");
	for (a = 0; a < size; a++)
	{
		cout << "                    ";
		for (b = 0; b < size; b++)
		{
			if (matrix[a][b] == 0)
			{
				cout << "| |" << tab;
			}
			else if (matrix[a][b] == 1)
			{
				cout << "|x|" << tab;
			}
		}
		cout << endl << endl;
	}
	cout << "Pass " << (pass + 1) << ".";
	cout << endl;

	return;
}

// Asks user for a variable to generate a random map
void get_sequence(int &a)
{
	system("CLS");
	cout << setw(55) << "Game Of Life v1.1 - Mark McKelvy";
	cout << endl << endl << endl << endl;
	do
	{
		cout << "Positive Integer for Sequence:     ";
		cin >> a;
	}while (a >= RAND_MAX);
	
	return;
}

// Gets the number of iterations to run from user
void get_iterations(int &iterations)
{
	do
	{
		cout << "Positive Integer for Iterations:   ";
		cin >> iterations;
	}while ((iterations < 1) || (iterations > 32766));

	return;
}

// Wait for user to go onto the next generation or not
void waitforuser(int &wait)
{
	system("CLS");
	cout << setw(55) << "Game Of Life v1.1 - Mark McKelvy";
	cout << endl << endl << endl << endl;
	cout << "1. Fast" << endl;
	cout << "2. Slow" << endl;
	cout << "3. Wait for Key" << endl;
	cout << endl << endl;
	cout << "Speed?     ";
	cin >> wait;

	return;
}

// Calculates the next generation based upon current matrix
void next_generation(int &a, int &b, int &current_iteration, int &iterations)
{
	bool same = true;
	const int min = 0;
	const int max = (size - 1);
	int check = 0;
	int livecells = 0;

	for (a = min; a <= max; a++)
	{
		for (b = min; b <= max; b++)
		{
			livecells = 0;
			// checks inner cells
			if (!(a == min) || (a == max) || (b == min) || (b == max))
				//(a != min) && (a != max) && (b != min) && (b != max))
			{
				if (matrix[a - 1][b - 1] == 1)
					livecells++;
				if (matrix[a][b - 1] == 1)
					livecells++;
				if (matrix[a + 1][b - 1] == 1)
					livecells++;
				if (matrix[a - 1][b] == 1)
					livecells++;
				if (matrix[a + 1][b] == 1)
					livecells++;
				if (matrix[a - 1][b + 1] == 1)
					livecells++;
				if (matrix[a][b + 1] == 1)
					livecells++;
				if (matrix[a + 1][b + 1] == 1)
					livecells++;
			}
			// checks outer cells
			else 
				//if ((a == min) || (a == max) || (b == min) || (b == max))
			{
				if ((a == min) && ((b != min) && (b != max)))
				{
					if (matrix[a - 1][b] == 1)
						livecells++;
					if (matrix[a + 1][b] == 1)
						livecells++;
					if (matrix[a - 1][b + 1] == 1)
						livecells++;
					if (matrix[a][b + 1] == 1)
						livecells++;
					if (matrix[a + 1][b + 1] == 1)
						livecells++;
				}
				if ((a == max) && ((b != min) && (b != max)))
				{
					if (matrix[a - 1][b] == 1)
						livecells++;
					if (matrix[a + 1][b] == 1)
						livecells++;
					if (matrix[a - 1][b - 1] == 1)
						livecells++;
					if (matrix[a][b - 1] == 1)
						livecells++;
					if (matrix[a + 1][b - 1] == 1)
						livecells++;
				}
				if ((b == min) && ((a != min) && (a != max)))
				{
					if (matrix[a][b - 1] == 1)
						livecells++;
					if (matrix[a][b + 1] == 1)
						livecells++;
					if (matrix[a + 1][b - 1] == 1)
						livecells++;
					if (matrix[a + 1][b] == 1)
						livecells++;
					if (matrix[a + 1][b + 1] == 1)
						livecells++;
				}
				if ((b == max) && ((a != min) && (a != max)))
				{
					if (matrix[a][b - 1] == 1)
						livecells++;
					if (matrix[a][b + 1] == 1)
						livecells++;
					if (matrix[a - 1][b - 1] == 1)
						livecells++;
					if (matrix[a - 1][b] == 1)
						livecells++;
					if (matrix[a - 1][b + 1] == 1)
						livecells++;
				}
				if ((a == min) && (b == min))
				{
					if (matrix[a + 1][b] == 1)
						livecells++;
					if (matrix[a][b + 1] == 1)
						livecells++;
					if (matrix[a + 1][b + 1] == 1)
						livecells++;	
				}
				if ((a == min) && (b == max))
				{
					if (matrix[a][b - 1] == 1)
						livecells++;
					if (matrix[a + 1][b] == 1)
						livecells++;
					if (matrix[a + 1][b - 1] == 1)
						livecells++;	
				}
				if ((a == max) && (b == min))
				{
					if (matrix[a - 1][b] == 1)
						livecells++;
					if (matrix[a][b + 1] == 1)
						livecells++;
					if (matrix[a - 1][b + 1] == 1)
						livecells++;	
				}
				if ((a == max) && (b == max))
				{
					if (matrix[a - 1][b] == 1)
						livecells++;
					if (matrix[a][b - 1] == 1)
						livecells++;
					if (matrix[a - 1][b - 1] == 1)
						livecells++;	
				}
			}
			// Determine if cell is born, stays alive, or dies
			switch (livecells)
			{
			case 2:
				if (matrix[a][b] == 0)
					new_matrix[a][b] = 0;
				else
					new_matrix[a][b] = 1;
				break;
			case 3:
				new_matrix[a][b] = 1;
				break;
			default:
				new_matrix[a][b] = 0;
				break;
			}
		}
	}
	livecells = 0;
	check = 0;
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			if (new_matrix[a][b] == 1)
				livecells++;
			if (matrix[a][b] == 1)
				check++;
			if (new_matrix[a][b] != matrix[a][b])
				same = false;
		}
	}
	if ((livecells == 0) || (same)) 
		current_iteration = (iterations - 1);
	return;
}

// Gives the computer a slow down...
void pause(int &a, int &b, int &speed)
{
	ofstream fout;

	for (a = 0; a < speed; a++)
	{
		for (b = 0; b < speed; b++)
		{
			fout.open("dummyfile.txt", ios::out);
			fout << "*** Temporary File ***" << endl;
			fout << (a * b) << endl;
			fout.close();
		}
	}

	return;
}

// Reads the matrix information from a file
void input_matrix(int &a, int &b)
{
	ifstream fin;

	fin.open("MATRIX.TXT", ios::in);
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			fin >> matrix[a][b];
		}
	}
	fin.close();

	return;
}

// Writes the original matrix configuration to file
void output_matrix(int &a, int &b)
{
	ofstream fout;
	
	fout.open("MATRIX.TXT", ios::out);
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			fout << matrix[a][b] << " ";
		}
		fout << endl;
	}
	fout.close();

	return;
}

// Writes the next generation's matrix to file
void output_new_matrix(int &a, int &b)
{
	ofstream fout;
	
	fout.open("MATRIX.TXT", ios::out);
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			fout << new_matrix[a][b] << " ";
		}
		fout << endl;
	}
	fout.close();

	return;
}

// Allows a one second delay between iterations
bool delay()
{
	char tempbuf[9];
	char temp1[2];
	char temp2[2];

	_strtime( tempbuf );
	while(true)
	{
		for (int a = 0; a < 3; a++)
		{
			temp1[a] = tempbuf[a + 6];
		}
		_strtime( tempbuf );
		for (a = 0; a < 3; a++)
		{
			temp2[a] = tempbuf[a + 6];
		}
		if (strcmp(temp1, temp2) < 0)
			return true;
	}
}