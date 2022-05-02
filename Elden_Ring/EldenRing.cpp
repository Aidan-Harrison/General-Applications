// Crafting system
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

// Maybe do Ashes of War?

namespace tags {
    enum WEAPON_TYPES{DAGGER, SWORD, GREATSWORD, BOW};
    enum DAMAGE_TYPES{PHYSICAL, POISON, LIGHTNING};
}

struct weapon {
    std::string name = "";
    int curUpgrade = 0, maxUpgrades = 25;
    int modifier = 0; // Damage type
        // STR, DEX, INT, FTH
    char scaling[4] = {'F','F','F','F'};
    // Stats
    std::unordered_map<std::string, float> stats{
        {"phys dam", 25.0},
        {"magic dam", 0.0},
        {"weight", 2.5},
        {"value", 500.0}
    };
    weapon() {}
};

weapon * CompareWeapons(weapon & w1, weapon & w2) {
    // Returns overall superior
    int fWepValue = 0, sWepValue = 0;
    for(auto it = w1.stats.begin(); it != w1.stats.end(); it++) {
        if(it->second > w2.stats[it->first]) 
            fWepValue++;
        else
            sWepValue++;
    }
    if(fWepValue > sWepValue)
        return &w1;
    else if(fWepValue == sWepValue)
        return nullptr;
    return &w2;
}

struct item {
    std::string name = "";
    std::string recipe = "";
    int id = 0;
    item() {}
    item(const std::string & _recipe)
        :recipe(_recipe)
    {
    }
};

struct craftingItem : public item {
    int amount = 0;
    craftingItem() {}
};

namespace ITEMS {
    item bDarts("00");
    item pBolt("12");
}

namespace C_ITEMS {
    craftingItem animalBones;
    craftingItem boltTip;
    craftingItem feather;
}

/*
std::unordered_map<const int, craftingItem> c_Items = { 
    {0, C_ITEMS::animalBones}, {1, C_ITEMS::boltTip} 
};
*/

std::vector<item> items{ITEMS::bDarts, ITEMS::pBolt};
weapon curWep;
typedef std::pair<std::string,std::string> recipe;

void Swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Weapon Crafting
void UpgradeWeapon(weapon & w) {
    w.curUpgrade++;
}

void InfuseWeapon(weapon & w, int infusion = tags::LIGHTNING) {
    w.modifier = infusion;
    switch (infusion) {
        case tags::PHYSICAL: w.scaling[0] = 'B'; break;
        case tags::POISON: break;
        case tags::LIGHTNING: w.scaling[2] = 'B'; break;
    }
}

void CraftWeapon() {
    int input = 0;
    std::cin >> input;
    switch (input) {
        case 1: UpgradeWeapon(curWep); break;
        case 2: InfuseWeapon(curWep); break;
    }
}

std::string sort(std::string data) {
    for(uint8_t i = 0; i < data.length(); i++) {
        int min = i;
        for(uint8_t j = i+1; j < data.length(); j++) {
            if((int)data[j] < (int)data[min])
                min = j;
        }
        if(min != i)
            Swap(&data[i],&data[min]);
    }
    return data;
}

item * Combine(std::string craftingItems) {
    // Search through combos and amount
    if(craftingItems.length() == 0)
        return nullptr;
    item * newItem = nullptr;
    std::string availableRecipes = "";
    sort(craftingItems.begin(), craftingItems.end());
    int foundRecipes = 0;
    std::cout << items[1].name << '\n';
    for(uint16_t i = 0; i < items.size(); i++) {
        if(items[i].recipe == craftingItems) {
            std::cout << "Found!\n";
            availableRecipes += items[i].name + "|\n";
        }
    }
    /*
    if(foundRecipes == 0)
        return nullptr;
    else if(foundRecipes == 1) // Single recipe
        return nullptr;
    */
    std::cout << "Available recipes:\n";
    std::cout << availableRecipes << '\n';
    return newItem;
}

void Interface() {
    char input = 0;
    std::string craftingItems = "";
    while(input != -1) { 
        system("clear");
        std::cout << craftingItems;
        std::cout << "\nEnter recipe: ";
        std::cin >> input;
        craftingItems += input;
        if(craftingItems.length() > 6 || input == 'x')
            break;
    }
    item * newItem = Combine(craftingItems);
    if(newItem == nullptr)
        return;
    std::cout << "You crafted: " << newItem->name << '\n';
}

int main() {
    while(1) {
        Interface();
    }

    return 0;
}
