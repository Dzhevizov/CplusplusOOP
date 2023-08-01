#pragma once
#include <map>

class Word
{
	std::string m_strWord;
	static std::map<std::string, int> created_words;

public:
	Word(const std::string& strWord)
		: m_strWord(strWord)
	{
		created_words[strWord]++;
	}

	std::string getWord() const
	{
		return m_strWord;
	}

	int getCount() const
	{
		int nCount = created_words[m_strWord];
		created_words[m_strWord] = 0;

		return nCount;
	}

	bool operator < (const Word& other) const
	{
		return this->getWord() < other.getWord();
	}

};

std::map<std::string, int> Word::created_words;