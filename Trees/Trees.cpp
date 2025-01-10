#include <iostream>
#include "Header.h"
 
int main()
{
	BinaryTree tree;

	tree.create();

	tree.preOrderL(tree.getRootNode());

	return 0;
}