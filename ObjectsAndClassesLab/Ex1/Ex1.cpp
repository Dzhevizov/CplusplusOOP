#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

class OurString
{
    string m_strString;

public:

    OurString(string strString)
    {
        m_strString = strString;
    }

    void replacePunctoation()
    {
        for (size_t i = 0; i < m_strString.length(); i++)
        {
            if (ispunct(m_strString[i]))
                m_strString[i] = ' ';
        }
    }

    void splitToSetOfWords(set<string>& oSet)
    {
        istringstream iStr(m_strString);

        string strWord;

        while (iStr >> strWord)
        {
            oSet.insert(strWord);
        }
    }

    bool hasChar(const char& chChar)
    {
        for (char chCurrChar : m_strString)
        {
            if (chCurrChar == tolower(chChar) || chCurrChar == toupper(chChar))
            {
                return true;
            }
        }

        return false;
    }

    string getString()
    {
        return m_strString;
    }
};

int main()
{
    string strString;
    getline(cin, strString);

    OurString strMyString(strString);

    strMyString.replacePunctoation();

    set<string> MySet;

    strMyString.splitToSetOfWords(MySet);

    char chChar;
    cin >> chChar;

    while (chChar != '.')
    {
        bool isFound = false;

        for (string strWord : MySet)
        {
            OurString ostrWord(strWord);

            if (ostrWord.hasChar(chChar))
            {
                isFound = true;

                cout << ostrWord.getString() << ' ';
            }
        }

        if (!isFound)
            cout << "---";

        cout << endl;
        cin >> chChar;
    }

    return 0;
}
