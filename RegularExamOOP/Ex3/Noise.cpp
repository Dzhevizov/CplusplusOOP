#include "Noise.h"
#include <sstream>

void Noise::newNoise(size_t time)
{
	last = time;
	number++;
	each = (last - first) / number;
}

std::string Noise::getNewNoiseStatistics(void) const
{
	std::ostringstream oStr;

	if (number == 1)
	{
		oStr << number;
	}
	else
	{
		oStr << number << ", each ";

		if (each <= 1)
			oStr << "minute";
		else
			oStr << each << " minutes";
	}

	return oStr.str();
}

std::string Noise::getFinalStatistics(void) const
{
	std::ostringstream oStr;

	if (number == 1)
		oStr << number << " at " << first;
	else
	{
		oStr << number << ", from " << first << " till " << last << ", each ";

		if (each <= 1)
			oStr << "minute";
		else
			oStr << each << " minutes";
	}
	
	return oStr.str();
}
