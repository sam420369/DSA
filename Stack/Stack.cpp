#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    node* one = new node;

    one->setData(1);

    one->push(one, 10);
    one->push(one, 11);

    one->display();

    cout << one->peek(1) << endl;

    return 0;
}