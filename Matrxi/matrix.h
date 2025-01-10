#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>

using namespace std;

class diagonalMatrix {
private:
	// A is a 1D matrix to store the data of the diagonal of n*n matrix
	int* A;
	int n;

public:
	diagonalMatrix(int n_val);

	int get(int i, int j);

	void set(int i, int j, int x);

	void display();

	~diagonalMatrix();
};

class lowerTriangularMatrix {
private:
	// A is a 1D matrix to store the data of the diagonal of n*n matrix
	int* A;
	int n;

public:
	lowerTriangularMatrix(int n_val);

	int get(int i, int j);

	void set(int i, int j, int x);

	void display();

	~lowerTriangularMatrix();
};

class upperTriangularMatrix {
private:
	// A is a 1D matrix to store the data of the diagonal of n*n matrix
	int* A;
	int n;

public:
	upperTriangularMatrix(int n_val);

	int get(int i, int j);

	void set(int i, int j, int x);

	void display();

	~upperTriangularMatrix();
};

class symmetricMatrix {
private:
	// A is a 1D matrix to store the data of the diagonal of n*n matrix
	int* A;
	int n;

public:
	symmetricMatrix(int n_val);

	int get(int i, int j);

	void set(int i, int j, int x);

	void display();

	~symmetricMatrix();
};

class triDiagonalMatrix {
private:
	// A is a 1D matrix to store the data of the diagonal of n*n matrix
	int* A;
	int n;

public:
	triDiagonalMatrix(int n_val);

	int get(int i, int j);

	void set(int i, int j, int x);

	void display();

	~triDiagonalMatrix();
};

class toeplitzMatrix {
private:
	// A is a 1D matrix to store the data of the diagonal of n*n matrix
	int* A;
	int n;

public:
	toeplitzMatrix(int n_val);

	int get(int i, int j);

	void set(int i, int j, int x);

	void display();

	~toeplitzMatrix();
};


class element {
private:
	int i;
	int j;
	int elem;

public:
	void setI(int x);

	void setJ(int x);

	void setElem(int x);

	int getI();

	int getJ();

	int getElem();
};

class sparseMatrix {
private:
	// i, j = matrix dimensions
	int i;
	int j;
	size_t totalElem;
	vector<element> A;

public:
	sparseMatrix();
	sparseMatrix(int i_val, int j_val, int totalElem_val);

	int getI();

	int getJ();

	size_t getTotalElement();

	void setI(int x);

	void setJ(int x);

	void setTotalElement(size_t x);

	void create();

	int get(int i, int j);

	void display();

	void add(sparseMatrix x, sparseMatrix y);

	//~sparseMatrix();
};

class node {
private:
	int column;
	int num;
	node* next = NULL;
public:
	void create();

	void display();
};

#endif

