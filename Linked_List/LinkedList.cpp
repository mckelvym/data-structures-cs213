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
		cout << "Pointer is already at the end" << endl;
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
	current = head;
	if (strcmp(current->name, target) == 0)
	{
		cout << "Name: " << current->name << endl;
		cout << "Data: " << current->data << endl;
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
			cout << "Name: " << current->name << endl;
			cout << "Data: " << current->data << endl;
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
	node *temp = getdata();
	if (head != NULL)
	{
		current = head;
	}
	else
		head = temp;
	while ((strcmp(current->name, temp->name) > -1) && (current != NULL))
	{
		current = current->next;	
	}
	temp->next = current->next;
	temp->next->previous = temp;
	temp->previous = current;
	current->next = temp;
	length++;
}

bool linkedlist::remove(char target[30])
{
	node *temp;
	current = head;
	if (strcmp(current->name, target) == 0)
	{
		current = current->previous;
		temp = current->next;
		current->next = temp->next;
		if (temp->next != NULL)
			temp->next->previous = current;
		delete temp;

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
			current = current->previous;
			temp = current->next;
			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->previous = current;
			delete temp;

			return true;
		}
		else
		{
			cout << "Node not found" << endl;
			return false;	
		}
	}
		length--;
}

node* linkedlist::getdata()
{
	node *temp;
	temp = new node;
	cin >> temp->name;
	cin >> temp->data;
	
	return temp;
}
