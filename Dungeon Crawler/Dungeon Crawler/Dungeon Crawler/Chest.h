#ifndef Chest_h
#define Chest_h

#include <iostream>
#include <vector>

class Chest {
private:
public:
	short chestX = 10, chestY = 6;
	std::vector<std::string> contents{};
	Chest(short x, short y)
		:chestX(x), chestY(y)
	{
	};
	~Chest() = default;
};

#endif