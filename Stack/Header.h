#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <vector>

using namespace std;

class stack {
private:
	int size = 0;
	int Top = -1;
	int* Stack = nullptr;
	
public:
	stack();

	void isEmpty();

	void isFull();

	void push(int data);

	void pop();

	int top();

	int peek(int pos);

};

class node {
private:
	int data = NULL;
	node* next = nullptr;

public:
	void setData(int data);

	void isEmpty();

	void isFull();

	void display();

	void push(node*& head, int data);

	void pop(node*& head);

	node* top();

	int peek(int pos);
};

#endif

