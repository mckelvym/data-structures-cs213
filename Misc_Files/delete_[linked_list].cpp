// delete

	while ((strcmp(current->next->name, target) != 0) && (current->next != NULL))
	{
		current=current->next;
	}

	if (current->next == NULL)
	{
		cout << "Node could not be found" << endl;
	}
	else if (current->next == target)
	{
		temp = current->next;
		current->next = temp->next;
		delete temp;
	}