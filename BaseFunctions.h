#pragma once

#include <random>

void mswap(int* a, int* b);
int min(int a, int b);
int max(int a, int b);
int get_rand_value(int N);

int* alloc_arr_1d(int N);
void fill_rand_arr_1d(int N, int* arr, int max_el = RAND_MAX);
int* get_copy_arr_1d(int N, int* arr);
void print_arr_1d(int N, int* arr);
void free_arr_1d(int* arr);

int** alloc_arr_2d(int N, int M);
void fill_rand_arr_2d(int N, int M, int** arr, int max_el);
void print_arr_2d(int N, int M, int** arr);
void free_arr_2d(int** arr);