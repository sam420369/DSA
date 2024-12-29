#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <vector>
#include <stack>

//using array
class aQueue {
private:
	int size = 0;
	int front = -1;
	int rear = -1;
	std::vector<int> q;

public:
	aQueue(int x);

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

class node {
private:
	int data = NULL;
	node* next = nullptr;

public:
	int getData();

	void setData(int x);

	node* getNextNode();

	void setNextNode(node* t);

	void setNextNodeNull();

};

// using linked list
class Queue {
private:
	node* front = nullptr;
	node* rear = nullptr;
public:
	bool isEmpty();

	bool isFull();

	void enqueue(int x);

	void dequeue();

	void display();
};

class deQueue {
private:
	node* front = nullptr;
	node* rear = nullptr;

public:
	void enqueue(int x);

	void dequeue();

	void enqueueF(int x);

	void dequeueR();

	void display();
};
	
class sQueue {
private:
	std::stack<int> s1;
	std::stack<int> s2;
	
public:
	void enqueue(int x);

	void dequeue();

	void display();
};
#endif // !_QUEUE_H_
