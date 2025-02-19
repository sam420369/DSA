#include <iostream>
#include "Header.h"
 
int main()
{
	BinaryTree tree;

	tree.create();

	tree.inOrderL(tree.getRootNode());

	return 0;
}