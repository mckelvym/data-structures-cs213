// Mark McKelvy
// Data Structures 3:00 MWF
// 2/12/03
// Store Code Segment


// Assume the following is a constructor of the one_key_table class
void store (char target_name[], int value)
{
	int probe = 0;
	int probe2 = 0;
	bool found = false;
	char key_name[30];
	while ((probe < table_length) && (!found))
	{
		strcpy(key_name,rows[probe].return_key_name());
		if (strcmp(key_name,target) >= 0)
		{
			found = true;
		}
	}
	if ((found == true) && (strcmp(key_name,target_name) == 0)))
	{
		association[probe2](targetname, value);
	}
	else if(table_length<MAX)
	{
		probe = 0;
		while (strcmp(key_name[probe], targetname) == -1)
		{
			probe++;
		}
		probe++;
		probe2 = 0;
		while (strcmp(key_name[probe2], "###") != 0)
		{
			probe2++;
		}
		for (probe2; probe2 > probe; probe--)
		{
			key_name[probe2 + 1] = key_name[probe2];
		}
		association[probe2](targetname, value);
	}
}