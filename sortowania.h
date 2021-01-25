#ifndef SORTOWANIA
#define SORTOWANIA
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cmath>

//ZADANIE 21

// zaimplementowany insertsort
void insertsort(int arr[], int size, unsigned long long* assignment_counter, unsigned long long* comparison_counter);

// zaimplementowany bubblesort
void bubblesort(int arr[], int size, unsigned long long* assignment_counter, unsigned long long* comparison_counter);

// zaimplementowany shellsort
void shellSort(int arr[], size_t n, unsigned long long* assignment_counter, unsigned long long* comparison_counter);

// zaimplementowany quicksort
void quicksort(int arr[], int low, int high, unsigned long long* assignment_counter, unsigned long long* comparison_counter);

// funkcja pomocnicza do quicksorta
int partition(int arr[], int low, int high, unsigned long long* assignment_counter, unsigned long long* comparison_counter);

// przepisuje n elementow miedzy tablicami src[]->dst[]
void copy_array(int src[], int dst[], size_t n);

// wypelnia tablice losowymi wartosciami z zakresu 0-max
void randomfill_array(int arr[], size_t n, int max);

// wypelnia tablice zerami
void zero_array(unsigned long long arr[], size_t n);

// wypisuje tablice
void print_arr(int arr[], size_t n);

// znajduje optymalny indeks dla funkcji wyznaczacej odstep w shellsorcie
int shellsort_gap_max_index(int max);

// zwraca odstep w shellsorcie
int shellsort_gap(int index);

// Odwraca tablice o n elementach
void reverse_arr(int arr[], int n);

// Zwraca najmniejszy element w tablicy
unsigned long long min_arr(unsigned long long arr[], size_t n);

// Zwraca najwiekszy element w tablicy
unsigned long long max_arr(unsigned long long arr[], size_t n);

// Zwraca wartosc srednia tablicy
unsigned long long average_arr(unsigned long long arr[], size_t n);

// drukuje statystyki
void sort_stats(const char* name, unsigned long long* assig_arr, unsigned long long* comp_arr, size_t n);

// Zadanie 22

#endif // !SORTOWANIA
