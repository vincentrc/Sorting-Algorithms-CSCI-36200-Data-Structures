//heap.cpp

#include "heap.h"

heap::heap()
{
	this->size = 0;
}
heap::~heap(){}

//Method for inserting a num into the correct location in the heap (should be buildheap - oops)
void heap::insert(int num)
{
	int x;

	//For first insertion
	if(this->size == 0)
	{
		this->heaparray[1] = num;
		this->size++;	//Increment size
	}

	//Insert and percolate up if necessary 
	else
	{
		//Sets x as the next open location
		x = this->size + 1;

		//Percolate up 
		while(1)
		{
			if(x == 1)
				break;
			else if(this->heaparray[x/2] > num)
			{
				this->heaparray[x] = this->heaparray[x/2];
				x /= 2;
			}
			else
				break;
		}

		this->heaparray[x] = num;

		this->size++;	//Increment size
	}
}

//Returns the root of the heap, and maintains the heap using percolate down if necessary 
int heap::findmin()
{
	int min = this->heaparray[1];
	int last = size;	//Index of last element
	int x = 1;
	int rightonly;

	//Take the last element in the heap and percolate down starting from root
	while(1)
	{
		rightonly = 0;

		//If last fits, or position is a leaf node
		if((this->heaparray[last] <= this->heaparray[x*2]) && (this->heaparray[last] <= this->heaparray[(x*2)+1]))
			break;	//Correct position found
		
		else if((x*2)+1 >= size)	//No right child
		{
			if(x*2 >= size) //No left child
				break;		//Correct position found
		}

		else if(x*2 >= size)
			rightonly = 1;	//This node only has a right child

		if((rightonly != 1) && (this->heaparray[x*2] <= this->heaparray[(x*2)+1]))	//Left child is smaller
		{
			this->heaparray[x] = this->heaparray[x*2];	//Swap with left child
			x *= 2;
		}

		else	//Right child is smaller
		{
			this->heaparray[x] = this->heaparray[(x*2)+1];	//swap with right child
			x = x*2 + 1;
		}
	}

	this->heaparray[x] = this->heaparray[last];	//Places the last element into the new position

	this->size--;

	return min;
}
