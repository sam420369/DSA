#include <iostream>
#include "Header.h"
#include <vector>

int main()
{
	size_t size = 10;
	std::vector<int> input = { 23, 12, 3,19, 38, 394, 189, 21, 239, 59 };

	std::vector<int> output = insertionSort(input, size);

	for (auto x : output) {
		std::cout << x << std::endl;
	}

	return 0;
}