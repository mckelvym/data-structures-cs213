#include <iostream.h>
#include <string.h>

struct node
{
	char data[30];
	node *next;
	node *previous;
};

node *head = NULL;
node *current = NULL;
node *temp = NULL;

int main()
{
	int counter = 1;
// set up a three node, doubly-linked list
	// create first node
	head = new node;
	current = head;
	strcpy(current->data, "APPLES");
	current->previous = NULL;
	current->next = NULL;
	// add a second node
	temp = new node;
	strcpy(temp->data, "BUTTER");
	temp->previous = current;
	temp->next = NULL;
	current->next = temp;
	current = current->next;
	// add a third node
	temp = new node;
	strcpy(temp->data, "EGGS");
	temp->previous = current;
	temp->next = NULL;
	current->next = temp;
	current = current->next;
// insert a fourth node
	// search for insertion point
	current = head;
	while (strcmp(current->data, "BUTTER") != 0)
	{
		current = current->next;
	}
	// create new node
	temp = new node;
	strcpy(temp->data, "CORN");
	temp->previous = NULL;
	temp->next = NULL;
	// insert node
	temp->next = current->next;
	temp->previous = current;
	current->next = temp;
	current = temp->next;
	current->previous = temp;
// delete a node
	// search for node
	current = head;
	while (strcmp(current->data, "CORN") != 0)
	{
		current = current->next;
	}
	// delete node
	temp = current;
	current = current->next;
	current->previous = temp->previous;
	current = temp->previous;
	current->next = temp->next;
	delete temp;
	current = head;
// output the nodes
	while (current != NULL)
	{
		cout << "Node " << counter << "'s data: " << current->data << endl;
		counter++;
		current = current->next;
	}
	cout << "End of Linked List" << endl;

	return 0;
}