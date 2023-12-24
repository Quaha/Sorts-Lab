#include "BaseFunctions.h";

void bubble_sort(int N, int* arr, bool comp(const int&, const int&)) {
	for (int i = 0; i < N; i++) {
		bool isSorted = true;
		for (int j = 0; j < N - 1 - i; j++) {
			if (comp(arr[j + 1], arr[j])) {
				mswap(&arr[j], &arr[j + 1]);
				isSorted = false;
			}
		}
		if (isSorted) break;
	}
}

void insert_sort(int N, int* arr, bool comp(const int&, const int&)) {
	for (int i = 1; i < N; i++) {
		int pos = i;
		for (int j = i - 1; j >= 0; j--) {
			if (comp(arr[i], arr[j])) {
				pos = j;
			}
			else {
				break;
			}
		}
		int V = arr[pos];
		arr[pos] = arr[i];
		for (int j = pos + 1; j <= i; j++) {
			int temp = arr[j];
			arr[j] = V;
			V = temp;
		}
	}
}

void choice_sort(int N, int* arr, bool comp(const int&, const int&)) {
	for (int i = 0; i < N; i++) {
		int minInd = i;
		for (int j = i + 1; j < N; j++) {
			if (comp(arr[j], arr[minInd])) {
				minInd = j;
			}
		}
		mswap(&arr[minInd], &arr[i]);
	}
}