#pragma once
#include <iostream>
#include <sstream>

template<typename T>
class Parser
{
	std::istream& iStr;
	std::string stopLine;

public:
	Parser<T>(std::istream& iStr, std::string& stopLine)
		: iStr(iStr)
		, stopLine(stopLine)
	{
	}

	bool readNext(T& var)
	{
		std::string temp;
		getline(iStr, temp);
		
		if(temp == stopLine)
			return false;

		std::istringstream stream(temp);
		stream >> var;

		return true;
	}
};