#ifndef Skills_h
#define Skills_h

#include <iostream>
#include <vector>

struct SkillNode {
    bool isPrinted = false;
    std::string nodeName = "Default Node";
    std::vector<SkillNode*> children{};
    int curLevel = 0;
    int maxLevel;
    SkillNode(const std::string &nName, int mLevel = 4) // Average is 4
        : nodeName(nName), maxLevel(mLevel)
    {
    }

    void AddNode(SkillNode *n);

    ~SkillNode() {}
};  

void SkillNode::AddNode(SkillNode *n) {
    if(!children.size() > 3)
        children.push_back(n);
}

class Skill {
protected:
    std::string skillName = "Default Skill";
    int skillLevel = 0;
public:
    SkillNode *rootNode;
    Skill() = default;
    Skill(SkillNode *newRoot) 
        : rootNode(newRoot)
    {
        std::cout << rootNode->nodeName << '\n';
    }

    void PrintSkillTree(SkillNode *n);
    std::string GetName() const;

    virtual ~Skill() 
    {
        std::cout << "Base skill destroyed!\n";
    }
};

void Skill::PrintSkillTree(SkillNode *n){
    for(auto i : n->children)
        std::cout << i->nodeName << ", ";
    std::cout << n->nodeName << "->";
    n->isPrinted = true;
    for(auto i : n->children) {
        if(!i->isPrinted)
            PrintSkillTree(i);
    }
    putchar('\n');
}

std::string Skill::GetName() const {
    return skillName;
}

struct Alteration : public Skill {
    SkillNode *alterationRoot = new SkillNode("Alteration Root", 2);
    Alteration() 
    {
        // Skill Nodes
        SkillNode *manaEff = new SkillNode("Mana Efficiency", 4);
        SkillNode *spellDamage = new SkillNode("Spell Damage", 4);
        SkillNode *range = new SkillNode("Spell Range", 2);

        alterationRoot->AddNode(manaEff);
        alterationRoot->AddNode(spellDamage);
        alterationRoot->AddNode(range);

        Skill(alterationRoot);
        skillName = "Alteration";
    }
    ~Alteration() 
    {
        std::cout << "Alteration Destroyed!\n";
    }
};

struct Conjuration : public Skill {
    SkillNode *conjurationRoot = new SkillNode("Conjuration Root", 2);
    Conjuration() 
    {
        SkillNode *manaEff = new SkillNode("Mana Efficiency", 4);

        conjurationRoot->AddNode(manaEff);

        Skill(conjurationRoot);
        skillName = "Conjuration";
    }
    ~Conjuration() 
    {
        std::cout << "Conjuration Destroyed!\n";
    }
};

#endif