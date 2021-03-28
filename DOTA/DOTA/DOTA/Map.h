#ifndef Map_h
#define Map_h

struct Map {
	short timeOfDay = 0; // Convert to M:S
	bool m_RoshUp = false, isNight = false; // Move from nightStalker??
	Map() = default;
	~Map() = default;
};

#endif // !Map_h