#include "Setup.h"

// Based off traditional zombies design, few perks, a lot of weapons and gums!

// Name | Cost | Health | Damage | Unique
namespace PerkSetup { // Their are only a few perks, so don't need to be heap allocated initially, only when created for a player
	Perks QuickRevive("Quick Revive",500,   0,  0, true);
	Perks Juggernaut ("Juggernaut", 2500, 100,  0, false);
	Perks DoubleTap  ("Double-Tap", 2000,   0, 10, false);
	Perks SpeedCola  ("Speed-Cola", 3000,   0,  0, false);
	Perks MuleKick   ("Mule-Kick",  4000,   0,  0, true);
	Perks WidowsWine ("WidowsWine", 3500,   0,  0, true);
	Perks StaminaUp  ("Stamina-Up", 2500,   0,  0, false);
};

// Their could be 100+ weapons and gums, so we heap allocate 
// Name | Damage | Range | Weight | Ammo | Unique
namespace WeaponSetup { 
	Weapon *FiveSeven  = new Weapon("Five-Seven", 20, 10, 1,  75, false);
	Weapon *Olympus    = new Weapon("Olympus",    20,  5, 3,  48, false);
	Weapon *RPK	       = new Weapon("RPK",        20, 10, 4, 250, false);
	Weapon *Raygun     = new Weapon("Ray-Gun",    50, 10, 4, 250, true);
	Weapon *Thundergun = new Weapon("Thundergun", 20, 10, 4,  25, true);
};
// Name
namespace GumSetup {
	Gum *PerkAHolic   = new Gum("Perk-A-Holic",  3, "Legendary");
	Gum *FastHands    = new Gum("Fast-Hands",    1, "Common");
	Gum *AvoidZombies = new Gum("Avoid-Zombies", 1, "Common");
};