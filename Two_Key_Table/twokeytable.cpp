// two key table
int data[MAX_rows][MAX_cols]; // int data[20[10]
int row_l;

void store(char key1[], char key2[], int value)
{
	int rows_index = 0;
	int columns_index = 0;
	int columnl[MAX_ROWS];
	bool found1 = false;
	bool found2 = false;
	
	// searches for name (key1); goes through rows
	while ((rows_index < row_l) && (!found1))
	{
		if (strcmp(data[rows][cols], key1) == 0)
		{
			found1 = true;
		}
		else rows_index++;
	}
	// rows = 2	
	if (!found1)
	{
		if (rows < MAX_ROWS)
		{
			rows++;
		}
		else cout << "NO ROOM\n";
	}
	
	while (columns_index < columnl[rows_index] && !found2)
	{
		if (strcmp(data[rows][cols], key2 == 0)
		{
			found2 = true;
		}
		else cols++;
	}


	if (!found2) // height does not exist
	{
		// is there room? for another col in row two?
		if (columnl[rows] < MAX_COLUMNS)
		{
			columnl[rows]++;
		}
		else cout << "No room\n";
	}

	//one instance of this class makes one row
template <class anytype> 
class association{
private:
	char key_name[30];
	anytype value;

public:

	association(char key[30],anytype new_value); 
	association(){
		strcpy(key_name,"###");
		value=0;
	}
	association(const association &a){
        strcpy(key_name,a.return_key_name());
		value=a.return_value();
	}
};
template <class anytype>
char* association<anytype>::return_key_name(){
		return key_name;
	}
    int return_value(){
		return value;
	}

};
const int MAX=10;
template <class anytype>
class one_key_table {
private:
	association rows[MAX];
	int table_length;
public:
	one_key_table(){
		association<anytype> a;
		table_length=0;
		rows[0]=a;
	}

	void store(char target_name[], int value){
		int probe=0;
		bool found=false;
		char key_name[30];
        while(probe<table_length && !found){
			strcpy(key_name,rows[probe].return_key_name());
			if(strcmp(key_name,target)>=0)
				found=true;
		}

		if(found==true && strcmp(key_name,target_name)==0))
			//update existing waist size with the new "value"
		else if(table_length<MAX)
				//room available

				int main(){
			       one_key_table<int> table;

		

	int main(){
		association a("Neil", 32);
		association b(a);//calling the copy constructor




