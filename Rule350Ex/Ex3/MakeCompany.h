#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"

std::shared_ptr<Company> makeCompany(std::vector<std::string> properties)
{
	int id = stoi(properties[0]);
	std::string name = properties[1];
	std::vector<std::pair<char, char> > employees;
	for (size_t index = 2; index < properties.size(); index++)
	{
		const std::string& initials = properties[index];
		employees.push_back(std::make_pair(initials[0], initials[1]));
	}

	return std::make_shared<Company>(Company(id, name, employees));
}

#endif // !MAKE_COMPANY_H
