#include <iostream>
#include "Header.h"

Queue::Queue(int x) : size(x) {
	q.resize(size);
}

void Queue::enqueue(int num) {
	if (this->rear == this->size - 1) {
		std::cerr << "Queue is full" << std::endl;
		return;
	}
	else {
		this->rear++;
		q[this->rear] = num;
	}
}

void Queue::dequeue() {
	if (this->front == this->rear) {
		std::cerr << "Queue is empty" << std::endl;
		return;
	}

	// just use linked list and don't look at the below bs.
	// lets take a queue like 1 2 3 4 5 6 and so on. the from pointer in pointing at -1 while rear at 7(i.e. number 6). To dequeue we move the front pointer to 0 essentialy ignoring the 1 because the queue always begins at front + 1. 

	front++;
}

void Queue::display() {
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