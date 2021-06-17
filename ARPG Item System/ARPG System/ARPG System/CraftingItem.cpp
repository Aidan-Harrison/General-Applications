#include "CraftingItem.h"

void AgonyOrb::Use(Item *i) {
	delete i;
	RollItem();
}

void PerfectionOrb::Use(Item *i) {
	i->rarity++;
	if(i->rarity >= 4)
		i->rarity = 4;
}

void LamentGem::Use(Item *i) {
	// Removes a random suffix
	int choice = rand() % 3; // Get suffix size, removing will reduce options
	choice++;
	i->suffixValues[0] = 0; // Check!
	i->suffixStatText[choice].setString("");
	i->suffixModText[choice].setString("");
	i->suffixTierText[choice].setString("");
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