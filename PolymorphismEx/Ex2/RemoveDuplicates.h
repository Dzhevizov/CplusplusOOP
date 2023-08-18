#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include "Company.h"
#include <unordered_set>

void removeDuplicates(std::list<Company*>& companies)
{
	std::unordered_set<std::string> oCompanyNames;
	std::list<Company*> uniqueCompanies;

	for (Company* c : companies)
	{
		if (oCompanyNames.find(c->getName()) != oCompanyNames.end())
			continue;
		else
		{
			oCompanyNames.insert(c->getName());
			uniqueCompanies.push_back(c);
		}
			
	}

	companies = uniqueCompanies;
}

#endif // !REMOVE_DUPLICATES_H