#include "FixedArray.h"

FixedArray::FixedArray(const int arraySize)
	: BrokenArray(arraySize)
{
}

FixedArray::~FixedArray()
{
}

FixedArray::FixedArray(const FixedArray& other) : BrokenArray(other)
{
	const int size = BrokenArray::getSize();
	_array = new int[size];
	for (int i = 0; i < size; i++)
	{
		_array[i] = other._array[i];
	}
}

FixedArray& FixedArray::operator=(const FixedArray& other)
{
	if (this != &other)
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
		}

		BrokenArray::operator=(other);

		const int size = BrokenArray::getSize();
		_array = new int[size];
		for (int i = 0; i < size; i++)
		{
			_array[i] = other._array[i];
		}
	}

	return *this;
}

void FixedArray::addValueToMemory(const int value)
{
	return BrokenArray::addValueToMemory(value);
}

int FixedArray::getMemorySumValue() const
{
	return BrokenArray::getMemorySumValue();
}