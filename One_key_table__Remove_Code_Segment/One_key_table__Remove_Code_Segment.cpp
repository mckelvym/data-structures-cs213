// Mark McKelvy
// Data Structures 3:00 MWF
// 2/14/03
// Remove Code Segment

// Assume 'remove' is a constructor of class one_key_table
void remove (char target[])
{
	int index = 0;
	bool found = false;
	char current_key[30];

	while ((index < table_length) && (!found))
	{
		strcpy(current_key, row[index].return_key());
		if (strcmp(current_key, target) == 0)
		{
			found = true;
		}
		else if (strcmp(current_key, target != 0)
		{
			index++;
		}
	}
	if (found)
	{
		index = 0;
		while (index < table_length)
		{
			association[index]((row[index + 1].return_key(), row[index + 1].return_val()));
			index++;
		}
		table_length--;
		
		return;
	}
	else if (!found)
	{
		cout << error_msg() << endl;
		
		return;
	}
}

// not a constructor
void error_msg()
{
	system("CLS");
	cout << "The key to be removed does not exist!" << endl;
	
	return;
}