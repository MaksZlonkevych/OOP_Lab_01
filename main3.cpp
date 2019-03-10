#include <iostream>

#define N 100
using namespace std;

class Queue {
private:
	int n;
	int front;
	int rear;
public:
	Queue(int a, int b, int c) { n = a;  front = b; rear = c; }
	~Queue() {}
	int queue[N];

	void Push() {
		int val;
		if (rear == n - 1)
			cout << "Queue Overflow" << endl;
		else {
			if (front == -1)
				front = 0;
			cout << "Push the element in queue : " << endl;
			cin >> val;
			rear++;
			queue[rear] = val;
		}
	}
	void Pop() {
		if (front == -1 || front > rear) {
			cout << "Queue Underflow " << endl;
			return;
		}
		else {
			cout << "Element poped from queue is : " << queue[front] << endl;
			front++;;
		}
	}
	void Display() {
		if (front == -1)
			cout << "Queue is empty" << endl;
		else {
			cout << "Queue elements are : ";
			for (int i = front; i <= rear; i++)
				cout << queue[i] << " ";
			cout << endl;
		}
	}
	int Getrear() {
		return rear;
	}
	int Getfront() {
		return front;
	}
	int Amount() {
		return Getrear() - Getfront() + 1;
	}
	int SumStay() {
		int sum = 0;
		for (int rear1 = Getrear(); rear1 >= Getfront(); rear1--) {
			sum += queue[rear1];
		}
		return sum;
	}



	int SumExit() {
		int sum = 0;
		for (int front1 = 0; front1 < Getfront(); front1++) {
			sum += queue[front1];
		}
		return sum;
	}

	int Multiply() {
		int multiply = 1;
		for (int rear2 = Getrear(); rear2 >= Getfront(); rear2--) {
			multiply *= queue[rear2];
		}
		return multiply;
	}
};

int main() {
	int number_of_operations;

	Queue objQueue(N, -1, -1);

	cout << "1) Push element to queue" << endl;
	cout << "2) Pop element from queue" << endl;
	cout << "3) Display all the elements of queue" << endl;
	cout << "4) Complete editing queue" << endl;


	do {
		cout << "Enter your choice : " << endl;
		cin >> number_of_operations;
		switch (number_of_operations) {
		case 1: objQueue.Push();
			break;
		case 2: objQueue.Pop();
			break;
		case 3: objQueue.Display();
			break;
		case 4: cout << "Complete editing queue" << endl;
			break;
		default: cout << "Invalid choice" << endl;
		}
	} while (number_of_operations != 4);
	cout << objQueue.Getrear() << endl;
	cout << objQueue.Getfront() << endl;
	cout << "The sum of the elements that exit of the queue - " << objQueue.SumExit() << endl;
	cout << "The sum of the elements that enter of the queue - " << objQueue.SumStay() << endl;
	cout << "The multiply of the elements of the queue - " << objQueue.Multiply() << endl;
	cout << "Amount of the elements of the queue - " << objQueue.Amount() << endl;
	system("pause");
	return 0;
}