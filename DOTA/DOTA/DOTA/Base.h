#ifndef Base_h
#define Base_h

#include <iostream>
#include <cassert>

class Base {
private:
	// Do?
public:
	// Possibly group together again, change array accordingly
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

	struct Shrine { // Get actual name if incorrect!
		short health = 500;
		const short goldToGive = 100;
		Shrine() = default;
		~Shrine() = default;
	};

	std::string baseName = "Radiant Base";
	short ancientHealth = 7000; // Check this value to dictate if game is over or not
	MeleeBarracks mB[3];
	RangedBarracks rB[3];
	//Shrine[3];
	Base(const std::string name, const int health) // Change health depending on gamemode
		:baseName(name), ancientHealth(health)
	{
		assert(ancientHealth != 0);
	}
	void InitialiseBase();
	void checkBarracks(MeleeBarracks &m, RangedBarracks &r); // Check whether mega creeps can spawn | Use array!!!!
	~Base() = default;
};

#endif