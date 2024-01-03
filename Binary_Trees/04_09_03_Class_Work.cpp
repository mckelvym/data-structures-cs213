// section 7.1 p322
// 1, 4, 5, 6, 9

#include <iostream>

struct node
{
	int data;
	node *left;
	node *right;
}

node *root = NULL;
node *current = NULL;
node *previous = NULL;

void insert(int number);

int main()
{
	root = new node;
	root->data = 87;
	insert(84);

	return 0;
}

void insert(int number)
{
	node *temp = new node;
	temp->data = number;
	temp->left = NULL;
	temp->right = NULL;

	if (root != NULL)
	{
		current = root;
		if (current->data > number)
		{
			if (current->left == NULL)
				current->left = temp;
			else
			{
				current = current->left;
				insert();
			}
}
