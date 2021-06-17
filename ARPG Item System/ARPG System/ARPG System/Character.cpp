#include "Character.h"

void Character::PrintStats(sf::RenderWindow &window) const {
	window.draw(nameGraphics);
}

void Character::GetItemStash() const {
	for(unsigned int i = 0; i <= itemStash->size(); i++)  {
		if(i % 10 == 0)
			putchar('\n');
	}
}

void Character::GetCraftingStash(sf::RenderWindow& window) const {
	float offset = 25.0f;
	for(unsigned int i = 0; i < materialsStash.size(); i++)  {
		materialsStash[i].Draw(window, offset);
		offset += 25.0f;
	}	
}