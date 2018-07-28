//quick.cpp
#include "sorts.h"
#include "functions.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void swap(int list[], int x, int y);

//Quicksort top-level function
void quicksort(int list[], int left, int right)
{
	int pivot, pval;
	int x = left-1, y = right;

	if(left < right)
	{
		srand(time(NULL));

		//Sets pivot to a random index in the range of the array
		pivot = rand() % (right - left + 1) + left; 
		pval = list[pivot];

		//Swaps the pivot and the rightmost element
		swap(list, pivot, right);
		
		//Loop for partitioning
		while(1)
		{
			//Incs x and decs y until x > pivot val and y < pivot val
			while(list[++x] < pval){}
			while(pval < list[--y]){}

			//Swap, or exit if partition is complete
			if(x < y)
				swap(list, x, y);
			else
				break;
		}

		//Swaps pivot back to correct position
		swap(list, x, right);
		quicksort(list, left, x-1);		//Sort small elements
		quicksort(list, x+1, right);	//Sort large elements
	}
}

//Function for swapping two elements in the list
void swap(int list[], int x, int y)
{
	int temp;

	temp = list[x];
	list[x] = list[y];
	list[y] = temp;
}