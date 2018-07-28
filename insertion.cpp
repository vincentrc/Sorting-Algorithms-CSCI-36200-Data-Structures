//insertion.cpp
#include "sorts.h"

//Insertion sort algorithm
void insertionsort(int list[], int size)
{
	int x, y, temp;

	//Iterates through all positions in list 
	for(x=1;x<=size-1;x++)
	{
		temp = list[x];
		
		//Pushes numbers below the current position up until a smaller one is found
		for(y=x;(y>0)&&(temp<list[y-1]);y--)
		{
			list[y] = list[y-1];
		}
		//Inserts current number into proper position
		list[y] = temp;
	}

}