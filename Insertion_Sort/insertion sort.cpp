void insertion_sort (list_type list, int n)
{
	int j, k;
	element item_to_insert;
	boolean still_looking;

	// on the kth pass, insert item k into its correct position among
	// the first k entries in the array.

	for (k = 1; k < n; k++)
	{
	// walk backwards through the list, lookng for slot to insert list[k]
		item_to_insert = list[k];
		j = k - 1;
		still_looking = TRUE;
		while ((j >= 0) && still_looking)
			if (item_to_insert < list[j])
			{
				list[j + 1] = list[j];
				j--;
			}
			else
			still_looking = FALSE;
		// upon leaving loop, j + 1 is the index
		// where item_to_insert belongs
		list[j + 1] = item_to_insert;
	}
}