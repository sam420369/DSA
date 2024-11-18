#include <iostream>
#include "Header.h"

using namespace std;

stack::stack() {
	cout << "Enter the size of the stack: " << endl;
	cin >> size;
	Stack = new int[5];
}

void stack::isEmpty() {
	if (Top == -1) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "Stack is not empty" << endl;
	}
}

void stack::isFull() {
	if (Top == size - 1) {
		cout << "Stack is full" << endl;
	}
	else {
		cout << "Stack is not full" << endl;
	}
}

void stack::push(int data) {
	if (Top + 1 < size) {
		Stack[Top + 1] = data;
		Top++;
	}
	else {
		cout << "Stack overflow" << endl;
	}
}

void stack::pop() {
	if (Top == -1) {
		cout << "Stack is empty" << endl;
	}
	else {
		Stack[Top--] = NULL;
	}
}

int stack::top() {
	if (Top != -1) {
		return Stack[Top];
	}
	else {
		cout << "Stack is empty" << endl;
		return INT_MIN;
	}
}

int stack::peek(int pos) {
	if (pos < size && pos > -1) {
		return Stack[Top - pos];
	}
	else {
		cout << "Invalid index given" << endl;
		return -1;
	}
}

void node::setData(int data) {
	this->data = data;
}

void node::isEmpty() {
	if (this == NULL) {
		cout << "Stack underflow" << endl;
	}
	else {
		cout << "Stack is not empty" << endl;
	}
}

void node::isFull() {
	if (this == NULL) {
		cout << "Stack is full" << endl;
	}
	else {
		cout << "Stack is not full" << endl;
	}
}

void node::display() {
	node* current = this;

	while (current) {
		cout << current->data << " " << endl;
		current = current->next;
	}

	cout << endl;

}

void node::push(node*& head, int data) {
	node* temp = new node;
	node* current = head;

	if (temp == NULL) {
		cout << "Stack overflow" << endl;
	}
	else {
		temp->data = data;
		temp->next = current;
		head = temp;
	}
}

void node::pop(node*& head) {
	node* current = head;
	node* temp = nullptr;

	if (head != NULL) {
		temp = current;
		current = current->next;
		delete temp;
		head = current;
	}
}

node* node::top() {
	return this;
}

int node::peek(int pos) {
	node* current = this;

	// conditional if..{} else{

	for (int i = 0; i < pos - 1 && current != NULL; i++) {
		current = current->next;
	}

	if (current != NULL)
		return current->data;
	else
		return -1;
}