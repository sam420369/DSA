#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
	node* node1 = new node;
	node* node2 = new node;
	node* node3 = new node;
	node* node4 = new node;
	node* appendage = new node;


	node1->num = 1;
	node2->num = 2;
	node3->num = 3;
	node4->num = 4;
	appendage->num = 100;

	node1->setNextNode(node2);
	node2->setNextNode(node3);
	node3->setNextNode(node4);

	node1->display();

	return 0;
}

