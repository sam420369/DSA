#include <iostream>
#include "Header.h"
 
int main()
{
	BinaryTree tree;

	tree.create();

	int n = tree.totalNodes(tree.getRootNode());

	int h = tree.height(tree.getRootNode());

	std::cout << "Total nodes: " << n << std::endl;
	std::cout << "Height: " << h << std::endl;

	return 0;
}