#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	stack one;
	bool res = NULL;
	
	res = one.paranthesisMatching();

	if (res)
		cout << "Match" << endl;
	else
		cout << "No Match" << endl;

	cout << one.totalElements() << endl;

	return 0;
}