#include "header.h"
#include "BaseFunctions.h"
#include "MergeSort.h"

void benchmarking_by_size(void sort(int, int*, bool(const int&, const int&)), int start_value, int end_value, int step, int times, char* FileName, bool comp(const int&, const int&)) {
	FILE* FileObj;
	fopen_s(&FileObj, FileName, "w");
	for (int N = start_value; N <= end_value; N += step) {
		printf_s("%i / %i\n", N, end_value);
		char point[100];
		double res = 0;
		for (int test_case = 0; test_case < times; test_case++) {
			int* arr = alloc_arr_1d(N);
			fill_rand_arr_1d(N, arr);
			double tm = clock();
			sort(N, arr, comp);
			res += (double)(clock() - tm);
			free_arr_1d(arr);
		}
		sprintf_s(point, 100, "%i %f\n", N, res / (double)times);
		fputs(point, FileObj);
	}
}

void benchmarking_by_inv(void sort(int, int*, bool(const int&, const int&)), int start_inv, int end_inv, int step, int size, int times, char* FileName, bool comp(const int&, const int&)) {
	FILE* FileObj;
	fopen_s(&FileObj, FileName, "w");
	for (int i = start_inv; i <= end_inv; i += step) {
		printf_s("%i / %i\n", i, end_inv);
		char point[100];
		double res = 0;
		for (int test_case = 0; test_case < times; test_case++) {
			int* arr = alloc_arr_1d(size);
			fill_rand_arr_1d(size, arr);
			merge_sort(size, arr, comp);
			for (int j = 0; j < i; j++) {
				int id1 = (rand() * rand()) % size;
				int id2 = (rand() * rand()) % size;
				mswap(&arr[id1], &arr[id2]);
			}
			double tm = clock();
			sort(size, arr, comp);
			res += (double)(clock() - tm);
			free_arr_1d(arr);
		}
		sprintf_s(point, 100, "%i %f\n", i, res / (double)times);
		fputs(point, FileObj);
	}
}