#pragma once

#include <sstream>
#include <vector>

template <typename T>
std::vector <T> split(std::string& strInput , const char& chSeparator)
{
	std::vector<T> oOutput;
	std::string strCurrElement = "";
	T currEll;

	for (char chLetter : strInput)
	{
		if (chLetter == chSeparator)
		{
			std::istringstream iStr(strCurrElement);
			iStr >> currEll;
			oOutput.push_back(currEll);
			strCurrElement = "";
		}

		else
			strCurrElement += chLetter;
	}

	std::istringstream iStr(strCurrElement);
	iStr >> currEll;
	oOutput.push_back(currEll);

	return oOutput;
}