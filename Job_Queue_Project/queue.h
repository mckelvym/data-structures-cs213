#ifndef QUEUEADT_H
#define QUEUEADT_H

struct node
{
	int data;
	node *next;
};

class QueueADT
{
	public:
		QueueADT();
		~QueueADT();
		bool is_empty(); 
		int at_front();
		int at_rear();
		int dequeue();
		int get_job(int number);
		int get_length();
		void enqueue(int item);

	private:
		int length;
		node *front;
		node *rear;
};

#endif QUEUEADT_H

QueueADT::QueueADT()
{
	front = NULL;
	rear = NULL;
	length = 0;
}

QueueADT::~QueueADT()
{
	node *temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
}

bool QueueADT::is_empty()
{
	if ((front == NULL) && (rear == NULL) && (length == 0))
		return true;
	else
		return false;
}

int QueueADT::get_length()
{
	return length;
}

void QueueADT::enqueue(int item)
{
	node *temp = new node;
	temp->data = item;
	temp->next = NULL;

	if (front == NULL)
	{
		front = rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = rear->next;
	}
	length++;
}

int QueueADT::dequeue()
{
	if (length > 0)
	{	
		int some_data;
		node *temp = new node;
	
		temp = front;
		front = front->next;
		some_data = temp->data;
		delete temp;
		length--;
		return some_data;
	}
	else 
	{
		return -1;
	}
}

int QueueADT::at_front()
{
	if (front != NULL)
		return front->data;
	else
		return -1;
}

int QueueADT::at_rear()
{
	if (rear != NULL)
		return rear->data;
	else 
		return -1;
}

int QueueADT::get_job(int number)
{
	int node_number = 1;
	int data;

	if (length != 0)
	{
		node *current = new node;
		current = front;
		while ((node_number != number) && (node_number <= length))
		{
			current = current->next;
			node_number++;
		}
		if (node_number > length)
			return -1;
		else 
		{
			data = current->data;
			return data;
		}
	}
	else return -1;
}
