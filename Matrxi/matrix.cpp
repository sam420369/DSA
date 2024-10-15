#include "matrix.h"
#include <iostream>

using namespace std;

diagonalMatrix::diagonalMatrix(int n_val) : n(n_val) { A = new int[n]; }

int diagonalMatrix::get(int i, int j) {
	if (i == j /*i.e it is an element of the diagonal of a diagonal matrix */) {
		return A[i];
	}
	return 0;
}

void diagonalMatrix::set(int i, int j, int x) {
	if (i == j) {
		A[i] = x;
	}
}

void diagonalMatrix::display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				cout << A[i] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

diagonalMatrix::~diagonalMatrix() { delete[] A; }

// lower triangular
// for row major do column major other time
lowerTriangularMatrix::lowerTriangularMatrix(int n_val) : n(n_val) {
	int size = n * (n + 1) / 2;
	A = new int[size];
}

int lowerTriangularMatrix::get(int i, int j) {
	if (i >= j) {
		int index{};
		// this works for matrices if you consider like 5*5 matrix to start like
		// from 0 to 4;
		index = (i * (i + 1) / 2) + j;
		return A[index];
	}
	return 0;
}

void lowerTriangularMatrix::set(int i, int j, int x) {
	if (i >= j) {
		int index{};
		index = (i * (i + 1) / 2) + j;
		A[index] = x;
	}
}

void lowerTriangularMatrix::display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= j)
				cout << A[(i * (i + 1) / 2) + j] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

lowerTriangularMatrix::~lowerTriangularMatrix() { delete[] A; }

// upper triangular
// for column major do row major other time
upperTriangularMatrix::upperTriangularMatrix(int n_val) : n(n_val) {
	int size = n * (n + 1) / 2;
	A = new int[size];
}

int upperTriangularMatrix::get(int i, int j) {
	if (i <= j) {
		int index{};
		// this works for matrices if you consider like 5*5 matrix to start like
		// from 0 to 4;
		index = (j * (j + 1) / 2) + i;
		return A[index];
	}
	return 0;
}

void upperTriangularMatrix::set(int i, int j, int x) {
	if (j >= i) {
		int index{};
		index = (j * (j + 1) / 2) + i;
		A[index] = x;
	}
}

void upperTriangularMatrix::display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j >= i)
				cout << A[(j * (j + 1) / 2) + i] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

upperTriangularMatrix::~upperTriangularMatrix() { delete[] A; }

// symmetric matrix
// for row major do column major other time
symmetricMatrix::symmetricMatrix(int n_val) : n(n_val) {
	int size = n * (n + 1) / 2;
	A = new int[size];
}

int symmetricMatrix::get(int i, int j) {
	if (i == j || i > j) {
		return A[(i * (i + 1) / 2) + j];
	}
	else if (i < j) {
		return A[(j * (j + 1) / 2) + i];
	}
	return 999;
}

void symmetricMatrix::set(int i, int j, int x) {
	int index{};
	if (i >= j) {
		index = (i * (i + 1) / 2) + j;
		A[index] = x;
	}
	else if (i < j) {
		index = (j * (j + 1) / 2) + i;
		A[index] = x;
	}
}

void symmetricMatrix::display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= j)
				cout << A[(i * (i + 1) / 2) + j] << " ";
			else
				cout << A[(j * (j + 1) / 2) + i] << " ";
		}
		cout << "\n";
	}
}

symmetricMatrix::~symmetricMatrix() { delete[] A; }

// triDiagonal matrix
triDiagonalMatrix::triDiagonalMatrix(int n_val) : n(n_val) {
	int size = 3 * n - 2;
	A = new int[size];
}

int triDiagonalMatrix::get(int i, int j) {
	if (i == j) {
		return A[3 * i];
	}
	else if (i < j) {
		return A[3 * i + 1];
	}
	else if (i > j) {
		return A[3 * i - 1];
	}
	return 999999;
}

void triDiagonalMatrix::set(int i, int j, int x) {
	int index{};
	if (i == j) {
		index = 3 * i;
		A[index] = x;
	}
	else if (i < j) {
		index = 3 * i + 1;
		A[index] = x;
	}
	else if (i > j) {
		index = 3 * i - 1;
		A[index] = x;
	}
}

void triDiagonalMatrix::display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				cout << A[3 * i] << " ";
			else if (i - j == -1)
				cout << A[3 * i + 1] << " ";
			else if (i - j == 1)
				cout << A[3 * i - 1] << " ";
			else
				cout << 0 << " ";
		}
		cout << "\n";
	}
}

triDiagonalMatrix::~triDiagonalMatrix() { delete[] A; }

// toeplitz matrix
toeplitzMatrix::toeplitzMatrix(int n_val) : n(n_val) {
	int size = 2 * n - 1;
	A = new int[size];
}

int toeplitzMatrix::get(int i, int j) {
	if (i <= j) {
		return A[j - i];
	}
	else if (i > j) {
		return A[n + i - j - 1];
	}
	return 999999;
}

void toeplitzMatrix::set(int i, int j, int x) {
	int index{};
	if (i <= j) {
		index = j - i;
		A[index] = x;
	}
	else if (i > j) {
		index = n + i - j - 1;
		A[index] = x;
	}
}

void toeplitzMatrix::display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i <= j)
				cout << A[j - i] << " ";
			else if (i > j)
				cout << A[n + i - j - 1] << " ";
			else
				cout << 0 << " ";
		}
		cout << "\n";
	}
}

toeplitzMatrix::~toeplitzMatrix() { delete[] A; }

void element::setI(int x) {
	i = x;
}

void element::setJ(int x) {
	j = x;
}

void element::setElem(int x) {
	elem = x;
}

int element::getI() {
	return i;
}

int element::getJ() {
	return j;
}

int element::getElem() {
	return elem;
}

sparseMatrix::sparseMatrix() : i(0), j(0), totalElem(0) {}

sparseMatrix::sparseMatrix(int i_val, int j_val, int totalElem_val) : i(i_val), j(j_val), totalElem(totalElem_val) {
	A.resize(totalElem);
}

void sparseMatrix::setI(int x) {
	i = x;
}

void sparseMatrix::setJ(int x) {
	j = x;
}

void sparseMatrix::setTotalElement(size_t x) {
	totalElem = x;
}

void sparseMatrix::create() {
	int z = 0;
	int currentElement = 0;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			cout << "Enter the element " << x << ", " << y << endl;
			cin >> currentElement;

			if (currentElement != 0) {
				A[z].setI(x);
				A[z].setJ(y);
				A[z].setElem(currentElement);
				z++;
			}
		}
	}
}

size_t sparseMatrix::getTotalElement() {
	return totalElem;
}

int sparseMatrix::getI() {
	return i;
}

int sparseMatrix::getJ() {
	return j;
}

int sparseMatrix::get(int x, int y) {
	for (int a = 0; a < getTotalElement(); a++) {
		if (A.at(a).getI() == x && A.at(a).getJ() == y) {
			return A.at(a).getElem();
		}
	}

	return 0;
}

void sparseMatrix::display() {
	int z = 0;

	for (int i = 0; i < getI(); i++) {
		for (int j = 0; j < getJ(); j++) {
			if (z < getTotalElement() && A.at(z).getI() == i && A.at(z).getJ() == j) {
				cout << A.at(z).getElem() << " ";
				z++;
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << "" << endl;
	}
}

void sparseMatrix::add(sparseMatrix x, sparseMatrix y) {
	// add garda dimension same bhasi x y jun liye ni bha total element last ma set garni (Kati hunxa tha nai xaina)
	setI(x.getI());
	setJ(x.getJ());

	A.resize(x.getTotalElement() + y.getTotalElement());

	int i = 0;
	int j = 0;
	int k = 0;

	while (i < x.getTotalElement() && j < y.getTotalElement()) {
		if (i < x.getTotalElement() && x.A.at(i).getI() < y.A.at(j).getI()) {
			A.at(k++) = x.A.at(i++);

		}
		else if (i < x.getTotalElement() && (x.A.at(i).getI() == y.A.at(j).getI() && x.A.at(i).getJ() < y.A.at(j).getJ())) {
			A.at(k++) = x.A.at(i++);
		}
		else if (j < y.getTotalElement() && x.A.at(i).getI() > y.A.at(j).getI()) {
			A.at(k++) = y.A.at(j++);
		}
		else if (j < y.getTotalElement() && x.A.at(i).getI() == y.A.at(j).getI() && x.A.at(i).getJ() > y.A.at(j).getJ()) {
			A.at(k++) = y.A.at(j++);
		}
		else if ((i < x.getTotalElement() && j < y.getTotalElement()) && x.A.at(i).getI() == y.A.at(j).getI() && x.A.at(i).getJ() == y.A.at(j).getJ()) {
			A.at(k).setElem(x.A.at(i).getElem() + y.A.at(j).getElem());
			A.at(k).setI(x.A.at(i).getI());
			A.at(k).setJ(x.A.at(i).getJ());
			i++;
			j++;
			k++;

		}
	}

	while (i < x.getTotalElement()) {
		A.at(k) = x.A.at(i);
		i++;
		k++;
	}

	while (j < y.getTotalElement()) {
		A.at(k) = y.A.at(j);
		j++;
		k++;
	}

	setTotalElement(A.size());
}