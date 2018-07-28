//heapsort.cpp
#include "sorts.h"
#include "heap.h"

//Function for heap sort
void heapsort(int list[], int size)
{
	int x;
	heap *myheap = new heap();

	//Inserts each number into the heap one by one
	for(x=0;x<size;x++)
	{
		myheap->insert(list[x]);
	}

	//Refills the list by finding min size times
	for(x=0;x<size;x++)
	{
		list[x] = myheap->findmin();
	}

	delete myheap;
}