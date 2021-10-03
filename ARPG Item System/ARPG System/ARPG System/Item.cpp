#include "Item.h"

void Item::Draw(sf::RenderWindow &window) const {
	window.draw(rarityVisual);
	window.draw(rarityText);
	window.draw(itemText);
	// window.draw(img);

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

void Item::StashDraw(sf::RenderWindow &window) const {
	window.draw(itemPrevBack);
	window.draw(itemPreview);
}

void Sword::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Damascus Steel Sword") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		implicitModText[1].setString("crit chance");
	}
	else if (itemName.find("Iron Sword") != std::string::npos) {
		implicitModText[0].setString("extra attack speed");
		implicitModText[1].setString("crit multi");
	}
	else if (itemName.find("Serrated Sword") != std::string::npos) {
		implicitModText[0].setString("bleed chance");
		implicitModText[1].setString("damage dealt over time");
	}
	else if (itemName.find("Scimitar") != std::string::npos) {
		implicitModText[0].setString("extra attack speed");
		implicitModText[1].setString("dexterity");
	}
	else if (itemName.find("Twisted Sword") != std::string::npos) {
		implicitModText[0].setString("strength"); // +
		implicitModText[1].setString("health"); // +
	}
	else if (itemName.find("Spiral Sword") != std::string::npos) {
		implicitModText[0].setString("pierce rating");
		implicitModText[1].setString("crit-multi");
	}
	else if (itemName.find("Katana") != std::string::npos) {
		implicitModText[0].setString("attack range");
		implicitModText[1].setString("multi strike chance");
	}
	else if (itemName.find("Plate Sword") != std::string::npos) {
		implicitModText[0].setString("block chance"); // %
		implicitModText[1].setString("increased armor");
	}
	else if (itemName.find("Falchion") != std::string::npos) {
		implicitModText[0].setString("dodge rating");
		implicitModText[1].setString("movement speed");
	}
	else if (itemName.find("Rapier") != std::string::npos) {
		implicitModText[0].setString("crit chance");
		implicitModText[1].setString("crit multi");
	}
	for (unsigned int j = 0; j < implicitStatText.size(); j++)
		implicitStatText[j].setString(std::to_string(choice = rand() % 100));
	for (unsigned int j = 0; j < 4; j++) { // Fix!
		if (implicitValues[0] > thresholds[j]) implicitTierText[0].setString(j);
		if (implicitValues[1] > thresholds[j]) implicitTierText[1].setString(j);
	}
}

void Boots::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("movement speed");
		implicitModText[1].setString("dodge rating");
	}
	else if (itemName.find("Steel Greaves") != std::string::npos) {
		implicitModText[0].setString("armor");
		implicitModText[1].setString("block rating");
	}
	else if (itemName.find("Silk Slippers") != std::string::npos) {
		implicitModText[0].setString("INT");
		implicitModText[1].setString("mana");
	}
	else if (itemName.find("Paladain Greaves") != std::string::npos) {
		implicitModText[0].setString("STR");
		implicitModText[1].setString("physical resistance");
	}
	else if (itemName.find("Rag Shoes") != std::string::npos) {
		implicitModText[0].setString("DEX");
		implicitModText[1].setString("crown control reduction");
	}
	else if (itemName.find("Woven Treads") != std::string::npos) {
		implicitModText[0].setString("movement ability cooldown reduction");
		implicitModText[1].setString("reduced mana usage");
	}
	else if (itemName.find("Studded Boots") != std::string::npos) {
		implicitModText[0].setString("damage");
		implicitModText[1].setString("damage reflect");
	}
	else if (itemName.find("Steelcapped Boots") != std::string::npos) {
		implicitModText[0].setString("movement speed");
		implicitModText[1].setString("more armor"); // % based
	}
	for (unsigned int j = 0; j < implicitStatText.size(); j++)
		implicitStatText[j].setString(std::to_string(choice = rand() % 100));
	for (unsigned int j = 0; j < 4; j++) {
		if (implicitValues[0] > thresholds[j]) implicitTierText[0].setString(j);
		if (implicitValues[1] > thresholds[j]) implicitTierText[1].setString(j);
	}
}

void Ring::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		implicitModText[1].setString("crit chance");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		implicitModText[1].setString("crit chance");
	}
	else if (itemName.find("Leather Boots") != std::string::npos) {
		implicitModText[0].setString("extra damage");
		implicitModText[1].setString("crit chance");
	}
	for (unsigned int j = 0; j < implicitStatText.size(); j++)
		implicitStatText[j].setString(std::to_string(choice = rand() % 100));
	for (unsigned int j = 0; j < 4; j++) {
		if (implicitValues[0] > thresholds[j]) implicitTierText[0].setString(j);
		if (implicitValues[1] > thresholds[j]) implicitTierText[1].setString(j);
	}
}

void Chest::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Leather Armor") != std::string::npos) {
		implicitModText[0].setString("Increased armor");
		implicitModText[1].setString("STR");
	}
	else if (itemName.find("Paladins Plate") != std::string::npos) { // Significantly more armor
		implicitModText[0].setString("Increased armor");
		implicitModText[1].setString("Light radius");
	}
	else if (itemName.find("Silk Robes") != std::string::npos) {
		implicitModText[0].setString("Increased mana");
		implicitModText[1].setString("Spell damage resistance");
	}
	else if (itemName.find("Rag Cloth") != std::string::npos) {
		implicitModText[0].setString("DEX");
		implicitModText[1].setString("Attack Speed");
	}
}

void Belt::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Leather Armor") != std::string::npos) {
		implicitModText[0].setString("Increased armor");
		implicitModText[1].setString("STR");
	}
	else if (itemName.find("Paladins Plate") != std::string::npos) { // Significantly more armor
		implicitModText[0].setString("Increased armor");
		implicitModText[1].setString("Light radius");
	}
	else if (itemName.find("Silk Robes") != std::string::npos) {
		implicitModText[0].setString("Increased mana");
		implicitModText[1].setString("Spell damage resistance");
	}
	else if (itemName.find("Rag Cloth") != std::string::npos) {
		implicitModText[0].setString("DEX");
		implicitModText[1].setString("Attack Speed");
	}
}

void Bow::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Wooden Bow") != std::string::npos) {
		implicitModText[0].setString("Increased attack speed");
		implicitModText[1].setString("DEX");
	}
	else if (itemName.find("Siege Bow") != std::string::npos) { // Significantly more armor
		implicitModText[0].setString("Increased physical damage");
		implicitModText[1].setString("Increased physical penertration");
	}
	else if (itemName.find("War Bow") != std::string::npos) {
		implicitModText[0].setString("STR");
		implicitModText[1].setString("DEX");
	}
}

void Staff::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Wooden Staff") != std::string::npos) {
		implicitModText[0].setString("Increased attack speed");
		implicitModText[1].setString("Mana reduction");
	}
	else if (itemName.find("Ivory Staff") != std::string::npos) { // Significantly more armor
		implicitModText[0].setString("INT");
		implicitModText[1].setString("Increased spell damage");
	}
	else if (itemName.find("Onyx Staff") != std::string::npos) {
		implicitModText[0].setString("Increased elemental damage");
		implicitModText[1].setString("Increased energy shield");
	}
	else if (itemName.find("Iron War Staff") != std::string::npos) {
		implicitModText[0].setString("Increased Physical damage");
		implicitModText[1].setString("Increased elemental resistance");
	}
	else if (itemName.find("Royal Staff") != std::string::npos) {
		implicitModText[0].setString("Increased item rarity");
		implicitModText[1].setString("STR, DEX & INT");
	}

}

void Helmet::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Leather Cap") != std::string::npos) {
		implicitModText[0].setString("Increased attack speed");
		implicitModText[1].setString("DEX");
	}
	else if (itemName.find("Knights Helm") != std::string::npos) { // Significantly more armor
		implicitModText[0].setString("Increased physical damage");
		implicitModText[1].setString("Increased physical penertration");
	}
	else if (itemName.find("Templar Helmet") != std::string::npos) {
		implicitModText[0].setString("Increased energy shield");
		implicitModText[1].setString("Physical damage converted to holy damage");
	}
	else if (itemName.find("Champions Helmet") != std::string::npos) {
		implicitModText[0].setString("Increased Armor");
		implicitModText[1].setString("Increased health");
	}
	else if (itemName.find("Gladiators Helmet") != std::string::npos) {
		implicitModText[0].setString("STR");
		implicitModText[1].setString("Increased physical damage");
	}
	else if (itemName.find("Silk Headband") != std::string::npos) {
		implicitModText[0].setString("INT");
		implicitModText[1].setString("Increased spell damage");
	}
	else if (itemName.find("Driftwood Circlet") != std::string::npos) {
		implicitModText[0].setString("INT");
		implicitModText[1].setString("Increased mana");
	}
}

void Amulet::GenerateStats(int thresholds[4], int choice) {
	if (itemName.find("Emerald Amulet") != std::string::npos) {
		implicitModText[0].setString("Increased attack speed");
		implicitModText[1].setString("Physical damage converted to poison");
	}
	else if (itemName.find("Topaz Skull Amulet") != std::string::npos) { // Significantly more armor
		implicitModText[0].setString("STR");
		implicitModText[1].setString("Increased fire damage");
	}
	else if (itemName.find("Rabbits Foot") != std::string::npos) {
		implicitModText[0].setString("Increased luck");
		implicitModText[1].setString("Increased movement speed");
	}
	else if (itemName.find("Jade Amulet") != std::string::npos) {
		implicitModText[0].setString("DEX");
		implicitModText[1].setString("Increased dodge rating");
	}
	else if (itemName.find("Aquamarine Necklace") != std::string::npos) {
		implicitModText[0].setString("INT");
		implicitModText[1].setString("Spell damage");
	}
	else if (itemName.find("Ruby Necklace") != std::string::npos) {
		implicitModText[0].setString("Increased health");
		implicitModText[1].setString("Health regeneration");
	}
	else if (itemName.find("Gold Amulet") != std::string::npos) {
		implicitModText[0].setString("Increased item rarity found");
		implicitModText[1].setString("Increased gold found");
	}
}
