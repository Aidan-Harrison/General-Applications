#ifndef Tree_h
#define Tree_h

#include <SFML/Graphics.hpp>

struct tNode {
	int data = 0;
	bool isVisited = false;
	sf::Text dataText;
	sf::CircleShape circle;
	tNode* lChild = nullptr;
	tNode* rChild = nullptr;
	tNode() {}
	tNode(int d, sf::Vector2f pos, bool left = true) 
	{
		circle.setFillColor(sf::Color::Green);
		circle.setRadius(25.0f);
		circle.setOrigin(circle.getRadius()/2, circle.getRadius()/2);
		if(left)
			circle.setPosition(pos.x - 50.0f, pos.y - 50.0f);
		else
			circle.setPosition(pos.x + 50.0f, pos.y - 50.0f);
	}
	~tNode() {}
};

struct Tree {
	sf::Vector2f rootPos;

	tNode* root;

	Tree(const int screenWidth, const int screenHeight) 
	{
		rootPos.x = screenWidth / 2;
		rootPos.y = screenHeight / 2;
	}

	void DFS(tNode *n);
	void Draw(sf::RenderWindow &window);

	~Tree() {}
};

#endif