#ifndef Chest_h
#define Chest_h

#include <iostream>
#include <vector>

class Chest {
private:
public:
	short chestX = 10, chestY = 6;
	std::vector<std::string> contents{};
	Chest(short x = 5, short y = 5)
		:chestX(x), chestY(y)
	{
	};
	~Chest() = default;
	void Spawn(short x, short y); // Randomises position and contents
};

#endif