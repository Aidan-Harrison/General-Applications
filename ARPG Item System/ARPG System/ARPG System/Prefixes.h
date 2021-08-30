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

#endif