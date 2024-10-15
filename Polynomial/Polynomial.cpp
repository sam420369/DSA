#include <iostream>
#include "polynomial.h"

using namespace std;

int main() {
	Polynomial poly1;
	Polynomial poly2;
	Polynomial total;

	poly1.create();
	poly2.create();

	total.add(poly1, poly2);
	total.display();
	return 0;
}
