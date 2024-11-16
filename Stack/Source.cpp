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
		return Stack[pos];
	}
	else {
		cout << "Invalid index given" << endl;
		return -1;
	}
}