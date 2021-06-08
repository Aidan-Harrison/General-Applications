#include <iostream>
#include <vector>

// Prefixes
namespace SwordPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Sharp", "Blunt", "Refined", "Prestine", "Forged", "Nimble", "Holy", "Corrupted", "Cleansed", "Crude", "Fast"};
}
namespace BootsPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Strapped", "Rugged", "Crafted", "Handmade", "Fitted", "Crude", "Fast", "Heavy", "Light"};
}
namespace ChestPrefixNames {
	std::vector<std::string> prefixes{ "", "Worn", "Blessed", "Strapped", "Rugged", "Crafted", "Handmade", "Fitted", "Crude", "Heavy", "Light" };
}
namespace RingPrefixNames {
	std::vector<std::string> prefixes{ "", "Worn", "Blessed", "Shaped", "Prestine", "Forged", "Crafted", "Exqusite", "Flawless", "Cracked", "Chipped", "Crude", "Pure"};
}

// Bases
namespace SwordBaseNames {
	std::vector<std::string> bases{"Damascus Steel Sword", "Iron Sword", "Serrated Sword", "Curved Sword", "Twisted Sword", "Spiral Sword", "Katana", "Plate Sword", "Scimitar", "Falchion", "Rapier"};
}
namespace BootsBaseNames {
	std::vector<std::string> bases{"Leather Boots", "Steel Greaves", "Silk Slippers", "Paladin Greaves", "Rag Shoes", "Woven Treads", "Studded Boots", "Steelcapped Boots"};
}
namespace RingBaseNames {
	std::vector<std::string> bases{"Gold Ring", "Ruby Ring", "Emerald Ring", "Sapphire Ring", "Diamond Ring", "Onyx Ring", "Mahogany Ring", "Jade Ring", "Amythest Ring"};
}

// Suffixes | Applies to all | Suffixes are rare and generate slightly differently
namespace SuffixNames {
	std::vector<std::string> suffixes{"of Lothric", "of Torment", "of Agony", "of Prosperity", "of Justice", "of the Church", "of the Saints"};
}