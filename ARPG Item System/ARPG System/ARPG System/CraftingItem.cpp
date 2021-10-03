#include "CraftingItem.h"

void CraftingItem::SetPos(float x, float y) {
	spr.setPosition(x, y);
	debugTex.setPosition(x, y);
	nameText.setPosition(x, y + 75.0f);
}

void CraftingItem::Draw(sf::RenderWindow &window) const {
	// window.draw(spr);
	window.draw(debugTex);
	// window.draw(nameText);
}

void AgonyOrb::Use(Item &i, int thresholds[4], int choice) {
	i.GenerateStats(thresholds, choice);
}

void PerfectionOrb::Use(Item &i, int thresholds[4], int choice) {
	i.rarity++;
	if(i.rarity >= 4)
		i.rarity = 4;
}

void LamentGem::Use(Item &i, int thresholds[4], int choice) { // Re-do this!
	// Removes a random suffix
	choice = rand() % 3; // Get suffix size, removing will reduce options
	choice++;
	i.suffixValues[0] = 0; // Check!
	i.suffixStatText[choice].setString("");
	i.suffixModText[choice].setString("");
	i.suffixTierText[choice].setString("");
}

// Drawing
void AgonyOrb::Draw(sf::RenderWindow& window, float offset) {
	spr.setPosition(sf::Vector2f(offset, 50.0f));
	window.draw(spr);
}

void PerfectionOrb::Draw(sf::RenderWindow& window, float offset) {
	spr.setPosition(sf::Vector2f(offset, 50.0f));
	window.draw(spr);
}

void LamentGem::Draw(sf::RenderWindow& window, float offset) {
	spr.setPosition(sf::Vector2f(offset, 50.0f));
	window.draw(spr);
}