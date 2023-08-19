#ifndef CUT_TRANSFORM_H
#define CUT_TRANSFORM_H

#include "TextTransform.h"

class CutTransform : public TextTransform
{
public:
	void invokeOn(std::string& text, int startIndex, int endIndex) override
	{
		lastCut = std::string(text, startIndex, endIndex - startIndex);
		text.erase(startIndex, endIndex - startIndex);
	}

	std::string getLastCut() const
	{
		return lastCut;
	}

private:
	std::string lastCut;
};

#endif // CUT_TRANSFORM_H
