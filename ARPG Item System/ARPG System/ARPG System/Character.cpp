#include "Character.h"

template<typename STAT_TEMP>
void Character<STAT_TEMP>::SetStats() {
	stats.push_back(health);
	stats.push_back(mana);
	stats.push_back(STR);
	stats.push_back(DEX);
	stats.push_back(INT);
	stats.push_back(attackSpeed);
	stats.push_back(moveSpeed);
	stats.push_back(physRes);
	stats.push_back(fireRes);
	stats.push_back(coldRes);
	stats.push_back(lightningRes);
	stats.push_back(chaosRes);
	stats.push_back(poisonRes);

	for (unsigned int i = 0; i < stats.size(); i++) {
		statsText[i].setString(std::to_string(stats[i]));
	}
}

template<typename STAT_TEMP>
void Character<STAT_TEMP>::SetInventory() {
	float xPos = 0.0f;
	float yPos = 0.0f;
	int counter = 0;
	for (std::unordered_map<int, Item>::iterator it; it != itemStashMap.end(); it++) {
		if(!it->second.stashSet)
			it->second.itemPrevBack.setPosition(xPos, yPos);
		it->second.stashSet = true;
		xPos += 50.0f;
		counter++;
		if (counter == 10) {
			counter = 0;
			xPos = 0;
			yPos += 90.0f;
		}
	}
}

template<typename STAT_TEMP>
void Character<STAT_TEMP>::PrintStats(sf::RenderWindow &window) const {
	window.draw(nameGraphics);
}

template<typename STAT_TEMP>
void Character<STAT_TEMP>::PrintItemStash(sf::RenderWindow &window) const {
	for (std::unordered_map<int, Item>::iterator it; it != itemStashMap.end(); it++) {
		it->second.StashDraw(window);
	}
}

template<typename STAT_TEMP>
void Character<STAT_TEMP>::PrintMatStash(sf::RenderWindow& window) const {
	for (auto i : materialsStash) {
		i.Draw(window);
	}
}

template<typename STAT_TEMP>
void Character<STAT_TEMP>::SortInventory() {
}

template<typename STAT_TEMP>
void Character<STAT_TEMP>::GetItemStash() const {
	for(unsigned int i = 0; i <= itemStash.size(); i++)  {
		if(i % 10 == 0)
			putchar('\n');
	}
}

template<typename STAT_TEMP>
void Character<STAT_TEMP>::SearchItemStash(std::string &search) {
	if (itemStash.size() == 0) {
		std::cout << "Stash is empty!\n";
		return;
	}
	for (std::unordered_map<int, Item>::iterator it; it != itemStashMap.end(); it++) {
		if (it->second.itemName.find(search)) {
			std::cout << "Found!\n";
			it->second.itemPrevBack.setOutlineColor(sf::Color::White);
			it->second.itemPrevBack.setOutlineThickness(5.0f);
		}
	}
}