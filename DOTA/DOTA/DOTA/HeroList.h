#ifndef HeroList_h
#define HeroList_h

#include "Hero.h"

// Heap allocate!

/*
* KEY: =====================================================
* HERO: NAME, HEALTH, MANA, DAMAGE, MOVE SPEED, ATTACK RANGE
* ABILITY: NAME, MANA COST, COOLDOWN, PASSIVE
*/

// Assign abilities to respective heroes
namespace Heroes {
// Riki ===============================
	Hero Riki{"Riki", 550, 225, 75, 300, 400, 1};
		Ability smokeScreen{"Smoke Screen", 50, 25, false}; // Do which ability it is! (Enum)
		Ability backStab{"Backstab", 0, 4, true};
		Ability leap{"Leap", 100, 10, false};
		Ability killZone{"Kill-Zone", 175, 80, false};
		std::vector<Ability> rikiAbilities{ smokeScreen, backStab, leap, killZone };
// Sniper =============================
	Hero Sniper{"Sniper", 650, 250, 100, 250, 1250, 1};
		Ability shrapnel{"Shrapnel", 50, 0, false}; // Do which ability it is! (Enum)
		Ability headshot{"Headshot", 0, 0, true};
		Ability takeaim{"Take Aim", 30, 6, true};
		Ability assassinate{"Assassinate", 275, 10, false};
		std::vector<Ability> sniperAbilities{ shrapnel, headshot, takeaim, assassinate };
// Axe ================================
	Hero Axe{ "Axe", 650, 250, 100, 250, 1250, 0};
// Bloodthirster  =====================
	Hero Bloodthirster{ "Bloodthirster", 550, 250, 75, 300, 300, 1};
// Alchemist  =========================
	Hero Alchemist{"Alchemist", 700, 300, 50, 225, 250, 0};
// Nightstalker
	Hero NightStalker{"Nightstalker", 700, 300, 50, 225, 250, 0};
}

std::vector<Hero> heroes {
	Heroes::Alchemist,
	Heroes::Axe,
	Heroes::Bloodthirster,
	Heroes::NightStalker,
	Heroes::Riki,
	Heroes::Sniper
};

#endif