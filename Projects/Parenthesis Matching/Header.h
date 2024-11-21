#ifndef _PARANTHESIS_MATCHING_
#define _PARANTHESIS_MATCHING_

class stack {
private:
	int size = 0;
	char* Stack = nullptr;
	int Top = -1;
public:
	stack();

	bool isEmpty();

	void push(char x);

	void pop();

	int totalElements();

	char top();

	bool paranthesisMatching();

	~stack();

};

#endif // !_PARANTHESIS_MATCHING_
