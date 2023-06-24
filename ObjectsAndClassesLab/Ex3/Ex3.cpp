#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class CitiesMapper
{
    vector<string> m_oCities;
    unordered_map<string, pair<string, string>> m_oCitiesMap;

public:

    CitiesMapper()
    {
    }

    ~CitiesMapper()
    {
    }

private:

    void InitMatrix(string strCity, string strLatitude, string strLongitude)
    {
        m_oCities.push_back(strCity);
        m_oCitiesMap[strCity] = make_pair(strLatitude, strLongitude);
    }

    bool HasCity(const string& strCity)
    {
        for (string City : m_oCities)
        {
            if (strCity == City)
                return true;
        }

        return false;
    }

public:

    void ReadInput()
    {
        string strInput;
        getline(cin, strInput);

        while (strInput != ".")
        {
            vector<string> oInput;
            string strCurrWord;
            for (size_t i = 0; i < strInput.length(); i++)
            {
                if (strInput[i] == ',')
                {
                    oInput.push_back(strCurrWord);
                    strCurrWord = "";
                    continue;
                }

                strCurrWord += strInput[i];
            }

            oInput.push_back(strCurrWord);

            InitMatrix(oInput[0], oInput[1], oInput[2]);

            getline(cin, strInput);
        }
    }

    void ReadQueries()
    {
        string strQuery;
        getline(cin, strQuery);

        while (strQuery != ".")
        {
            if (HasCity(strQuery))
                cout << strQuery << "," << m_oCitiesMap[strQuery].first << "," << m_oCitiesMap[strQuery].second << endl;

            else
            {
                istringstream iStr(strQuery);
                string strLatitude, strLongitude;
                iStr >> strLatitude >> strLongitude;

                for (string strCity : m_oCities)
                {
                    if (m_oCitiesMap[strCity] == pair<string, string>(strLatitude, strLongitude))
                        cout << strCity << "," << m_oCitiesMap[strCity].first << "," << m_oCitiesMap[strCity].second << endl;
                }
            }

            getline(cin, strQuery);
        }
    }
};

int main()
{
    CitiesMapper oCitiesMapper;

    oCitiesMapper.ReadInput();

    oCitiesMapper.ReadQueries();

    return 0;
}
