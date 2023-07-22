#pragma once

#include <sstream>
#include <vector>

template <typename T>
std::string join(std::vector<T>& oInput, std::string& strJoinStr)
{
	std::string strOutput;
	std::stringstream oStr;
	int i = 0;
	for (T El : oInput)
	{
		if (i == oInput.size() - 1)
			oStr << El;
		else
			oStr << El << strJoinStr;

		i++;
	}

	getline(oStr,strOutput);

	return strOutput;
}