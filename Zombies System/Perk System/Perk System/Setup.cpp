#include "Setup.h"

// Name | Cost | Health | Damage | Unique
namespace PerkSetup {
	Perks QuickRevive("Quick Revive",500,   0,  0, true);
	Perks Juggernaut ("Juggernaut", 2500, 100,  0, false);
	Perks DoubleTap  ("Double-Tap", 2000,   0, 10, false);
	Perks SpeedCola  ("Speed-Cola", 3000,   0,  0, false);
	Perks MuleKick   ("Mule-Kick",  4000,   0,  0, true);
	Perks WidowsWine ("WidowsWine", 3500,   0,  0, true);
	Perks StaminaUp  ("Stamina-Up", 2500,   0,  0, false);
};
// Name | Damage | Range | Weight | Ammo | Unique
namespace WeaponSetup {
	Weapon FiveSeven ("Five-Seven", 20, 10, 1,  75, false);
	Weapon Olympus	 ("Olympus",    20,  5, 3,  48, false);
	Weapon RPK	     ("RPK",        20, 10, 4, 250, false);
	Weapon Raygun	 ("Ray-Gun",    50, 10, 4, 250, true);
	Weapon Thundergun("Thundergun", 20, 10, 4,  25, true);
};
// Name
namespace GumSetup {
	Gum PerkAHolic   ("Perk-A-Holic",  3, "Legendary");
	Gum FastHands    ("Fast-Hands",    1, "Common");
	Gum AvoidZombies ("Avoid-Zombies", 1, "Common");
};