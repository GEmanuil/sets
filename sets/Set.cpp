#include "Set.h"
#include <iostream>

Set::Set(const int* arr, const size_t size)
{
	setElements(arr, size);
}

Set::Set(const Set& set)
{
	this->size = set.size;
	this->elements = new int[this->size];
	setElements(set.elements, getSize());
}

void Set::setSize(size_t size)
{
	this->size = size;
}

void Set::setElements(const int* arr, int s)
{
	elements = new int[s];
	setSize(s);

	for (int i = 0; i < s; i++)
	{
		elements[i] = arr[i];
	}
}

size_t Set::getSize() const
{
	return this->size;
}

void Set::print() const 
{
	for (int i = 0; i < size; i++)
	{
		std::cout << elements[i] << " ";
	}
	std::cout << std::endl;

}

size_t Set::calculateRealSizeForAddition(int* arr, int sizeOfArr) const
{
	size_t diplicateNums = 0;
	for (int i = 0; i < sizeOfArr; i++)
	{
		for (int j = 0; j < getSize(); j++)
		{
			if (arr[i] == elements[j])
			{
				diplicateNums++;
			}
		}

	}
	return (getSize() + sizeOfArr) - diplicateNums;
}

bool Set::elExists(const int* from, const int fromSize, const int element) const
{
	for (int i = 0; i < fromSize; i++)
	{
		if (element == from[i])
		{
			return true;
		}
	}
	return false;
}

Set::~Set()
{
	delete[] elements;
}

Set& Set::operator=(const Set& other)
{
	if (this != &other)
	{
		delete[] elements;
		//setElements(other.elements, getSize());
		setSize(other.size);
		elements = new int[getSize()];
		setElements(other.elements, getSize());

	}

	return *this;
}

Set& Set::operator+=(const Set& other)
{
	this->print();
	other.print();
	
	size_t newSize = calculateRealSizeForAddition(other.elements, other.getSize());
	int* res = new int[newSize];

	for (int i = 0; i < getSize(); i++)
	{
		res[i] = elements[i];
	}
 
	for (int i = getSize(); i < newSize; i++)
	{
		for (size_t j = 0; j < other.getSize(); j++)
		{
			if (!elExists(res, newSize, other.elements[j]))
			{
				res[i] = other.elements[j];
				break;
			}
		}

	}
	delete[] elements;
	elements = res;
	setSize(newSize);

	return *this;
}

Set Set::operator+(const Set& other)
{
	Set result(*this);
	result += other;
	return result;
}

