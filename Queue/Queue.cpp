#include <iostream>
#include "Header.h"

int main()
{
	circularQueue que(5);

	que.enqueue(1);
	que.enqueue(2);
	que.enqueue(3);
	que.enqueue(4);

	que.display();

	return 0;
}
