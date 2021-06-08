#ifndef Base_h
#define Base_h

#include <iostream>
#include <cassert>
#include <array>

class Base {
private:
	std::string baseName = "Radiant Base";
	bool meleeBuffed = false, rangeBuffed = false, hasMega = false;
public:
	// Possibly group together again, change array accordingly
	struct MeleeBarracks {
		int health = 1000;
		bool isDestroyed = false;
		MeleeBarracks() = default;
		~MeleeBarracks() = default;
	};
	struct RangedBarracks {
		int health = 1000;
		bool isDestroyed = false;
		RangedBarracks() = default;
		~RangedBarracks() = default;
	};

	struct Shrine { // Get actual name if incorrect!
		int health = 500;
		const int goldToGive = 100;
		Shrine() = default;
		~Shrine() = default;
	};
	int ancientHealth = 5000; // Check this value to dictate if game is over or not
	std::array<MeleeBarracks, 3>  MeleeBarracksList{};
	std::array<RangedBarracks, 3> RangedBarracksList{};
	//Shrine[3];
	Base() = default;
	Base(const std::string name, const int health) // Change health depending on gamemode
		:baseName(name), ancientHealth(health)
	{
		assert(ancientHealth != 0);
	}
	void InitialiseBase();
	void checkBarracks(std::array<MeleeBarracks, 3> &m, std::array<RangedBarracks, 3> &r); // Check whether mega creeps can spawn | Use array!!!!
	~Base() = default;
};

#endif