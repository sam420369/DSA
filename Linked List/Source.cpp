#include <iostream>
#include <vector>
#include <stack>
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

void node::joinLinkedList(node* x) {
	node* current = this;
	node* appendage = x;

	while (current->next) {
		current = current->next;
	}

	current->next = appendage;
	appendage = NULL;
}

void node::mergeSortedLinkedList(node* second) {
	node* first = this;
	node* head = NULL;
	node* connector = NULL;

	if (first->num < second->num) {
		head = connector = first;
		first = first->next;
		connector->next = NULL;
	}
	else {
		head = connector = second;
		second = second->next;
		connector->next = NULL;
	}

	while (first && second) {
		if (first->num < second->num) {
			connector->next = first;
			connector = first;
			first = first->next;
			connector->next = NULL;
		}
		else {
			connector->next = second;
			connector = second;
			second = second->next;
			connector->next = NULL;
		}
	}

	if (first) {
		connector->next = first;
	}
	else {
		connector->next = second;
	}
}

void node::isLoop() {
	node* current = this;
	node* jump = this->next->next;

	while (current != jump && jump) {
		current = current->next;
		jump = jump->next->next;

		if (jump == current) {
			cout << "There is loop" << endl;
			return;
		}
	}

	cout << "There is no loop" << endl;
}

void node::displayCircularLinkedList() {
	node* current = this;
	node* head = this;

	do {
		cout << current->num << " ";
		current = current->next;
	} while (current != head);

	cout << endl;
}

void node::insertInCircularLinkedList(int data, int pos) {
	node* current = this;
	node* temp = new node;

	temp->num = data;

	if (pos == 0) {
		temp->num = current->num;
		current->num = data;
		temp->next = current->next;
		current->next = temp;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			current = current->next;
		}

		temp->next = current->next;
		current->next = temp;
	}
}

void node::deleteNodeInCircularLinkedList(int pos) {
	node* HEAD = this;
	node* iterator = this;
	node* temp = NULL;

	if (pos == 0) {
		if (iterator == HEAD) {
			delete HEAD;
			HEAD = nullptr;
		}
		else {
			while (HEAD != iterator->next) {
				iterator = iterator->next;
			}

			iterator->next = HEAD->next;
			delete HEAD;
			HEAD = iterator->next;
		}
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			HEAD = HEAD->next;
		}

		temp = HEAD->next;
		HEAD->next = temp->next;
		delete temp;
	}
}

node* node::middleNode() {
	node* slider = this;
	node* skipper = this;

	while (skipper) {
		skipper = skipper->next;
		if (skipper) {
			skipper = skipper->next;
			slider = slider->next;
		}
	}
	cout << "The middle node has data: " << slider->num << endl;
	return slider;
}

node* node::intersectingNode(node*& one, node*& two) {
	node* primary = one;
	node* secondary = two;

	stack<node*> first;
	stack<node*> second;

	node* res = NULL;

	while (primary) {
		first.push(primary);
		primary = primary->next;
	}

	while (secondary) {
		second.push(secondary);
		secondary = secondary->next;
	}

	while (first.top() == second.top()) {
		res = first.top();
		first.pop();
		second.pop();
	}

	if (res) {
	cout << "The data at the intersecting node is: " << res->num << endl;
	}
	else {
		cout << "There is not intersecting node." << endl;
		return 0;
	}

	return res;
}