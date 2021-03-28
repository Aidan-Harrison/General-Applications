#include "Item.h"
#include "Hero.h"

// Heap alloc?

namespace Items { // Extern!
	Item mantaStyle{"Manta Style", 2750, "Allows you to spawn clones"};
	Item blinkDagger{"Blink Dagger", 2500, "Allows you to blink to a location"};
	// PostHaste postHaste{"PostHaste", 3000, "Allows you to teleport anywhere"}; // Do constructor
}

namespace Heroes { // Extern!
	// Riki ===============================
	Hero Riki{"Riki", 550, 225, 75, 300, 400};
		Ability smokeScreen{"Smoke Screen", 50, false}; // Do which ability it is! (Enum)
		Ability backStab{"Backstab", 0, true};
		Ability leap{ "Leap", 100, false };
		Ability killZone{ "Kill-Zone", 175, false };
	Hero Sniper{"Sniper", 650, 250, 100, 250, 1250};
}