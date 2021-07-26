#ifndef Player_h
#define Player_h

#include <vector>
#include "Setup.h"

struct Player { // Make singleton
	int points = 500, maxWeapons = 3;
	int m_Health, m_Stamina, m_Damage, m_ReloadSpeed, m_MaxPerkCount = 4;
	bool canSelfRevive = false, isInvisible = false;
	std::vector<Perks> perkInventory{};
	std::vector<Weapon*> weaponInventory{};
	std::vector<Gum*> gumInventory{};

	Player(int health = 100, int stamina = 100, int damage = 10, int reloadSpeed = 5)
		:m_Health(health), m_Stamina(stamina), m_Damage(damage), m_ReloadSpeed(reloadSpeed)
	{
		assert(m_Health != 0 && m_Stamina != 0 && m_Damage != 0 && m_ReloadSpeed != 0);
	}

	void AddPerk(int perk);
	void AddWeapon(int weapon);
	void AddGum(int gum);
	void PrintStats() const;
	void DeletePlayer(Player* p);

	~Player() {};
};

#endif