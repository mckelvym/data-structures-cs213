//	Mark McKelvy
//	Data Structures 3:00 MWF
//	1/29/03
//	CD Database Management v1.2



// ***** START CD DATABASE PROGRAM CODE *****

// *** Header Files ***
#include <fstream.h>
#include <iomanip.h>
#include <stdlib.h>
#include "oostring.h"

// *** Global CD Data Struct ***
struct cd_data					// struct for album/artist/tracks
{
	oostring album;				// string to hold album name
	oostring artist;			// string to hold artist name
	oostring tracks;			// string to hold number of tracks
};

// *** Function Declarations ***
int startup();					// display startup welcome
void firstmenu(int choice);		// display first menu along with startup
void intro();					// show introduction if chosen from firstmenu()
void menu();					// main menu from which program is driven
void addcd();					// append an entry to data.dat file
void deletecd();				// delete an entry to data.dat file
void renamecd();				// rename an entry in data.dat file
void sortcd();					// sort the database alphabetically
void sortcdrev();				// sort the database reverse alphabetically
void displaycd();				// show user the cd database
void outputcd();				// output cd database to specified filename

// *********************
// *** Main Function ***
// *********************
int main()
{
	int choice = startup();		// startup menu & return choice
	firstmenu(choice);			// send choice to firstmenu() function
								// and 'run' from there

	return 0;
}

// Startup: Welcome and Menu
int startup()
{
	int choice;
	
	do
	{	// Welcome Screen & Menu
		system("CLS");
		cout << "cdman.exe v1.0" << endl << endl << endl;
		cout << "\t\tWELCOME TO THE CD DATABASE MANAGEMENT PROGRAM!" << endl;
		cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl << endl;
		cout << "-------------------------------------------------------------------------------" << endl << endl;
		cout << "    1. Start Program                 2. Introduction                 3. EXIT   " << endl << endl;
		cout << "-------------------------------------------------------------------------------" << endl << endl;
		cout << endl << endl << "Your Choice? ";
		cin >> choice;		// get choice
	}while ((choice > 3) || (choice < 1));

	return (choice);	
}

// First Menu Switch
void firstmenu(int choice)
{
	// First Menu Switch
	switch (choice)
	{
	case 1:
		menu();				// go to main menu
		break;
	case 2:
		intro();			// show intro
		menu();				// go to main menu
		break;
	case 3:
		system("CLS");
		exit(0);			// exit program
		break;
	}

	return;
}

// Introduction
void intro()
{
	int choice;

	system("CLS");
	cout << "This program allows you to manage a cd database." << endl << endl;
	cout << "You may: " << endl << endl;
	cout << "        -Add entries" << endl;
	cout << "        -Delete entries" << endl;
	cout << "        -Sort entries" << endl;
	cout << "        -Save entries to a file" << endl << endl;
	do
	{
		cout << "Enter 1 for more ------> ";
		cin >> choice;
	}while (choice != 1);
	system("CLS");
	cout << "The menus are driven by number entries (as you have just experienced)." << endl << endl;
	cout << "To add an entry, you may have:" << endl << endl;
	cout << "                             -Album names up to 30 characters " << endl;
	cout << "                             -Artist names up to 30 characters" << endl;
	cout << "                             -Track numbers for two digits    " << endl << endl;
	cout << "To delete an entry, simply enter the corresponding number.    " << endl << endl;
	cout << "The sort will alphabetize the cd database.                    " << endl << endl;
	cout << "You may display or save the database.                         " << endl << endl;
	cout << "ENJOY!" << endl << endl;
	choice = 0;
	do
	{
		cout << endl;
		cout << "-----------" << endl;
		cout << "1. Continue" << endl;
		cout << "2. Exit" << endl;
		cout << "-----------" << endl << endl << endl;
		cout << "Your Choice? ";
		cin >> choice;			// get choice
		if (choice == 1)
		{
			return;				// go to main menu
		}
		if (choice == 2)
		{
			exit(0);			// exit program
		}
	}while((choice != 1) || (choice != 2));
	system("CLS");
	
	return;
}

// Main Menu
void menu()
{
	int choice;

	do
	{	
		// display main menu
		system("CLS");
		cout << endl << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "M                 1. DISPLAY CD Database                                      M" << endl << endl;
		cout << " A                2. ADD an entry to CD Database                             A " << endl << endl;
		cout << "  I               3. DELETE an entry to CD Database                         I  " << endl << endl;
		cout << "   N              4. RENAME an entry in the CD Database                    N   " << endl << endl;
		cout << "   M              5. SORT the CD Database alphabetically                   M   " << endl << endl;
		cout << "  E               6. SORT the CD Database in reverse order                  E  " << endl << endl;
		cout << " N                7. SAVE the CD Database into a text file                   N " << endl << endl;
		cout << "U                 0. EXIT the CD Database Management Program                  U" << endl;
		cout << "-------------------------------------------------------------------------------" << endl << endl;
		cout << endl << endl << "YOUR CHOICE? ";
		cin >> choice;		// get choice
	}while((choice >= '0') && (choice <= '5'));
	// Main Menu Switch
	switch (choice)
	{
	case 0:
		system("CLS");
		exit(0);			// exit program
		break;
	case 1:
		displaycd();		// display cd database to user
		menu();				// loop back to menu
		break;
	case 2:
		addcd();			// allow user to append cd to database
		menu();				// loop back to menu
		break;
	case 3:
		deletecd();			// allow user to delete a chosen cd
		menu();				// loop back to menu
		break;
	case 4:
		renamecd();			// allow user to rename a chosen cd
		menu();				// loop back to menu
		break;
	case 5:
		sortcd();			// sort alphabetically
		menu();				// loop back to menu
		break;
	case 6:
		sortcdrev();		// sort reverse alphabetically
		menu();				// loop back to menu
		break;
	case 7:
		outputcd();			// output database to user-specified file
		menu();				// loop back to menu
		break;
	}

	return;
}

// Add CD Entry
void addcd()
{
	int a, choice, tempo = 0;
	char temp[30], album[30], artist[30], tracks[3];
	ifstream fin;
	ofstream fout;
	cd_data cd[500];
	
	// read data file for number of entries and increment 'tempo' to that number
	fin.open("data.dat", ios::in);
	do
	{
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		tempo++;
	}while(!fin.eof());
	fin.close();
	// read in cd database from data file 'tempo' # of times
	// and store in a temporary struct
	fin.open("data.dat", ios::in);
	for(a = 0; a <= tempo; a++)
	{
		fin.getline(album, 30, '\n');
		cd[a].album = album;
		fin.getline(artist, 30, '\n');
		cd[a].artist = artist;
		fin.getline(tracks, 30, '\n');
		cd[a].tracks = tracks;
	}
	fin.close();
	system("CLS");
	cout << endl << "  ADD CD ENTRY  " << endl;
	cout <<         "----------------" << endl;
	cin.ignore(80, '\n');
	cout << endl << "Please enter the album: ------------> ";
	cin.getline(album, 30, '\n');
	cout << endl << "Please enter the artist ------------> ";
	cin.getline(artist, 30, '\n');
	cout << endl << "Please enter number of tracks ------> ";
	cin.getline(tracks, 3, '\n');
	system("CLS");
	// output back to the data file with new entry
	fout.open("data.dat", ios::out);
	for (a = 0; a < (tempo - 1); a++)
	{
		fout << cd[a].album << endl << cd[a].artist << endl << cd[a].tracks << endl;
	}
	fout << album << endl << artist << endl << tracks << endl;
	fout.close();
	system("CLS");
	cout << endl << "THE CD HAS BEEN SUCCESSFULLY ADDED!" << endl << endl;
	do
	{
		cout << endl;
		cout << "-----------" << endl;
		cout << "1. Continue" << endl;
		cout << "2. Exit" << endl;
		cout << "-----------" << endl << endl << endl;
		cout << "Your Choice? ";
		cin >> choice;		// get choice
		if (choice == 1)
		{
			return;			// back to main menu
		}
		if (choice == 2)
		{
			exit(0);		// exit program
		}
	}while((choice != 1) || (choice != 2));
}

// Delete Specific Entry
void deletecd()
{
	int a, choice, choice2, tempo = 0;
	char temp[30], album[30], artist[30], tracks[3];
	ifstream fin;
	ofstream fout;
	cd_data cd[500];

	system("CLS");
	cout.setf(ios::right);
	cout << endl << setw(40) << "DELETE CD" << endl << endl;
	// read data file for number of entries and increment 'tempo' to that number
	fin.open("data.dat", ios::in);
	do
	{
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		tempo++;
	}while(!fin.eof());
	fin.close();
	// read in cd database from data file 'tempo' # of times
	// and store in a temporary struct
	fin.open("data.dat", ios::in);
	for(a = 0; a <= tempo; a++)
	{
		fin.getline(album, 30, '\n');
		cd[a].album = album;
		fin.getline(artist, 30, '\n');
		cd[a].artist = artist;
		fin.getline(tracks, 30, '\n');
		cd[a].tracks = tracks;
	}
	fin.close();
	// display the database to user
	cout.setf(ios::left);
	cout << setw(7) << "      " << setw(30) << "ALBUM" << setw(30) << "ARTIST" << "TRACKS" << endl;
	cout << setw(7) << "      " << setw(30) << "-----" << setw(30) << "------" << "------" << endl;
	for (a = 0; a < (tempo - 1); a++)
	{	
		if((a <= 8) && (a >= 0))
		{
			cout << "0";
		}
		cout.setf(ios::right);
		cout << a + 1 << setw(5) << "." << setw(30) << cd[a].album << setw(30) << cd[a].artist << cd[a].tracks << endl;
	}
	if((a <= 8) && (a >= 0))
		{
			cout << "0";
		}
	cout << a + 1 << setw(5) << "." << setw(30) << "--GO BACK--" << setw(30) << "--GO BACK--" << "00" << endl;
	cout << endl << endl << "Your Choice?  ";
	cin >> choice;		// get choice
	choice = choice - 1;
	if (choice == a)
	{
		return;			// back to main menu
	}
	do
	{	// make sure that user wants to delete entry
		system("CLS");
		cout << endl << "ARE YOU SURE YOU WANT TO DELETE THIS ENTRY?" << endl;
		cout << endl << "-------";
		cout << endl << "1. YES" << endl;
		cout << endl << "2. NO";
		cout << endl << "-------";
		cout << endl << endl << "Your Choice? ";
		cin >> choice2;	// get choice
		if (choice2 == 1)
		{
			// begin at 'choice' and overwrite data
			for (choice; choice < tempo; choice++)
			{
				cd[choice].album = cd[choice + 1].album;
				cd[choice].artist = cd[choice + 1].artist;
				cd[choice].tracks = cd[choice + 1].tracks;
			}
			// output back to data file minus selected
			fout.open("data.dat", ios::out);
			for (a = 0; a < (tempo - 2); a++)
			{
				fout << cd[a].album << endl << cd[a].artist << endl << cd[a].tracks << endl;
			}
			fout.close();
			system("CLS");
			cout << endl << "DELETE COMPLETED!" << endl << endl;
			choice = 0;
				do
				{
					cout << endl;
					cout << "-----------" << endl;
					cout << "1. Continue" << endl;
					cout << "2. Exit" << endl;
					cout << "-----------" << endl << endl << endl;
					cout << "Your Choice? ";
					cin >> choice;		// get choice
					if (choice == 1)
					{
						return;			// back to main menu
					}
					if (choice == 2)
					{
						exit(0);		// exit program
					}
				}while((choice != 1) || (choice != 2));
			system("CLS");
			return;						// back to main menu
		}
		if (choice2 == 2)
		{
			return;						// back to main menu
		}
	}while((choice != 1) || (choice != 2));
}

// Rename Specific Entry
void renamecd()
{
	int a, choice, choice2, tempo = 0;
	char temp[30], album[30], artist[30], tracks[3];
	ifstream fin;
	ofstream fout;
	cd_data cd[500];
			
	// read data file for number of entries and increment 'tempo' to that number
	fin.open("data.dat", ios::in);
	do
	{
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		tempo++;
	}while(!fin.eof());
	fin.close();
	// read in cd database from data file 'tempo' # of times
	// and store in a temporary struct
	fin.open("data.dat", ios::in);
	for(a = 0; a <= tempo; a++)
	{
		fin.getline(album, 30, '\n');
		cd[a].album = album;
		fin.getline(artist, 30, '\n');
		cd[a].artist = artist;
		fin.getline(tracks, 30, '\n');
		cd[a].tracks = tracks;
	}
	fin.close();
	system("CLS");
	// display the database to user
	cout << endl << "RENAME CD" << endl << endl;
	cout.setf(ios::left);
	cout << setw(7) << "   " << setw(30) << "ALBUM" << setw(30) << "ARTIST" << "TRACKS" << endl;
	cout << setw(7) << "   " << setw(30) << "-----" << setw(30) << "------" << "------" << endl << endl;
	for (a = 0; a < (tempo - 1); a++)
	{	
		if((a <= 8) && (a >= 0))
		{
			cout << "0";
		}
		cout.setf(ios::right);
		cout << a + 1 << setw(5) << "." << setw(30) << cd[a].album << setw(30) << cd[a].artist << cd[a].tracks << endl;
	}
	cout << endl << "What CD to rename? ";
	cin >> choice;		// get choice
	do
	{
		// make sure that user wants to delete entry
		system("CLS");
		cout << endl << "ARE YOU SURE YOU WANT TO RENAME THIS ENTRY?" << endl;
		cout << endl << "-------";
		cout << endl << "1. YES" << endl;
		cout << endl << "2. NO";
		cout << endl << "-------";
		cout << endl << endl << "Your Choice? ";
		cin >> choice2;	// get choice
		if (choice2 == 1)
		{
			// procede with renaming
			choice = choice - 1;
			system("CLS");
			cin.ignore(80, '\n');
			// overwrite choice
			cout << endl << "Please enter the album: ------------> ";
			cin.getline(album, 30, '\n');
			cd[choice].album = album;
			cout << endl << "Please enter the artist ------------> ";
			cin.getline(artist, 30, '\n');
			cd[choice].artist = artist;
			cout << endl << "Please enter number of tracks ------> ";
			cin.getline(tracks, 3, '\n');
			cd[choice].tracks = tracks;
			system("CLS");
			// open data file and output database
			fout.open("data.dat", ios::out);
			for (a = 0; a < tempo - 1; a++)
			{
				fout << cd[a].album << endl << cd[a].artist << endl << cd[a].tracks << endl;
			}
			fout.close();
			system("CLS");
			cout << endl << "THE CD HAS BEEN SUCCESSFULLY ADDED!" << endl << endl;
			choice = 0;
			do
			{
				cout << endl;
				cout << "-----------" << endl;
				cout << "1. Continue" << endl;
				cout << "2. Exit" << endl;
				cout << "-----------" << endl << endl;
				cout << "Your Choice? ";
				cin >> choice;		// get choice
				if (choice == 1)
				{
					return;			// back to main menu
				}
				if (choice == 2)
				{
					exit(0);		// exit program
				}
			}while((choice != 1) || (choice != 2));
		}
		if (choice2 == 2)
		{
			return;					// back to main menu
		}
	}while((choice != 1) || (choice != 2));
	
	return;
}

// Sort Database Alphabetically
void sortcd()
{
	int a = 0, choice, tempo = 0, j, k, n;
	char temp[30], album[30], artist[30], tracks[3];
	bool exchange_made = 1;
	ifstream fin;
	ofstream fout;
	cd_data cd[500], swap;

	// read data file for number of entries and increment 'tempo' to that number
	fin.open("data.dat", ios::in);
	do
	{
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		tempo++;
	}while(!fin.eof());
	fin.close();
	// read in cd database from data file 'tempo' # of times
	// and store in a temporary struct
	fin.open("data.dat", ios::in);
	for(a = 0; a <= tempo; a++)
	{
		fin.getline(album, 30, '\n');
		cd[a].album = album;
		fin.getline(artist, 30, '\n');
		cd[a].artist = artist;
		fin.getline(tracks, 30, '\n');
		cd[a].tracks = tracks;
	}
	fin.close();
	// use bubble sort on struct sort sort alphabetically
	n = tempo;
	k = 0;
	while ((k < n - 1) && (exchange_made == 1))
	{
		exchange_made = 0;
		++k;
		for (j = 0; j < n - k; ++j)
		{
			if (cd[j].album > cd[j + 1].album)
			{
				swap = cd[j];
				cd[j] = cd[j + 1];
				cd[j + 1] = swap;
				exchange_made = 1;
			}
		}
	}
	// output sorted database
	fout.open("data.dat", ios::out);
	for (a = 1; a < tempo; a++)
	{
		fout << cd[a].album << endl << cd[a].artist << endl << cd[a].tracks << endl;
	}
	fout.close();
	system("CLS");
	cout << endl << "SORT COMPLETE!" << endl << endl;
	do
	{
		cout << endl;
		cout << "-----------" << endl;
		cout << "1. Continue" << endl;
		cout << "2. Exit" << endl;
		cout << "-----------" << endl << endl << endl;
		cout << "Your Choice? ";
		cin >> choice;		// get choice
		if (choice == 1)
		{
			return;			// back to main menu
		}
		if (choice == 2)
		{
			exit(0);		// exit program
		}
	}while((choice != 1) || (choice != 2));

	return;
}

// Sort Database Reverse Alphabetically
void sortcdrev()
{
	int a = 0, choice, tempo = 0, j, k, n;
	char temp[30], album[30], artist[30], tracks[3];
	bool exchange_made = 1;
	ifstream fin;
	ofstream fout;
	cd_data cd[500], swap;

	// read data file for number of entries and increment 'tempo' to that number
	fin.open("data.dat", ios::in);
	do
	{
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		tempo++;
	}while(!fin.eof());
	fin.close();
	// read in cd database from data file 'tempo' # of times
	// and store in a temporary struct
	fin.open("data.dat", ios::in);
	for(a = 0; a <= tempo; a++)
	{
		fin.getline(album, 30, '\n');
		cd[a].album = album;
		fin.getline(artist, 30, '\n');
		cd[a].artist = artist;
		fin.getline(tracks, 30, '\n');
		cd[a].tracks = tracks;
	}
	fin.close();
	// use bubble sort on struct sort sort reverse alphabetically
	n = tempo;
	k = 0;
	while ((k < n - 1) && (exchange_made == 1))
	{
		exchange_made = 0;
		++k;
		for (j = 0; j < n - k; ++j)
		{
			if (cd[j].album < cd[j + 1].album)
			{
				swap = cd[j];
				cd[j] = cd[j + 1];
				cd[j + 1] = swap;
				exchange_made = 1;
			}
		}
	}
	// output sorted database
	fout.open("data.dat", ios::out);
	for (a = 0; a < tempo - 1; a++)
	{
		fout << cd[a].album << endl << cd[a].artist << endl << cd[a].tracks << endl;
	}
	fout.close();
	system("CLS");
	cout << endl << "SORT COMPLETE!" << endl << endl;
	do
	{
		cout << endl;
		cout << "-----------" << endl;
		cout << "1. Continue" << endl;
		cout << "2. Exit" << endl;
		cout << "-----------" << endl << endl << endl;
		cout << "Your Choice? ";
		cin >> choice;		// get choice
		if (choice == 1)
		{
			return;			// back to main menu
		}
		if (choice == 2)
		{
			exit(0);		// exit program
		}
	}while((choice != 1) || (choice != 2));

	return;
}

// Display CD Database
void displaycd()
{
	int a, choice, tempo = 0;
	char temp[30], album[30], artist[30], tracks[3];
	ifstream fin;
	ofstream fout;
	cd_data cd[500];
			
	// read data file for number of entries and increment 'tempo' to that number
	fin.open("data.dat", ios::in);
	do
	{
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		tempo++;
	}while(!fin.eof());
	fin.close();
	// read in cd database from data file 'tempo' # of times
	// and store in a temporary struct
	fin.open("data.dat", ios::in);
	for(a = 0; a <= tempo; a++)
	{
		fin.getline(album, 30, '\n');
		cd[a].album = album;
		fin.getline(artist, 30, '\n');
		cd[a].artist = artist;
		fin.getline(tracks, 30, '\n');
		cd[a].tracks = tracks;
	}
	fin.close();
	system("CLS");
	// Display Cd Database Information
	cout.setf(ios::left);
	cout << setw(7) << "   " << setw(30) << "ALBUM" << setw(30) << "ARTIST" << "TRACKS" << endl;
	cout << setw(7) << "   " << setw(30) << "-----" << setw(30) << "------" << "------" << endl << endl;
	for (a = 0; a < (tempo - 1); a++)
	{	
		if((a <= 8) && (a >= 0))
		{
			cout << "0";
		}
		cout.setf(ios::right);
		cout << a + 1 << setw(5) << "." << setw(30) << cd[a].album << setw(30) << cd[a].artist << cd[a].tracks << endl;
	}
	do
	{
		cout << endl;
		cout << "-----------" << endl;
		cout << "1. Continue" << endl;
		cout << "2. Exit" << endl;
		cout << "-----------" << endl << endl;
		cout << "Your Choice? ";
		cin >> choice;		// get choice
		if (choice == 1)
		{
			return;			// back to main menu
		}
		if (choice == 2)
		{
			exit(0);		// exit program
		}
	}while((choice != 1) || (choice != 2));
}

// Save Database to File
void outputcd()
{
	int a, choice, tempo = 0;
	char temp[30], filename[30], album[30], artist[30], tracks[3];
	ifstream fin;
	ofstream fout;
	cd_data cd[500];

	// read data file for number of entries and increment 'tempo' to that number
	fin.open("data.dat", ios::in);
	do
	{
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		fin.getline(temp, 30, '\n');
		tempo++;
	}while(!fin.eof());
	fin.close();
	// read in cd database from data file 'tempo' # of times
	// and store in a temporary struct
	fin.open("data.dat", ios::in);
	for(a = 0; a <= tempo; a++)
	{
		fin.getline(album, 30, '\n');
		cd[a].album = album;
		fin.getline(artist, 30, '\n');
		cd[a].artist = artist;
		fin.getline(tracks, 30, '\n');
		cd[a].tracks = tracks;
	}
	fin.close();
	system("CLS");
	cin.ignore(80, '\n');
	// prompt user for a filename for the database
	cout << "Please enter the filename: ";
	cin.get(filename, 30, '\n');
	// create file for output
	fout.open(filename, ios::out);
	// output cd database to file for user
	fout.setf(ios::left);
	fout << "CD Database" << endl << endl;
	fout << setw(30) << "ALBUM" << setw(30) << "ARTIST" << "TRACKS" << endl;
	fout << setw(30) << "-----" << setw(30) << "------" << "------" << endl;
	for (a = 0; a < (tempo - 1); a++)
	{	
		fout.setf(ios::left);
		fout << setw(30) << cd[a].album << setw(30) << cd[a].artist << cd[a].tracks << endl;
	}
	fout.close();
	system("CLS");
	cout << endl << "SAVE SUCCESS!" << endl << endl;
	cout << "The CD Database saved as '" << filename << "'" << endl << endl;
	do
	{
		cout << endl;
		cout << "-----------" << endl;
		cout << "1. Continue" << endl;
		cout << "2. Exit" << endl;
		cout << "-----------" << endl << endl << endl;
		cout << "Your Choice? ";
		cin >> choice;		// get choice
		if (choice == 1)
		{
			return;			// back to main menu
		}
		if (choice == 2)
		{
			exit(0);		// exit program
		}
	}while((choice != 1) || (choice != 2));

	return;
} 
// ***** END CD DATABASE PROGRAM CODE *****