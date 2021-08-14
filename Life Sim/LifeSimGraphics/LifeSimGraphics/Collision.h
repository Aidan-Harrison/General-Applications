#ifndef Collision_h
#define Collision_h

#include <SFML/Graphics.hpp>

class Collision {
private:
public:
	sf::RectangleShape col;
	bool Check(Collision& otherCol);
	Collision(const float x, const float y, const sf::Vector2f &pos) // Position as well!
	{
		col.setSize(sf::Vector2f(x, y));
	}

	~Collision() {}
};

bool Collision::Check(Collision &otherCol) {
	if (col.getPosition().x < otherCol.col.getPosition().x + otherCol.col.getSize().x && col.getSize().x + otherCol.col.getSize().x > otherCol.col.getPosition().x
		&& col.getPosition().y < otherCol.col.getPosition().y + otherCol.col.getSize().y && col.getSize().y + otherCol.col.getSize().y > otherCol.col.getPosition().y) {
		return true;
	}
}

#endif
