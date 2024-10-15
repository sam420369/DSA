#include <iostream>
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

	temp->num = val;
	temp->next = nullptr;

	//yo mila
	/*if (val < current->num) {
		temp->next = current;
		*temp = *current;
		return;
	}*/

	node* prev = new node;

	while (current && current->num < val) {
		prev = current;
		current = current->next;
	}

	temp->next = prev->next;
	prev->next = temp;
}

node::~node() {
	node* current = this;
	node* temp;

	if (current == NULL) {
		return;
	}

	while (current) {
		temp = current->next;
		delete current;
		current = temp;
	}
}