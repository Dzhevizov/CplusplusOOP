#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted)
	: copyrighted(copyrighted)
{
}

bool Article13Filter::blockIfCopyrighted(std::string s)
{
	if (!isCopyrighted(s))
		return false;

	blocked.push_back(s);
	return true;
}

bool Article13Filter::isCopyrighted(std::string s)
{
	for (std::string str : copyrighted)
	{
		if (str == s)
			return true;
	}

	return false;
}

std::vector<std::string> Article13Filter::getBlocked()
{
	return blocked;
}