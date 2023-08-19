#ifndef PASTE_TRANSFORM_H
#define PASTE_TRANSFORM_H

#include "CutTransform.h"

class PasteTransform : public TextTransform
{
public:
	PasteTransform(std::shared_ptr<CutTransform> cutTransform)
		: m_cutTransform(cutTransform) {}

	void invokeOn(std::string& text, int startIndex, int endIndex) override
	{
		text.replace(startIndex, endIndex - startIndex, m_cutTransform->getLastCut());
	}

private:
	std::shared_ptr<CutTransform> m_cutTransform;

};

#endif // PASTE_TRANSFORM_H
