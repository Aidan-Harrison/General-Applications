#ifndef Prefixes_h
#define Prefixes_h

#include <iostream>
#include <vector>

namespace SwordPrefixes {
	std::vector<std::string> prefixes = {"Increased physical damage", "Increased attack range", "Increased pierce", "Increased attack speed"};
}

namespace BootPrefixes {
	std::vector<std::string> prefixes = {"Increased armor"};
}

namespace RingPrefixes {
	std::vector<std::string> prefixes = {"Increased rarity of items found", "Reduced debuff duration"};
}

namespace ChestPrefixes {
	std::vector<std::string> prefixes = {"Increased physical resistance", "Increased armor", "Reflect damage"};
}

namespace BeltPrefixes {
	std::vector<std::string> prefixes = {"Increased physical resistance", "Increased armor", "Increased health"};
}

namespace BowPrefixes {
	std::vector<std::string> prefixes = {"Increased dexterity", "Increased attack speed", "Increased pierce", "Increaed attack range", "DEX"};
}

namespace AmuletPrefixes {
	std::vector<std::string> prefixes = {"Increased item rarity", "Increased amount of gold found", "Increased magic resistance", "INT"};
}

namespace StaffPrefixes {
	std::vector<std::string> prefixes = {"INT", "Physical converted to fire", "Physical converted to cold", "Physical converted to lightning", "Physical converted to poison", "Physical converted to chaos"};
}

#endif