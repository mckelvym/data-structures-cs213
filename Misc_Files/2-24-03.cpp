#include<iostream.h>
struct node{
	char name[20];
	int age;
	node *next;
};


int main(){
node *head;
node *current;
node *temp;//add a new node to my list or deleting a node from list
head=new node;
current=new node;
temp=new node;
head=NULL;
cin>>head->name; //or cin.get(head->name,20);
cin>>head->age;
head->next=NULL;
do{
	
 //adding nodes- get info from user
	//add nodes to end of list



}while(choice=='y');

void move_current_to_end(){
	current=head;
	while(current->next!=NULL)
		current=current->next;
}



/*int *a;//static allocation- memory add cannot be moved
int size;
cin>>size;
a=new int[size];
a=new int[size*2];
int b;
a=&b;
b=10;
b++;
cout<<++(*a)<<endl;
int *c;
c=new int;
*a=13;
c=a;
cout<<"value of c:"<<*c;
return 0;*/
}

