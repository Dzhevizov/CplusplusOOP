#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>


std::vector<std::string>& operator<< (std::vector<std::string>& v1, const std::string& str)
{
	v1.push_back(str);
	return v1;
}

std::ostream& operator<< (std::ostream &oStr, const std::vector<std::string>& v1)
{
	for (size_t i = 0; i < v1.size(); i++)
	{
		oStr << v1[i] << std::endl;
	}
	return oStr;
}

std::string& operator+(std::string& str, int n)
{
	str += std::to_string(n);
	return str;
}
#endif // !OPERATORS_H