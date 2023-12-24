#include "header.h"
#include "BaseFunctions.h"

#include "benchmark.h";

#include "QuadraticSorts.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SepMergeSort.h"
#include "CntSort.h"

bool comp(const int &A, const int &B) {
	return A < B;
}

int main() {
    
	srand(time(0));

	char* FileName = nullptr;

	//char Bubble[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\bubble.txt";
	//FileName = Bubble;
	//benchmarking_by_size(bubble_sort, 1000, 50000, 1000, 5, FileName, comp);

	//char Insert[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\insert.txt";
	//FileName = Insert;
	//benchmarking_by_size(insert_sort, 1000, 75000, 1000, 5, FileName, comp);

	//char Choice[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\choice.txt";
	//FileName = Choice;
	//benchmarking_by_size(choice_sort, 1000, 75000, 1000, 5, FileName, comp);

	//char Merge[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\merge.txt";
	//FileName = Merge;
	//benchmarking_by_size(merge_sort, 1000, 200000, 1000, 10, FileName, comp);

	//char Quick[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\quick.txt";
	//FileName = Quick;
	//benchmarking_by_size(quick_sort, 1000, 200000, 1000, 10, FileName, comp);

	//char SepMergeS[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\sepmerge_s.txt";
	//FileName = SepMergeS;
	//benchmarking_by_size(stable_sep_merge_sort, 1000, 200000, 1000, 10, FileName, comp);

	//char SepMergeU[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\sepmerge_u.txt";
	//FileName = SepMergeU;
	//benchmarking_by_size(unstable_sep_merge_sort, 1000, 200000, 1000, 10, FileName, comp);

	//char Cnt[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\cnt.txt";
	//FileName = Cnt;
	//benchmarking_by_size(cnt_sort, 1000, 100000000, 10000, 5, FileName, comp);

	char Merge1[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\merge1.txt";
	FileName = Merge1;
	benchmarking_by_inv(merge_sort, 1000, 10000, 100, 100000, 5, FileName, comp);

	char Quick1[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\quick1.txt";
	FileName = Quick1;
	benchmarking_by_inv(quick_sort, 0, 10000, 100, 100000, 5, FileName, comp);

	char SepMergeS1[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\sepmerge_s1.txt";
	FileName = SepMergeS1;
	benchmarking_by_inv(stable_sep_merge_sort, 0, 10000, 100, 100000, 5, FileName, comp);

	char SepMergeU1[] = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\sepmerge_u1.txt";
	FileName = SepMergeU1;
	benchmarking_by_inv(unstable_sep_merge_sort, 0, 10000, 100, 100000, 5, FileName, comp);

	//int* arr = alloc_arr_1d(10);
	//fill_rand_arr_1d(10, arr);
	//stable_sep_merge_sort(10, arr, comp);
	//print_arr_1d(10, arr);

    return 0;
}

