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
	int temp = 0;
	size_t j = 0;

	for (size_t i = 1; i < size; i++) {
		temp = input.at(i);
		j = i - 1;
		while (j > -1 && input.at(j) > temp) {
			input.at(j + 1) = input.at(j);
			j--;
		}
		input.at(j + 1) = temp;

	}
	return input;
}

std::vector<int> selectionSort(std::vector<int> input, size_t size) {

	return input;
}
#endif // !_SORTING_TECHNIQUES_