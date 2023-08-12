#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main()
{
    std::string strInput;
    std::getline(std::cin, strInput);

    std::vector<std::pair<int, int>> ranges;

    while (strInput != ".")
    {
        std::istringstream iStr(strInput);

        int num1 = 0, num2 = 0;
        iStr >> num1 >> num2;

        ranges.push_back(std::make_pair(num1, num2));

        std::getline(std::cin, strInput);
    }

    sort(ranges.begin(), ranges.end());

    int num = 0;

    while (std::cin >> num)
    {
        bool is_found = false;
        auto it = lower_bound(ranges.begin(), ranges.end(), std::make_pair(num, 0));

        if (it != ranges.end() && num >= it->first && num <= it->second)
            is_found = true;
        
        if (!is_found)
            it--;
        if (it != ranges.end() && num >= it->first && num <= it->second)
            is_found = true;

        if (is_found)
            std::cout << "in" << std::endl;
        else
            std::cout << "out" << std::endl;
    }

    return 0;
}
