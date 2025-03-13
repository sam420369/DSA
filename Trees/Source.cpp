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

void BinaryTree::createBST() {
	node* temp = NULL;
	node* current = NULL;
	int data = 0;
	std::queue<node*> storage;

	std::cout << "Enter data in root node:" << std::endl;
	std::cin >> data;

	if (data == -1) {
		std::cout << "Tree is not created" << std::endl;
		return;
	}

	temp = new node;
	temp->setData(data);

	this->root = temp;
	storage.push(temp);

	do
	{
		current = storage.front();
		storage.pop();

		do {
			std::cout << "Data in left node: " << std::endl;
			std::cin >> data;
		} while (data > current->getData());

		if (data != -1) {
			temp = new node;
			temp->setData(data);
			current->setLeft(temp);
			storage.push(temp);
		}

		do {
			std::cout << "Data in right node: " << std::endl;
			std::cin >> data;
		} while (data < current->getData() && data != -1);

		if (data != -1)
		{
			temp = new node;
			temp->setData(data);
			current->setRight(temp);
			storage.push(temp);
		}
	} while (!storage.empty());
}

int BinaryTree::search(node* root, int key) {
	int x;

	if (root == NULL)
		return 0;
	else if (key < root->getData())
		x = search(root->getLeft(), key);
	else if (key > root->getData())
		x = search(root->getRight(), key);
	else
		return 1;

	return x;
}

void BinaryTree::insert(int data) {
	node* current = this->getRootNode();
	node* tail = NULL;

	while (current) {
		tail = current;
		if (data == current->getData())
			return;
		else if (data < current->getData())
			current = current->getLeft();
		else
			current = current->getRight();
	}

	node* temp = new node;
	temp->setData(data);
	if (data < tail->getData())
		tail->setLeft(temp);
	else
		tail->setRight(temp);
}

node* BinaryTree::recursiveInsert(node* root, int data) {
	if (root == NULL) {
		node* temp = new node;
		temp->setData(data);
		root = temp;
	}
	else if (data < root->getData()) {
		root->setLeft(recursiveInsert(root->getLeft(), data));
	}
	else if (data > root->getData()) {
		root->setRight(recursiveInsert(root->getRight(), data));
	}
	else {
		std::cout << "Data cannot be duplicated." << std::endl;
	}
	return root;
}

node* BinaryTree::inorderPredecessor(node* root) {
	while (root && root->getRight() != NULL)
		root = root->getRight();
	return root;
}

node* BinaryTree::inorderSuccessor(node* root) {
	while (root && root->getLeft() != NULL)
		root = root->getLeft();
	return root;
}

node* BinaryTree::removeNode(node* root, int data) {
	if (root == NULL)
		return NULL;

	if (root->getLeft() == NULL && root->getRight() == NULL) {
		if (root == this->getRootNode())
			this->root = NULL;
		delete root;
		return NULL;
	}

	if (data < root->getData())
		root->setLeft(removeNode(root->getLeft(), data));
	else if (data > root->getData())
		root->setRight(removeNode(root->getRight(), data));
	else {
		if (height(root->getLeft()) > height(root->getRight())) {
			node* temp = inorderPredecessor(root->getLeft());
			root->setData(temp->getData());
			root->setLeft(removeNode(root->getLeft(), temp->getData()));
		}
		else {
			node* temp = inorderSuccessor(root->getRight());
			root->setData(temp->getData());
			root->setRight(removeNode(root->getRight(), temp->getData()));
		}
	}
	return root;
}

void BinaryTree::getTree() {
	node* root = new node;
	node* current = NULL;
	node* temp = NULL;
	std::stack<node*> st;

	std::vector<int> vec1;
	size_t size = 0;

	std::cout << "Enter the size of traversal:" << std::endl;
	std::cin >> size;

	std::cout << "Enter the traversal: " << std::endl;
	for (int i = 0; i < size; i++) {
		int temp = 0;
		std::cin >> temp;
		vec1.push_back(temp);
	}

	root->setData(vec1.at(0));
	st.push(root);
	this->root = root;

	int i = 1;

	while (i < size) {
		current = new node;
		current->setData(vec1.at(i));
		if (vec1.at(i) < root->getData()) {
			root->setLeft(current);
			root = current;
			st.push(current);
			i++;
		}
		else if (vec1.at(i) > root->getData()) {
			st.pop();
			if (!st.empty() && vec1.at(i) < st.top()->getData()) {
				root->setRight(current);
				st.push(current);
				root = current;
				i++;
			}
			else {
				if (!st.empty()) {
					root = st.top();
					st.pop();
				}
				root->setRight(current);
				st.push(current);
				root = current;
				i++;
			}
		}
	}

}