#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <conio.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char name[30];
	char disease[30];
	char sex;
	int age;
	node *next;
};

class linkedlist
{
	public:
		linkedlist();
		~linkedlist();
		bool empty();
		bool at_end();
		int listlength();
		void next();
		void first();
		bool retrieve(char target[30]);
		void insert();
		bool remove(char target[30]);  
		void print_list();
		void save_list(char filename[80]);
		void change(char target[30]);
		void datafile();
		void setdata(char a_name[30], char an_illness[30], char a_sex, int an_age);
		node & operator = (node & name);
	private:
		node *head;
		node *current;
		node *previous;
		int length;
};

#endif

linkedlist::linkedlist()
{
	head = NULL;
	current = NULL;
	previous = NULL;
	length = 0;
}

linkedlist::~linkedlist()
{
	if (head != NULL)
	{
		current = head;
		head = NULL;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
			delete previous;
		}
		delete current;
		current = NULL;
		previous = NULL;
		length = 0;
	}
	else
	{
		previous = NULL;
		current = NULL;
		length = 0;
	}
}

bool linkedlist::empty()
{
	if (length == 0)
		return true;
	else
		return false;
}

bool linkedlist::at_end()
{
	if ((current != NULL) && (current->next == NULL))
		return true;
	else
		return false;
}

int linkedlist::listlength()
{
	return length;
}

void linkedlist::next()
{
	if ((current != NULL) && (current->next != NULL))
	{
		previous = current;
		current = current->next;
	}
	else
		cout << "Pointer is already at the end" << endl;
}

void linkedlist::first()
{
	if (head != NULL)
	{
		current = head;
		previous = NULL;
	}
}

bool linkedlist::retrieve(char target[30])
{
	current = head;
	if (strcmp(current->name, target) == 0)
	{
		system("CLS");
		cout << "Name:    " << current->name << endl;
		cout << "Disease: " << current->disease << endl;
		cout << "Sex:     " << current->sex << endl;
		cout << "Age:     " << current->age << endl;
		cout << endl << endl;
		cout << "Press any key: " << endl;
		getch();
		return true;
	}
	else
	{
		while ((strcmp(current->name, target) != 0) && (current != NULL))
		{
			current = current->next;
		}
		if (strcmp(current->name, target) == 0)
		{
			system("CLS");
			cout << "Name:    " << current->name << endl;
			cout << "Disease: " << current->disease << endl;
			cout << "Sex:     " << current->sex << endl;
			cout << "Age:     " << current->age << endl;
			cout << endl << endl;
			cout << "Press any key: " << endl;
			getch();
			return true;
		}
		else
		{
			cout << "Node not found" << endl;
			return false;
		}
	}
}

void linkedlist::insert()
{
	system("CLS");
	node *temp = new node;
	cout << "Name: ";
	cin.ignore(80, '\n');
	cin.get(temp->name, 30, '\n');
	cout << endl << "Disease: ";
	cin.ignore(80, '\n');
	cin.get(temp->disease, 30, '\n');
	cout << endl << "Sex (m/f): ";
	cin >> temp->sex;
	cout << endl << "Age: ";
	cin >> temp->age;
	temp->next = NULL;
	
	if (head == NULL)
	{
		head = temp;
		current = head;
	}
	else
	{
		current = head;
		if (strcmp(current->name, temp->name) > 0)
		{
			head = temp;
			head->next = current;
			current = head;
			previous = NULL;
		}
		else
		{
			while ((strcmp(current->name, temp->name) < 0) && (current->next != NULL))
			{
				current = current->next;
			}
			if (previous != NULL)
				previous->next = temp;
			else
				head = temp;
			temp->next = current;
			current = temp;
			/*
			current = current->next;
			previous->next = temp;
			temp->next = current;
			current = temp;*/
		}
	}
	length++;
}

bool linkedlist::remove(char target[30])
{
	current = head;
	if (strcmp(current->name, target) == 0)
	{
		head = current->next;
		delete current;
		length--;
		current = head;
		return true;
	}
	else
	{
		while ((strcmp(current->name, target) < 0) && (current != NULL))
		{
			previous = current;
			current = current->next;
		}
		if (strcmp(current->name, target) == 0)
		{
			previous->next = current->next;
			delete current;
			length--;
			current = previous->next;
			return true;
		}
		else return false;
	}
}

void linkedlist::print_list()
{
	int counter = 1;

	if (head != NULL)
	{
		current = head;
		while (current != NULL)
		{
			system("CLS");
			cout << "Patient #" << counter << endl << endl;
			cout << "Name:    " << current->name << endl;
			cout << "Disease: " << current->disease << endl;
			cout << "Sex:     " << current->sex << endl;
			cout << "Age:     " << current->age << endl;
			cout << endl << endl;
			cout << "Press any key:" << endl;
			current = current->next;
			counter++;
			getch();
		}
	}
	else
		cout << endl << "No Patients in the list.";
}

void linkedlist::save_list(char filename[80])
{
	int counter = 1;
	ofstream fout;

	if (head != NULL)
	{
		current = head;
		fout.open(filename, ios::out);
	
		while (current != NULL)
		{
			fout << "Patient #" << counter << endl;
			fout << "Name:    " << current->name << endl;
			fout << "Disease: " << current->disease << endl;
			fout << "Sex:     " << current->sex << endl;
			fout << "Age:     " << current->age << endl;
			fout << endl;
			counter++;
			current = current->next;
		}
		fout << endl << "*** End of File ***";
		fout.close();
	}
	else
		cout << "No Patients" << endl;
}

void linkedlist::change(char target[30])
{
	current = head;
	if (strcmp(current->name, target) == 0)
	{
		system("CLS");
		cout << endl << "Disease: ";
		cin.ignore(80, '\n');
		cin.get(current->disease, 30, '\n');
		cout << endl << "Sex:     ";
		cin >> current->sex;
		cout << endl << "Age:     ";
		cin >> current->age;
		cout << endl << endl;
		cout << "Press any key: " << endl;
		getch();
	}
	else
	{
		while ((strcmp(current->name, target) != 0) && (current != NULL))
		{
			current = current->next;
		}
		if (strcmp(current->name, target) == 0)
		{
			system("CLS");
			cout << endl << "Disease: ";
			cin.ignore(80, '\n');
			cin.get(current->disease, 30, '\n');
			cout << endl << "Sex:     ";
			cin >> current->sex;
			cout << endl << "Age:     ";
			cin >> current->age;
			cout << endl << endl;
			cout << "Press any key: " << endl;
			getch();
		}
		else
		{
			cout << "Node not found" << endl;
		}
	}
}

void linkedlist::datafile()
{
	ofstream fout;

	if (head != NULL)
	{
		current = head;
		fout.open("data.dat", ios::out);
		while (current != NULL)
		{
			fout << current->name << endl;
			fout << current->disease << endl;
			fout << current->sex << endl;
			fout << current->age << endl;
			current = current->next;
		}
		fout.close();
	}
	else
	{
		fout.open("data.dat", ios::out);
		fout.close();
	}
}

void linkedlist::setdata(char a_name[30], char an_illness[30], char a_sex, int an_age)
{
	node *temp = new node;
	strcpy(temp->name, a_name);
	strcpy(temp->disease, an_illness);
	temp->sex = a_sex;
	temp->age = an_age;
	temp->next = NULL;
	
	if (head == NULL)
		current = head = temp;
	else
	{
		current = head;
		if (strcmp(current->name, temp->name) == 1)
		{
			head = temp;
			head->next = current;
			current = head;
			previous = NULL;
		}
		else if ((strcmp(current->name, temp->name) == -1) && (current->next == NULL))
		{
			current->next = temp;
			previous = current;
			current = temp;
		}
		else
		{
			while (strcmp(current->name, temp->name) < 0)
			{
				previous = current;
				current = current->next;	
			}
			temp->next = current;
			previous->next = temp;
			current = temp;
		}
	}
	length++;
}
