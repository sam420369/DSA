#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

// ignoring most if not all edge cases or scenarios 

stack::stack() {
	cout << "Enter the size of the stack:" << endl;
	cin >> size;

	Stack = new char[size];
}

bool stack::isEmpty() {
	if (Top == -1) {
		return true;
	}
	else {
		return false;
	}
}

void stack::push(char x) {
	Stack[Top + 1] = x;
	Top++;
}

void stack::pop() {
	Stack[Top--] = NULL;
}

int stack::totalElements() {
	return Top + 1;
}

char stack::top() {
	return Stack[Top];
}

bool stack::paranthesisMatching() {
	string str = "[{(a+b) * (c+d)} + d]";


	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			this->push(str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (this->isEmpty()) {
				return false;
			}
			this->pop();
		}
	}

	return true;
}

stack::~stack() {
	delete Stack;
}