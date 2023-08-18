#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <thread>
#include <chrono>

#include "RenderingUtils.h"
#include "Organism.h"
#include "Cat.h"
#include "Mouse.h"

const int WORLD_SIZE = 30;

int Position::MinPosition = 0;
int Position::MaxPosition = WORLD_SIZE - 1;

typedef std::vector<std::unique_ptr<Organism>> Organisms;

class ZooLoader
{
public:
	ZooLoader() = delete;

	static Organisms generateOrganisms()
	{
		Organisms organisms;
		organisms.push_back(std::make_unique<Cat>(Position(0, 0)));
		organisms.push_back(std::make_unique<Mouse>(Position(1, 1)));

		return organisms;
	}
};

int main() {
	Renderer r(WORLD_SIZE);

	auto organisms = ZooLoader::generateOrganisms();
	
	while (true) {
		for (auto& organism : organisms)
		{
			organism->act();
		}

		for (const auto& organism : organisms)
		{
			r.render(organism->getPosition(), organism->getImage());
		}
		r.flushToScreen();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;
}