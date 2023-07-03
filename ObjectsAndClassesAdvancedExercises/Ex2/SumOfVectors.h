#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>

using namespace std;

vector<string> operator+(const vector<string>& v1, const vector<string>& v2)
{
	vector<string> result;

	for (size_t i = 0; i < v1.size(); i++)
	{
		string str = v1[i] + " " + v2[i];
		result.push_back(str);
	}

	return result;
}

#endif // !SUMOFVECTORS_H