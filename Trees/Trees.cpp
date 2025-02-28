#include <iostream>
#include "Header.h"

int main()
{
	BinaryTree tree;

	tree.createBST();

	tree.insert(tree.getRootNode(), 1);

	tree.preOrderL(tree.getRootNode());

	return 0;
}