#ifndef List_h
#define List_h

#include <vector>
#include <iostream>
#include <array>

#include <SFML/Graphics.hpp>

// Get arrow image, set position equal to right side of rectangle
// Set rectangle positions based off of the first position (Offset)

class List {
private:
	sf::Font font;

	int choice = 0;
	sf::Text operationText;
public:
	struct node {
		float xOffset = 0.0f;
		int data = 0;
		sf::RectangleShape rect; // Scale as list gets larger (Reaches certain size)
		sf::Text text;
		sf::Font font; // Move?
		node* next;
		node() :next(nullptr) {};
		node(int d)
			:data(d), next(nullptr)
		{
			if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
				std::cerr << "Failed to load font!\n";
			rect.setSize(sf::Vector2f(50.0f, 50.0f));
			rect.setFillColor(sf::Color::White);
			rect.setOrigin(rect.getSize().x, rect.getSize().y);
			rect.setPosition(xOffset, 300.0f);

			text.setString(std::to_string(data));
			text.setFont(font);
			text.setFillColor(sf::Color::Black);
		}
	};

	std::vector<node> list;
	void AddNode(node* n, int data); // Possibly return node
	void DelNode(node* n);

	void Delete(node *n);

	void Draw(sf::RenderWindow &window);
	void Interface(sf::RenderWindow &window);

	List() // Do!
	{
	}

	~List() {}
};

class dList {
private:
	sf::Font font;

	int choice = 0;
	sf::Text operationText;
public:
	struct dNode {
		int data = 0;
		sf::RectangleShape rect; // Scale as list gets larger (Reaches certain size)
		sf::Text text;
		sf::Font font;
		dNode *prev;
		dNode *next;
		dNode() :prev(nullptr), next(nullptr) {}
		dNode(int d)
			:data(d), prev(nullptr), next(nullptr)
		{
			if (!font.loadFromFile(""))
				std::cerr << "Failed to load font!\n";
			rect.setSize(sf::Vector2f(50.0f, 50.0f));
			rect.setFillColor(sf::Color::White);
			rect.setOrigin(rect.getSize().x, rect.getSize().y);

			text.setString(std::to_string(data));
			text.setFont(font);
			text.setFillColor(sf::Color::Black);
		}
	};

	std::array<dNode*, 10> list; // Check!
	void AddNode(dNode *n, int data); // Possibly return node
	void DelNode(dNode *n);

	void Delete(dNode *n);

	void Draw(sf::RenderWindow& window);
	void Interface(sf::RenderWindow &window);

	dList() 
	{
	}
	~dList() {}
};

#endif