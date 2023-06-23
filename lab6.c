#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* values, int low, int high, int search) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		if (search < values[mid]) {
			return binarySearch(values, low, mid - 1, search);
		}
		else if (search > values[mid]) {
			return binarySearch(values, mid + 1, high, search);
		}
		else
			return 1;
	}
	return 0;
}
