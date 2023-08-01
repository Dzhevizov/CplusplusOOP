#include <iostream>
#include <string>

#include "BigInt.h"

using namespace std;

int GetSumOfDigits(const string& digits)
{
    int result = 0;

    for (int i = 0; i < digits.length(); i++)
    {
        result += digits[i] - '0';
    }

    return result;
}

bool DivisibleOf45(const string& digits)
{
    if (digits[digits.length() - 1] == '0' || digits[digits.length() - 1] == '5')
    {
        if (GetSumOfDigits(digits) % 9 == 0)
            return true;
    }

    return false;
}

int main()
{
    string strFirst, strSecond;
    getline(cin, strFirst);
    getline(cin, strSecond);

    BigInt oFirst(strFirst);
    BigInt oSecond(strSecond);

    for (BigInt i = oFirst; i < oSecond; i += BigInt(1))
    {
        if (DivisibleOf45(i.getDigits()))
            cout << i << endl;
    }
    return 0;
}
