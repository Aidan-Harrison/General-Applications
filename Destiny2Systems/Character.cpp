#include "Character.h"

void Character::Check() {
    switch(curClass) {
        case 1: { 
            className = "Hunter";
            hunterModifier = 3.0f;  
            break;
        }
        case 2: { 
            className = "Titan";
            titanModifier = 3.0f;   
            break;
        }
        case 3: { 
            className = "Warlock";
            warlockModifier = 3.0f; 
            break;
        }
        default: hunterModifier = 3.0f; break;
    }
}

void Character::Interaction() {
    std::cout << "F1) Change Sub Class \t F2) Modify Sub Class \t F3) Change Gear";
    // Replace with function keys ~ Write keyboard parser
    std::cin >> choice;
    switch (choice) {
        case 1: ChangeSubClass(); break;
        case 2: ModifySubClass(); break;
        case 3: ChangeGear(); break;
        case 4: ModifyGear(); break;
    }
}

// Improve format
void Character::DisplayGear() {
    switch (curClass) {
        case 1: std::cout << "Hunter\n";  break;
        case 2: std::cout << "Titan\n";   break;
        case 3: std::cout << "Warlock\n"; break;
    }
    std::cout << "====WEAPONS====\n";
    int counter = 0;
    for(std::unordered_map<int, Weapon>::iterator it = weapons.begin(); it != weapons.end(); it++) {
        std::cout << it->first << " | " << it->second.weaponName << '\n';
        counter++;
        if(counter == 4) // ?
            putchar('\t');
    }
    std::cout << "====STATS====";
    switch (curSubClass) {
        case 1: std::cout << "VOID\n";   break;
        case 2: std::cout << "SOLAR\n";  break;
        case 3: std::cout << "ARC\n";    break;
        case 4: std::cout << "STASIS\n"; break;
    }
    for(unsigned int i = 0; i < 3; i++)
        std::cout << mainStats[i] << '\n';
    std::cout << "====ARMOR====";    
    for(std::unordered_map<int, ArmorPiece>::iterator it = armor.begin(); it != armor.end(); it++) {
        std::cout << it->first << " | " << it->second.armorName << '\n';
    }
}

void Character::ChangeGear() {
    int counter = 0;
    std::cin >> choice;
    // Weaponsi:
    switch (choice) {
        case 1: {
            for(int i = 0; i < wepGearSlotInvent[0].size(); i++)
                std::cout << wepGearSlotInvent[0].at(i)->weaponName;
            break;
        }
    }
    /*
    if(choice == 1) {
        for(unsigned int i = 0; i < wepGearSlotInvent[0].size(); i++) {
            std::cout << wepGearSlotInvent[0].at(i).weaponName;
        }
        std::cin >> choice;
        std::cout << wepGearSlotInvent[0].at(choice).weaponName;
    }
    else if(choice == 2) {
        for(unsigned int i = 0; i < wepGearSlotInvent[1].size(); i++) {
            std::cout << wepGearSlotInvent[1].at(i).weaponName;
        }
        std::cin >> choice;
        std::cout << wepGearSlotInvent[1].at(choice).weaponName;
    }
    else if(choice == 3) {
        for(unsigned int i = 0; i < wepGearSlotInvent[2].size(); i++) {
            std::cout << wepGearSlotInvent[2].at(i).weaponName;
        }
        std::cin >> choice;
        std::cout << wepGearSlotInvent[2].at(choice).weaponName;
    }
    // Armor:
    else if(choice == 4) {
        for(unsigned int i = 0; i < wepGearSlotInvent[3].size(); i++) {
            std::cout << wepGearSlotInvent[3].at(i).weaponName;
        }
        std::cin >> choice;
        std::cout << wepGearSlotInvent[3].at(choice).weaponName;
    }
    else if(choice == 5) {
        for(unsigned int i = 0; i < wepGearSlotInvent[4].size(); i++) {
            std::cout << wepGearSlotInvent[4].at(i).weaponName;
        }
        std::cin >> choice;
        std::cout << wepGearSlotInvent[4].at(choice).weaponName;
    }
    else if(choice == 6) {
        for(unsigned int i = 0; i < wepGearSlotInvent[5].size(); i++) {
            std::cout << wepGearSlotInvent[5].at(i).weaponName;
        }
        std::cin >> choice;
        std::cout << wepGearSlotInvent[5].at(choice).weaponName;
    }
    else if(choice == 7) {
        for(unsigned int i = 0; i < wepGearSlotInvent[6].size(); i++) {
            std::cout << wepGearSlotInvent[6].at(i).weaponName;
        }
        std::cin >> choice;
        std::cout << wepGearSlotInvent[6].at(choice).weaponName;
    }
    // Ghost:
    else if(choice == 8) {
        for(unsigned int i = 0; i < wepGearSlotInvent[7].size(); i++) {
            std::cout << wepGearSlotInvent[7].at(i).weaponName;
        }
        std::cin >> choice;
        std::cout << wepGearSlotInvent[7].at(choice).weaponName;
    }
    */
}

void Character::ModifyGear() {
    std::cin >> choice;
    switch(choice) {
        case 1: weapons[0].Modify(); break;
        case 2: weapons[1].Modify(); break;
        case 3: weapons[2].Modify(); break;
        case 4: armor[3].Modify(); break;
        case 5: armor[4].Modify(); break;
        case 6: armor[5].Modify(); break;
        case 7: armor[6].Modify(); break;
        case 8: armor[7].Modify(); break;
        case 9: armor[8].Modify(); break;
    }
}

// Account for pointers!
template<typename T>
void Character::AddEquipment(T &item, bool PrintDrop = true) {
    if(std::is_same<item, Weapon>) {
        std::cout << "Weapon\n";
        for(unsigned int i = 0; i < c.wepGearSlotInvent[item.slot-1].size(); i++) {
            if(c.wepGearSlotInvent[item.slot-1].at(i) == nullptr)
                c.wepGearSlotInvent[item.slot-1].at(i) = item;
        }
    }
        // Loop through respective gear slots, check available space
        // If none, send to valut
        // If no space in vault send to reserves or just delete
    else if(std::is_same<item, ArmorPiece>) {
        std::cout << "Armor\n";
    }
}

void Character::ChangeSubClass() {
    int choice;
    std::cout << "Pick a new sub-class:\t";
    std::cin >> choice;
    switch(choice) {
        case VOID: curSubClass = VOID;     break;
        case SOLAR: curSubClass = SOLAR;   break;
        case ARC: curSubClass = ARC;       break;
        case STASIS: curSubClass = STASIS; break;
        default: curSubClass = VOID;       break;
    }
}

void Character::ModifySubClass() {
    std::cout << "Pick a ability set:\n";
    std::cin >> choice;
    if(curSubClass == 1) {
        switch (choice) {
            case 1: currentSubClass.curSubSet = currentSubClass.DEFENCE; break;
            case 2: currentSubClass.curSubSet = currentSubClass.POWER;   break;
            case 3: currentSubClass.curSubSet = currentSubClass.UTILITY; break;
        }
    }
}