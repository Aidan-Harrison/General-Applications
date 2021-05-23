#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <cassert>
#include <array>
#include <conio.h>

class Player {
private:
	short m_Health = 100;
public:
	enum direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
	direction dir;
	bool hasKey = false;
	short playerX = 6, playerY = 4;
	std::array<std::string, 6> inventory{};
	Player() = default;
	Player(const short health, const std::array<std::string, 6> &startInvent);

	inline short GetHealth() const { return m_Health; }
	void PrintStats() const;

	void Input();
	void Logic();
	void Kill();
};

#endif