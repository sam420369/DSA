#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <iostream>
#include <vector>

using namespace std;

class Term {
public:
	int coeff;
	int exponent;
};

class Polynomial {
private:
	int totalTerms;
	vector<Term> t;

public:
	Polynomial();

	void setTotalTerms(int x);

	int getTotalTerms();

	void create();

	void display();

	void calculate();

	void add(Polynomial x, Polynomial y);
};

#endif