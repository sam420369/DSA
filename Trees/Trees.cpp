#include <iostream>
#include "Header.h"

int main()
{
	BinaryTree tree;

	tree.getTree();

	tree.preOrderL(tree.getRootNode());

	return 0;
}