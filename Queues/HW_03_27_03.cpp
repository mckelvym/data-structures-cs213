// mark mckelvy
// data structures 3:00 mwf
// march 27, 2003
// section 5.3 homework p239: 1, 2 and remaining functions/test driver

#include <iostream.h>
#include "queue.h"

int main()
{
	QueueADT q;
	int get;

	q.enqueue(50);
	q.enqueue(30);
	q.enqueue(348);
	cout << "Length = " << q.length() << endl;
	cout << "At Front = " << q.at_front() << endl;
	cout << "At Rear = " << q.at_rear() << endl;
	if (q.is_empty())
		cout << "List is Empty" << endl;
	else
		cout << "List is Not Empty" << endl;
	cout << endl << "List: " << endl;
	get = q.dequeue();
	cout << get << endl;
	get = q.dequeue();
	cout << get << endl;
	get = q.dequeue();
	cout << get << endl;
	
	return 0;
}

1.
	void replace (queue<int> &q, int old_int, int new_int)
	{
		int index = front;

		while (index != rear)
		{
			if (q[index] == old_int)
				q[index] = new_int;
			index++;
		}
	}

2.
	float average (queue<float> &q)
	{
		int index = front;
		float total = 0.0f;
		int counter = 0;

		while (index != rear)
		{
			total += q[index];
			counter++;
			index++;
		}

		return (float(total / counter));
	}


