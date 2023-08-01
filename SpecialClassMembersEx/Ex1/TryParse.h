#pragma once

#include <sstream>

bool tryParse(const std::string& strString, int& nInt)
{
	std::istringstream iStr(strString);
	if (iStr >> nInt)
		return true;

	return false;
}