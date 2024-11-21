#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
    string exp = "(a+b) * (b+c)";
    stack one;

    one.paranthesisMatching(exp);

    return 0;
}