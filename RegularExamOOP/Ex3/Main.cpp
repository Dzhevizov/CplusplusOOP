#include "Noises.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>

int main()
{
	std::string time, noise;
	std::cin >> time >> noise;

	Noises noises;

	while (noise != "TheEnd" && noise != "THEEND" && noise != "theend")
	{
		std::cout << noises.registerNoise(time, noise) << std::endl;

		std::cin >> time >> noise;
	}

	noises.printStatistics(std::cout);

	return 0;
}