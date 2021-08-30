#include "Character.h"

void Character::PrintStats(sf::RenderWindow &window) const {
	window.draw(nameGraphics);
}

void Character::PrintMatStash(sf::RenderWindow& window) const {
	for (auto i : materialsStash) {
		i.Draw(window);
	}
}

void Character::GetItemStash() const {
	for(unsigned int i = 0; i <= itemStash->size(); i++)  {
		if(i % 10 == 0)
			putchar('\n');
	}
}