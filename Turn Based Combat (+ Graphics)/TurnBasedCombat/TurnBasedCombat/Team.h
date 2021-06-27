#ifndef Team_h
#define Team_h

#include "Ally.h"

class AllyTeam {
private:
	sf::RectangleShape inventoryBackground;
	sf::Text header;
public:
	bool teamWiped = false;
	float invSizeX = 250.0f;
	float invSizeY = 300.0f;
	std::string teamName = "";
	std::array<Ally, 3> aTeam;
	AllyTeam(const std::string &name, std::vector<Ally> &allies)
		:teamName(name)
	{
		for (unsigned int i = 0; i < 3; i++)
			aTeam[i] = allies[i];

		inventoryBackground.setFillColor(sf::Color::Blue);
		inventoryBackground.setSize(sf::Vector2f(invSizeX, invSizeY));
		inventoryBackground.setOrigin(invSizeX / 2, invSizeY / 2);
		inventoryBackground.setPosition(100.0f, 200.0f); // Get screen size
		header.setString("INVENTORY");


	}
	~AllyTeam() = default;
	void GetTeam() const;

	void DisplayInventory(sf::RenderWindow &window) const;

	void DrawTeam(sf::RenderWindow &window);
};

class EnemyTeam {
private:
	bool teamWiped = false;
public:
	std::array<Enemy, 5> eTeam;
	EnemyTeam(const short amount, std::vector<Enemy> &enemies) 
	{
		for (unsigned int i = 0; i < amount; i++)
			eTeam[i] = enemies[i];
	} 
	~EnemyTeam() = default;

	void GetTeam() const;
	void DrawTeam(sf::RenderWindow& window);
};

#endif