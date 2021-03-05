#ifndef gum_h
#define gum_h

#include <iostream>

struct Gum {
	std::string m_Name = " ", rarityName = "";
	short m_Rarity = 0;
	enum rarity{COMMON = 0, RARE, EPIC, LEGENDARY};
	Gum() = default;
	Gum(std::string name, short rare, std::string rarity)
		:m_Name(name), m_Rarity(rare), rarityName(rarity)
	{
		assert(m_Name != " " && rarityName != " ");
	}
	~Gum() = default;
};

#endif
