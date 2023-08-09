#ifndef MIN_BY_H
#define MIN_BY_H

#include <string>
#include <algorithm>
#include <vector>

const std::string& minBy(std::vector<std::string>& values, bool func(const std::string& a, const std::string& b))
{
	sort(values.begin(), values.end(), func);

	return values[0];
}

#endif // !MIN_BY_H