#include "Item.h"

void Item::PrintItem(sf::RenderWindow &window) const {
	window.draw(itemText);
	for (unsigned int i = 0; i < statText.size(); i++)
		window.draw(statText[i]);
}

// Sword
void Sword::GenerateStats() {
	int value = 1;
	value = rand() % 101;
	damageModifier = value;
	value = rand() % 101;
	attackSpeedModifier = value;
	value = rand() % 101;
	critMulti = value;
	value = rand() % 51;
	critChance = value;
	value = rand() % 51;
	fireDamage = value;
}