// mark mckelvy
// data structures 3:00 mwf
// may 2, 2003
// binary tree project (incomplete)

#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

struct node
{
	char data;
	node *left;
	node *right;
};

bool used = false;
int counter;
int currentchar = 0;
char mathstring[80];
node *root = NULL;
node *temp = NULL;
node *temp2 = NULL;
node *newnode(char data);
void parsestring();
void display();
void display_infix(node *tree);
void display_prefix(node *tree);
void display_postfix(node *tree);
void destroy_tree(node *tree);
void output(node *a_node);
void maketree();

int main()
{
	char choice;
	bool done = false;

	root = new node;
	temp = new node;
	cout << "Since this program does not fully work..." << endl << endl;
	cout << "Enter 1 to skip to a demonstration of the traversal algorithms" << endl;
	cin >> choice;
	if (choice == '1')
	{
		temp = newnode('f');
		temp->left = newnode('d');
		temp->right = newnode('g');
		root = temp;
		temp = temp->right;
		temp->right = newnode('i');
		temp = temp->right;
		temp->left = newnode('h');
		temp->right = newnode('j');
		temp = root->left;
		temp->right = newnode('e');
		temp->left = newnode('b');
		temp = temp->left;
		temp->left = newnode('a');
		temp->right = newnode('c');
		temp = NULL;
		delete temp;
		display();
	}
	else if (choice == 'x')
	{
		cout << "Enter a fully parenthesized mathematical expression (without spaces):" << endl << endl;
		cin >> mathstring;
		counter = 0;
		while (!done)
		{
			if (mathstring[counter] == NULL)
				done = true;
			else
				counter++;
		}
		parsestring();
	}
	else
		cout << endl << "Bad choice" << endl;
		
	return 0;
}

node *newnode(char data)
{
	node *temporary = new node;
	temporary->left = NULL;
	temporary->right = NULL;
	temporary->data = data;

	return temporary;
}

// ((((a+b)-(b-d))*c)/(f+(b*d)))
void parsestring()
{
	if (currentchar <= counter)
	{
		switch (mathstring[currentchar])
		{
			case '+':
				temp = newnode(mathstring[currentchar]);
				if (mathstring[currentchar - 1] >= 65 || mathstring[currentchar - 1] <= 90)
				{
					temp->left = newnode(mathstring[currentchar - 1]);
				}
				if (mathstring[currentchar + 1] >= 65 || mathstring[currentchar + 1] <= 90)
				{
					temp->right = newnode(mathstring[currentchar + 1]);
					currentchar++;
				}				
				break;
			case '-':
				temp = newnode(mathstring[currentchar]);
				if (mathstring[currentchar - 1] >= 65 || mathstring[currentchar - 1] <= 90)
				{
					temp->left = newnode(mathstring[currentchar - 1]);
				}
				if (mathstring[currentchar + 1] >= 65 || mathstring[currentchar + 1] <= 90)
				{
					temp->right = newnode(mathstring[currentchar + 1]);
					currentchar++;
				}
				break;
			case '*':
				temp = newnode(mathstring[currentchar]);
				if (mathstring[currentchar - 1] >= 65 || mathstring[currentchar - 1] <= 90)
				{
					temp->left = newnode(mathstring[currentchar - 1]);
				}
				if (mathstring[currentchar + 1] >= 65 || mathstring[currentchar + 1] <= 90)
				{
					temp->right = newnode(mathstring[currentchar + 1]);
					currentchar++;
				}
				break;
			case '/':
				temp = newnode(mathstring[currentchar]);
				if (mathstring[currentchar - 1] >= 65 || mathstring[currentchar - 1] <= 90)
				{
					temp->left = newnode(mathstring[currentchar - 1]);
				}
				if (mathstring[currentchar + 1] >= 65 || mathstring[currentchar + 1] <= 90)
				{
					temp->right = newnode(mathstring[currentchar + 1]);
					currentchar++;
				}
				break;
			case '(':
				break;
			case ')':
				break;
			default:
				break;
		}
		currentchar++;
		temp2 = root;
		maketree();
		parsestring();
	}
}

void maketree()
{
	if ((root == NULL) && (temp != NULL))
	{
		root = temp;
		temp2 = root;
		used = true;
	}
	if ((temp2->left != NULL) && !used)
	{
		temp2 = temp2->left;
		maketree();
		used = true;
	}
	if ((temp2->left == NULL) && (temp != NULL))
		temp2->left = temp;
	if ((temp2->right != NULL) && !used)
	{
		temp2 = temp2->right;
		maketree();
		used = true;
	}
	if ((temp2->right == NULL) && (temp != NULL))
		temp2->right = temp;
}

void display()
{
	char choice;
	
	do
	{
		system("CLS");
		cout << "What type of display?" << endl << endl;
		cout << "1. Infix" << endl;
		cout << "2. Prefix" << endl;
		cout << "3. Postfix" << endl;
		cout << "4. Exit Program" << endl;
		cin >> choice;
		switch (choice)
		{
			case '1':
				system("CLS");
				cout << "Infix (Inorder Transversal)" << endl << endl;
				display_infix(root);
				cout << endl;
				break;
			case '2':
				system("CLS");
				cout << "Prefix (Preorder Transversal)" << endl << endl;
				display_prefix(root);
				cout << endl;
				break;
			case '3':
				system("CLS");
				cout << "Postfix (Postorder Transversal)" << endl << endl;				
				display_postfix(root);
				cout << endl;
				break;
			case '4':
				destroy_tree(root);
				root = NULL;
				system("CLS");
				exit(0);
				break;
			default:
				break;
		}
		getch();
	}while (choice != '4');
}
	
void display_infix(node *tree)
{
	if (tree != NULL)
	{
		display_infix(tree->left);
		output(tree);
		display_infix(tree->right);
	}
}

void display_prefix(node *tree)
{
	if (tree != NULL)
	{
		output(tree);
		display_prefix(tree->left);
		display_prefix(tree->right);
	}
}

void display_postfix(node *tree)
{
	if (tree != NULL)
	{
		display_postfix(tree->left);
		display_postfix(tree->right);
		output(tree);
	}
}

void destroy_tree(node *tree)
{	
	if (tree != NULL)
	{
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		delete tree;
	}
}

void output(node *a_node)
{
	cout << a_node->data;
}