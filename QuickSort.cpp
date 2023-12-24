#include "BaseFunctions.h"

void quick_sort(int N, int* arr, bool comp(const int&, const int&)) {
	while (N > 1) {
		int p = N / 2;
		mswap(&arr[p], &arr[N - 1]);
		int i = 0;
		int j = N - 2;
		while (i <= j) {
			while (comp(arr[i], arr[N - 1])) {
				i++;
			}
			while (!comp(arr[j], arr[N - 1])) {
				j--;
			}
			if (i > j) {
				break;
			}
			mswap(&arr[i], &arr[j]);
		}
		mswap(&arr[i], &arr[N - 1]);
		if (i < N - i - 1) {
			quick_sort(i, arr, comp);
			arr = arr + i + 1;
			N = N - i - 1;
		}
		else {
			quick_sort(N - i - 1, arr + i + 1, comp);
			N = i;
		}
	}
}