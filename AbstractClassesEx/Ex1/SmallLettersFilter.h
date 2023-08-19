#ifndef SMALL_LETTERS_FILTER_H
#define SMALL_LETTERS_FILTER_H

#include "Filter.h"

class SmallLettersFilter : public Filter
{
	bool shouldFilterOut(char symbol) const override
	{
		if (symbol >= 'a' && symbol <= 'z')
			return true;

		return false;
	}
};

#endif // !SMALL_LETTERS_FILTER_H
