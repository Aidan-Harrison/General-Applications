#ifndef Item_h
#define Item_h

#include <iostream>
#include <SFML/Graphics.hpp>

class Item {
private:
	std::string m_ItemName = "";
	sf::RectangleShape body; // Change for image
public:
	Item(const std::string &name) 
		:m_ItemName(name)
	{
		body.setSize(sf::Vector2f(15.0f,15.0f));
	}
	~Item() = default;
	std::string GetName() const { return m_ItemName; }
};

#endif