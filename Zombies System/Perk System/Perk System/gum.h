#ifndef gum_h
#define gum_h

#include <iostream>

struct Gum {
	std::string m_Name = " ";
	short m_Rarity = 0;
	enum rarity{COMMON = 0, RARE, EPIC, LEGENDARY};
	Gum() = default;
	Gum(std::string name, short rare)
		:m_Name(name), m_Rarity(rare)
	{
		assert(m_Name != " ");
	}
	~Gum() = default;
};

#endif
