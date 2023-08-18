#include <iostream>

#include "Glock.h"

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo)
	: Pistol(damagePerRound, clipSize, remainingAmmo) {}

bool Glock::fire(PlayerVitalData& enemyPlayerData)
{
	const int damageToHealth = _damagePerRound / 2;
	const int damageToArmor = damageToHealth;

	for (int i = 0; i < ROUNDS_PER_FIRE; ++i)
	{
		if (0 == _currClipBullets)
		{
			reload();
			return false;
		}

		--_currClipBullets;

		enemyPlayerData.armor -= damageToArmor;
		if (0 > enemyPlayerData.armor)
		{
			enemyPlayerData.health += enemyPlayerData.armor;
			enemyPlayerData.armor = 0;
		}

		enemyPlayerData.health -= damageToHealth;

		std::cout << "Enemy left with: " << enemyPlayerData.health << " health and "
			<< enemyPlayerData.armor << " armor" << std::endl;

		if (0 >= enemyPlayerData.health)
		{
			return true;
		}
	}
	
	return false;
}