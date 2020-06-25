#include <string>
#include <iostream>
#include <stdlib.h>
#include "time.h"
using namespace std;

void binary_search(int arr[], int key, int first, int last) { 
	//bool found = false;

	//while (first <= last && !found) {
	//	int mid = (first + last) / 2;

	//	if (arr[mid] == key) {
	//		found = true;
	//	}
	//	else if (arr[mid] < key) {
	//		first = mid + 1;
	//	}
	//	else {
	//		last = mid - 1;
	//	}
	//}

	//return found;
	if (first > last) {
		return;
	}

	int mid = (first + last) / 2;
	if (key == arr[mid]) {
		return;
	}
	else if (key > arr[mid]) {
		binary_search(arr, key, mid + 1, last);
	}
	else {
		binary_search(arr, key, first, mid - 1);
	}
}

int main() {
	int arr_sizes[8] = { 128, 512, 2048, 8192, 32768, 131072, 524288, 2097152 };
	int start, stop;
	int *a;
	a = (int*)malloc(sizeof(int) * 2097152);
	int j;

	for (int i = 0; i < 8; i++) {
		for (j = 0; j < arr_sizes[i]; j++) {
			a[j] = j;
			start = clock();
			for (int k = 0; k < 20000; k++) {
				binary_search(a, j, 0, j - 1);

			}
		}
		stop = clock();
		cout << "time taken for size " << j << " is: " << (stop - start) / double(CLOCKS_PER_SEC)<< endl;
	}


	return 0;
	//system("pause");
}