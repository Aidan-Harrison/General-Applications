#ifndef Graph_h
#define Graph_h

#include <iostream>

#include <SFML/Graphics.hpp>

// Add lines!!

class node {
private:
	sf::Font font;
public:
	int data = 0;
	sf::Text dText;
	// Binary
	node* lChild;
	node* rChild;
	node() 
		:lChild(nullptr), rChild(nullptr) 
	{
		// Binary Tree
		dText.setFont(font);
		dText.setString(std::to_string(data));
	}
	node(int d)
		:data(d), lChild(nullptr), rChild(nullptr)
	{
		dText.setFont(font);
		dText.setString(std::to_string(data));
	}
	~node() {}
};

class Graph {
private:
	sf::Font font;

	void Insert(const int key, node *n);
	node* Search(const int key, node *n, const char type);
public:
	node *root;

	std::vector<node> children; // Check!
	std::vector<sf::Text> childrenText;
	std::vector<sf::CircleShape> childrenNodes;

	void Insert(const int key);
	void Search(const int key, const char type);

	void Draw(sf::RenderWindow& window);

	Graph(const std::vector<int> &data) 
	{
		root = new node(0);

		for (unsigned int i = 0; i < children.size(); i++) {
			childrenNodes[i].setFillColor(sf::Color::White);
			childrenNodes[i].setRadius(50.0f);
			childrenNodes[i].setOrigin(sf::Vector2f(childrenNodes[i].getRadius() / 2, childrenNodes[i].getRadius() / 2));

			// Position is the hard part

			childrenText[i].setFont(font);
			childrenText[i].setString(std::to_string(children[i].data));
			childrenText[i].setOrigin(childrenText[i].getLocalBounds().width / 2, childrenText[i].getLocalBounds().height / 2);
			childrenText[i].setPosition(childrenNodes[i].getPosition().x, childrenNodes[i].getPosition().y);
		}
	}
	~Graph() {}
};

#endif