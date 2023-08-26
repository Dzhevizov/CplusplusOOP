#include "Noises.h"
#include <sstream>

std::string Noises::registerNoise(const std::string& time_, const std::string& noise_)
{
	std::ostringstream oStr;

	size_t time = stringToTime(time_);
	if (noises.find(noise_) == noises.end())
	{
		noises[noise_] = Noise(time);
	}
	else
	{
		noises[noise_].newNoise(time);
	}

	oStr << noise_ << ": " << noises[noise_].getNewNoiseStatistics();

	return oStr.str();
}

void Noises::printStatistics(std::ostream& ostr) const
{
	ostr << "----" << std::endl;

	if (noises.size() == 0)
		ostr << "No noises.";
	else
	{
		for (auto noise : noises)
		{
			ostr << noise.first << ": " << noise.second.getFinalStatistics() << std::endl;
		}
	}

}