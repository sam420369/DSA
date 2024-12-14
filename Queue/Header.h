#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <vector>

class Queue {
private:
	int size = 0;
	int front = -1;
	int rear = -1;
	std::vector<int> q;

public:
	Queue(int x);

	void enqueue(int num);

	void dequeue();

	void display();
};

class circularQueue {
private:
	int size = 0;
	int front = 0;
	int rear = 0;
	std::vector<int> q;

public:
	circularQueue(int x);

	void enqueue(int num);

	void dequeue();

	void display();
};

#endif // !_QUEUE_H_
