//one instance of this class makes one row
class association{
private:
	char key_name[30];
	int value;

public:

	association(char key[30],int new_value); 
	association(){
		strcpy(key_name,"###");
		value=0;
	}
	association(const association &a){
        strcpy(key_name,a.return_key_name());
		value=a.return_value();
	}

	char* return_key_name(){
		return key_name;
	}
    int return_value(){
		return value;
	}

};
const int MAX=10;
class one_key_table {
private:
	association rows[MAX];
	int table_length;
public:
	one_key_table(){
		association a;
		table_length=0;
		rows[0]=a;}
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
			association[probe](targetname, value);
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


		









	int main(){
		association a("Neil", 32);
		association b(a);//calling the copy constructor




