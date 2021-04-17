#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <conio.h>

class Player {
private:
	short m_Health = 100;
public:
	enum direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
	direction dir;
	bool hasKey = false;
	short playerX = 6, playerY = 4;
	std::vector<std::string> inventory{};
	Player() = default;
	Player(short health);

	int GetHealth() const { return m_Health; }

	void Input();
	void Logic();
	void Kill();
};

#endif