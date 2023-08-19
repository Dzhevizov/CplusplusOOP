#ifndef CAPITAL_LETTERS_FILTER_H
#define CAPITAL_LETTERS_FILTER_H

#include "Filter.h"

class CapitalLettersFilter : public Filter
{
	bool shouldFilterOut(char symbol) const override
	{
		if (symbol >= 'A' && symbol <= 'Z')
			return true;

		return false;
	}
};

#endif // !CAPITAL_LETTERS_FILTER_H
