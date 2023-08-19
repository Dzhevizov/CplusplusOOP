#ifndef NUMBERS_EXTRACTOR_H
#define NUMBERS_EXTRACTOR_H

#include "BufferedExtractor.h"

class NumbersExtractor : public BufferedExtractor
{
public:
	NumbersExtractor(std::istream& stream)
		: BufferedExtractor(stream) {}

	bool shouldBuffer(char symbol) override
	{
		if (symbol >= '0' && symbol <= '9')
			return true;

		return false;
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
};

#endif // !NUMBERS_EXTRACTOR_H