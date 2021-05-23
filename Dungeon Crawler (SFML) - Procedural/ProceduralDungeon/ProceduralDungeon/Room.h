#ifndef Room_h
#define Room_h

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Room {
private:
public:
	sf::RectangleShape m_Room;
	sf::Vector2i left_Pos;
	sf::Vector2i right_Pos;
	sf::Vector2i top_Pos;
	sf::Vector2i bottom_Pos;

	sf::RectangleShape leftDEBUG;
	sf::RectangleShape rightDEBUG;
	sf::RectangleShape topDEBUG;
	sf::RectangleShape bottomDEBUG;

	std::vector<sf::Vector2i> points{left_Pos, right_Pos, top_Pos, bottom_Pos};

	void SetPoints();
	void Initialise();
	void CreateRoom(sf::Vector2i &pointPos);
	void Draw(sf::RenderWindow &window);

	Room(sf::Vector2i &pointPos) 
	{
		CreateRoom(pointPos);
	}

	~Room() = default;
};

#endif