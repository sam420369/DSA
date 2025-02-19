#include <iostream>
#include <queue>
#include <stack>
#include "Header.h"

void node::setData(int x) {
	this->data = x;
}

int node::getData() {
	return this->data;
}

void node::setLeft(node* x) {
	this->left = x;
}

void node::setRight(node* x) {
	this->right = x;
}

node* node::getLeft() {
	if (this->left)
		return this->left;
	else
		return nullptr;
}

node* node::getRight() {
	if (this->right)
		return this->right;
	else
		return nullptr;
}

node::~node() {
	delete this->left;
	delete this->right;
}

node* BinaryTree::getRootNode() {
	return this->root;
}

void BinaryTree::create() {
	node* current = nullptr;
	node* temp = new node;
	std::queue<node*> storage;

	int data = 0;

	std::cout << "Data in root:" << std::endl;
	std::cin >> data;

	temp->setData(data);
	this->root = temp;
	storage.push(temp);

	do {
		current = storage.front();
		storage.pop();

		std::cout << "Data for left node:" << std::endl;
		std::cin >> data;

		if (data != -1) {
			temp = new node;
			temp->setData(data);
			current->setLeft(temp);
			storage.push(temp);
		}

		std::cout << "Data for right node:" << std::endl;
		std::cin >> data;

		if (data != -1) {
			temp = new node;
			temp->setData(data);
			current->setRight(temp);
			storage.push(temp);
		}
	} while (!storage.empty());

}

//using recursion
void BinaryTree::preOrder(node* root) {
	node* current = root;

	if (current) {
		std::cout << current->getData() << " ";
		preOrder(current->getLeft());
		preOrder(current->getRight());
	}
}

void BinaryTree::inOrder(node* root) {
	node* current = root;

	if (current) {
		inOrder(current->getLeft());
		std::cout << current->getData() << " ";
		inOrder(current->getRight());
	}
}

void BinaryTree::postOrder(node* root) {
	node* current = root;

	if (current) {
		postOrder(current->getLeft());
		postOrder(current->getRight());
		std::cout << current->getData() << " ";
	}
}

//using loop
void BinaryTree::preOrderL(node* root) {
	node* current = root;
	std::stack<node*> st;

	while (current || !st.empty()) {
		if (current) {
			std::cout << current->getData() << " ";
			st.push(current);
			current = current->getLeft();
		}
		else {
			current = st.top();
			st.pop();
			current = current->getRight();
		}
	}
}


void BinaryTree::inOrderL(node* root) {
	node* current = root;
	std::stack<node*> st;

	while (current || !st.empty()) {
		while (current) {
			st.push(current);
			current = current->getLeft();
		}
		current = st.top();
		st.pop();
		
		std::cout << current->getData() << " ";
		current = current->getRight();
	}

}

void BinaryTree::postOrderL(node* root) {
	node* current = root;
	std::stack<node*> st;
	node* temp = NULL;

	while (!st.empty()) {
		if (current) {
			st.push(current);
			current = current->getLeft();
		}
		else {
			temp = st.top();
			if (temp > 0) {

			}
		}
	}

}