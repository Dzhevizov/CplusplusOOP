#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"
#include <sstream>
#include <vector>

Company* parseUniqueCompanies(const std::string& input, int& numCompanies, std::string func(const Company& c))
{
	std::istringstream iStr(input);
	std::string currEl;
	numCompanies = 0;
	std::vector<Company*> companiesVec;

	while (iStr >> currEl)
	{
		int id = stoi(currEl);

		iStr >> currEl;

		std::string name = currEl;

		Company* c = new Company(id, name);
		companiesVec.push_back(c);
	}

	std::vector<Company*> uniqueVec;

	size_t i = 0;

	for (auto it = companiesVec.begin(); it != companiesVec.end(); it++)
	{
		bool is_unique = true;

		for (auto el : uniqueVec)
		{
			if (func(*(*it)) == func(*el))
			{
				is_unique = false;
				break;
			}
		}

		if (is_unique)
		{
			uniqueVec.push_back(*it);
			i++;
		}
		
	}
	
	numCompanies = i;
	Company* unique_companies = new Company[numCompanies]{};
	size_t j = 0;

	for (auto it = uniqueVec.begin(); it != uniqueVec.end(); it++)
	{
		unique_companies[j] = *(*it);
		j++;
	}
	
	return unique_companies;
}

#endif // !PARSE_COMPANIES_H
