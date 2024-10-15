#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
	node* node1 = new node;
	node* node2 = new node;
	node* node3 = new node;

	node1->num = 1;
	node2->num = 2;
	node3->num = 3;

	node1->setNextNode(node2);
	node2->setNextNode(node3);

	node1->sortedInsert(0);

	node1->display();
	return 0;
}

