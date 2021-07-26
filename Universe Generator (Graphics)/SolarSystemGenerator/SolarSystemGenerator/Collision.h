#ifndef Collision_h
#define Collision_h

#include <SFML/Graphics.hpp>

// AABB collision

class Collider {
private:
	sf::RectangleShape collider;
public:
	Collider() {}
	~Collider() {}

	bool Detect(Collider &otherCol);
};

bool Collider::Detect(Collider &otherCol) { // All colliders are always Squares, so only one loop
	for (int i = 0; i < otherCol.collider.getSize().x; i++) {
		if (collider.getPosition() == otherCol.collider.getPosition() - otherCol.collider.getSize()) {
			std::cout << "Hit!\n";
			return true;
		}
	}
	return false;
}

#endif
