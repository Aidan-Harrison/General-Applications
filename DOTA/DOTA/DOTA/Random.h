#ifndef Random_h
#define Random_h

#include <iostream>
#include <ctime>

// Singleton class | Check!
class Random {
private:
	// Internal generators
	int IInt(int range) {
		srand(time(0)); // Possibly replace
		int value;
		value = rand() % range;
		return value;
	}
	float IFloat(int range) {
		srand(time(0));
		float value;
		value = rand() % range; // Allow for float
		return value;
	}
public:
	Random() {}; // Private constructor | Causing errors (RE-DO)
	int GetInt(int range) { return IInt(range); }
	float GetFloat(int range) { return IFloat(range); } // Check!
};

#endif
