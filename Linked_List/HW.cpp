Mark McKelvy
Data Structures 3:00 MWF
3/12/03
Page 162: 9, 10
Page 171: 1 - 6

P 162

9.	int sum()
	{
		current = head;
		int summation = 0;
		while (current != NULL)
		{
			summation += current->data;
			current = current->next;
		}
		return summation;
	}

10.	remove()
	{
		node *temp;
		current = head;
		bool done = false;
		while ((head != NULL) && !done)
		{
			if (current->next != NULL)
			{
				temp = current;
				current = current->next;
				delete current;
			}
			else
			{
				delete head;
				head = NULL;
				current = NULL;
				temp = NULL;
				done = true;
			}
		}
	}

P 171
1.	a) a = b; true
	b) a = a->data; false, because the pointer stores the memory address of a struct, not an int
	c) a = a->node_ptr; true
	d) delete a; true
	e) delete b->data; false, because the whole node needs to be deleted
	f) delete b;
2.	a) a = a->next;				would point to b
	b) b = a;					would point to a
	c) c = a->next;				would point to b
	d) b->data = c->data;		b->data would be 3
	e) a->data = b->next->data;	a->data would be 3
	f) c->next = a;				would point to a
3.	a->next = b;
4.	node* temp = getdata();
	current = head;
	temp->next = head;
5.	current = head;
	head = head->next;
	temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = current;
6.	a) 5 5
	b) 14 4 10
	c) 10 100