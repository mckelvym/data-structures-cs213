mark mckelvy
data structures 3:00 mwf
april 7, 2003

page 292: 4,5,10
page 304: 4

4.	low		high	mid		target = 8
	0		15		8

5.	low		high	mid		target = -1 (not found)
	0		15		8
	0		7		4
	0		3		2
	0		1		1
	0		0		0
	0		-1		(Not Found, return -1)

10.	void insertion_sort (list_type list, int n, int k)
	{
		int j;
		element item_to_insert;
		boolean still_looking;

		item_to_insert = list[k];
		j = k - 1;
		still_looking = TRUE;
		while ((j >= 0) && still_looking)
		{
			if (item_to_insert < list[j])
			{
				list[j + 1] = list[j];
				j--;
			}
			else
				still_looking = FALSE;
			list[j + 1] = item_to_insert;
			if (k < n)
			{
				k++;
				insertion_sort(list_type list, int n, int k);
			}
		}
	}


4.	16, 1, 2, 3, 4, 3, 3, 4, 4, 3,
	 4, 2, 2, 3, 4, 3, 3, 4, 4, 3,
	 4, 3, 2, 3, 4, 3, 3, 4, 4, 3,
	 4, 4, 2, 3, 4, 3, 3, 4, 4, 3,
	 4
	