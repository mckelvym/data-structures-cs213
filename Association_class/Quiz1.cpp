// the function is part of the one_key_table class
// key_type key[] is a key that needs a new value
// int value is the value to change to
void store (key_type key[], int value, int &tablesize)
{
	probe = 0;
	probe2 = tablesize;		// find the table size and initialize it to probe2
	char target[] = key[];		// set key[] to the target string
	bool found = false;

	// go through table until the target key is found
	while (strcmp(rows[probe].return_key(), target) != 0 && !found)
	{
		probe++;
	}
	// if the target key is the one after probe...set found to 'true'
	if (strcmp(rows[probe + 1].return_key(), target) == 0)
	{
		found == true;
	}
	// if the key is found then set its key to the target string, and change the value
	if (found)
	{
		association[probe + 1](target, value);
	}
	// else if the table still has room, move all values below [probe + 1] down to make room
	// and increment the tablesize
	else if (tablesize < MAX)
	{	
		probe = 0;
		while (strcmp(rows[probe].return_key(), target) == -1)
		{
			probe++;
		}
		for (probe2; probe2 > probe; probe--)
		{
			association[probe2 + 1] = association[probe2]
		}
		association[probe2](target, value);
		tablesize++;
	}
}

