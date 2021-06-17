#include "Item.h"

void Item::Draw(sf::RenderWindow &window) const {
	window.draw(itemText);
	window.draw(img);

	for (unsigned int i = 0; i < implicitStatText.size(); i++) window.draw(implicitStatText[i]);
	for (unsigned int i = 0; i < implicitModText.size(); i++)  window.draw(implicitModText[i]);
	for (unsigned int i = 0; i < implicitTierText.size(); i++) window.draw(implicitTierText[i]);

	for (unsigned int i = 0; i < prefixStatText.size(); i++) window.draw(prefixStatText[i]);
	for (unsigned int i = 0; i < prefixModText.size(); i++)  window.draw(prefixModText[i]);
	for (unsigned int i = 0; i < prefixTierText.size(); i++) window.draw(prefixTierText[i]);

	for (unsigned int i = 0; i < suffixStatText.size(); i++) window.draw(suffixStatText[i]);
	for (unsigned int i = 0; i < suffixModText.size(); i++)  window.draw(suffixModText[i]);
	for (unsigned int i = 0; i < suffixTierText.size(); i++) window.draw(suffixTierText[i]);
}

void Item::GenerateSuffixStats(std::vector<std::string> &suffixes) { // Do stats better
	int choice = 0;
	choice = rand() % suffixes.size();
	suffixMods[0] = suffixes[choice];
	suffixModText[0].setString(suffixes[choice]);
	choice = rand() % 75;
	choice++;
	suffixStatText[0].setString(std::to_string(choice));
	choice = rand() % suffixes.size();
	suffixMods[1] = suffixes[choice];
	suffixModText[1].setString(suffixes[choice]);
	choice = rand() % 75;
	choice++;
	suffixStatText[1].setString(std::to_string(choice));
	choice = rand() % suffixes.size();
	suffixMods[2] = suffixes[choice];
	suffixModText[2].setString(suffixes[choice]);
	choice = rand() % 75;
	choice++;
	suffixStatText[2].setString(std::to_string(choice));
}

void Item::GenerateStats(std::vector<std::string> &suffixes) { // Change!
	return;
}

// Item Independent
void Sword::GenerateStats(std::vector<std::string>& suffixes) {
	int choice = 0;
	implicitMods[0] = "Sword Test 1";
	implicitModText[0].setString(implicitMods[0]);
	implicitMods[1] = "Sword Test 2";
	implicitModText[1].setString(implicitMods[1]);

	// Check base
	if (itemName.find("Damascus Steel Sword") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		implicitStatText[0].setString(std::to_string(choice = rand() % 25)); // Check!
		implicitModText[1].setString("crit chance");
		implicitStatText[1].setString(std::to_string(choice = rand() % 25));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Iron Sword") != std::string::npos) {
		implicitModText[0].setString("extra attack speed");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit multi");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Serrated Sword") != std::string::npos) {
		implicitModText[0].setString("bleed chance");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("damage dealt over time");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Scimitar") != std::string::npos) {
		implicitModText[0].setString("extra attack speed");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("dexterity");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Twisted Sword") != std::string::npos) {
		implicitModText[0].setString("strength"); // +
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("health"); // +
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Spiral Sword") != std::string::npos) {
		implicitModText[0].setString("pierce rating");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit-multi");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Katana") != std::string::npos) {
		implicitModText[0].setString("attack range");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("multi strike chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Plate Sword") != std::string::npos) {
		implicitModText[0].setString("block chance"); // %
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("increased armor");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Falchion") != std::string::npos) {
		implicitModText[0].setString("dodge rating");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("movement speed");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Rapier") != std::string::npos) {
		implicitModText[0].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit multi");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	GenerateSuffixStats(suffixes);
}

void Boots::GenerateStats(std::vector<std::string>& suffixes) {
	int choice = 0;
	implicitMods[0] = "Boots Test 1";
	implicitModText[0].setString(implicitMods[0]);
	implicitMods[1] = "Boots Test 2";
	implicitModText[1].setString(implicitMods[1]);

	if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("movement speed");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("dodge rating");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Steel Greaves") != std::string::npos) {
		implicitModText[0].setString("armor");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("block rating");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Silk Slippers") != std::string::npos) {
		implicitModText[0].setString("INT");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("mana");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Paladain Greaves") != std::string::npos) {
		implicitModText[0].setString("STR");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("physical resistance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Rag Shoes") != std::string::npos) {
		implicitModText[0].setString("DEX");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crown control reduction");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Woven Treads") != std::string::npos) {
		implicitModText[0].setString("movement ability cooldown reduction");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("reduced mana usage");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Studded Boots") != std::string::npos) {
		implicitModText[0].setString("damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("damage reflect");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Steelcapped Boots") != std::string::npos) {
		implicitModText[0].setString("movement speed");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("more armor"); // % based
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	GenerateSuffixStats(suffixes);
}

void Ring::GenerateStats(std::vector<std::string>& suffixes) {
	int choice = 0;
	implicitMods[0] = "Ring Test 1";
	implicitModText[0].setString(implicitMods[0]);
	implicitMods[1] = "Ring Test 2";
	implicitModText[1].setString(implicitMods[1]);

	if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	GenerateSuffixStats(suffixes);
}

void Amulet::GenerateStats(std::vector<std::string>& suffixes) {
	int choice = 0;
	implicitMods[0] = "Ring Test 1";
	implicitModText[0].setString(implicitMods[0]);
	implicitMods[1] = "Ring Test 2";
	implicitModText[1].setString(implicitMods[1]);

	if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	GenerateSuffixStats(suffixes);
}

void Chest::GenerateStats(std::vector<std::string>& suffixes) {
	int choice = 0;
	implicitMods[0] = "Ring Test 1";
	implicitModText[0].setString(implicitMods[0]);
	implicitMods[1] = "Ring Test 2";
	implicitModText[1].setString(implicitMods[1]);

	if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	GenerateSuffixStats(suffixes);
}

void Belt::GenerateStats(std::vector<std::string>& suffixes) {
	int choice = 0;
	implicitMods[0] = "Ring Test 1";
	implicitModText[0].setString(implicitMods[0]);
	implicitMods[1] = "Ring Test 2";
	implicitModText[1].setString(implicitMods[1]);

	if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		choice = rand() % 25;
		implicitStatText[0].setString(std::to_string(choice));
		implicitModText[1].setString("crit chance");
		choice = rand() % 25;
		implicitStatText[1].setString(std::to_string(choice));

		// Implicit Tiers
		if (implicitValues[0] > 20) implicitTierText[0].setString("1");
		else if (implicitValues[0] < 20 && implicitValues[0] > 15) implicitTierText[0].setString("2");
		else if (implicitValues[0] < 15 && implicitValues[0] > 10) implicitTierText[0].setString("3");
		else if (implicitValues[0] < 10 && implicitValues[0] > 5)  implicitTierText[0].setString("4");
		else if (implicitValues[0] < 5) implicitTierText[0].setString("5");

		if (implicitValues[1] > 20) implicitTierText[1].setString("1");
		else if (implicitValues[1] < 20 && implicitValues[1] > 15) implicitTierText[1].setString("2");
		else if (implicitValues[1] < 15 && implicitValues[1] > 10) implicitTierText[1].setString("3");
		else if (implicitValues[1] < 10 && implicitValues[1] > 5)  implicitTierText[1].setString("4");
		else if (implicitValues[1] < 5) implicitTierText[1].setString("5");
	}
	GenerateSuffixStats(suffixes);
}