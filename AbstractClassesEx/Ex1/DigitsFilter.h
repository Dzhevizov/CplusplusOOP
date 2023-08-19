#ifndef DIGITS_FILTER_H
#define DIGITS_FILTER_H

#include "Filter.h"

class DigitsFilter : public Filter
{
	bool shouldFilterOut(char symbol) const override
	{
		if (symbol >= '0' && symbol <= '9')
			return true;

		return false;
	}
};

#endif // !DIGITS_FILTER_H
