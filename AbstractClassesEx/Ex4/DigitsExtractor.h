#ifndef DIGITS_EXTRACTOR_H
#define DIGITS_EXTRACTOR_H

class DigitsExtractor : public Extractor
{
public:
	DigitsExtractor(std::istream& stream)
		: Extractor(stream) {}

protected:
	bool process(char symbol, std::string& output) override
	{
		if (symbol >= '0' && symbol <= '9')
		{
			output = symbol;
			return true;
		}
			
		return false;
	}
};

#endif // !DIGITS_EXTRACTOR_H