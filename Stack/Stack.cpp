#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    stack one;

    one.push(1);
    cout << one.top() << endl;
    one.push(2);
    cout << one.top() << endl;

    cout << one.peek(0) << endl;
    cout << one.peek(1) << endl; 
    one.pop();

    return 0;
}