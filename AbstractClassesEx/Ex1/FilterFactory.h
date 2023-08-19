#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include "CapitalLettersFilter.h"
#include "SmallLettersFilter.h"
#include "DigitsFilter.h"

class FilterFactory
{
public:
	Filter* buildFilter(std::string filterDefinition) const
	{
		Filter* filter = nullptr;

		if (filterDefinition == "A-Z")
			filter = new CapitalLettersFilter();

		else if (filterDefinition == "a-z")
			filter = new SmallLettersFilter();

		else if (filterDefinition == "0-9")
			filter = new DigitsFilter();

		return filter;
	}
};

#endif // !FILTER_FACTORY_H
