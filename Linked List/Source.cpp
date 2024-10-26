#include <iostream>
#include <vector>
#include "linkedList.h"

using namespace std;

void node::setNextNode(node* x) {
	next = x;
}

node* node::getNextNode() {
	return next;
}

void node::display() {
	node* current = this;

	if (current == NULL) {
		cout << "Node is empty or not created.";
	}
	while (current != NULL) {
		cout << current->num << " ";
		current = current->getNextNode();
	}
	cout << "\n";


}

int node::length() {
	node* current = this;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->getNextNode();
	}
	return count;
}

int node::sum() {
	int sum = 0;

	node* current = this;

	while (current) {
		sum += current->num;
		current = current->getNextNode();
	}

	return sum;
}

int node::max() {
	node* current = this;
	int max = INT_MIN;

	while (current) {
		if (current->num > max) {
			max = current->num;
		}
		current = current->getNextNode();
	}

	return max;
}

int node::min() {
	node* current = this;
	int min = INT_MAX;

	while (current) {
		if (current->num < min) {
			min = current->num;
		}
		current = current->getNextNode();
	}

	return min;
}

node* node::search(int x) {
	node* current = this;

	if (current->num == x) {
		return current;
	}

	while (current != nullptr) {
		if (current->num == x) {
			return current;

		}
		current = current->next;
	}
	return NULL;
}

void node::insert(int val) {
	node* current = this;
	node* temp = new node;

	temp->num = current->num;
	temp->next = current->next;

	current->num = val;
	current->next = temp;
}

void node::insert(int val, int pos) {
	node* current = this;
	node* temp = new node;

	if (pos == 0) {
		temp->num = current->num;
		temp->next = current->next;

		current->num = val;
		current->next = temp;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			current = current->next;
		}

		temp->num = val;
		temp->next = current->next;

		current->next = temp;
	}
}

void node::sortedInsert(int val) {
	node* current = this;
	node* temp = new node;

	if (val < current->num) {
		temp->num = current->num;
		temp->next = current->next;
		current->num = val;
		current->next = temp;
		return;
	}

	node* prev = new node;

	while (current && current->num < val) {
		prev = current;
		current = current->next;
	}

	temp->num = val;
	temp->next = prev->next;
	prev->next = temp;
}

void node::removeNode() {
	node* current = this;
	node* temp;

	while (current) {
		temp = current;
		current = current->next;
		delete temp;
	}
}

void node::removeSpecificNode(int pos) {
	node* current = this;
	node* tail = new node;

	for (int i = 0; i < pos - 1 && pos < length(); i++) {
		tail = current;
		current = current->next;
	}

	tail->next = current->next;
	delete current;
}


void node::isSorted() {
	int len = length();
	node* current = this;
	int x = INT_MIN;

	for (int i = 0; i < len && current; i++) {
		if (x > current->num) {
			cout << "Not Sorted" << endl;
			return;
		}
		x = current->num;
		current = current->next;
	}

	cout << "Sorted" << endl;
}

void node::removeDuplicate() {
	node* tail = this;
	node* head = tail->next;

	while (head != NULL) {
		if (head->num != tail->num) {
			tail = head;
			head = head->next;
		}
		else {
			tail->next = head->next;
			delete head;
			head = tail->next;
		}
	}
}

void node::reverseLinkedListArr() {
	node* current = this;
	vector<int> A(current->length());

	int i = 0;

	while (current) {
		A.at(i++) = current->num;
		current = current->next;
	}

	current = this;
	i--;

	while (current) {
		current->num = A.at(i--);
		current = current->next;
	}
}

void node::reverseLinkedListSlidingPointers() {
	node* head = this;
	node* body = NULL;
	node* tail = NULL;

	while (head != NULL) {
		tail = body;
		body = head;
		head = head->next;

		body->next = tail;	
	}
	
	*this = *body;
}

void node::joinLinkedList(node *x) {
	node* current = this;
	node* appendage = x;

	while (current->next) {
		current = current->next;
	}

	current->next = appendage;
}