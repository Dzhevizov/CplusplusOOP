#include <iostream>
#include <vector>

using namespace std;

class IronField
{
    char** m_oMatrix;
    size_t m_nSize;

public:

    IronField(size_t nSize) : 
        m_nSize(nSize),
        m_oMatrix(new char* [nSize])
    {
    }

    ~IronField()
    {
        for (size_t i = 0; i < m_nSize; i++)
            delete[] m_oMatrix[i];

        delete[] m_oMatrix;
    }

private:

    void findRusties(vector<pair<int, int>>& oRusties)
    {
        for (int i = 0; i < m_nSize; i++)
        {
            for (int j = 0; j < m_nSize; j++)
            {
                if (m_oMatrix[i][j] == '!')
                {
                    oRusties.push_back(make_pair(i, j));
                }
            }
        }
    }

public:

    void InitField()
    {
        for (size_t i = 0; i < m_nSize; i++)
        {
            m_oMatrix[i] = new char[m_nSize];

            for (size_t j = 0; j < m_nSize; j++)
            {
                cin >> m_oMatrix[i][j];
            }
        }
    }

    void getRusty()
    {
        vector<pair<int, int>> oRusties;
        findRusties(oRusties);


        for (auto oRusty : oRusties)
        {
            if (oRusty.first > 0 && m_oMatrix[oRusty.first - 1][oRusty.second] != '#')
                m_oMatrix[oRusty.first - 1][oRusty.second] = '!';

            if (oRusty.first < m_nSize - 1 && m_oMatrix[oRusty.first + 1][oRusty.second] != '#')
                m_oMatrix[oRusty.first + 1][oRusty.second] = '!';

            if (oRusty.second > 0 && m_oMatrix[oRusty.first][oRusty.second - 1] != '#')
                m_oMatrix[oRusty.first][oRusty.second - 1] = '!';

            if (oRusty.second < m_nSize - 1 && m_oMatrix[oRusty.first][oRusty.second + 1] != '#')
                m_oMatrix[oRusty.first][oRusty.second + 1] = '!';
        }
    }

    void printMatrix()
    {
        for (size_t i = 0; i < m_nSize; i++)
        {
            for (size_t j = 0; j < m_nSize; j++)
                cout << m_oMatrix[i][j];

            cout << endl;
        }
    }
};

int main()
{
    IronField oField(10);

    oField.InitField();

    int nRustyTimes = 0;
    cin >> nRustyTimes;

    for (int i = 0; i < nRustyTimes; i++)
    {
        oField.getRusty();
    }

    oField.printMatrix();

    return 0;
}
