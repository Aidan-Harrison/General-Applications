#ifndef Tree_h
#define Tree_h

#include "SFML/Graphics.hpp"
// #include "Collision.h"

std::vector<std::string> fruitNames{};

struct fruit {
	int health = 100;
	int col = 255;
	sf::RectangleShape rect;
	std::string name = "";
	fruit() 
	{
		health = rand() % 25;
		health += 10;

		rect.setFillColor(sf::Color::Red);
		rect.setSize(sf::Vector2f(15.0f, 15.0f));
		rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
	}

	void Generate();
	void Decay(); // Quality of fruit decreases and eventually deletes

	void Draw(sf::RenderWindow &window);

	~fruit() {}
};

void fruit::Generate() {
	int nameIndex = rand() % fruitNames.size();
	name = fruitNames[nameIndex];
}

void fruit::Decay() {
	health--;
	rect.setFillColor(sf::Color(col--,0,0,255));
	//if (health <= 0)
		// delete this;
}

void fruit::Draw(sf::RenderWindow &window) {
	window.draw(rect);
}

struct Tree {
	int chance = 0;
	int age = 0;
	int decayCol = 0, lifeCol = 255;
	sf::RectangleShape rect;
	std::vector<fruit*> droppedFruits{};
	Tree(const int screenWidth, const int screenHeight) 
	{
		rect.setFillColor(sf::Color::Green);
		rect.setSize(sf::Vector2f(35.0f, 35.0f));
		rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);

		int sW = rand() % screenWidth;
		int sH = rand() % screenHeight;
		rect.setPosition(sW, sH);
	}

	void Advance(); // Spawns fruit
	void Draw(sf::RenderWindow& window);

	~Tree() {}
};

void Tree::Advance() {
	age++; // Change tree colour
	rect.setFillColor(sf::Color(decayCol++,lifeCol--,0,255));
	// Add deletion
	chance = rand() % 50;
	chance++;
	// Low chance to drop fruit
	if (chance > 49) {
		fruit* newFruit = new fruit;
		int dir = rand() % 4;
		dir++;
		switch (dir) {
			case 1: newFruit->rect.setPosition(sf::Vector2f(rect.getPosition().x - 40.0f, rect.getPosition().y - 40.0f)); break;
			case 2: newFruit->rect.setPosition(sf::Vector2f(rect.getPosition().x + 40.0f, rect.getPosition().y - 40.0f)); break;
			case 3: newFruit->rect.setPosition(sf::Vector2f(rect.getPosition().x - 40.0f, rect.getPosition().y - 40.0f)); break;
			case 4: newFruit->rect.setPosition(sf::Vector2f(rect.getPosition().x - 40.0f, rect.getPosition().y + 40.0f)); break;
		}
		droppedFruits.push_back(newFruit);
	}
}

void Tree::Draw(sf::RenderWindow& window) {
	window.draw(rect);
	for (auto i : droppedFruits) {
		window.draw(i->rect);
		i->Decay();
	}
}

#endif
