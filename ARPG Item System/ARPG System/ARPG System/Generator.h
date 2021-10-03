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
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Strapped", "Rugged", "Crafted", "Handmade", "Fitted", "Crude", "Heavy", "Light"};
}
namespace BeltPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Strapped", "Rugged", "Crafted", "Handmade", "Fitted", "Crude", "Heavy", "Light", "Prestine"};
}
namespace RingPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Shaped", "Prestine", "Forged", "Crafted", "Exqusite", "Flawless", "Cracked", "Chipped", "Crude", "Pure"};
}
namespace BowPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Shaped", "Prestine", "Forged", "Crafted", "Exqusite", "Flawless", "Nimble", "Swift"};
}
namespace StaffPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Shaped", "Prestine", "Forged", "Crafted", "Exqusite", "Flawless", "Conjured", "Infused"};
}
namespace ShieldPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Shaped", "Prestine", "Forged", "Crafted", "Exqusite", "Flawless", "Sturdy", "Heavy", "Light"};
}
namespace HelmetPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Shaped", "Prestine", "Forged", "Crafted", "Exqusite", "Flawless", "Sturdy", "Heavy", "Light"};
}
namespace AmuletPrefixNames {
	std::vector<std::string> prefixes{"", "Worn", "Blessed", "Shaped", "Prestine", "Forged", "Crafted", "Exqusite", "Flawless", "Cracked", "Chipped", "Pure"};
}

// Bases
namespace SwordBaseNames {
	std::vector<std::string> bases{"Damascus Steel Sword", "Iron Sword", "Serrated Sword", "Twisted Sword", "Spiral Sword", "Katana", "Plate Sword", "Scimitar", "Falchion", "Rapier"};
}
namespace BootsBaseNames {
	std::vector<std::string> bases{"Leather Boots", "Steel Greaves", "Silk Slippers", "Paladin Greaves", "Rag Shoes", "Woven Treads", "Studded Boots", "Steelcapped Boots"};
}
namespace ChestBaseNames {
	std::vector<std::string> bases{"Leather Armor", "Paladins Plate", "Silk Robes", "Rag Cloth", "Sun Plate", "Spiked Mail"};
}
namespace BeltBaseNames {
	std::vector<std::string> bases{"Leather Belt", "Chain Belt", "Silk Sash", "Gladiator Belt", "Champion Belt", "Voodoo Cloth"};
}
namespace RingBaseNames {
	std::vector<std::string> bases{"Gold Ring", "Ruby Ring", "Emerald Ring", "Sapphire Ring", "Diamond Ring", "Onyx Ring", "Mahogany Ring", "Jade Ring", "Amythest Ring", "Topaz Ring"};
}
namespace BowBaseNames {
	std::vector<std::string> bases{"Wooden Bow", "Siege Bow", "War Bow"};
}
namespace StaffBaseNames {
	std::vector<std::string> bases{"Wooden Staff", "Ivory Staff", "Onyx Staff", "Iron War Staff", "Royal Staff"};
}
namespace ShieldBaseNames {
	std::vector<std::string> bases{"Wooden Buckler", "Tower Shield", "Gladiator Shield", "Cestus", "Kite Shield"};
}
namespace HelmetBaseNames {
	std::vector<std::string> bases{"Leather Cap", "Knights Helm", "Templar Helmet", "Champions Helmet", "Gladiators Helm", "Silk Headband", "Driftwood Circlet"};
}
namespace AmuletBaseNames {
	std::vector<std::string> bases{"Emerald Amulet", "Topaz Skull Amulet", "Rabbits Foot", "Jade Amulet", "Aquamarine Necklace", "Ruby Necklace", "Gold Amulet"};
}

// Suffixes | Applies to all
namespace SuffixNames {
	std::vector<std::string> nameSuffixes{"of Lothric", "of Torment", "of Agony", "of Prosperity", "of Justice", "of the Church", "of the Saints", "of the Abyss", "of Nothing", "of Everything", "of Torture", "of the Elders",
										  "of the Lessers", "of the Primordial"};
}

// Thresholds | Anything greater then max value = max tier
namespace SwordThresholds {
	int thresholds[4] = {5,10,15,20};
}

namespace BootThresholds {
	int thresholds[4] = {5,10,15,20};
}