#include <map>
#include <cassert>
#include <ctime>
#include <array>
#include <string>
#include <fstream>

// Add file streaming
#include "Player.h"
#include "CraftingItem.h"

namespace Global {
    int choice = 0;
    std::fstream fileHandler;   
}

namespace Mutations {
    int STAT_CAP = 100;
    int INVENTORY_SIZE = 20;
    int BASE_LEVEL = 1; // Defines the starting level of a newly created character
}

// Change from 'Player' to 'Character'
void Interface();

bool FileParser(const std::string &filePath, bool printContents) {
    if(filePath.length() == 0) {
        std::cerr << "File path is empty!\n";
        return false;
    }
    Global::fileHandler.open(filePath);
    if(printContents) {
        std::cout << "======" << filePath << "======\n";
        while(!Global::fileHandler.eof()) {
            // Print contents
        }
    }
    return true;
}

// Applys global modifiers and tweaks global settings
void MutationModifier() {
    if(FileParser("Mutation.txt", false))  {
        std::cout << "'Mutation.txt' loaded successfully!\n\t" 
                  << "Press ENTER to continue: ";
        std::cin.get();
        std::cin.get();
    } 
    else {
        std::cout << "'Mutation.txt' failed to load, either corrupt or missing!\n";
        return;
    }
    FileParser("Mutation.txt", true); // Expensive but cleaner
}

void FileSystem() {
    std::cout << "===FILE DATA===\n";
    // Open all files and print core data
    std::cout << "Select a file to modify:\n\t";
    std::cout << "1) Characters  2) Items  3) Mutation\n";
    std::cout << "Enter: ";
    std::cin >> Global::choice;
}

// --------------------------------------

namespace Characters {
    Player curPlayer; // Pointer
}

namespace CraftingItems {
    AgonyOrb aOrb("Agony Orb");
    DivineOrb dOrb("Divine Orb");
    LamentGem lGem("Lament Gem");
    MoltenCore mCor("Molten Core");
}

namespace Prefixes {
    std::vector<std::string> gPrefixes{"Seething ", "Lamenting ", "Ridden ", "Prismatic ", "Imbued "};
}

namespace BaseNames{
    // Swords
    std::tuple<std::string,int,int,int> steelLongsword{"Steel Longsword", 15, 15, 1};
    std::tuple<std::string,int,int,int> twistedSword{"Twisted Sword", 15, 15, 1};
    std::vector<std::tuple<std::string,int,int,int>> swordBases{steelLongsword, twistedSword};
    // Axes
    std::tuple<std::string,int,int,int> greatAxe{"Great Axe", 15, 15, 2};
    std::tuple<std::string,int,int,int> execAxe{"Executioners Axe", 15, 15, 2};
    std::vector<std::tuple<std::string,int,int,int>> axeBases{greatAxe, execAxe};
    // Shields
    std::tuple<std::string,int,int,int> buckler{"Buckler", 15, 15, 3};
    std::tuple<std::string,int,int,int> towerShield{"Tower Shield", 15, 15, 3};
    std::vector<std::tuple<std::string,int,int,int>> shieldBases{buckler, towerShield};
}

namespace Suffixes {
    std::vector<std::string> suffixes{" of Agony", " of Divinity", " of Hatred", " of Lothric", " of Londo", " of Riches"};   
}

// Handle bases and implicits
namespace Stats {
    std::vector<std::string> suffixStats{"Increased Fire Damage", "Increased Cold Damage", "Increased Lightning Damage", "Increased Holy Damage", "Increased Dark Damage", "Increased Void Damage",
    "Increased Poison Damage", "Increased Thunder Damage", "STR", "DEX", "INT", "Increased Dodge Rating", "Increased Evasion Rating", "Increased Movement Speed", "Increased Armor"};    
}

// Make printing in-line
void PrintItem(Item &item) { // Possibly just move to object?
    std::cout << "//// " << item.m_ItemName << " ////\n";
    std::cout << "\t--" << item.iLevel << "--\n";
    for(int i = 0; i < item.m_Stats.size(); i++) {
        std::cout << "---| " 
                  << std::get<0>(item.m_Stats[i]) 
                  << " | " << std::get<1>(item.m_Stats[i]) 
                  << " | " << std::get<2>(item.m_Stats[i]) 
                  << " |---\n";
    }
}

Item* Generate() {
    bool hasTaken = false;
    char choice = 0; // ?
    std::tuple<std::string,int,int,int> core;
    std::string baseName = "";
    int prefix = 0;
    bool hasPrefix = rand() % 2;
    int base = rand() % 3;
    // === ilevel ===
    if(Characters::curPlayer.level > 5)
        Global::choice = rand() % Characters::curPlayer.level - 5;
    else
        Global::choice = rand() % 5;
    Global::choice++;
    int iLevel = Global::choice; // ? Messy
    // === PREFIX === 
    if(hasPrefix) {
        prefix = rand() % Prefixes::gPrefixes.size();
        baseName += Prefixes::gPrefixes[prefix];
    }
    // === BASE/IMPLICIT ===
    switch (base) {
        case 0: {
            base = rand() % BaseNames::swordBases.size(); 
            baseName += std::get<0>(BaseNames::swordBases[base]);
            break;
        }
        case 1: {
            base = rand() % BaseNames::axeBases.size(); 
            baseName += std::get<0>(BaseNames::axeBases[base]);
            break;
        }
        case 2: {
            base = rand() % BaseNames::shieldBases.size(); 
            baseName += std::get<0>(BaseNames::shieldBases[base]);
            break;   
        }
    }
    int suffix = rand() % Suffixes::suffixes.size();
    std::get<0>(core) = baseName += Suffixes::suffixes[suffix];
    std::array<std::tuple<std::string, int, int>, 5> stats;
    // Stat generation
    for(unsigned int i = 0; i < stats.size(); i++) {
        choice = rand() % Stats::suffixStats.size();
        int value = rand() % Mutations::STAT_CAP;
        value++;
        std::get<0>(stats[i]) = Stats::suffixStats[choice];
        std::get<1>(stats[i]) = value;
        if(value > 75) // Do calculations to scale with STAT_CAP
            std::get<2>(stats[i]) = 1;
        else if(value < 75 && value > 50)
            std::get<2>(stats[i]) = 2;
        else if(value < 50 && value > 25)
            std::get<2>(stats[i]) = 3;
        else
            std::get<2>(stats[i]) = 4;
    }
    Item *newItem = new Item(iLevel, core, stats);
    PrintItem(*newItem);
    std::cout << "Do you want to take this item?\n\t (Y/N)\n";
    std::cout << "Enter: ";
    std::cin >> choice;
    choice = std::tolower(choice);
    while(choice != 'y' && choice != 'n') {
        std::cout << "Enter: ";
        std::cin >> choice;
    }
    if(choice == 'y') {
        std::cout << "You took " << newItem->m_ItemName << "!\n";
        // Auto equip if relevent gear slot is empty
        for(int i = 0; i < Characters::curPlayer.gear.size(); i++) {
            if(std::get<2>(Characters::curPlayer.gear[i]) && std::get<0>(Characters::curPlayer.gear[i])) { // Do ID matching!
                std::get<1>(Characters::curPlayer.gear[i]) = newItem;
                hasTaken = true;
            }
        }
        if(!hasTaken)
            Characters::curPlayer.inventory.push_back(newItem);
        return newItem;
    }
    Interface();
    return nullptr; // Check!
}

void ChangeGear() { // Format better, have inventory and gear side by side, ncurses?
    int curGearSlot = 0, curInventorySlot = 0;
    Characters::curPlayer.PrintInventory();
    Characters::curPlayer.GearScreen();
    std::cout << "\nPick a slot to change (Or enter '0' to exit):\n";
    std::cin >> Global::choice;
    if(Global::choice == 0)
        Interface();
    curGearSlot = Global::choice;
    std::cout << "Pick an item (Or enter '0' to clear current gear slot):\n";
    std::cin >> Global::choice;
    if(Global::choice == 0) {
        Characters::curPlayer.inventory.push_back(std::get<1>(Characters::curPlayer.gear[curGearSlot]));
        // Remove item from gear slot! (DO)
    }
    curInventorySlot = Global::choice;
    std::get<1>(Characters::curPlayer.gear[curGearSlot]) = Characters::curPlayer.inventory[curInventorySlot];
}

void Craft() { // Remove tempItem?? | Messy but safe
    if(Characters::curPlayer.inventory.size() == 0 && Characters::curPlayer.gear.size() == 0) {
        std::cout << "You have no items to craft, generate some\n";
        std::cout << "\tPress ENTER to continue: ";
        std::cin.get();
        std::cin.get();
        Interface();
    }
    system("cls");
    Characters::curPlayer.PrintInventory();
    std::cout << "============================\n";
    Characters::curPlayer.GearScreen();
    Item *tempItem;
    bool isInvent = false;
    bool isCrafting = true;
    std::cout << "Pick an item in your inventory(1) or gear(0):\n"; // Reformat
    std::cin >> Global::choice;
    if(Global::choice == 1)
        isInvent = true;
    std::cin >> Global::choice;
    if(isInvent) {
        while(Characters::curPlayer.inventory[Global::choice]->isCorrupted) {
            std::cout << "This item is corrupted!\n";
            std::cin >> Global::choice;
        }
        tempItem = Characters::curPlayer.inventory[Global::choice];
    }
    else {
        while(std::get<1>(Characters::curPlayer.gear[Global::choice])->isCorrupted) {
            std::cout << "This item is corrupted!\n";
            std::cin >> Global::choice;
        }
        tempItem = std::get<1>(Characters::curPlayer.gear[Global::choice]);
    }
    // Crafting
    while(isCrafting) {
        system("cls");
        PrintItem(*tempItem);
        std::cout << "Apply any of the following crafting items:\n";
        std::cout << "1) Agony Orb  2) Divine Orb  3) Lament Gem\n";
        std::cin >> Global::choice;
        switch(Global::choice) {
            case 0: isCrafting = false; break;
            case 1: tempItem->Apply(CraftingItems::aOrb, Stats::suffixStats); break;
            case 2: tempItem->Apply(CraftingItems::dOrb, Stats::suffixStats); break;
            case 3: tempItem->Apply(CraftingItems::lGem, Stats::suffixStats); break;
            default: tempItem->Apply(CraftingItems::lGem, Stats::suffixStats);break;
        }
    }
    delete tempItem;
}

void Interface() {
    bool isActive = true;
    system("cls");
    std::cout << "===ARPG ITEM SYSTEM LITE===\n" 
              << "\t1) Generate  2) Craft\n";
    while(isActive) {
        std::cout << "Enter: "; 
        std::cin >> Global::choice;
        switch(Global::choice) {
            case 0: isActive = false; break;
            case 1: Generate(); break;
            case 2: Craft(); break;
            case 3: FileSystem(); break;
        }
    }
    system("cls");
    std::cout << "Goodbye!";
    std::cin.get();
    std::cin.get();
    exit(0);
}

void Setup() { // Add file handling here!
    Player *newPlayer = new Player(); // Change how players are handled due to having multiple
    Interface();
}

int main() {
    srand(time(0));
    Setup();

    return 0;
}