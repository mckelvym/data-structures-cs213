//int data[rows][cols];
int data[MAX_ROWS][MAX_COLS]; //int data[20][10];
int row_length;

void store(char target_key1[], char target_key2[], int value){
	int rows=0,cols=0;
	int col_length[MAX_ROWS];
	bool found_key1=false;
	bool found_key2=false;
	//searching for name or key 1, going thru the rows
	while(rows<row_length && !found_key1){
		if(strcmp(data[rows][cols],target_key1)==0)
			found_key1=true;
		else rows++;
	}
	if(found_key1==false)
		if(rows<MAX_ROWS)
			rows++; 
		else cout<<"no room\n";
    //rows=2
	while(cols<col_length[rows] && !found_key2){
		if(strcmp(data[rows][cols],target_key2)==0)
			found_key2=true;
		else cols++;
	}

	if(found_key2==false) //height does not exist
		//is there room for another col in row2?
		if(col_length[row]<MAX_COLS)
			col_length{rows]++;
		else cout<<"No room\n";
	









		

