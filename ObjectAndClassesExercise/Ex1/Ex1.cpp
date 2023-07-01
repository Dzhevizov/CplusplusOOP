#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef vector<string> Sentence;

class SentenceShifter
{
    Sentence m_oSentence;
    const int m_nShifter;

public:

    SentenceShifter(const string& strSentence, const int nShifter) : m_nShifter(nShifter)
    {
        istringstream iStr(strSentence);
        string strWord;

        while (iStr >> strWord)
        {
            m_oSentence.push_back(strWord);
        }
    }

    ~SentenceShifter()
    {
    }

    void ShiftWords()
    {
        Sentence oNewSentence;
        for (string strEl : m_oSentence)
        {
            oNewSentence.push_back(" ");
        }
        
        for (size_t i = 0; i < m_oSentence.size(); i++)
        {
            int j = i + m_nShifter;
            
            if (j >= m_oSentence.size())
                j -= m_oSentence.size();

            oNewSentence[j] = m_oSentence[i];
        }

        m_oSentence = oNewSentence;
    }

    Sentence getShiftedSentence()
    {
        return m_oSentence;
    }
};

int main()
{
    string strInput;
    getline(cin, strInput);

    int nShifter = 0;
    cin >> nShifter;

    SentenceShifter oMyShifter(strInput, nShifter);

    oMyShifter.ShiftWords();

    for (string strWord : oMyShifter.getShiftedSentence())
    {
        cout << strWord << endl;
    }

    return 0;
}
