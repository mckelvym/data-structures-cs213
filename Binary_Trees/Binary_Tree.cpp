// Mark McKelvy
// CS 1:00 MWF
// December 15, 2002
// Final Program: Binary Tree

#include <iostream>
#include <fstream.h>
#include <stdlib.h>
#include "oostring.h"

struct tree_node
{
	int position;
	oostring question;
	tree_node *left;
	tree_node *right;
};

// Pointers
tree_node *root = NULL;
tree_node *current = NULL;
tree_node *temp = NULL;

// Create tree and node functions
tree_node *createnode(int position, oostring question);
void createtree(int position, oostring question);

// *********************
// *** Main Function ***
// *********************
int main()
{
	int position;			// variable to hold the position
	oostring thequestion;	// string to hold the question
	ifstream fin;			// pointer for input filestream
	char choice;				// variable for user choice

	// Welcome and instructions
	cout << endl << endl
		 << "Welcome to THE sound troubleshooter v1.0!"
		 << endl << endl
		 << "Press '1' to continue.     ";
	cin >> choice;
	if (choice != '1')
	{
		cout << endl << endl
			 << "Apparently you cannot follow directions"
			 << endl
			 << "So why do you have a computer in the first place?"
			 << endl << endl;
		exit(0);
	}
	cout << endl << endl
		 << "For your choice:"
	 	 << endl << "     '1' indicates 'Yes'"
		 << endl << "     '0' indicates 'No'"
		 << endl << endl;

	// Start reading the data from a file
	fin.open("data.txt", ios::in);
	while (!fin.eof())
		{
			fin >> position;
			getline(fin, thequestion);
			createtree(position, thequestion);
		}
	fin.close();

	// Set the temporary pointer to the root position
	temp = root;

	// Present the question to the user and traverse the list until at NULL
	do
	{
		cout << temp->question << "     ";
		cin >> choice;

		if (choice == '0')
			{
				temp = temp->left;
			}
		if (choice == '1')
			{
				temp = temp->right;
			}
		if ((choice != '1') && (choice != '0'))
			{
				cout << endl
					 << " Can't follow directions can you?"
					 << endl
					 << " I'll be nice and let you try again..."
					 << endl << endl;
			}
	}
	while ((temp->left != NULL) && (temp->right != NULL));

	// When at NULL, cout the information and exit the program
	if ((temp->left == NULL) && (temp->right == NULL))
		{
			cout << temp->question;
			cout << endl << endl
				 << "Thankyou for using the sound troubleshooter v1.0!"
				 << endl << endl;
			exit(0);
		}
	return 0;
}

// Function that will create the new nodes
tree_node *createnode(tree_node *current, int position, oostring question)
{
	if(position<current->position)
	{
		if(current->left == NULL)
		{
			current->left = new tree_node;
			current = current->left;
			current->position = position;
			current->question = question;
			current->left = NULL;
			current->right = NULL;
			return current;
		}
		else
		{
			createnode(current->left, position, question);
		}
	}
	else
	{
		if(current->right == NULL)
		{
			current->right = new tree_node;
			current = current->right;
			current->position = position;
			current->question = question;
			current->left = NULL;
			current->right = NULL;
			return current;
		}
		else
		{// move down the list until a NULL is reached
			createnode(current->right, position, question);
		}
	}
	return current;
}

// Function to create the binary tree
void createtree(int position, oostring question)
{
	if (root == NULL)
	{
		root = new tree_node;
		root->position = position;
		root->question = question;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		createnode(root, position, question);
	}

}
