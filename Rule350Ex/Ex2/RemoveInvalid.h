#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"

void removeInvalid(std::list<Company*>& companies)
{
	auto it = companies.begin();

	while (it != companies.end())
	{
		if ((*it)->getId() < 0)
		{
			delete (*it);
			it = companies.erase(it);
		}
		else
			it++;
	}
}

#endif // !REMOVE_INVALID_H