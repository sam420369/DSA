#ifndef _DOUBLYLL_H_
#define _DOUBLYLL_H_

#include <iostream>

using namespace std;

class node {
private:
	node* prev = nullptr;
	node* next = nullptr;
public:
	int data = NULL;

	void setNextNode(node* nextNode);

	void setPrevNode(node* prevNode);

	void setNextNodeNull();

	int length();

	void display();

	void insert(int data, int pos);

	void removeList(node*& head);

	void removeNode(node*& head, int pos);

	void reverseList(node*& head);

	void displayDoublyLL();

	void insertDoublyLL(node*& head, int data, int pos);

	void deleteDoublyLL(node*& head, int pos);
};

#endif