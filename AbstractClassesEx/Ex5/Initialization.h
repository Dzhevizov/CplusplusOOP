#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "AdvancedCommandInterface.h"

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text)
{
	auto interface = std::make_shared<AdvancedCommandInterface>(text);
	interface->init();

	return interface;
}

#endif // INITIALIZATION_H
