// read section 5.3 pages 229-238 and answer questions 1 and 2 on page 239
// write remaining functions and test driver

const int MAX = 2000;

class QueueADT{
private:
	int data[MAX];
	int front,rear;
public:
	QueueADT();
	bool is_empty(); 
	int length();
	void enqueue(int item);
	int dequeue();
	int at_front();
	int at_rear();
};

QueueADT::QueueADT(){
	front = -1;
	rear = -1;
}

bool QueueADT::is_empty()
{
	if ((front == -1) && (rear == -1))
		return true;
	else
		return false;
}

int QueueADT::length()
{
	int counter = 0;
	int index = -1;

	if (front == -1)
		return 0;
	else
	{
		index = front;
		counter++;
		while (index <= rear)
		{
			index++;
			counter++;
		}
		if (index == rear)
			return counter;
	}
}

void QueueADT::enqueue(int item){
	if(front == -1)
		front = rear = 0;
	else rear++;
		data[rear] = item;
}

int QueueADT::dequeue()
{
	if(front != -1)
		return data[front++];
	else return -999;
	//otherwise move data up one index
}

int QueueADT::at_front()
{
	if (front != -1)
		return data[front];
	else return -999;
}

int QueueADT::at_rear()
{
	if (rear != -1)
		return data[rear];
	else return -999;
}




		






