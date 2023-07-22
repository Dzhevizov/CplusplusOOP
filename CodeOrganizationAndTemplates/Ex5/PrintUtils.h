#pragma once

#include "Comparators.h"


template <typename Set>
void printContainer(typename Set::iterator begin, typename Set::iterator end)
{
	for (auto it = begin; it != end; ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}
