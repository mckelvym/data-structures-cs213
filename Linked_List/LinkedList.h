#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream.h>
#include <string.h>

struct node
{
	char name[30];
	char data[30];
	node *next;
	node *previous;
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
		void previous();
		void first();
		bool retrieve();
		void insert(char name[30], char data[30]);
		bool remove();  
		node & operator = (node & name);
		bool find(char target[30]);
	private:
		node *head;
		node *current;
		int length;
};

#endif

linkedlist::linkedlist()
{
	head = NULL;
	current = NULL;
	length = 0;
}

linkedlist::~linkedlist()
{
	node *temp;
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	while (current->previous != head)
	{
		temp = current;
		current = current->previous;
		delete temp;
	}
	if (current->previous == head)
	{
		delete current;
		current = head;
		delete current;
		head = NULL;
		current = NULL;
	}
	length = 0;
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
		current = current->next;
	else
		cout << "Pointer is already at end" << endl;
}

void linkedlist::previous()
{
	if ((current != head) && (current != NULL))
		current = current->previous;
	else
		cout << "Pointer is already at head" << endl;
}

void linkedlist::first()
{
	if (head != NULL)
		current = head;
	else
		cout << "No nodes in the list";
}

bool linkedlist::retrieve()
{
	if (current != NULL)
	{
		cout << endl << "Name: " << current->name;
		cout << endl <<	"Data: " << current->data;
		return true;
	}
	else if (current == NULL)
	{
		cout << endl << "Current node is NULL";
		return false;
	}
}

void linkedlist::insert(char name[30], char data[30])
{
	node *temp;
	strcpy(temp->name, name);
	strcpy(temp->data, data);
	temp->next = NULL;
	temp->previous = NULL;

	if (current == head)
	{
		head = temp;
		head->next = current;
		current->previous = head;
		current = temp;		
	}
	else if (current != head)
	{
		temp->previous = current->previous;
		temp->next = current;
		current->previous = temp;
		current = temp->previous;
		current->next = temp;
		current = current->next;
	}
	length++;
}

bool linkedlist::remove()
{
	if (current == head)
	{
		cout << endl << "Name: " << current->name;
		cout << endl <<	"Data: " << current->data;
		head = head->next;
		delete current;
		length--;
		return true;
	}
	else if (current == NULL)
	{
		cout << endl << "Current node is NULL";
		return false;
	}
	else
	{
		node *temp;
		temp = current;
		cout << endl << "Name: " << current->name;
		cout << endl <<	"Data: " << current->data;
		current = current->next;
		delete temp;
		length--;
		return true;
	}
}

bool linkedlist::find(char target[30])
{
	node *temp;
	temp = head;
	while ((strcmp(temp->name, target) != 0) && (temp != NULL))
	{
		temp = temp->next;
	}
	if (strcmp(temp->name, target) == 0)
	{
		current = temp;
		return true;
	}
	else
		return false;
}
