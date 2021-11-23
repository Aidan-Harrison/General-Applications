#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <fstream>
#include <set>

#include "Player.h"

// TO_DO:
// Fix certain crafting items and add new ones
// File streaming and moving data to files
    // Add new item content after
// Change mutation system and player constructor to a vector and index one by one to set values
// Improve interface
// Write a solution to stat safety checking to avoid generating the same mods
    // Write a crafting item which breaks this rule and copies an existing stat
// Improve keyboard parser, merge all input to be handled via the parser
// Rarity system

// Typedefs
typedef std::array<std::tuple<int, std::string, int>, 5> itemMods;

namespace Global {
    Keyboard *keyboard;
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
    std::string line;
    if(printContents) {
        std::cout << "======" << filePath << "======\n";
        while(!Global::fileHandler.eof()) {
            Global::fileHandler >> line;
            std::cout << line << '\n'; 
            for(int i = 0; i < line.length(); i++) {
                if(line[i] == ':')
                    std::cout << "BREAKER!\n";
            }
        }
    }
    return true;
}

// Applys global modifiers and tweaks global settings
void MutationModifier() {
    if(FileParser("Mutations.txt", false))  {
        std::cout << "'Mutation.txt' loaded successfully!\n\t" 
                  << "Press ENTER to continue: ";
        std::cin.get();
        std::cin.get();
    } 
    else {
        std::cout << "'Mutations.txt' failed to load, either corrupt or missing!\n";
        return;
    }
    FileParser("Mutations.txt", true); // Expensive but cleaner
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
    std::vector<Player*> allChars{};
}

namespace CraftingItems {
    AgonyOrb aOrb("Agony Orb");
    DivineOrb dOrb("Divine Orb");
    LamentGem lGem("Lament Gem");
    MoltenCore mCor("Molten Core");
    Mirror mir("Mirror");
}

namespace Prefixes {
    std::vector<std::string> gPrefixes{"Seething ", "Lamenting ", "Ridden ", "Prismatic ", "Imbued "};

    // Sword Prefixes
    std::vector<std::string> swPrefixes{"Sharp ", "Forged ", "Heavy ", "Light "};
    std::vector<std::string> axPrefixes{"Large ", "Hardened "};
    std::vector<std::string> shPrefixes{"Sturdy ", "Light ", "Tough "};
}

// Change naming scheme to original system
// tuple {prefix, base, suffix}!
namespace BaseNames{
    // Swords

    // Re-write test:
    // Remove type??
    typedef std::tuple<std::string, int> itemBase;

    itemBase steelLongsword{"Steel Longsword", 1};
    itemBase twistedSword{"Twisted Sword", 1};
    std::vector<itemBase> swordBases{steelLongsword, twistedSword};
    // Axes
    itemBase greatAxe{"Great Axe",2};
    itemBase execAxe{"Executioners Axe",2};
    std::vector<itemBase> axeBases{greatAxe, execAxe};
    // Shields
    itemBase buckler{"Buckler",3};
    itemBase towerShield{"Tower Shield",3};
    std::vector<itemBase> shieldBases{buckler, towerShield};
}

// Seperated for readability
namespace Implicitmods {
    // Swords
    std::string steelLongswordImp[2] = {"Increased Physical Damage", "DEX"};
    std::string twistedSwordImp[2] = {"STR", "Increased Physical Damage Per 10 STR"};
    // Axes
    std::string greatAxeImp[2] = {"Increased Physical Damage", "Increased Attack Range"};
    std::string execAxeImp[2] = {"Chance to Bleed", "Damage over time"};
    // Shields
    std::string bucklerImp[2] = {"Chance to Block", "Damage Reduction"};
    std::string towerShieldImp[2] = {"+20 Increased Health per 10 STR", "+5 Block chance per 20 STR"}; // Add value exceptions??
}

namespace Suffixes {
    std::vector<std::string> suffixes{" of Agony", " of Divinity", " of Hatred", " of Lothric", " of Londo", " of Riches", " of Sanctuary"};   
}

// Handle bases and implicits
namespace Mods {
    
    std::vector<std::string> suffixmods{"Increased Fire Damage", "Increased Cold Damage", "Increased Lightning Damage", "Increased Holy Damage", "Increased Dark Damage", "Increased Void Damage",
    "Increased Poison Damage", "Increased Thunder Damage", "STR", "DEX", "INT", "Increased Dodge Rating", "Increased Evasion Rating", "Increased Movement Speed", "Increased Armor"};    
}

// Move to own file
namespace Uniques {
    Item *testUnique = new Item(std::array<std::string, 3>{"","Test Unique",""});
    Item *testUnique2 = new Item(std::array<std::string, 3>{"","Test Unique 2",""});
    
    std::vector<Item*> uniqueItems{testUnique, testUnique2}; 
}

// Make printing in-line
void PrintItem(Item &item) { // Possibly just move to object?
    switch (item.rarity) {
        case 1: std::cout << "\tCOMMON\n"; break;
        case 2: std::cout << "\tMAGIC\n";  break;
        case 3: std::cout << "\tRARE\n";   break;
        case 4: std::cout << "\tUNIQUE\n"; break;
    }
    std::cout << "//// " << item.m_ItemName[0] << item.m_ItemName[1] << item.m_ItemName[2] << " ////\n";
    std::cout << "\t--" << item.iLevel << "--\n";
    for(int i = 0; i < item.m_Mods.size(); i++) {
        std::cout << "---| " 
                << std::get<0>(item.m_Mods[i]) 
                << " | " << std::get<1>(item.m_Mods[i]) 
                << " | " << std::get<2>(item.m_Mods[i]) 
                << " |---\n";
    }
}

// Also have to handle implicits
void RegenerateType(Item &i) {
    switch(i.type) {
        case 1: {
            Global::choice = rand() % BaseNames::swordBases.size();
            i.m_ItemName[1] = std::get<0>(BaseNames::swordBases[Global::choice]).at(1);
            while(i.m_ItemName[1] == std::get<0>(BaseNames::swordBases[Global::choice])) {
                Global::choice = rand() % BaseNames::swordBases.size();
                i.m_ItemName[1] = std::get<0>(BaseNames::swordBases[Global::choice]).at(1);
            }
            break;
        }
    }
}

// Replace char input with 'Keyboard'
void Pickup(Item &item) {
    bool hasTaken = false;
    char choice = 'a';
    PrintItem(item);
    std::cout << "Do you want to take this item?\n\t (Y/N)\n";
    choice = std::tolower(choice);
    while(choice != 'y' && choice != 'n') {
        std::cout << "Enter: ";
        std::cin >> choice;
    }
    if(choice == 'y') {
        std::cout << "You took " << item.m_ItemName[0] << item.m_ItemName[1] << item.m_ItemName[2] << "!\n";
        // Auto equip if relevent gear slot is empty
        // Check '&'
        for(int i = 0; i < Characters::curPlayer.gear.size(); i++) {
            if(std::get<2>(Characters::curPlayer.gear[i]) && std::get<0>(Characters::curPlayer.gear[i])) { // Do ID matching!
                std::get<1>(Characters::curPlayer.gear[i]) = &item;
                hasTaken = true;
            }
        }
        if(!hasTaken)
            Characters::curPlayer.inventory.push_back(&item);
    }
    else if(choice == 'n')
        Interface();
}

// Make safe, currently able to generate duplicates modifiers
void Generate() { // Return item??
    bool hasTaken = false;
    std::array<std::string, 3> name{};
    itemMods mods;
    int prefix = 0;
    bool hasPrefix = rand() % 2;
    int base = rand() % 3;
    int rarity = rand() % 4; // If unique, generate from unique pool, else just alter stats
    // === ilevel ===
    if(Characters::curPlayer.level > 5)
        Global::choice = rand() % Characters::curPlayer.level - 5;
    else
        Global::choice = rand() % 5;
    Global::choice++;
    int iLevel = Global::choice; // Change! 
    // Rarity
    if(rarity == Item::UNIQUE) {
        Global::choice = rand() % Uniques::uniqueItems.size();
        Pickup(*Uniques::uniqueItems[Global::choice]); // Check!
        return;
    }
    // Set item rarity!
    // === PREFIX === 
    if(hasPrefix) {
        hasPrefix = rand() % 2;
        if(hasPrefix) {
                prefix = rand() % Prefixes::gPrefixes.size(); 
                name[0] = Prefixes::gPrefixes[prefix];
        }
        else {
            switch(base) {
                case 0: {
                    prefix = rand() % Prefixes::swPrefixes.size(); 
                    name[0] = Prefixes::swPrefixes[prefix];
                    break;
                }
                case 1:  {
                    prefix = rand() % Prefixes::axPrefixes.size(); 
                    name[0] = Prefixes::axPrefixes[prefix];
                    break;
                }
                case 2: {
                    prefix = rand() % Prefixes::shPrefixes.size(); 
                    name[0] = Prefixes::shPrefixes[prefix];
                    break;
                }
            }
        }
    }
    // === BASE/IMPLICIT ===
    switch (base) { // Fix implicits?? 
        case 0: {
            base = rand() % BaseNames::swordBases.size(); 
            name[1] = std::get<0>(BaseNames::swordBases[base]);
            // Re-do
            if(name[1] == "Steel Longsword")
                for(int i = 0; i < 2; i++) // Implcit mods
                    std::get<1>(mods[i]) = Implicitmods::steelLongswordImp[i];
            else if(name[1] == "Twisted Sword")
                for(int i = 0; i < 2; i++)
                    std::get<1>(mods[i]) = Implicitmods::twistedSwordImp[i];
            break;
        }
        case 1: {
            base = rand() % BaseNames::axeBases.size(); 
            name[1] = std::get<0>(BaseNames::axeBases[base]);
            if(name[1] == "Great Axe")
                for(int i = 0; i < 2; i++) // Implcit mods
                    std::get<1>(mods[i]) = Implicitmods::greatAxeImp[i];
            else if(name[1] == "Executioners Axe")
                for(int i = 0; i < 2; i++)
                    std::get<1>(mods[i]) = Implicitmods::execAxeImp[i];
            break;
        }
        case 2: {
            base = rand() % BaseNames::shieldBases.size(); 
            name[1] = std::get<0>(BaseNames::shieldBases[base]);
            if(name[1] == "Buckler")
                for(int i = 0; i < 2; i++) // Implcit mods
                    std::get<1>(mods[i]) = Implicitmods::bucklerImp[i];
            else if(name[1] == "Tower Shield")
                for(int i = 0; i < 2; i++)
                    std::get<1>(mods[i]) = Implicitmods::towerShieldImp[i];
            break;   
        }
    }
    int suffix = rand() % Suffixes::suffixes.size(); 
    name[2] = Suffixes::suffixes[suffix];
    // Stat generation
    for(unsigned int i = 0; i < 2; i++) {
        int value = rand() % Mutations::STAT_CAP;
        value++;
        std::get<0>(mods[i]) = value;
    }
    for(unsigned int i = 2; i < mods.size(); i++) { // Implicits are already done
        Global::choice = rand() % Mods::suffixmods.size();
        int value = rand() % Mutations::STAT_CAP;
        value++;
        std::get<1>(mods[i]) = Mods::suffixmods[Global::choice];
        std::get<0>(mods[i]) = value;
    }
    // Tiers
    for(unsigned int i = 0; i < mods.size(); i++) {
        if(std::get<0>(mods[i]) > Mutations::STAT_CAP * 0.75)
            std::get<2>(mods[i]) = 1;
        else if(std::get<0>(mods[i]) < Mutations::STAT_CAP * 0.75 && std::get<0>(mods[i]) > Mutations::STAT_CAP * 0.5)
            std::get<2>(mods[i]) = 2;
        else if(std::get<0>(mods[i]) < Mutations::STAT_CAP * 0.5 && std::get<0>(mods[i]) > Mutations::STAT_CAP * 0.25)
            std::get<2>(mods[i]) = 3;
        else
            std::get<2>(mods[i]) = 4;
    }
    Item newItem(iLevel, name, mods);
    newItem.SafetyCheck(); // Intergrate
    Pickup(newItem);
}

void ChangeGear() { // Format better, have inventory and gear side by side, ncurses?
    int curGearSlot = 0, curInventorySlot = 0;
    Characters::curPlayer.PrintInventory();
    Characters::curPlayer.GearScreen();
    std::cout << "\nPick a slot to change (Or enter '0' to exit):\n";
    std::cin >> Global::choice;
    Global::keyboard->Parse(Global::choice);
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
    std::cout << "Pick an item in your inventory(1) or gear(0) \t Enter 'E' to Exit:\n"; // Reformat!
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
            case 1: tempItem->Apply(CraftingItems::aOrb, Mods::suffixmods); break;
            case 2: tempItem->Apply(CraftingItems::dOrb, Mods::suffixmods); break;
            case 3: tempItem->Apply(CraftingItems::lGem, Mods::suffixmods); break;
            default: tempItem->Apply(CraftingItems::lGem, Mods::suffixmods);break;
        }
    }
    delete tempItem;
}

void Interface() {
    bool isActive = true;
    system("cls");
    std::cout << "===ARPG ITEM SYSTEM LITE===\n" 
              << "\t1) Generate  2) Craft  3) Exit\n";
    while(isActive) {
        std::cout << "Enter: ";
        std::cin >> Global::choice;
        Global::keyboard->Parse(Global::choice); 
        switch(Global::choice) {
            case 0: isActive = false; break;
            case 1: Generate(); break;
            case 2: Craft(); break;
            case 3: exit(0); break;
        }
    }
    system("cls");
    std::cout << "Goodbye!";
    std::cin.get();
    std::cin.get();
    exit(0);
}

void Setup() { // Add file handling here!
    Player *newPlayer = new Player(Mutations::BASE_LEVEL, "Default Player"); // Change how players are handled due to having multiple
    Interface();

    delete newPlayer; // Check!
}

int main() {
    Keyboard keyboardInit;
    Global::keyboard = &keyboardInit;

    srand(time(0));
    Setup();

    return 0;
}