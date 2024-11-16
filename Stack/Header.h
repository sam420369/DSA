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

#endif

