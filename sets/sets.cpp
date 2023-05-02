#include <iostream>
#include <random>
#include "Set.h"

int main()
{
	size_t size = 5;
	int* elements = new int[size];
	for (int i = 0; i < size; i++)
	{
		elements[i] = rand();
	}

	Set set(elements, size);
	set.print();

	elements[0] = 0;
	elements[1] = 1;
	elements[2] = 2;
	elements[3] = 3;
	elements[4] = 4;


	Set set2(elements, size);
	//set = set2;
	set2.print();

	set += set2;

	set.print();

	Set set3(elements, size);
	
	elements[0] = 69420;

	set.print();
	set.setElements(elements, 5);

	set.print();
	set3 =set + set2;

	set3.print();

	delete[] elements;
	//set.~Set();
	//set2.~Set();
	//set3.~Set();
}