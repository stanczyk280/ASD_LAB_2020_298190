#include "heapSort.h"
using namespace std;

// warunek poczatkowy
int x = -1;

// globalna
string heap[1000];

void heapify(string k)
{
	x++;
	heap[x] = k;
	int child = x;
	string tmp;
	int index = x / 2;


	while (index >= 0)
	{


		if (heap[index] > heap[child])
		{

			tmp = heap[index];
			heap[index] = heap[child];
			heap[child] = tmp;
			child = index;

			index = index / 2;
		}
		else
			break;
	}
}


void heapSort()
{
	int left1, right1;

	while (x >= 0)
	{
		string k;
		k = heap[0];


		cout << k << " ";

		heap[0] = heap[x];


		x = x - 1;
		string tmp;
		int index = 0;
		int length = x;
		left1 = 1;
		right1 = left1 + 1;

		while (left1 <= length)
		{

			if (heap[index] <= heap[left1]
				&& heap[index] <= heap[right1])
			{
				break;
			}

			else
			{
				if (heap[left1] < heap[right1])
				{
					tmp = heap[index];
					heap[index] = heap[left1];
					heap[left1] = tmp;
					index = left1;
				}

				else
				{
					tmp = heap[index];
					heap[index] = heap[right1];
					heap[right1] = tmp;
					index = right1;
				}
			}

			left1 = 2 * left1;
			right1 = left1 + 1;
		}
	}
}

void Heapsort(string k[], int n)
{

	for (int i = 0; i < n; i++)
	{
		heapify(k[i]);
	}

	heapSort();
}

