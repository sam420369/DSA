// learn about post Order traversal or you a failure

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

//void BinaryTree::postOrderL(node* root) {
//	node* current = root;
//	std::stack<node*> st;
//	node* temp = NULL;
//
//	while (!st.empty() || current) {
//		
//	}
//
//}

void BinaryTree::levelOrder(node* root) {
	std::queue<node*> q;
	node* current = NULL;
	if (!root) {
		std::cerr << "Tree is empty." << std::endl;
		return;
	}

	q.push(root);

	while (!q.empty()) {
		current = q.front();
		q.pop();

		std::cout << current->getData() << " ";

		if (current->getLeft()) {
			q.push(current->getLeft());
		}

		if (current->getRight()) {
			q.push(current->getRight());
		}
	}
}

int BinaryTree::totalNodes(node* n) {
	int x, y;

	if (n != NULL) {
		x = totalNodes(n->getLeft());
		y = totalNodes(n->getRight());

		return x + y + 1;
	}
	return 0;
}

int BinaryTree::height(node* n) {
	int x, y;

	if (n != NULL) {
		x = height(n->getLeft());
		y = height(n->getRight());

		if (x > y)
			return x + 1;
		else
			return y + 1;
	}
	return 0;
}

int BinaryTree::leafNode(node* n) {
	int x, y;

	if (n != NULL) {
		x = leafNode(n->getLeft());
		y = leafNode(n->getRight());

		if (n->getLeft() == NULL && n->getRight() == NULL)
			return x + y + 1;
		else
			return x + y;
	}

	return 0;

} 

int BinaryTree::totalDegreeTwoNodes(node* n) {
	int x, y;

	if (n != NULL) {
		x = totalDegreeTwoNodes(n->getLeft());
		y = totalDegreeTwoNodes(n->getRight());

		if (n->getLeft() && n->getRight())
			return x + y + 1;
		else
			return x + y;
	}

	return 0;
}

int BinaryTree::totalDegreeTwoOrOneNodes(node* n) {
	int x, y;

	if (n != NULL) {
		x = totalDegreeTwoOrOneNodes(n->getLeft());
		y = totalDegreeTwoOrOneNodes(n->getRight());

		if (n->getLeft() || n->getRight())
			return x + y + 1;
		else
			return x + y;
	}

	return 0;
}