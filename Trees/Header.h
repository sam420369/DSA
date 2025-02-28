#ifndef _TREES_H_
#define _TREES_H_

#include <iostream>

class node {
private:
	node* left = nullptr;
	int data = NULL;
	node* right = nullptr;

public:
	void setData(int x);

	int getData();

	void setLeft(node* x);

	void setRight(node* x);

	node* getLeft();

	node* getRight();

	~node();
};

class BinaryTree {
private:
	node* root = nullptr;

public:
	node* getRootNode();

	void create();

	void createBST();

	void preOrder(node* root);

	void inOrder(node* root);

	void postOrder(node* root);

	void preOrderL(node* root);

	void inOrderL(node* root);

	//void postOrderL(node* root);

	void levelOrder(node* root);

	int totalNodes(node* n);

	int height(node* n);

	int leafNode(node* n);

	int totalDegreeTwoNodes(node* n);

	int totalDegreeTwoOrOneNodes(node* n);

	int search(node* root, int key);

	void insert(node* root, int data);
};

#endif