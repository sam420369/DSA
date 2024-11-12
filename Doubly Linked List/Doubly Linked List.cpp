#include <iostream>
#include "doublyLL.h"

using namespace std;

int main()
{
	node* node1 = new node;
	node* node2 = new node;
	node* node3 = new node;
	node* node4 = new node;
	node* node5 = new node;

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5;

	node1->setPrevNode(node5);
	node1->setNextNode(node2);

	node2->setPrevNode(node1);
	node2->setNextNode(node3);

	node3->setPrevNode(node2);
	node3->setNextNode(node4);

	node4->setPrevNode(node3);
	node4->setNextNode(node5);

	node5->setPrevNode(node4);
	node5->setNextNode(node1);

	node1->displayDoublyLL();

	node1->deleteDoublyLL(node1, 0);

	node1->displayDoublyLL();

	return 0;
}