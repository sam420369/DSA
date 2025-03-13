#ifndef _SORTING_TECHNIQUES_
#define _SORTING_TECHNIQUES_

#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> input, size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (input.at(i) > input.at(j)) {
				int temp = input.at(i);
				input.at(i) = input.at(j);
				input.at(j) = temp;
			}
		}
	}
	return input;
}

std::vector<int> insertionSort(std::vector<int> input, size_t size) {

	return input;
}
#endif // !_SORTING_TECHNIQUES_
