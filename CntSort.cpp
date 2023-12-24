#include "header.h";

const int MY_MAX_VALUE = 65000 + 1;

void cnt_sort(int N, int* arr, bool comp(const int&, const int&)) { // comp is usefull
	int* mcnt = (int*)malloc(MY_MAX_VALUE * sizeof(int));
	for (int i = 0; i < MY_MAX_VALUE; i++) {
		mcnt[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		mcnt[arr[i]]++;
	}
	for (int i = 1; i < MY_MAX_VALUE; i++) {
		mcnt[i] += mcnt[i - 1];
	}
	int* mtemp = (int*)malloc(N * sizeof(int));
	for (int i = N - 1; i >= 0; i--) {
		mtemp[mcnt[arr[i]] - 1] = arr[i];
		mcnt[arr[i]]--;
	}
	for (int i = 0; i < N; i++) {
		arr[i] = mtemp[i];
	}

	free(mcnt);
	free(mtemp);
}