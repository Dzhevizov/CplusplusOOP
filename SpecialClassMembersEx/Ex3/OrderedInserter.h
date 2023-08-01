#ifndef ORDERED_INSERTER_H
#define ORDERED_INSERTER_H
#include "Company.h"

class OrderedInserter
{
	std::vector<const Company*>& companies;

public:
	OrderedInserter(std::vector<const Company*>& companies)
		: companies(companies)
	{
	}

	void insert(const Company* pCompany)
	{
		if (companies.size() == 0)
			companies.push_back(pCompany);

		else
		{
			auto it = companies.begin();
			while (it != companies.end())
			{
				if ((*it)->getId() > pCompany->getId())
				{
					break;
				}

				it++;
			}

			companies.insert(it, pCompany);
		}
		
	}
};

#endif // !ORDERED_INSERTER_H
