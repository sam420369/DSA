#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>

using namespace std;

class node {
private:
	node* next = nullptr;

public:
	int num = NULL;

	void setNextNode(node* x);

	node* getNextNode();

	void display();

	int length();

	int sum();

	int max();

	int min();

	node* search(int x);

	void insert(int val);

	void insert(int val, int pos);

	void sortedInsert(int val);

	void removeNode();

	void removeSpecificNode(int pos);

	void isSorted();

	void removeDuplicate();

	void reverseLinkedListArr();

	void reverseLinkedListSlidingPointers();

	void joinLinkedList(node *x);

	void mergeSortedLinkedList(node *second);

	void isLoop();

	void displayCircularLinkedList();

	void insertInCircularLinkedList(int data, int pos);

	void deleteNodeInCircularLinkedList(int pos);

	node* middleNode();

	node* intersectingNode(node*& one, node*& two);
};

#endif