#include <iostream>

#include "DesertEagle.h"

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo)
	: Pistol(damagePerRound, clipSize, remainingAmmo) {}

bool DesertEagle::fire(PlayerVitalData& enemyPlayerData)
{
	if (0 == _currClipBullets)
	{
		reload();
		return false;
	}

	--_currClipBullets;

	const int damageToHealth = (_damagePerRound * 3) / 4;
	const int damageToArmor = _damagePerRound - damageToHealth;

	enemyPlayerData.armor -= damageToArmor;
	if (0 > enemyPlayerData.armor)
	{
		enemyPlayerData.health += enemyPlayerData.armor;
		enemyPlayerData.armor = 0;
	}

	enemyPlayerData.health -= damageToHealth;

	std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " 
		<< enemyPlayerData.armor << " armor" << std::endl;

	if (0 < enemyPlayerData.health)
	{
		return false;
	}

	return true;
}