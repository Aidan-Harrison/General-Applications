#ifndef Player_h
#define Player_h

#include <vector>
#include "Setup.h"

struct Player {
	short points = 500, maxWeapons = 3;
	short m_Health, m_Stamina, m_Damage, m_ReloadSpeed, m_MaxPerkCount = 4;
	bool canSelfRevive = false, isInvisible = false;
	std::vector<Perks> perkInventory{};
	std::vector<Weapon> weaponInventory{};
	std::vector<Gum> gumInventory{};
	Player(short health = 100, short stamina = 100, short damage = 10, short reloadSpeed = 5)
		:m_Health(health), m_Stamina(stamina), m_Damage(damage), m_ReloadSpeed(reloadSpeed)
	{
		assert(m_Health != 0 && m_Stamina != 0 && m_Damage != 0 && m_ReloadSpeed != 0);
	}

	~Player() = default;
	void AddPerk(short perk);
	void AddWeapon(short weapon);
	void AddGum(short gum);
	void PrintStats();
	void DeletePlayer(Player* p);
};

#endif