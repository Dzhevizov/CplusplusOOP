#include <iostream>

#include "Player.h"
#include "Glock.h"
#include "DesertEagle.h"

void Player::buyPistol(const PistolType pistolType,
	const int        damagePerRound,
	const int        clipSize,
	const int        remainingAmmo)
{
	if (pistolType == PistolType::DESERT_EAGLE)
	{
		_pistol = new DesertEagle(damagePerRound, clipSize, remainingAmmo);
	}
	else if (pistolType == PistolType::GLOCK)
	{
		_pistol = new Glock(damagePerRound, clipSize, remainingAmmo);
	}
	else
	{
		std::cerr << "Received unsupported PistolType: " << static_cast<int>(pistolType) << std::endl;
	}
}
