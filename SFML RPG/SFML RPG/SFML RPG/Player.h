#ifndef Player_h
#define Player_h

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include "Item.h"

// Possibly move HUD to another file

class Player {
private:
	std::string playerName = "";
	sf::Text health;
	sf::Text healthValue;
	sf::Text stamina;
	sf::Text staminaValue;
	sf::Font f;
public:
	sf::RectangleShape healthBar;
	sf::RectangleShape staminaBar;
	sf::RectangleShape body; // Change to image, animations
	short m_HP = 100;
	float m_Stamina = 100.0f;
	short movementSpeed = 5.0f;
	bool isSprinting = false;

	Player(const std::string &name = "Player")
		:playerName(name)
	{
		body.setSize(sf::Vector2f(75.0f, 75.0f));
		body.setOrigin(32.5f, 32.5f);

		if (!f.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";

		// Health
		health.setFont(f);
		health.setString("Health:");

		healthValue.setFont(f);
		healthValue.setString(std::to_string(m_HP));
		healthValue.setPosition(100.0f, 0.0f);

		healthBar.setSize(sf::Vector2f(100.0f,15.0f));
		healthBar.setOrigin(-healthBar.getSize().x, healthBar.getSize().y / 2);

		// Stamina
		stamina.setFont(f);
		stamina.setString("Stamina:");
		stamina.setPosition(0.0f, 25.0f);

		staminaValue.setFont(f);
		staminaValue.setString(std::to_string((int)m_Stamina));
		staminaValue.setPosition(115.0f, 25.0f);

		staminaBar.setSize(sf::Vector2f(100.0f, 15.0f));
		staminaBar.setOrigin(-staminaBar.getSize().x, staminaBar.getSize().y / 2);
	};
	~Player() = default;
	std::string GetName() const { return playerName; }
	void DrawUI(sf::RenderWindow &window);
	void Move(sf::RenderWindow &window);
};

#endif