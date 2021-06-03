#include "Team.h"

void AllyTeam::GetTeam() const {
	// Prints team members names and stats
	for (unsigned int i = 0; i < aTeam.size(); i++) {
		std::cout << aTeam[i].m_Name << '\n';
		std::cout << aTeam[i].m_Health << '\n';
		std::cout << aTeam[i].m_Mana << '\n';
		std::cout << "=======================\n";
	}
}

void AllyTeam::DisplayInventory(sf::RenderWindow &window) const {
	window.draw(inventoryBackground);
}

void EnemyTeam::GetTeam() const {
	for (unsigned int i = 0; i < eTeam.size(); i++) {
		std::cout << eTeam[i].m_Name << '\n';
		std::cout << eTeam[i].m_Health << '\n';
	}
}