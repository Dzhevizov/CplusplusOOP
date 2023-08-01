#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H
#include "Company.h"
#include "ProfitCalculator.h"
#include <sstream>

std::string getProfitReport(const Company* from, const Company* to, std::map<int, ProfitCalculator>& profitCalculatorsByCompany)
{
	std::ostringstream oStr;

	while (true)
	{
		const ProfitCalculator& pc = profitCalculatorsByCompany[from->getId()];

		oStr << from->getName() << " = " << pc.calculateProfit(*from) << std::endl;

		if (from == to)
			break;

		from++;
	}

	return oStr.str();
}

#endif // !PROFIT_REPORT_H
