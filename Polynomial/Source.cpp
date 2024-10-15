#include <iostream>
#include "polynomial.h"

using namespace std;

Polynomial::Polynomial() {
	totalTerms = 0;
}

void Polynomial::setTotalTerms(int x) {
	totalTerms = x;
}

int Polynomial::getTotalTerms() {
	return totalTerms;
}

void Polynomial::create() {
	int totalTerm = 0;

	cout << "Enter the total number of terms: " << endl;
	cin >> totalTerm;

	setTotalTerms(totalTerm);

	t.resize(getTotalTerms());

	for (int i = 0; i < totalTerm; i++) {
		cout << "Enter the " << i + 1 << " terms' coefficient and exponent: " << endl;
		cin >> t[i].coeff >> t[i].exponent;
	}
}

void Polynomial::display() {
	cout << "Your polynomial equation is: " << endl;

	for (int i = 0; i < getTotalTerms(); i++) {
		cout << t[i].coeff << "X^" << t[i].exponent;
		(i == getTotalTerms() - 1) ? cout : cout << " + ";
	}

	cout << endl;
}

void Polynomial::calculate() {
	int x_val = 0;
	double sum = 0;
	cout << "Enter for which value of 'X' do you want to evaluate the polynomial to: " << endl;
	cin >> x_val;

	for (int i = 0; i < getTotalTerms(); i++) {
		sum += t[i].coeff * pow(x_val,t[i].exponent);
	}

	cout << "The polynomial is evaluated to: " << sum << endl;
}

void Polynomial::add(Polynomial x, Polynomial y) {
	int i = 0, j = 0, z = 0;

	t.resize(x.totalTerms + y.totalTerms);

	while (i < x.totalTerms && j < y.totalTerms) {
		if (x.t[i].exponent == y.t[j].exponent) {
			t[z].coeff = x.t[i].coeff + y.t[j].coeff;
			t[z].exponent = x.t[i].exponent;
			i++;
			j++;
			z++;
		}
		else if (x.t[i].exponent < y.t[j].exponent) {
			t[z++] = y.t[j++];
		}
		else {
			t[z++] = x.t[i++];
		}
	}

	while (i < x.totalTerms) {
		t[z++] = x.t[i++];
	}

	while (j < y.totalTerms) {
		t[z++] = y.t[j++];
	}

	setTotalTerms(t.size());
	t.resize(t.size());
}