#include "Item.h"

void Item::Draw(sf::RenderWindow &window) const {
	window.draw(rarityVisual);
	window.draw(rarityText);
	window.draw(itemText);
	// window.draw(img);

	for (unsigned int i = 0; i < implicitStatText.size(); i++) window.draw(implicitStatText[i]);
	for (unsigned int i = 0; i < implicitModText.size(); i++)  window.draw(implicitModText[i]);
	//for (unsigned int i = 0; i < implicitTierText.size(); i++) window.draw(implicitTierText[i]);

	for (unsigned int i = 0; i < prefixStatText.size(); i++) window.draw(prefixStatText[i]);
	for (unsigned int i = 0; i < prefixModText.size(); i++)  window.draw(prefixModText[i]);
	//for (unsigned int i = 0; i < prefixTierText.size(); i++) window.draw(prefixTierText[i]);

	for (unsigned int i = 0; i < suffixStatText.size(); i++) window.draw(suffixStatText[i]);
	for (unsigned int i = 0; i < suffixModText.size(); i++)  window.draw(suffixModText[i]);
	//for (unsigned int i = 0; i < suffixTierText.size(); i++) window.draw(suffixTierText[i]);
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

// Item Independent
void Sword::GenerateStats(std::vector<std::string>& suffixes) {
	GenerateSuffixStats(suffixes);
}
