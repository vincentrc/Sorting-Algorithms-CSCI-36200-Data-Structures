//main.cpp
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "sorts.h"
#include "functions.h"
#include "heap.h"


int main()
{
	int original[10000], list[10000], temp[10000], sorted[10000];
	int	n[7] = {100, 500, 1000, 2000, 5000, 8000, 10000};
	int x, y;
	int start, stop, duration;
	int iu[7], is[7];	//Arrays to hold the runtimes for each algorithm
	int mu[7], ms[7];	//both for sorted (s) and unsorted (u) lists of data
	int qu[7], qs[7];
	int hu[7], hs[7];

	std::cout << "Generating list...\n\n";

	//Randomly generates a list of 10000 numbers with no duplicates
	generatelist(original, 10000);

	//For insertion sort with unsorted data 
	for(x=0;x<7;x++)
	{
		//Copies original list over (since the algorithms sort the list, avoids regenerating every time)
		//(Using the same list every time allows for a more accurate comparison between runtimes)
		for(y=0;y<n[x];y++)
		{
			list[y] = original[y];
		}

		start = clock();
		insertionsort(list, n[x]);
		stop = clock();
		iu[x] = stop - start;
	}

	//Sets up sorted array
	for(x=0;x<10000;x++)
	{
		sorted[x] = list[x];
	}

	//For insertion sort with sorted data 
	for(x=0;x<7;x++)
	{
		//Copies sorted list over 
		for(y=0;y<n[x];y++)
		{
			list[y] = sorted[y];
		}

		start = clock();
		insertionsort(list, n[x]);
		stop = clock();
		is[x] = stop - start;
	}

	//For merge sort with unsorted data 
	for(x=0;x<7;x++)
	{
		//Copies original list over 
		for(y=0;y<n[x];y++)
		{
			list[y] = original[y];
		}

		start = clock();
		mergesort(list,temp,0,n[x]-1);
		stop = clock();
		mu[x] = stop - start;
	}

	//For merge sort with sorted data 
	for(x=0;x<7;x++)
	{
		//Copies sorted list over 
		for(y=0;y<n[x];y++)
		{
			list[y] = sorted[y];
		}

		start = clock();
		mergesort(list,temp,0,n[x]-1);
		stop = clock();
		ms[x] = stop - start;
	}

	//For quick sort with unsorted data 
	for(x=0;x<7;x++)
	{
		//Copies original list over 
		for(y=0;y<n[x];y++)
		{
			list[y] = original[y];
		}

		start = clock();
		quicksort(list,0,n[x]-1);
		stop = clock();
		qu[x] = stop - start;
	}

	//For quick sort with sorted data 
	for(x=0;x<7;x++)
	{
		//Copies sorted list over 
		for(y=0;y<n[x];y++)
		{
			list[y] = sorted[y];
		}

		start = clock();
		quicksort(list,0,n[x]-1);
		stop = clock();
		qs[x] = stop - start;
	}

	//For heap sort with unsorted data 
	for(x=0;x<7;x++)
	{
		//Copies original list over 
		for(y=0;y<n[x];y++)
		{
			list[y] = original[y];
		}

		start = clock();
		heapsort(list, n[x]);
		stop = clock();
		hu[x] = stop - start;
	}

	//For heap sort with sorted data 
	for(x=0;x<7;x++)
	{
		//Copies sorted list over 
		for(y=0;y<n[x];y++)
		{
			list[y] = sorted[y];
		}

		start = clock();
		heapsort(list, n[x]);
		stop = clock();
		hs[x] = stop - start;
	}


	//Display (my very poorly collected) results
	printf("\n\nUnsorted:\n");
	printf("\nSize:   Insertion:   Merge:   Quick:   Heap:\n");
	for(x=0;x<7;x++)
	{
		printf("\n%3dus   %8dus   %4dus   %4dus   %3dus\n", n[x], iu[x], mu[x], qu[x], hu[x]);
	}

	printf("\n\nSorted:\n");
	printf("\nSize:   Insertion:   Merge:   Quick:   Heap:\n");
	for(x=0;x<7;x++)
	{
		printf("\n%3dus   %8dus  %4dus   %4dus   %3dus\n", n[x], is[x], ms[x], qs[x], hs[x]);
	}
	
	return 0;
}