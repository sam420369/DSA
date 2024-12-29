#include <iostream>
#include "Header.h"

aQueue::aQueue(int x) : size(x) {
	q.resize(size);
}

void aQueue::enqueue(int num) {
	if (this->rear == this->size - 1) {
		std::cerr << "Queue is full" << std::endl;
		return;
	}
	else {
		this->rear++;
		q[this->rear] = num;
	}
}

void aQueue::dequeue() {
	if (this->front == this->rear) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}

	// just use linked list and don't look at the below bs.
	// lets take a queue like 1 2 3 4 5 6 and so on. the from pointer in pointing at -1 while rear at 7(i.e. number 6). To dequeue we move the front pointer to 0 essentialy ignoring the 1 because the queue always begins at front + 1. 

	front++;
}

void aQueue::display() {
	for (int it = this->front + 1; it <= rear; it++) {
		std::cout << q.at(it) << std::endl;
	}
}

circularQueue::circularQueue(int x) : size(x) {
	q.resize(this->size);
}

void circularQueue::enqueue(int x) {
	if ((rear + 1) % size == front) {
		std::cerr << "Queue is full" << std::endl;
		return;
	}

	rear = (rear + 1) % size;
	q[rear] = x;
}

void circularQueue::dequeue() {
	if (this->front == this->rear) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}

	front = (front + 1) % size;
}

void circularQueue::display() {
	for (int it = front + 1; it != (rear + 1) % size; it = (it + 1) % size) {
		std::cout << q[it] << std::endl;
	}

}

int node::getData() {
	return this->data;
}

void node::setData(int x) {
	this->data = x;
}

node* node::getNextNode() {
	return this->next;
}

void node::setNextNode(node* t) {
	this->next = t;
}

void node::setNextNodeNull() {
	this->next = nullptr;
}

bool Queue::isEmpty() {
	if (this->front == nullptr) {
		return 1;
	}
	return 0;
}

bool Queue::isFull() {
	node* temp = new node;

	if (!temp) {
		return 1;
	}
	return 0;
}

void Queue::enqueue(int x) {
	node* temp = new node;

	if (temp == nullptr) {
		std::cerr << "Queue is full" << std::endl;
		return;
	}

	temp->setData(x);
	temp->setNextNodeNull();

	if (this->isEmpty()) {
		front = rear = temp;
	}
	else {
		rear->setNextNode(temp);
		rear = temp;
	}
}

void Queue::dequeue() {
	if (this->isEmpty()) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}

	node* temp = this->front;

	this->front = this->front->getNextNode();

	delete temp;
}

void Queue::display() {
	node* temp = this->front;

	if (this->isEmpty()) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}

	while (temp) {
		std::cout << temp->getData() << std::endl;
		temp = temp->getNextNode();
	}
}

void deQueue::enqueue(int x) {
	node* temp = new node;
	temp->setData(x);
	temp->setNextNode(NULL);

	if (temp == NULL) {
		std::cerr << "Queue is full" << std::endl;
		return;
	}

	if (rear != nullptr) {
		rear->setNextNode(temp);
		rear = temp;
	}
	else {
		front = rear = temp;
	}
}

void deQueue::dequeue() {
	if (this->front == nullptr) {
		std::cerr << "Queue is already empty" << std::endl;
		return;
	}

	node* temp = front;
	front = front->getNextNode();
	delete temp;
}

void deQueue::enqueueF(int x) {
	node* temp = new node;
	temp->setData(x);

	if (!temp) {
		std::cerr << "Queue is full" << std::endl;
		return;
	}

	if (this->front == nullptr && this->rear == nullptr) {
		temp->setNextNodeNull();
		front = rear = temp;
	}
	else {
		temp->setNextNode(front);
		front = temp;
	}
}

void deQueue::dequeueR() {
	if (rear == nullptr) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}

	node* temp = this->front;

	while (temp->getNextNode() != nullptr && temp->getNextNode() != this->rear) {
		temp = temp->getNextNode();
	}

	if (rear != front) {
		rear = temp;
		temp = temp->getNextNode();
		rear->setNextNodeNull();
		delete temp;
	}
	else {
		front = rear = nullptr;
	}
}

void deQueue::display() {
	if (front == nullptr) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}

	node* temp = this->front;
	while (temp) {
		std::cout << temp->getData() << std::endl;
		temp = temp->getNextNode();
	}
}

void sQueue::enqueue(int x) {
	s1.push(x);
}

void sQueue::dequeue() {
	if (s1.empty() && s2.empty()) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}

	if (s2.empty()) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}
	else {
		s2.pop();
	}
}

void sQueue::display() {
	if (s1.empty() && s2.empty()) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}
	while (!s2.empty()) {
		std::cout << s2.top() << std::endl;
		s2.pop();
	}

	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}

	while (!s2.empty()) {
		std::cout << s2.top() << std::endl;
		s2.pop();
	}
}