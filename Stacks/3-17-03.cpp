const int MAX=20;
class stack{
private:
	int top_index;
	char my_stack[MAX];
public :
	char on_top();
	stack();//create function
	void push(char data);
	char pop();
	bool empty();
};

stack::stack(){
	top_index=-1;
}

char stack::on_top(){
	if(top_index!=-1)
		return my_stack[top_index];
    else return '@';
}


void stack::push(char data){
	top_index++;
	my_stack[top_index]=data;
}

char stack::pop(){
    char item=my_stack[top_index];
	top_index--;
	return item;
}

bool stack::empty(){
	if(top_index==-1)
		return true;
	else return false;
}

f
d
e
p
q
b


int main(){
	stack s;
	s.push('b');
	s.push('d');
	s.pop();
	cout<<s.pop();
	char expression[20];
	cin>>expression;
	//for(int i=0...)
	while(expression[i]!='\n')
		if(expression[i]=='(')
			s.push(expression[i]);
		else if(expression[i]==')')
				if(s.empty())
					cout<<"paranthesis not correct\n";
				else s.pop();
}


HW: page 211 read sec 5.1 and answer questions 1,4,5,7  













