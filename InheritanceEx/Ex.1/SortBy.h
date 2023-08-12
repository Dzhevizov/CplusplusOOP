#ifndef SORT_BY_H
#define SORT_BY_H

#include "Company.h"
#include <algorithm>

void sortBy(Company** companiesBegin, Company** companiesEnd, bool func(const Company& a, const Company& b))
{
    for (int i = 0; i < companiesEnd - companiesBegin - 1; i++)
    {
        int minIdx = i;

        for (int j = i + 1; j < companiesEnd - companiesBegin; j++)
        {
            if (func(*companiesBegin[j], *companiesBegin[minIdx]))
            {
                minIdx = j;
            }
        }

        std::swap(companiesBegin[i], companiesBegin[minIdx]);
    }
}

#endif // !SORT_BY_H
