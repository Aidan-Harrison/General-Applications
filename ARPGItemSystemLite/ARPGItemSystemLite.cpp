#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <memory>

#include "Player.h"

// TO_DO:
// Fix certain crafting items and add new ones
// File streaming and moving data to files
    // Add new item content after
// Change mutation system and player constructor to a vector and index one by one to set values
// Improve interface -- WIP
// Write a solution to stat safety checking to avoid generating the same mods
    // Write a crafting item which breaks this rule and copies an existing stat
// Improve keyboard parser, merge all input to be handled via the parser
// Rarity alters amount of mods on item! -- WIP
// Fix item corruption, bricked!
// If item rarity is common, don't generate name suffixes
    // Can do name prefixes

// Typedefs
typedef std::vector<std::tuple<int, std::string, int>> itemMods;
typedef std::array<std::string, 3> itemName;
typedef std::pair<std::string, int> itemBase;

#define _FIRST  std::get<0>
#define _SECOND std::get<1>
#define _THIRD  std::get<2>

namespace Global {
    Keyboard *keyboard = nullptr;
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

void clear_screen() {
    #ifdef _WIN64 
        system("cls");
    #elif __APPLE__ || __MACH__
        system("clear");
    #endif 
}

int random(int range) { return rand() % range; }

int input(const std::string && msg) {
    std::cout << msg;
    std::cin >> Global::choice;
    return Global::choice;
}

bool FileParser(const std::string & filePath, bool printContents) {
    if(filePath.length() == 0) {
        std::cerr << "File path is empty!\n";
        return false;
    }
    Global::fileHandler.open(filePath);
    if(Global::fileHandler.fail()) {
        std::cerr << "Failed to open: " << filePath << " either corrupt or missing\n";
        return false;
    }
    std::string line = "";
    if(printContents) {
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
        std::cout << "'Mutation.txt' loaded successfully!\n" << "\tPress ENTER to continue: ";
        std::cin.get();
        std::cin.get();
    }  else {
        std::cout << "'Mutations.txt' failed to load, either corrupt or missing!\n";
        return;
    }
}

namespace Characters {
    Player * curPlayer;
    std::vector<Player*> allChars{}; // Change, not cache friendly
}

namespace CraftingItems {
    AgonyOrb aOrb;
    DivineOrb dOrb;
    LamentGem lGem;
    MoltenCore mCor;
    Mirror mir;
    ExtensionOrb eOrb;
}

namespace Prefixes {
    using namespace std;
    vector<string> gPrefixes{"Seething ", "Lamenting ", "Ridden ", "Prismatic ", "Imbued "};
    vector<string> swPrefixes{"Sharp ", "Forged ", "Heavy ", "Light "};
    vector<string> axPrefixes{"Large ", "Hardened "};
    vector<string> shPrefixes{"Sturdy ", "Light ", "Tough "};
}

namespace BaseNames{ // Type system pointless?
    using namespace std;
    vector<string> swordBases{"Steel Longsword", "Twisted Sword"};
    vector<string> axeBases{"Great Axe", "Executioners Axe"};
    vector<string> shieldBases{"Buckler", "Tower Shield"};
}

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
    // Sword Prefixes
    using namespace std;
    vector<string> swordPrefixes{"Increased attack speed", "Increased physical damage", "Increased pierce rating"};
    vector<string> axePrefixes{"Increased attack speed", "Increased physical damage", "Increased bleed chance"};

    vector<string> suffixmods{"Increased Fire Damage", "Increased Cold Damage", "Increased Lightning Damage", "Increased Holy Damage", "Increased Dark Damage", "Increased Void Damage",
    "Increased Poison Damage", "Increased Thunder Damage", "STR", "DEX", "INT", "Increased Dodge Rating", "Increased Evasion Rating", "Increased Movement Speed", "Increased Armor", "Increased rarity of items found"};    
}

// Move to own file
namespace Uniques {
    Item * testUnique  = new Item(itemName{"","Test Unique",""}, 4); // Check empty space!
    Item * testUnique2 = new Item(itemName{"","Test Unique 2",""}, 4);
    
    std::vector<Item*> items{testUnique, testUnique2}; 
}

int const KeyboardParser(const int key) {
    switch (key) {
        case 49: break;
        case 50: break;
        case 101: exit(0); break;
    }
    return - 1;
}

void CopyImp(std::string arr1[], std::string arr2[]) {
    for(int i = 0; i < 2; i++)
        arr1[i] = arr2[i];
}

// Make printing in-line
void PrintItem(Item & item) {
    clear_screen();
    switch (item.rarity) {
        case COMMON: std::cout << "\tCOMMON\n"; break;
        case MAGIC:  std::cout << "\tMAGIC\n";  break;
        case RARE:   std::cout << "\tRARE\n";   break;
        case UNIQUE: std::cout << "\tUNIQUE\n"; break;
    }
    std::cout << "//// " << item.m_ItemName[0] << item.m_ItemName[1] << item.m_ItemName[2] << " ////\n";
    std::cout << "\t--" << item.iLevel << "--\n";
    for(int i = 0; i < item.m_Mods.size(); i++) {
        std::cout << "---| " 
                << " | " << _FIRST(item.m_Mods[i]) 
                << " | " << _SECOND(item.m_Mods[i]) 
                << " | " << _THIRD(item.m_Mods[i]) 
                << " |---\n";
    }
}

// Also have to handle implicits
void RegenerateType(Item & i) {
    switch(i.type) {
        case SWORD: {
            i.m_ItemName[1] = BaseNames::swordBases[random(BaseNames::swordBases.size())];
            while(i.m_ItemName[1] == BaseNames::swordBases[Global::choice])
                i.m_ItemName[1] = BaseNames::swordBases[random(BaseNames::swordBases.size())];
            break;
        }
    }
}

void Pickup(Item * item) {
    bool hasTaken = false;
    char choice = 'a';
    PrintItem(*item);
    std::cout << "\nDo you want to take this item?\n\t (Y/N)\n";
    // input("Enter: ");
    std::cin >> choice;
    choice = std::tolower(choice);
    // Handle miss-input!
    if(choice == 'y') {
        std::cout << "You took " << item->m_ItemName[0] << item->m_ItemName[1] << item->m_ItemName[2] << "!\n";
        for(int i = 0; i < Characters::curPlayer->gear.size(); i++) {
            if(Characters::curPlayer->gear[i] == nullptr && Characters::curPlayer->gearID[i] == item->core) { // Empty slot 
                Characters::curPlayer->gear[i] = item;
                hasTaken = true;
                break;
            }
        }
        if(!hasTaken)
            Characters::curPlayer->inventory.push_back(item);
    }
    std::cin.get();
    std::cin.get();
    Interface();
}

// Make safe, currently able to generate duplicate modifiers
void Generate() {
    std::array<std::string, 3> name{};
    itemMods mods;
    int prefix = 0, iLevel = 0;
    bool hasPrefix = rand() % 2, hasSuffix = rand() % 2;
    int base = rand() % 3; // Make automatic?
    base++;
    int rarity = rand() % 100; // If unique, generate from unique pool, else just alter stats and mod count
    int nameSuffixApplied = false;
    // === ilevel ===
    iLevel = rand() % Characters::curPlayer->level - 5;
    iLevel++;
    // Rarity
    if(rarity > 95) { // Unique
        mods.resize(6);
        Pickup(Uniques::items[random(Uniques::items.size())]);
        rarity = UNIQUE;
        return;
    } else if(rarity > 75 && rarity < 95) {
        mods.resize(6);
        rarity = RARE;
    } else if(rarity > 40 && rarity < 75) {
        mods.resize(4);
        rarity = MAGIC;
    } else {
        mods.resize(2);
        rarity = COMMON;
    }
    // === NAME PREFIXES === 
    if(hasPrefix) {
        switch(base) {
            case SWORD: name[0] = Prefixes::swPrefixes[random(Prefixes::swPrefixes.size())]; break; // SWORDS
            case AXE: name[0] = Prefixes::axPrefixes[random(Prefixes::axPrefixes.size())]; break; // AXES
            case SHIELD: name[0] = Prefixes::shPrefixes[random(Prefixes::shPrefixes.size())]; break; // SHIELDS
        }
    }

    // === SET VALUES ===
    for(unsigned int i = 0; i < mods.size(); i++) 
        _FIRST(mods[i]) = random(Mutations::STAT_CAP)+1;

    // === BASE/IMPLICIT ===
    std::string setVec[2] = {"",""};
    std::cout << "Base: " << base << '\n';
    if(base == SWORD) {
        name[1] = BaseNames::swordBases[random(BaseNames::swordBases.size())];
        if(name[1]      == "Steel Longsword")  CopyImp(setVec, Implicitmods::steelLongswordImp);  
        else if(name[1] == "Twisted Sword")    CopyImp(setVec, Implicitmods::twistedSwordImp);
    } else if(base == AXE) { 
        name[1] = BaseNames::axeBases[random(BaseNames::axeBases.size())];
        if(name[1]      == "Great Axe")        CopyImp(setVec, Implicitmods::greatAxeImp);
        else if(name[1] == "Executioners Axe") CopyImp(setVec, Implicitmods::execAxeImp);
    } else if(base == SHIELD) { 
        name[1] = BaseNames::shieldBases[random(BaseNames::shieldBases.size())];
        if(name[1]      == "Buckler")          CopyImp(setVec, Implicitmods::bucklerImp);
        else if(name[1] == "Tower Shield")     CopyImp(setVec, Implicitmods::towerShieldImp);
    }

    for(int i = 0; i < 2; i++) // Set implicits
        _SECOND(mods[i]) = setVec[i];

    for(unsigned int i = 2; i < 4; i++) { // Set prefixes
        using namespace Mods;
        switch(base) {
            case SWORD: _SECOND(mods[i]) = swordPrefixes[random(swordPrefixes.size())]; break;
            case AXE: _SECOND(mods[i]) = axePrefixes[random(axePrefixes.size())]; break;
        }
    }

    for(int i = 4; i < mods.size(); i++) // Set Suffixes
        _SECOND(mods[i]) = Mods::suffixmods[random(Mods::suffixmods.size())];

    // Set last suffix if suffix name modifier | Allow for dynamic size
    if(name[2] == "of Riches")       _SECOND(mods[5]) = "Increased rarity of items found";
    else if(name[2] == "of Lothric") _SECOND(mods[5]) = "Increased fire damage";

    // Tiers
    for(unsigned int i = 0; i < mods.size(); i++) {
        if(_FIRST(mods[i]) > Mutations::STAT_CAP * 0.75)
            _THIRD(mods[i]) = 1;
        else if(_FIRST(mods[i]) < Mutations::STAT_CAP * 0.75 && _FIRST(mods[i]) > Mutations::STAT_CAP * 0.5)
            _THIRD(mods[i]) = 2;
        else if(_FIRST(mods[i]) < Mutations::STAT_CAP * 0.5 && _FIRST(mods[i]) > Mutations::STAT_CAP * 0.25)
            _THIRD(mods[i]) = 3;
        else
            _THIRD(mods[i]) = 4;
    }
    Item newItem(base, rarity, iLevel, name, mods);
    newItem.SafetyCheck(); // Intergrate into constructor and generation
    Pickup(&newItem);
}

void ChangeGear() { // Format better, have inventory and gear side by side, ncurses?
    int curGearSlot = 0, curInventorySlot = 0;
    Characters::curPlayer->PrintInventory();
    Characters::curPlayer->GearScreen();
    std::cout << "\nPick a slot to change (Or enter '0' to exit):\n";
    Global::choice = Global::keyboard->Parse(Global::choice, true);
    // Global::keyboard->Parse(Global::choice);
    if(Global::choice == 0)
        Interface();
    curGearSlot = Global::choice;
    std::cout << "Pick an item (Or enter '0' to clear current gear slot):\n";
    Global::choice = Global::keyboard->Parse(Global::choice, true);
    if(Global::choice == 0) {
        Characters::curPlayer->inventory.push_back(Characters::curPlayer->gear[curGearSlot]);
        // Remove item from gear slot! (DO)
    }
    curInventorySlot = Global::choice;
    Characters::curPlayer->gear[curGearSlot] = Characters::curPlayer->inventory[curInventorySlot];
}

bool SafetyCheck(Item &item, const std::string &newGen, bool baseCheck = false) {
    if(baseCheck) {
        // When generating new bases, ensure we don't generate the same one
    }
    else {
        for(unsigned int i = 0; i < item.m_Mods.size(); i++) {
            if(newGen == _SECOND(item.m_Mods[i]))
                return false;
        }
    }
    return true;
}

void ApplyCraftingItem(Item & item, CraftingItem & c, std::vector<std::string> & modifiers) {
    if(item.isCorrupted)
        return;
    switch(c.type) {
        case 0: { // Agony Orb
            item.isCorrupted = true;
            for(int i = 2; i <= 4; i++) {
                int roll = rand() % corruptedMods.size();
                int modToChange = rand() % item.m_Mods.size();
                while(!SafetyCheck(item, corruptedMods[roll], false))
                    roll = rand() % corruptedMods.size();
                _SECOND(item.m_Mods[modToChange]) = corruptedMods[roll];
            }
            break;
        }
        case 1: { // Divine Orb
            int choice = 0;
            while(_THIRD(item.m_Mods[choice]) != 1)
            choice = rand() % item.m_Mods.size();
            _THIRD(item.m_Mods[choice]) = 1;
            break;
        }
        case 2: { // Lament Gem
            int roll = 0;
            for(int i = 2; i <= 4; i++) {
                // Randomize everything except for implicits
                switch(item.type) {
                    case 0: {
                        roll = Mods::swordPrefixes.size(); 
                        while(!SafetyCheck(item, Mods::swordPrefixes[roll], false))
                            roll = Mods::swordPrefixes.size(); 
                        break;
                    }
                    case 1: {
                        roll = Mods::axePrefixes.size(); 
                        while(!SafetyCheck(item, Mods::axePrefixes[roll], false))
                            roll = Mods::axePrefixes.size(); 
                        break; 
                    }
                }
            }
            for(int i = 5; i < item.m_Mods.size(); i++) {
                roll = rand() % Mods::suffixmods.size(); // Don't want just suffixes
                while(!SafetyCheck(item, Mods::suffixmods[roll], false))
                    roll = rand() % Mods::suffixmods.size();
                _SECOND(item.m_Mods[i]) = Mods::suffixmods[roll];
                _FIRST(item.m_Mods[i]) = rand() % 100;
                _FIRST(item.m_Mods[i])++;
                roll = _FIRST(item.m_Mods[i]);
                if(roll > 75)
                    _THIRD(item.m_Mods[i]) = 1;
                else if(roll < 75 && roll > 50)
                    _THIRD(item.m_Mods[i]) = 2;
                else if(roll < 50 && roll > 25)
                    _THIRD(item.m_Mods[i]) = 3;
                else
                    _THIRD(item.m_Mods[i]) = 4;
            }
            break;   
        }
        case 3: { // Molten Core
            // Get item type
            // Regenerate to any item of that same type
            // Only alters base and thus implicits, everything else remains the same
            // Store everything but impicits and then paste into everything but implicits
            int curType = item.type;
            while(random(3) != curType)
                item.type = random(3);
            switch(item.type) {
                case 0:  
                    break;
                case 1: 
                    break;
                case 2: 
                    break;
            }
            break;
        }
        case 4: { // Use copy constructor instead | Mirror
            int modToSwap = 0;
            int modToCopy = 0;
            std::tuple<std::string, int, int> modToCopyTuple;
            std::tuple<std::string, int, int> modToSwapTuple;
            modToCopy = rand() % item.m_Mods.size();
            modToSwap = rand() % item.m_Mods.size();
            while(modToSwap == modToCopy) {
                modToSwap = rand() % item.m_Mods.size();
            }
            item.m_Mods[modToSwap] = item.m_Mods[modToCopy];
            break;
        }
        case 5: { // Extension Orb
            if(item.rarity != UNIQUE)
                item.maxMods++;
            break;
        }
    }
}

void Craft() { // Remove tempItem?? | Messy but safe | Copy constructor?
    using namespace Characters;
    if(curPlayer->inventory.size() == 0 && curPlayer->gear.size() == 0) {
        std::cout << "You have no items to craft, generate some\n";
        std::cout << "\tPress ENTER to continue: ";
        std::cin.get();
        std::cin.get();
        Interface();
    }
    clear_screen();
    curPlayer->PrintInventory();
    std::cout << "\n<><><><><><><><><><><><><><>\n";
    // curPlayer->GearScreen();
    Item * tempItem = nullptr;
    std::cout << "\nPick an item in your 1) Inventory 2) Gear \t 3) Exit\nInput: ";
    std::cin >> Global::choice;
    clear_screen();
    if(Global::choice == 1 && curPlayer->inventory.size() > 0) {
        curPlayer->PrintInventory();
        input("Enter: ");
        while(curPlayer->inventory[Global::choice]->isCorrupted) {
            std::cout << "This item is corrupted!\nChoose another item\n";
            input("Enter: ");
        }
        tempItem = curPlayer->inventory[input("Enter: ")-1];
    } 
    else if(Global::choice == 2 && curPlayer->inventory.size() > 0) {
        curPlayer->GearScreen();
        input("Enter: ");
        while(curPlayer->gear[Global::choice-1]->isCorrupted) {
            std::cout << "This item is corrupted!\nChoose another item\n";
            input("Enter: ");
        }
        tempItem = curPlayer->gear[Global::choice-1];
    } else {
        Interface();
    }
    input("Enter: ");
    while(Global::choice > curPlayer->inventory.size() || Global::choice < 0) {
        std::cout << "You have entered an invalid value!\n";
        input("Enter: ");
    }

    bool isCrafting = true;
    while(isCrafting) {
        clear_screen();
        PrintItem(*tempItem);
        std::cout << "Apply any of the following crafting items:\n";
        std::cout << "1) Agony Orb  2) Divine Orb  3) Lament Gem\n\t 0) EXIT\n";
        std::cin >> Global::choice;
        switch(Global::choice) {
            case 0: isCrafting = false; break;
            case 1: tempItem->Apply(CraftingItems::aOrb, Mods::suffixmods);  break;
            case 2: tempItem->Apply(CraftingItems::dOrb, Mods::suffixmods);  break;
            case 3: tempItem->Apply(CraftingItems::lGem, Mods::suffixmods);  break;
            default: tempItem->Apply(CraftingItems::lGem, Mods::suffixmods); break;
        }
    }
}

void Interface() {
    bool isActive = true;
    clear_screen();
    std::cout << "===ARPG ITEM SYSTEM===\n" 
            << "\t1) Generate  2) Craft  3) Exit\n";
    while(isActive) {
        std::cout << "Enter: ";
        //Global::choice = Global::keyboard->Parse(Global::choice, true);
        std::cin >> Global::choice;
        switch(Global::choice) {
            case 1: Generate(); break;
            case 2: Craft(); break;
            case 3: isActive = false; break;
        }
    }
    clear_screen();
    std::cout << "Goodbye!";
}

void Setup() { // Add file handling here!
    Player * newPlayer = new Player(Mutations::BASE_LEVEL, "Default Player"); // Change how players are handled due to having multiple
    Characters::curPlayer = newPlayer;

    Interface();
    delete newPlayer;
}

int main() {
    srand(time(0));

    Keyboard *keyboardInit;
    Global::keyboard = keyboardInit;

    Setup();

    return 0;
}