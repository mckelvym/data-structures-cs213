#include <iostream.h>

struct node
{
	char data;
	node *left;
	node *right;
};

int currentchar = 0;
char mathstring[80];
node *root();
node *newtree();
void parsestring();

int main()
{
	int counter;
	int currentchar;
	bool done = false;

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
	
	parsestring(mathstring[80]);

	return 0;
}

node *newtree()
{
	node *templeft = new node;
	templeft->left = NULL;
	templeft->right = NULL;
	node *tempright = new node;
	tempright->left = NULL;
	tempright->right = NULL;
	node *temp = new node;
	temp->left = templeft;
	temp->right = tempright;
	return temp;
}

void parsestring()
{
	if (currentchar <= counter)
	{
		if (mathstring[currentchar] == '(')
		{
			currentchar++;
			parsestring();
		}
		else
			/*
			//((((a+b)-(b-d))*c)/(f+(b*d)))
		if ((mathstring[currentchar] >= 65) || (mathstring[currentchar] <= 90))
		{
			temp = newtree();
			temp->left->data = mathstring[currentchar];
			currentchar++;
			temp->data = mathstring[currentchar];
			currentchar++;
			temp->right->data = mathstring[currentchar];
			currentchar++;
		}*/
	}
}