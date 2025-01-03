#include <iostream>

// for n nodes the total different binary trees that can be formed is given as:
// t(n) = C(2n, n)/(n + 1) for unlabelled tree
// t(n) = C(2n, n) * n!/(n + 1) for labelled tree
// t(n) is called catalan number

// for h height of a binary tree, we get nodes(n) as
// minimum nodes = h+1
// maximum nodes = 2^(h+1) - 1

// for n node of a binary tree, we get height(h) as
// maximum height = n-1
// minimum height = log(n+1) - 1

// in binary tree, 
// deg(2) is external/non-leaf node
// deg(0) is internal/leaf node
// deg(0) = deg(2) + 1

// in strict binary tree
// when height is given
// minimum node = 2h + 1
// maximum node = 2^(h + 1) - 1

// when nodes is given
// maximum height = (n - 1)/2
// minimum height = log(n + 1) - 1

// in strict binary tree
// deg(0) = deg(2) + 1
 
int main()
{

	return 0;
}