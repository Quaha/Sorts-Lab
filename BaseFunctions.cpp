#include "header.h"

/* Base functions */

void mswap(int* a, int* b) {
	int c = *b;
	*b = *a;
	*a = c;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int get_rand_value(int N) {
	int V1 = rand();
	int V2 = rand();
	int res = V1 * V2;
	if (V1 % 2 == 0 && V2 % 2 == 0) {
		res += 7;
	}
	return (res % (N + 1));
}

/* Arrays: */

//1D arrays
int* alloc_arr_1d(int N) {
	int* arr = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
	}
	return arr;
}

void fill_rand_arr_1d(int N, int* arr, int max_el = RAND_MAX) {
	for (int i = 0; i < N; i++) {
		arr[i] = get_rand_value(max_el);
	}
}

int* get_copy_arr_1d(int N, int* arr) {
	int* copy = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		copy[i] = arr[i];
	}
	return copy;
}

void print_arr_1d(int N, int* arr) {
	for (int i = 0; i < N; i++) {
		printf_s("%i ", arr[i]);
	}
	printf_s("\n");
}

void free_arr_1d(int* arr) {
	free(arr);
}

//2D arrays

int** alloc_arr_2d(int N, int M) {
	int** arr = (int**)malloc(N * sizeof(int*));
	arr[0] = (int*)malloc(N * M * sizeof(int));
	for (int i = 1; i < N; i++) {
		arr[i] = arr[0] + M * i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = 0;
		}
	}
	return arr;
}

void fill_rand_arr_2d(int N, int M, int** arr, int max_el = RAND_MAX) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = get_rand_value(max_el);
		}
	}
}

void print_arr_2d(int N, int M, int** arr) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf_s("%i ", arr[i][j]);
		}
		printf_s("\n");
	}
}

void free_arr_2d(int** arr) {
	free(arr[0]);
	free(arr);
}