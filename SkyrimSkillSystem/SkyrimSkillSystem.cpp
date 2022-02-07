#include <unordered_map>

#include "Player.h"

// Destructors are being called!
// Fix memory management

/*
void PrintSkillTree(SkillNode *n) {
    std::cout << n->nodeName << "->";
    n->isPrinted = true;
    for(auto i : n->children)
        if(!i->isPrinted)
            PrintSkillTree(i);
    putchar('\n');
}
*/

void Interface(Player &p) {
    std::cout << "=====SKYRIM=====\n";
    p.PrintStats();
    p.SkillMenu();
    std::cout << "Select a skill to modify: ";
    int choice;
    std::cin >> choice;
    system("cls");
    switch (choice) {
        case 1: p.m_Skills[0]->PrintSkillTree(p.m_Skills[0]->rootNode); break;
        case 2: p.m_Skills[1]->PrintSkillTree(p.m_Skills[1]->rootNode); break;
        default: p.m_Skills[0]->PrintSkillTree(p.m_Skills[0]->rootNode); break;
    }
}

void Setup() {
    Alteration *s_Alt = new Alteration;
    Conjuration *s_Con = new Conjuration;

    // New Test:
    



    // s_Con->PrintSkillTree(s_Con->rootNode);

    // std::array<Skill*, 2> skills{s_Alt, s_Con};

    // Player p(skills, 100);

    // Interface(p);
}

int main() {
    Setup();

    return 0;
}