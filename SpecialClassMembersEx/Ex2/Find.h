#pragma once

Company* find(const std::vector<Company*>& companies, const int searchId)
{
	for (Company* oEl : companies)
	{
		if (oEl != nullptr && oEl->getId() == searchId)
			return oEl;
	}

	return nullptr;
}
