#include <iostream>
#include "linkedlist.h"

int main()
{
	linkedlist list;
	char temp[30] = "monkey";
	bool found = false;

	cout << "Linked List" << endl;
	cout << endl << "Node1";
	list.first();
	cout << "Node2";
	list.insert();
	cout << "Node3";
	list.insert();
	cout << "Node4";
	list.insert();
	cout << "Enter a search string: ";
	cin.get(temp, 30, '\n');
	cin.ignore(80, '\n');
	found = list.retrieve(temp);
	getch();

	return 0;
}

//Page 162: 9, 10
//Page 171: 1 - 6
