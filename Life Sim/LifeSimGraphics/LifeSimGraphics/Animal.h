#ifndef Animal_h
#define Animal_h

#include <iostream>
#include <unordered_map>
#include "Collision.h"

struct Animal {
	std::vector<std::string> names{"Kiki", "Butch", "Gojira", "Orga"}; // Convert to namespace or .txt file. Don't want to be creating this much memory | Force unique names
	enum direction{LEFT, RIGHT, UP, DOWN};
	int dir = 0;

	// Stats
	std::string name = "Default";
	sf::Font font;
	sf::Text nameText;
	int health = 0;
	float moveSpeed = 1.0f;
	
	// SFML
	sf::RectangleShape rect;
	sf::RectangleShape fVector;
	sf::CircleShape detectRad;
	float positionX = 0.0f, positionY = 0.0f;

	Collision* collider = new Collision(25.0f, 25.0f, rect.getPosition());

	Animal() {}
	Animal(int h, sf::Vector2f &pos) 
		:health(h) 
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";

		positionX = pos.x;
		positionY = pos.y;

		rect.setSize(sf::Vector2f(25.0f,25.0f));
		rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
		rect.setFillColor(sf::Color(255,165,0,255));
		rect.setPosition(positionX, positionY);

		fVector.setFillColor(sf::Color::Red);
		fVector.setSize(sf::Vector2f(5.0f, 35.0f));
		fVector.setOrigin(fVector.getSize().x/2, fVector.getSize().y - fVector.getSize().y);
		fVector.setPosition(rect.getPosition().x, rect.getPosition().y);

		// Detection radius
		detectRad.setFillColor(sf::Color(105,105,105,15));
		detectRad.setRadius(5.0f);
		detectRad.setPosition(rect.getPosition().x, rect.getPosition().y);
		detectRad.setOrigin(detectRad.getRadius()/2, detectRad.getRadius()/2);

		// Text | Add option to hide
		nameText.setFont(font);
		// Check existing
		std::unordered_map<std::string, int> namesMap{};
		for (auto i : names)
			namesMap[i];

		nameText.setFillColor(sf::Color::White);
		nameText.setOrigin(nameText.getLocalBounds().width / 2, nameText.getLocalBounds().height - nameText.getLocalBounds().height);

		Generate();
	}
	~Animal() 
	{
		std::cout << "Deleted!\n";
	}

	void Generate();
	void Roam(const float screenWidth, const float screenHeight, std::vector<Animal*> &otherAnimals);
	void Draw(sf::RenderWindow& window, bool drawText);
};

struct Bird : public Animal {
	Bird(int h, sf::Vector2f& pos)
	{
		Animal(h, pos);
	}
	~Bird() {}
};

struct Fox : public Animal {
	Fox(int h, sf::Vector2f& pos)
	{
		Animal(h, pos);
	}
	~Fox() {}
};

#endif