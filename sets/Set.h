#pragma once
class Set
{
public:
	Set(const int*, const size_t size);
	Set(const Set* set);
	~Set();

	Set& operator=(const Set& set);
	Set& operator+=(const Set& other);
	Set operator+(const Set& other);


	void setSize(size_t size);
	void setElements(const int*, int s);

	size_t getSize() const;
	void print();

private:
	size_t calculateRealSizeForAddition(int* arr, int sizeOfArr) const;
	bool elExists(const int* from, const int fromSize, const int element) const;

	int* elements;
	size_t size;
};

