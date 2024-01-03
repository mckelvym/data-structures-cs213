// mark mckelvy
// data structures 3:00 mwf
// march 27, 2003
// hospital database project

#include <fstream.h>
#include <iostream>
#include <stdlib.h>
#include "linkedlist.h"

linkedlist list;

void input();
void welcome();
int menu();
void choose_operation(const int &choice);

int main()
{
	int menuchoice;

	input();
	welcome();
	while (true)
	{
		menuchoice = menu();
		choose_operation(menuchoice);
	}

	return 0;
}

void input()
{
	ifstream fin;
	ofstream fout;
	char the_name[30];
	char the_disease[30];
	char the_sex;
	int the_age;

	fout.open("data.dat", ios::app);
	fout.close();
	fin.open("data.dat", ios::in);
	while (!fin.eof())
	{
		fin.get(the_name, 30, '\n');
		fin.get(the_disease, 30, '\n');
		fin >> the_sex;
		fin >> the_age;
		list.setdata(the_name, the_disease, the_sex, the_age);
	}
}

void welcome()
{
	cout << "Hospital Database Program v1.1" << endl << endl;
	cout << endl << "Press any key: " << endl;
	getch();
}

int menu()
{
	char choice;

	do
	{
		system("CLS");
		cout << "*** Main Menu ***" << endl;
		cout << endl;
		cout << "1. Add Patient" << endl;
		cout << "2. Remove Patient" << endl;
		cout << "3. Find Patient" << endl;
		cout << "4. Display All Patients" << endl;
		cout << "5. Save Patient list to file" << endl;
		cout << "6. Change Patient info" << endl;
		cout << endl;
		cout << "0. Exit" << endl;
		cout << endl << endl;
		cout << "Choice? ";
		cin >> choice;

		if (choice == 49)
			return 1;
		else if (choice == 50)
			return 2;
		else if (choice == 51)
			return 3;
		else if (choice == 52)
			return 4;
		else if (choice == 53)
			return 5;
		else if (choice == 54)
			return 6;
		else if (choice == 48)
		{
			list.datafile();
			exit(0);
		}
	}while ((choice >= 48) && (choice <= 54));
	return 0;
}

void choose_operation(const int &choice)
{
	char search_string[30];
	char filename[80];

	switch (choice)
	{
		case 1:
			list.insert();
			break;
		case 2:
			system("CLS");
			cout << "Enter name of patient: ";
			cin.ignore(80, '\n');
			cin.get(search_string, 30, '\n');
			list.remove(search_string);
			break;
		case 3:
			system("CLS");
			cout << "Enter name of patient: ";
			cin.ignore(80, '\n');
			cin.get(search_string, 30, '\n');
			list.retrieve(search_string);
			break;
		case 4:
			list.print_list();
			break;
		case 5:
			system("CLS");
			cout << "Filename: " << endl;
			cin.ignore(80, '\n');
			cin.get(filename, 80, '\n');
			list.save_list(filename);
			break;
		case 6:
			system("CLS");
			cout << "Enter name of patient: ";
			cin.ignore(80, '\n');
			cin.get(search_string, 30, '\n');
			list.change(search_string);
			break;
	}
}
