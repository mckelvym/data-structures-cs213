// mark mckelvy
// data structures 3:00 mwf
// march 27, 2003
// job queue project

#include <conio.h>
#include <iomanip.h>
#include <iostream.h>
#include <stdlib.h>

// ***** Begin Queue Class *****

// 'node' to hold queue data
struct node
{
	int data;			// holds time for entering queue
	node *next;			// pointer to next node in queue
};

// class that has all helper functions for the queue
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
		int length;		// holds length of queue
		node *front;	// pointer to the front of the queue
		node *rear;		// pointer to the rear of the queue
};

// default constructor function
QueueADT::QueueADT()
{
	front = NULL;
	rear = NULL;
	length = 0;
}

// default destructor function
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

// returns if the queue is empty or not
bool QueueADT::is_empty()
{
	if ((front == NULL) && (length == 0))
		return true;
	else
		return false;
}

// returns the length of the queue
int QueueADT::get_length()
{
	return length;
}

// enqueues a job with timestamp
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

// dequeues a job, returning the timestamp
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

// returns the timestamp of the front node in the queue
int QueueADT::at_front()
{
	if (front != NULL)
		return front->data;
	else
		return -1;
}

// returns the timestamp of the rear node in the queue
int QueueADT::at_rear()
{
	if (rear != NULL)
		return rear->data;
	else 
		return -1;
}

// returns the timestamp of the 'nth' node in the queue
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

// ***** End Queue Class *****

// ***** Begin Program *****

QueueADT q;						// dynamic variable to hold job queue

double random();				
void get_data(float &probability, int &total_minutes, int &work_time);								
void welcome();					

int main()
{
	bool beenused = false;	
	bool display = false;		// variable that determines if a job is being processed
	float probability;			// variable that holds probability of job entering queue
	int counter;				// variable that shows which jobs are in the queue
	int current_time = 0;		// variable for current minute
	int display_job = 1;		// variable that holds the number for the job to display
	int job_being_processed = 0;// variable holding current job being processed
	int job_enqueued = 0;		// variable that holds number of jobs enqueued
	int job_queue;				// variable for length of job queue
	int jobs_completed = 0;		// variable that holds number of jobs completed
	int time_entered;			// variable that holds the time that a job enters queue
	int timeleft = 0;			// varialbe to keep track of how much more work a job requires
	int total_minutes;			// variable for total minutes of time to work (iterate)
	int total_time_on_jobs = 0;	// variable that holds total amount of time actually spent working
	int work_time;				// variable that holds amount of time to spend of each job
	
	welcome();
	get_data(probability = -1.0f, total_minutes = -1, work_time = -1);
	
	for (current_time = 1; current_time <= total_minutes; current_time++)
	{	
		system("CLS");
		cout.setf(ios::left);
		cout << setw(10) << "Minute" << setw(20) << "Job Enqueued" << setw(25) << "Job being Processed" << "Jobs Waiting/Wait Time" << endl << endl;
		cout << setw(10) << current_time;
		// determines if a new job enters the queue
		if (random() <= probability)
		{
			q.enqueue(current_time);
			job_enqueued++;
			cout << "Job " << setw(20) << job_enqueued;
		}
		else
			cout << setw(20) << "NONE";
		// determines whether or not there is a job being processed
		if ((timeleft == 0) && (q.is_empty()))
		{
			display = false;
		}
		// determines if a new job is to be dequeued
		if ((timeleft == 0) && (!q.is_empty()))
		{
			time_entered = q.dequeue();
			total_time_on_jobs = total_time_on_jobs + (current_time - time_entered);
			job_being_processed = ++jobs_completed;
			timeleft = work_time;
			display = true;
		}
		// decreases the time left to work on current job
		if (timeleft != 0)
			timeleft--;
		job_queue = q.get_length();
		counter = job_being_processed + 1;
		display_job = 1;

		// displays the job being processed (if there is one)
		if ((job_being_processed != 0 ) && (display))
			cout << "Job " << setw(30) << job_being_processed;
		else
			cout << setw(30) << "NONE";
				// displays the jobs waiting in the queue (if there are some)
		if (job_queue != 0)
		{
			beenused = false;
			while (display_job <= job_queue)
			{
				if (beenused == false)
					cout << endl;
				cout << setw(65) << "" << "Job " << counter << " - " 
					 << current_time - q.get_job(display_job) << endl;
				beenused = true;
				counter++;
				display_job++;
			}
		}
		else
			cout << setw(65) << endl << "NONE";
		cout << endl << endl;
		getch();
	}

	system("CLS");
	cout << "Total Jobs Completed:  " << jobs_completed << endl;
	cout << "Average Wait Time:     " << float(total_time_on_jobs / jobs_completed) 
		 << " minutes." << endl;
	
	return 0;
}

// returns a random number between 0 (including) and 1 (not including)
double random()
{
	return (rand() / (double(RAND_MAX)));
}

// gets probability, total work time, a time to spend on each job from user
void get_data(float &probability, int &total_minutes, int &work_time)
{
	// get a valid probability from the user
	do
	{
		system("CLS");
		if (probability > 1.0f)
		{
			system("CLS");
			cout << "You may be a work-a-holic..." << endl;
			cout << "But the computer simulation program is not." << endl;
			cout << "Try again, with a more reasonable probability this time..." << endl;
		}
		if ((probability <= 0.0f) && (probability != -1.0f))
		{
			system("CLS");
			cout << "So, we have a lazy one eh?" << endl;
			cout << "Try again, with a real chance to do work please..." << endl;
		}
		cout << endl << "Enter the probability for a job to enter queue (as decimal). ";
		cin >> probability;
	}while ((probability > 1.0f) || (probability <= 0.0f));
	
	// get a valid total time to work
	do
	{
		system("CLS");
		if ((total_minutes < 100) && (total_minutes >= 0))
		{
			system("CLS");
			cout << "Too little work time!" << endl;
		}
		else if (total_minutes > 3600)
		{
			system("CLS");
			cout << "The simulation won't run for that long!" << endl;
		}
		else if (total_minutes < -1)
		{
			system("CLS");
			cout << "I'm not sure where you are from, but" << endl;
			cout << "we measure time in a positive form." << endl;
			cout << "Try again..." << endl;
		}
		cout << endl << "Enter total minutes to work (least = 100). ";
		cin >> total_minutes;
	}while ((total_minutes < 100) || (total_minutes > 3600));
	
	// get a valid amount of time to work on each job
	do
	{
		system("CLS");
		if (work_time == 0)
		{
			system("CLS");
			cout << "0 minutes for work time...impressive!" << endl;
			cout << "Try again chump..." << endl;
		}
		else if (work_time < -1)
		{
			system("CLS");
			cout << "I'm not sure where you are from, but" << endl;
			cout << "we measure time in a positive form." << endl;
			cout << "Try again..." << endl;
		}
		else if (work_time > total_minutes)
		{
			system("CLS");
			cout << "Would you mind explaining how a you are goin to finish" << endl;
			cout << "a job that lasts longer than you have time? Or wait, just" << endl;
			cout << "Try again, and be smart this time..." << endl;
		}
		cout << endl<< "Enter the amount of time required to process a job (as integer). ";
		cin >> work_time;
	}while ((work_time < 1) || (work_time > total_minutes));
}

// displays welcome screen
void welcome()
{
	cout << "\n                             The CPU simulator!" << endl;
	cout << "\n\n\n\nThis program simulates a job queue for a processor.";
	cout << "\n\nPress any key." << endl;
	getch();
}

