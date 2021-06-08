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

void Character::GetCraftingStash() const {
	for(unsigned int i = 0; i < materialsStash.size(); i++)  {
		if(i % 10 == 0)
			putchar('\n');
		std::cout << materialsStash[i].itemName << " ";
	}	
}