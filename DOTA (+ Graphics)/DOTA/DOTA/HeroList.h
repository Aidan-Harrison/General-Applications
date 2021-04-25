#ifndef HeroList_h
#define HeroList_h

#include "Hero.h"

/*
* KEY: =====================================================
* HERO: NAME, HEALTH, MANA, DAMAGE, MOVE SPEED, ATTACK RANGE
* ABILITY: NAME, MANA COST, COOLDOWN, PASSIVE
*/

// Assign abilities to respective heroes
// Heap allocate, 10 heroes all with items is too much
namespace Heroes {
// Riki ===============================
	Hero *Riki = new Hero{"Riki", 550, 225, 75, 300, 400, 1};
		Ability *smokeScreen = new Ability{"Smoke Screen", 50, 25, false}; // Do which ability it is! (Enum)
		Ability *backStab    = new Ability{"Backstab", 0, 4, true};
		Ability *leap        = new Ability{"Leap", 100, 10, false};
		Ability *killZone    = new Ability{"Kill-Zone", 175, 80, false};
		std::vector<Ability> rikiAbilities{ *smokeScreen, *backStab, *leap, *killZone }; // Remove pointers per index
// Sniper =============================
	Hero *Sniper = new Hero{"Sniper", 650, 250, 100, 250, 1250, 1};
		Ability *shrapnel    = new Ability{"Shrapnel", 50, 0, false};
		Ability *headshot    = new Ability{"Headshot", 0, 0, true};
		Ability *takeaim     = new Ability{"Take Aim", 30, 6, true};
		Ability *assassinate = new Ability{"Assassinate", 275, 10, false};
		std::vector<Ability> sniperAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
// Axe ================================
	Hero *Axe = new Hero{ "Axe", 650, 250, 100, 250, 1250, 0};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> axeAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
// Bloodthirster  =====================
	Hero *Bloodthirster = new Hero{ "Bloodthirster", 550, 250, 75, 300, 300, 1};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> bloodthirsterAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
// Alchemist  =========================
	Hero *Alchemist = new Hero{"Alchemist", 700, 300, 50, 225, 250, 0};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> alchemistAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
// Nightstalker =========================
	Hero *NightStalker = new Hero{"Nightstalker", 700, 300, 50, 225, 250, 0};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> nightstalkerAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
// Sven =========================
	Hero *Sven = new Hero{"Sven", 700, 300, 50, 225, 250, 0};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> svenAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
// Hoodwink =========================
	Hero *Hoodwink = new Hero{"Hoodwink", 700, 300, 50, 225, 250, 0};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> hoodwinkAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
// Lifestealer =========================
	Hero *Lifestealer = new Hero{"Lifestealer", 700, 300, 50, 225, 250, 0};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> lifestealerAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
// Drow Ranger =========================
	Hero *Drowranger = new Hero{"Drow Ranger", 700, 300, 50, 225, 250, 0};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> drowrangerAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
// Wraith King =========================
	Hero *Wraithking = new Hero{"Wraith King", 700, 300, 50, 225, 250, 0};
		/*
			Ability* shrapnel = new Ability{ "Shrapnel", 50, 0, false };
			Ability* headshot = new Ability{ "Headshot", 0, 0, true };
			Ability* takeaim = new Ability{ "Take Aim", 30, 6, true };
			Ability* assassinate = new Ability{ "Assassinate", 275, 10, false };
			std::vector<Ability> wraithkingAbilities{ *shrapnel, *headshot, *takeaim, *assassinate };
		*/
}

// Re-do so pointers do not need to be assigne individually
std::vector<Hero> heroes {
	*Heroes::Alchemist,
	*Heroes::Axe,
	*Heroes::Bloodthirster,
	*Heroes::NightStalker,
	*Heroes::Riki,
	*Heroes::Sniper
};

#endif