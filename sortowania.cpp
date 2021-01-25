#include "sortowania.h"

void copy_array(int src[], int dst[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		dst[i] = src[i];
}
void randomfill_array(int arr[], size_t n, int max)
{
	if (max != 0)
		for (size_t i = 0; i < n; i++)
			arr[i] = rand() % max;
	else
		for (size_t i = 0; i < n; i++)
			arr[i] = rand();
}
void print_arr(int arr[], size_t n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}
void zero_array(unsigned long long arr[], size_t n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}
void reverse_arr(int arr[], int n)
{
	int tmp;
	for (int i = 0; i < n / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[n - i];
		arr[n - i] = tmp;
	}
}
unsigned long long average_arr(unsigned long long arr[], size_t n)
{
	unsigned long long avr = 0;
	for (int i = 0; i < n; i++)
		avr += arr[i];
	avr /= n;
	return avr;
}
unsigned long long min_arr(unsigned long long arr[], size_t n)
{
	unsigned long long minimum = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] < minimum)
			minimum = arr[i];
	return minimum;
}
unsigned long long max_arr(unsigned long long arr[], size_t n)
{
	unsigned long long maximum = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > maximum)
			maximum = arr[i];
	return maximum;
}
void insertsort(int arr[], int size, unsigned long long* assignment_counter, unsigned long long* comparison_counter)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key&& ++* comparison_counter)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			++* assignment_counter;
		}
		arr[j + 1] = key;
		++* assignment_counter;
	}
}


void bubblesort(int arr[], int size, unsigned long long* assignment_counter, unsigned long long* comparison_counter)
{
	int i, j, x;
	for (i = 1; i < size; i++)
		for (j = size - 1; j >= i; j--)
			if (arr[j - 1] > arr[j] && ++* comparison_counter)
			{
				x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
				*assignment_counter += 3;
			}
}

void shellSort(int arr[], size_t n, unsigned long long* assignment_counter, unsigned long long* comparison_counter)
{
	int max_gap_index = shellsort_gap_max_index(n / 3);
	size_t gap;
	do
	{
		gap = shellsort_gap(--max_gap_index);
	//for (size_t gap = n / 2; gap > 0; gap /= 2)
		for (size_t i = gap; i < n; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp&& ++* comparison_counter; j -= gap)
			{
				arr[j] = arr[j - gap];
				++* assignment_counter;
			}
			arr[j] = temp;
			++* assignment_counter;
		}
	} while (gap > 0);
}
int shellsort_gap_max_index(int max)
{
	int i = 0;
	while ((pow(3, i) - 1) / 2 < max)
		i++;
	return i;
}
int shellsort_gap(int i)
{
	return (pow(3, i) - 1) / 2;
}

int partition(int arr[], int p, int r, unsigned long long* assignment_counter, unsigned long long* comparison_counter)
{
	int _r = rand() % (r - p + 1), y, x, i, j;
	//x = arr[p];
	//arr[p] = arr[_r];
	//arr[_r] = x;
	x = arr[p];
	i = p - 1;
	j = r + 1;
	do
	{
		do
		{
			j--;
		} while (arr[j] > x);
		do
		{
			i++;
		} while (arr[i] < x);
		if (i < j && ++ * comparison_counter)
		{
			y = arr[i];
			arr[i] = arr[j];
			arr[j] = y;
			*assignment_counter += 3;
		}
	} while (i < j);
	return j;
}

void quicksort(int arr[], int p, int r, unsigned long long* assignment_counter, unsigned long long* comparison_counter)
{
	int q;
	if (p < r)
	{
		q = partition(arr, p, r, assignment_counter, comparison_counter);
		quicksort(arr, p, q, assignment_counter, comparison_counter);
		quicksort(arr, q + 1, r, assignment_counter, comparison_counter);
	}
	return;
}

void sort_stats(const char* name, unsigned long long* assig_arr, unsigned long long* comp_arr, size_t n)
{
	puts(name);
	printf("Porownania: \tmin: %lld\tmax: %lld\tavr: %lld\n", min_arr(comp_arr, n), max_arr(comp_arr, n), average_arr(comp_arr, n));
	printf("Przypisania: \tmin: %lld\tmax: %lld\tavr: %lld\n", min_arr(assig_arr, n), max_arr(assig_arr, n), average_arr(assig_arr, n));
	putchar('\n');
}
