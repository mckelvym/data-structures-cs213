class one_key_table()
{
public:
	one_key_table();
	void create(int length);
	void remove(datatype2 target[]);
	void add(datatype1 key, datatype2 value);
	void search(datatype1 target);
	void rename(datatype1 key, datatype2 value);
	datatype1 current_key();
	{
		return key;
	}
	datatype2 current_value();
	{
		return value;
	}
	int table_length();
private:
	datatype1 key;
	datatype2 value;
};

void one_key_table::remove(datatype1 target[])
{
	bool deleted = false;
	int length = table_length();
	int element = 0;

	while ((false) && (element < (length - 1)))
	{
		if (strcmp(current_key[element](), targer) != 0)
		{
			while (strcmp(current_key[element](), target) < 0)
			{
				element++;
			}
			if (strcmp(current_key[element](), target) > 0)
			{
				cout << "Not Found" << endl;
				return;
			}
		}
		else if (strcmp(current_key[element](), target) == 0)
		{
			while ((current_key[element + 1]()) != NULL)
			{
				rename(current_key[element + 1](), current_key[element]());
				element++;
			}
			deleted = true;
		}

	}
}

void bubblesort()
{
	bool switched = false;
	datatype *current;
	int length;
	int array[10];
	int counter = 0;
for (
	for (counter = 0; counter < 10; counter++)
	{
		switched = false;
		if (array[counter] > array[counter - 1])
