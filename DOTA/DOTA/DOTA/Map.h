#ifndef Map_h
#define Map_h

struct Map {
	short timeOfDay = 0; // Convert to M:S
	bool m_RoshUp = false, isNight = true; // Remove from nightStalker??
	std::vector<Hero> radiantTeam{}, direTeam{};
	Map() = default;
	~Map() = default;
	short GetTime() {
		if(timeOfDay % 5 == 0) // Do better!
			if(!isNight)
				isNight = true;
			else
				isNight = false;
		switch(isNight) { // Check!
			case false: std::cout << "It is currently DAY\n"; break;
			case true: std::cout << "It is currently NIGHT\n"; break;
		}
		return timeOfDay; 
	}
	short GetClock() const { return timeOfDay; }
};

#endif