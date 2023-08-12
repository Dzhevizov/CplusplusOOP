#include "IndexedSet.h"

IndexedSet::IndexedSet()
	: valuesArray(nullptr)
{
}

IndexedSet::IndexedSet(const IndexedSet& other)
	: valuesSet(other.valuesSet)
	, valuesArray(nullptr)
{
}

void IndexedSet::add(const Value& v)
{
	valuesSet.insert(v);
	clearIndex();
}

size_t IndexedSet::size() const
{
	return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index)
{
	if (!valuesArray)
		buildIndex();

	return valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other)
{
	if (this != &other)
	{
		valuesSet = other.valuesSet;
		clearIndex();
	}

	return *this;
}

IndexedSet::~IndexedSet()
{
	clearIndex();
}

void IndexedSet::buildIndex()
{
	size_t size = valuesSet.size();
	valuesArray = new Value[size];

	size_t Idx = 0;

	for (const Value& value : valuesSet)
	{
		valuesArray[Idx] = value;
		++Idx;
	}
}

void IndexedSet::clearIndex()
{
	if (valuesArray)
	{
		delete[] valuesArray;
		valuesArray = nullptr;
	}
}