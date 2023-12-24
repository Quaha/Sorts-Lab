#include "header.h"

void __merge_sort(int N, int* arr, bool comp(const int&, const int&), int* buffer = nullptr) {
	if (N <= 1) {
		return;
	}
	__merge_sort(N / 2, arr, comp, buffer);
	__merge_sort(N - N / 2, arr + N / 2, comp, buffer);
	int p1 = 0;
	int p2 = N / 2;
	int id = 0;
	for (; p1 < N / 2 && p2 < N; id++) {
		if (comp(arr[p1], arr[p2])) {
			buffer[id] = arr[p1];
			p1++;
		}
		else {
			buffer[id] = arr[p2];
			p2++;
		}
	}
	for (p1, id; p1 < N / 2; p1++, id++) {
		buffer[id] = arr[p1];
	}
	for (p2, id; p2 < N; p2++, id++) {
		buffer[id] = arr[p2];
	}
	for (int i = 0; i < N; i++) {
		arr[i] = buffer[i];
	}
}

void merge_sort(int N, int* arr, bool comp(const int&, const int&)) {
	int* buffer = (int*)malloc(sizeof(int) * N);
	__merge_sort(N, arr, comp, buffer);
	free(buffer);
}