#ifndef EXTRACTOR_INITIALIZATION_H
#define EXTRACTOR_INITIALIZATION_H

#include <memory>

#include "DigitsExtractor.h"
#include "NumbersExtractor.h"
#include "QuotesExtractor.h"

std::shared_ptr<Extractor> getExtractor(const std::string& extractType, std::istringstream& lineIn)
{
	if (extractType == "digits")
		return std::make_shared<DigitsExtractor>(lineIn);

	if (extractType == "numbers")
		return std::make_shared<NumbersExtractor>(lineIn);

	if (extractType == "quotes")
		return std::make_shared<QuotesExtractor>(lineIn);

	return nullptr;
}

#endif // !EXTRACTOR_INITIALIZATION_H
