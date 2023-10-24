/*
Experiment No. 29 : 
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
If the operating system does not use priorities, then the jobs are processed in the order they enter the system. 
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.
*/

#include<iostream>
#define size 5
using namespace std;

class JobQue {
    private:
	    struct queue {
		int que[size];
		int front, rear;
	    } Q;
    public:
	    JobQue();
	    int Qfull();
	    int insert(int);
	    int Qempty();
	    int delet();
	    void display();
};

JobQue::JobQue() {
	Q.front = -1;//-1 indicates it is empty
	Q.rear = -1;
}

int JobQue::Qfull() {
	if (Q.rear >= size-1)
		return 1;
	else
		return 0;
}

//The insert  Function
int JobQue::insert(int item) {
	if (Q.front == -1)
		Q.front++;
	Q.que[++Q.rear] = item;
	return Q.rear;
}

int JobQue::Qempty() {
	if ((Q.front == -1) || (Q.front > Q.rear))
		return 1;
	else
		return 0;
}

//The delete Function
int JobQue::delet() {
	int item;
	item = Q.que[Q.front];
	Q.front++;
	cout << "\nThe deleted Job is : " << item << endl;
	return Q.front;
}

//The display Function
void JobQue::display() {
	int i;
    cout << "\n";
	for (i = Q.front; i <= Q.rear; i++)
		cout << Q.que[i] << "\t";
    cout << "\n";
}
int main(void) {
	int choice, item;
	char ans;
	JobQue obj;
	do {
		cout << "\nMain Menu";
		cout << "\n1. ADD Job\n2. Delete Job\n3. Display Job Queue";
		cout << "\nEnter Your Choice : ";
		cin >> choice;
		switch (choice) {
			case 1:
                if (obj.Qfull())       //checking for Queue overflow
				cout << "\nCan not insert the Job";
				else {
					cout << "\nEnter The Job number : ";
					cin >> item;
					obj.insert(item);
				}
				break;
			case 2:
                if (obj.Qempty())
					cout << "\nQueue Underflow!!";
				else
					obj.delet();
				break;
			case 3:
                if (obj.Qempty())
					cout << "\nJob Queue Is Empty!";
				else
					obj.display();
				break;
			default:
                cout << "\nWrong choice!";
					break;
		}
		cout << "\nDo You Want to continue? : ";
		cin>>ans;
	} while (ans == 'Y' || ans == 'y');
	return 0;
}
