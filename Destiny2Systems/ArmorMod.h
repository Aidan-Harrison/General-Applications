#ifndef ArmorMod_h
#define ArmorMod_h

#include <iostream>

struct ArmorMod {
    enum MODTYPE{UTILITY = 1, GENERAL}; // Get actual mod types from wiki
    enum RARITY{COMMON = 1, RARE, LEGENDARY};
    std::string modName = "";
    int rarity = 1;
    int modValue = 0;
    int type = 0;
    ArmorMod() {}
    ArmorMod(const std::string &name, const int rar) 
        :modName(name)
    {
        switch(rar) {
            case COMMON: 
                rarity = 1; 
                modName.append("(COMMON)");
                break;
            case RARE:
                rarity = 2; 
                modName.append("(RARE)");
                break;
            case LEGENDARY:
                rarity = 3; 
                modName.append("(LEGENDARY)");
                break;
        }
    }
    ~ArmorMod() {}
};

void InitialiseMods() { // Get cpp linking functioning in VS Code, run from main function
}

#endif