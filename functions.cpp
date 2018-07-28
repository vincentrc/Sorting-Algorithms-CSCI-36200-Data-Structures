//functions.cpp
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "functions.h"

//Function for displaying a list of numbers
void displaylist(int list[], int size)
{
	int x;

	std::cout << "\n\n";
	for(x=0;x<size;x++)
	{
		std::cout << list[x] << ", ";
	}
	std::cout << "\n\n";
}

//Function to generate a random list of numbers with given size
void generatelist(int list[], int size)
{
	int x=0, y, num, flag;

	srand(time(NULL));

	//Adds a random number until the list is full
	while(x<size)
	{
		num = rand()%(size) + 1;

		//Checks to see if duplicate
		flag = 0;
		for(y=0;y<x;y++)
		{
			if(list[y] == num)
			{
				flag = 1;
				break;
			}
		}

		//Tries again if duplicate, otherwise adds to list
		if(flag == 1)
			continue;
		else
		{
			list[x] = num;
			x++;
		}
	}
}