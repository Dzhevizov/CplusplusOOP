#pragma once

std::vector<Company> readCompaniesFromMemory(unsigned char *chMemory, int nNumCompanies)
{
	std::vector<Company> result;

	unsigned char* chCurr = chMemory;

	for (size_t i = 0; i < nNumCompanies; i++)
	{
		int nId = *chCurr;
		chCurr++;

		std::string strName;

		while (*chCurr != '\0')
		{
			strName += *chCurr;
			chCurr++;
		}

		chCurr++;

		int nNumEmployees = *chCurr;
		chCurr++;

		std::vector<std::pair<char, char> > oEmployees;

		for (size_t j = 0; j < nNumEmployees; j++)
		{
			char chFirstInit = *chCurr;
			chCurr++;
			char chSecondInit = *chCurr;
			chCurr++;

			oEmployees.push_back(std::make_pair(chFirstInit, chSecondInit));
		}

		Company oCompany(nId, strName, oEmployees);
		result.push_back(oCompany);
	}

	return result;
};