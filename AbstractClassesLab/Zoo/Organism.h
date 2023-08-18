#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>
#include <utility>

#include "Position.h"

class Organism {
public:
	Organism(std::string strName, const Position& pos)
		: name(std::move(strName)), position(pos) {}

	virtual std::string getImage() const = 0;

	virtual void act() = 0;

	Position getPosition() const {
		return this->position;
	}

protected:
	std::string name;
	Position position;
	
};

#endif // !ORGANISM_H

