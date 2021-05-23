#ifndef Tower_h
#define Tower_h

#include <cassert>

class Tower {
private:
	const short attackRange = 2000;
	short damage = 10, health = 2500;
public:
	const std::string m_Type = " "; // Dictates what level of tower it is, front, mid, base, ancient
	const int m_TeamID = 1; // 1 = Radiant, 2 = Dire
	Tower() = default;
	Tower(const std::string type, const int team)
		:m_Type(type), m_TeamID(team)
	{
		assert(m_TeamID != 0);
	}
	~Tower() = default;
};

#endif