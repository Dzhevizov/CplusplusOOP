#ifndef QUOTES_EXTRACTOR_H
#define QUOTES_EXTRACTOR_H

#include "BufferedExtractor.h"

class QuotesExtractor : public BufferedExtractor
{
public:
	QuotesExtractor(std::istream& stream)
		: BufferedExtractor(stream)
		, has_quotes(false) {}

	bool shouldBuffer(char symbol) override
	{
		if (buffer.str().empty() && symbol == '"')
		{
			has_quotes = true;
			return false;
		}

		if (!buffer.str().empty() && symbol == '"')
		{
			has_quotes = false;
			return false;
		}

		if (!has_quotes)
			return false;

		return true;
	}

	bool process(char symbol, std::string& output) override {
		if (shouldBuffer(symbol)) {
			buffer << symbol;
			return false;
		}
		else if (!buffer.str().empty()) {
			output = buffer.str();

			buffer.str("");
			buffer.clear();
			return true;
		}

		return false;
	}

private:
	bool has_quotes;
};

#endif // !QUOTES_EXTRACTOR_H