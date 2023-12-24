#pragma once

void benchmarking_by_size(void sort(int, int*, bool(const int&, const int&)), int start_value, int end_value, int step, int times, char* FileName, bool comp(const int&, const int&));
void benchmarking_by_inv(void sort(int, int*, bool(const int&, const int&)), int start_inv, int end_inv, int step, int size, int times, char* FileName, bool comp(const int&, const int&));