#ifndef Player_h
#define Player_h

#include "Skills.h"
#include <array>

class Player {
private:
    int maxLevel;
public:
    std::unordered_map<std::string, int> stats{{"One-Handed Sword Damage", 100}};
    std::array<Skill*, 2> m_Skills;
    int curLevel = 1;
    Player(std::array<Skill*, 2> &skills, int mLevel = 100) 
        : m_Skills(skills), maxLevel(mLevel)
    {
        for(auto i : m_Skills)
            std::cout << i->GetName();
    }

    void PrintStats() const;
    void SkillMenu();

    ~Player() {}
};

void Player::PrintStats() const {
    std::cout << "===STATS===\n";
}

void Player::SkillMenu() {
    std::cout << "===SKILLS===\n";
    for(unsigned int i = 0; i < m_Skills.size(); i++) {
        std::cout << m_Skills[i]->GetName() << '\t';
        if(i != 0 && i % 5 == 0)
            putchar('\n');
    }
}

#endif