#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <SFML/Graphics.hpp>

struct node {
	bool isVisited = false;
	sf::Font font;
	int data = 0;
	sf::Text dText;
	std::vector<node*> children{};
	node() 
	{
		dText.setFont(font);
		dText.setString(std::to_string(data));
	}
	node(int d)
	{
		dText.setFont(font);
		dText.setString(std::to_string(data));
	}
	~node() {}
};

class Graph {
private:
	void Insert(const int key, node *n);
	node* Search(const int key, node *n, const char type);
public:
	node *root;

	std::vector<node> children;
	std::vector<sf::Text> childrenText;
	std::vector<sf::CircleShape> childrenNodes;

	void Insert(const int key);
	void Search(const int key, const char type);

	void Draw(sf::RenderWindow& window);
	void DFS(node *n);

	Graph(const std::vector<int> &data) 
	{
		root = new node(0);

		for (unsigned int i = 0; i < children.size(); i++) {
			childrenNodes[i].setFillColor(sf::Color::White);
			childrenNodes[i].setRadius(50.0f);
			childrenNodes[i].setOrigin(sf::Vector2f(childrenNodes[i].getRadius() / 2, childrenNodes[i].getRadius() / 2));

			childrenText[i].setFont(root->font);
			childrenText[i].setString(std::to_string(children[i].data));
			childrenText[i].setOrigin(childrenText[i].getLocalBounds().width / 2, childrenText[i].getLocalBounds().height / 2);
			childrenText[i].setPosition(childrenNodes[i].getPosition().x, childrenNodes[i].getPosition().y);
		}
	}
	~Graph() {}
};

#endif