mark mckelvy
data structures 3:00 mwf
march 17, 2003
section 5.1 homework: stacks

1)	4	4	4	4	4	4
		10	10	10	10	10
			12		36	36
						108

4)	a.	stack::stack()
		{
			top_index = -1;
		}
		stack::stack(const &s)
		{
			top_index = 0;
			linkedlist a_stack;
			a_stack.first(s);
		}
		
	b.	void stack::destroy()
		{
			linkedlist a_stack;
			while (top_index != -1)
			{
				pop();
			}
		}

	c.	bool stack::empty()
		{
			if (top_index == -1)
				return true;
			else return false;
		}

	d.	void stack::push(datatype item)
		{
			if (a_stack.at_end())
				a_stack.insert(item);
			else
			{
				while (!a_stack.at_end())
				{
					a_stack.next();
				}
				a_stack.insert(item);
			}
		}

	e.	datatype stack::pop()
		{
			datatype item;
			item = a_stack.retrieve();
			a_stack.remove();
			return item;
		}

	f.	bool stack::on_top()
		{
			if (a_stack[top_index].retrieve())
				return true;
			else return false;
		}

5)	(	(	(	(	(	(	(	
		(	(	(	(	(
			(		(

7)	int main()
	{
		stack mystack;
		char myitem[30];
		int counter = 0;
		cin >> myitem;

		while (counter != '\n')
		{
			mystack.push(myitem[counter]);
			counter++;
		}
		while (counter != -1)
		{
			cout <<	mystack.pop();
			counter--;
		}
		return 0;
	}

