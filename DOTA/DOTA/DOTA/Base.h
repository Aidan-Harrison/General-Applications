#ifndef Base_h
#define Base_h

#include <iostream>

class Base {
private:
public:
	std::string baseName = "Radiant Base";
	short ancientHealth = 5000; // Check this value to dictate if game is over or not
	//Barracks[3]; // 3 sets of 2
	//Shrine[3];
	Base(std::string name)
		:baseName(name)
	{
	}
	void InitialiseBase();
	void checkBarracks(); // Check whether mega creeps can spawn
	~Base() = default;
};

struct Barracks { // Probably not the best
	struct MeleeBarracks {
		short health = 1000;
		bool isDestroyed = false;
		MeleeBarracks() = default;
		~MeleeBarracks() = default;
	};
	struct RangedBarracks {
		short health = 1000;
		bool isDestroyed = false;
		RangedBarracks() = default;
		~RangedBarracks() = default;
	};
};

struct Shrine {
	short health = 500;
	const short goldToGive = 100;
	Shrine() = default;
	~Shrine() = default;
};

#endif