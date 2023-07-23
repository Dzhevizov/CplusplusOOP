#include "Echo.h"

bool echoOn = false;

void echo(std::string strString)
{
	if (echoOn)
		std::cout << strString << std::endl;
}
