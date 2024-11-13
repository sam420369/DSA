#include <iostream>
#include "doublyLL.h"

using namespace std;

void node::setNextNode(node* nextNode) {
	this->next = nextNode;
}

void node::setPrevNode(node* prevNode) {
	this->prev = prevNode;
}

void node::setNextNodeNull() {
	this->next = NULL;
}

int node::length() {
	node* current = this;
	int length = 0;

	while (current) {
		current = current->next;
		length++;
	}

	return length;
}

void node::display() {
	node* current = this;

	if (!current) {
		cout << "The list is empty." << endl;
		return;
	}


	while (current) {
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;

}

void node::insert(int data, int pos) {
	node* current = this;
	node* temp = new node;

	if (pos == 0) {
		temp->data = current->data;
		temp->next = current->next;
		temp->prev = current;
		current->next = temp;
		current->data = data;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			current = current->next;
		}

		temp->data = data;
		temp->next = current->next;
		temp->prev = current;
		current->next = temp;
		if (temp->next) {
			current = temp->next;
			current->prev = temp;
		}
	}
}

void node::removeList(node*& head) {
	node* current = head;
	node* temp = nullptr;

	while (current) {
		temp = current;
		current = current->next;
		delete temp;
	}

	head = nullptr;
}

void node::removeNode(node*& head, int pos) {
	node* current = head;
	node* temp = new node;

	if (pos == 0) {
		temp = current->next;
		delete current;
		current = temp;
		current->next = temp->next;
		current->prev = NULL;
		head = current;
	}
	else {
		if (pos < length()) {
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}

			temp = current->next;
			current->next->prev = current;
			current->next = current->next->next;
			delete temp;
		}
		else {
			cout << "Out of bounds" << endl;
		}
	}
}

void node::reverseList(node*& head) {
	node* current = head;
	node* temp = NULL;

	while (current) {
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = current->prev;

		if (current != NULL && current->next == NULL) {
			head = current;
		}
	}
}

void node::displayDoublyLL() {
	node* head = this;
	node* current = this;

	do {
		cout << current->data << " ";
		current = current->next;
	} while (current != head);

	cout << endl;
}

void node::insertDoublyLL(node*& head, int data, int pos) {
	node* current = head;
	node* temp = new node;

	if (pos == 0) {
		// this is considered bad practice because i am changing the address of the previous head node instead of creating a new address for the new data (this was because the latter didnot work :|)
		temp->prev = current;
		temp->next = current->next;
		temp->data = current->data;
		current->data = data;
		current->next = temp;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			current = current->next;
		}
		temp->prev = current;
		temp->next = current->next;
		current->next = temp;	
	}
}

void node::deleteDoublyLL(node*& head, int pos) {
	node* current = head;
	node* temp = NULL;

	if (pos == 0) {
		temp = current;
		current = current->next;
		current->prev = temp->prev;
		temp->prev->next = current;
		delete temp;
		head = current;
	}
	else {
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}

		temp = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete temp;
	}
}