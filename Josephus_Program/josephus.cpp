// mark mckelvy
// data structures 3:00 mwf
// 3/31/03
// josephus program

#include <iostream>

struct node
{
	int data;
	node *next;
};

node *start = NULL;
node *current = NULL;
node *previous = NULL;

void create(node *pointer);
node *getdata(int counter_for_nodes);

int main()
{
	int nodes;
	int counter_for_nodes;
	int number_to_skip;
	node *pointer;

	cout << "Welcome to tha 'Josephus' Program!" << endl << endl;
	cout << "Pick the amount of nodes: ";
	cin >> nodes;
	counter_for_nodes = 1;
	while (counter_for_nodes <= nodes)
	{
		pointer = getdata(counter_for_nodes);
		create(pointer);
		counter_for_nodes++;
	}
	cout << endl << "What is the number to skip? ";
	cin >> number_to_skip;

	current = start;
	while (current != NULL)
	{
		if (current == current->next)
		{
			cout << endl << "Node #" << current->data << " has been deleted.";
			cout << endl;
			delete current;
			current = NULL;
		}
		else
		{
			counter_for_nodes = 0;
			while (counter_for_nodes != number_to_skip)
			{
				previous = current;
				current = current->next;
				counter_for_nodes++;
			}
			if (counter_for_nodes == number_to_skip)
			{
				previous->next = current->next;
				cout << endl << "Node #" << current->data << " has been deleted.";
				delete current;
				current = previous->next;
			}
		}
	}

	return 0;
}

void create(node *pointer)
{
	current = start;
	while (current->next != start)
		{
			current = current->next;
		}
	if (current->next == start)
		current->next = pointer;
}

node *getdata(int counter_for_nodes)
{
	node *temp = new node;
	temp->data = counter_for_nodes;
	if (start == NULL)
		start = temp;
	temp->next = start;
	return temp;
}
