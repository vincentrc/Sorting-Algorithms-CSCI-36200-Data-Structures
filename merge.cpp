//merge.cpp
#include <iostream>
#include <vector>
#include "sorts.h"

void merge(int list[], int temp[], int left, int right, int middle);

//Merge Sort top-level function
void mergesort(int list[],int temp[], int left, int right)
{
	//Only sorts if indexes make sense
	if(left < right)
	{
		//Finds the middle of the list, then recursively calls on left and right halves
		int middle = ((left + right)/2);
		mergesort(list,temp,left,middle); 
		mergesort(list,temp,middle+1,right);

		//Merges the two now sorted halves
		merge(list,temp,left,middle+1,right);
	}

}

//Merge function
void merge(int list[], int temp[], int left, int right, int rightend)
{
	int leftend = right-1;
	int temppos = left;
	int num = rightend - left +1;
	int x;

	//Starts at beginning of each half, and finds which element is smaller,
	//then adds that element to the temp array, and increments the index for that half
	while((left <= leftend)&&(right <= rightend))
	{
		if(list[left] <= list[right])
			temp[temppos++] = list[left++];
		else
			temp[temppos++] = list[right++];
	}
	
	//Adds the remainder of whichever half was bigger
	while(left <= leftend)
	{
		temp[temppos++] = list[left++];
	}
	while(right <= rightend)
	{
		temp[temppos++] = list[right++];
	}

	//Puts temp array contents back into original array in correct spot
	for(x=0;x<num;x++,rightend--)
	{
		list[rightend] = temp[rightend];
	}
}