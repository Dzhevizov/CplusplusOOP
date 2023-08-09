#pragma once


class ArrayOfPointers
{
	int addedCompanies;
	Company** companiesPtrArray;

public:

	ArrayOfPointers()
		: addedCompanies(0)
	{
		companiesPtrArray = new Company*[1000];
	}

	~ArrayOfPointers()
	{
		delete[] companiesPtrArray;
	}

	void add(Company* c)
	{
		companiesPtrArray[addedCompanies] = c;
		addedCompanies++;
	}

	const int getSize() const
	{
		return addedCompanies;
	}

	const Company* get(const int index) const
	{
		return companiesPtrArray[index];
	}
};