#include "Setup.h"

// Name | Health | Damage
namespace PerkSetup {
	Perks Juggernaut("Juggernaut", 100, 0);
	Perks DoubleTap("Double-Tap", 0, 10);
	Perks SpeedCola("Speed-Cola", 0, 0);
	Perks MuleKick("Mule-Kick", 0, 0);
};
// Name | Damage | Range | Weight
namespace WeaponSetup {
	Weapon FiveSeven("Five-Seven", 20, 10, 1, 75);
	Weapon Olympus("Olympus", 20, 10, 3, 24);
	Weapon RPK("RPK", 20, 10, 4, 250);
};