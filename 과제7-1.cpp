// selection_sort.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <iostream>


typedef struct data {
	int *id;
	int *score;
} data;

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void selection_sort(data *list, int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j<n; j++)
			if (list->score[j]<list->score[least]) least = j;
		SWAP(list->score[i], list->score[least], temp);
		SWAP(list->id[i], list->id[least], temp);
	}
}

void selection_sort_stable(data *list, int n)
{
	for (int i = 0; i < n - 1; i++)
	{

		// Loop invariant : Elements till a[i - 1]
		// are already sorted.

		// Find minimum element from
		// arr[i] to arr[n - 1].
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (list->score[min] > list->score[j])
				min = j;

		// Move minimum element at current i.
		int key = list->score[min];
		while (min > i)
		{
			list->score[min] = list->score[min - 1];
			min--;
		}
		list->score[i] = key;
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}


int main()
{
	int data_id[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int data_score[] = { 30, 25, 10, 20, 80, 30, 25, 10 };

	int in_size = 8;
	data *input = (data *)malloc(sizeof(data));
	
	input->id = data_id;
	input->score = data_score;

	//Print out the input data
	printf("Input data\n");
	for (int i = 0; i < in_size; i++)
		printf("%d\t %d\n", input->id[i], input->score[i]);
	printf("\n");

	// Produce the stable sorting results by replacing 'selection_sort' with 'selection_sort_stable'.
	selection_sort_stable(input, in_size);

	//Print out the sorted data
	printf("Sorted data\n");
	for (int i = 0; i < in_size; i++)
		printf("%d\t %d\n", input->id[i], input->score[i]);
	printf("\n");

    return 0;
}

