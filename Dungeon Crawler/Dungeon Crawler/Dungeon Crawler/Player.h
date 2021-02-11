#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <conio.h>

class Player {
private:
public:
	enum direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
	direction dir;
	bool hasKey = false;
	short m_Health = 100;
	short playerX = 6, playerY = 4;
	std::vector<std::string> inventory{};
	Player() = default;
	Player(short health);
	void Input();
	void Logic();
	void Kill(Player &player);
};

#endif