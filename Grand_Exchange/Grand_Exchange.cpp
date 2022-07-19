#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <tuple>
#include <map>

#define getF std::get<0>
#define getS std::get<1>

struct Item {
    std::string name;
    int value = 1;
    bool isStackable = false;
    Item(const std::string &_name, const int _value) :name(_name), value(_value) {}
    Item(Item &other) 
    {
        name = other.name;
        value = other.value;
        isStackable = other.isStackable;
    }
};

struct Character {
    // Item | Stack Count | Inventory Size
    std::array<std::tuple<Item*, int>, 28> inventory{};
};

namespace Items {
    Item * gp = new Item("gp", 1);

    Item * i_Bones   = new Item("Bones",   16);
    Item * i_Logs    = new Item("Logs",    34);
    Item * i_Feather = new Item("Feather", 28);

    std::map<int, Item*> i_GlobalPool = {{1, gp},
                                        {2, i_Bones},
                                        {3, i_Logs},
                                        {4, i_Feather}};
}

// Index:
// 0) = Empty
// 1) = Buying
// 2) = Selling
// 3) = Bought
// 4) = Sold
namespace Global {
    std::tuple<char, int> geInput; // Mod, Val
    std::array<std::tuple<int, Item*>, 6> slots{};
}

// FORCE single char input, ncurses??
Item* Search(const std::map<int, Item*> &data) {
    int counter = 0;
    char character;
    bool checkingIndex = false;
    int index = 0;
    std::string searchString;
    std::string prevString = "";
    while(1) {
        system("clear");
        std::cout << "Search: ";
        std::cin >> character;
        if(!isdigit(character))
            searchString += std::tolower(character);
        else {
            index = character - '0';
            checkingIndex = true;
        }
        std::cout << searchString << '\n';
        for(auto i = Items::i_GlobalPool.begin(); i != Items::i_GlobalPool.end(); i++) {
            if(i->first % 6 == 0 && i->first != 0)
                putchar('\n');
            if(checkingIndex) {
                if(index == i->first)
                    return i->second;
            }
            for(unsigned int j = 0; j < i->second->name.length() && j < searchString.length(); j++) {
                if(counter > searchString.length())
                    continue;
                if(i->second->name[j] == searchString[j])
                    std::cout << i->first << ") " << i->second->name << '\t';
                /*
                if(prevString == i->second->name || searchString[counter] == i->second->name[j]) {
                    std::cout << i->second->name << '\t';
                    prevString = searchString;
                    counter++; // Won't function
                }
                */
            }
            //if(i->second->name.find(searchString)) // Change and fix!
                //std::cout << i->second->name << "\t";
        }
    }
}

void InventoryInterface(Character &c) {
    for(unsigned int i = 0; i < c.inventory.size(); i++) {
        if(i % 4 == 0 && i != 0)
            putchar('\n');
        if(getF(c.inventory[i]) != nullptr)
            std::cout << getF(c.inventory[i])->name << "  ";
        else
            std::cout << "  ";
    }
    putchar('\n');
}

int FindEmpty(Character &c) {
    for(unsigned int i = 0; i < c.inventory.size(); ++i) {
        if(getF(c.inventory[i]) == nullptr)
            return i;
    }
    return -1; // Add safter to return whenever using this function!!
}

void GrandExchange(Character &c) {
    int amount = 1;
    float priceMod = 0.0;
    int itemValue = 0;
    char geSlotState;
    while(1) {
        system("clear");
        InventoryInterface(c);
        std::cout << "\n===============================\n";
        std::cout << "===Grand Exchange===\n";
        for(unsigned int i = 0; i < Global::slots.size(); i++) {
            if(i % 3 == 0 && i != 0)
                putchar('\n');
            if(getF(Global::slots[i]) == 0)
                std::cout << "BUY/SELL\t";
            else if(getF(Global::slots[i]) == 1)
                std::cout << "Buying: " << getS(Global::slots[i])->name << '\t';
            else if(getF(Global::slots[i]) == 2)
                std::cout << "Selling: " << getS(Global::slots[i])->name << '\t';
        }
        putchar('\n');
        std::cout << "Input: [BUY/SELL, SLOT]\n";
        std::cin >> geSlotState; // Slightly cheaper then calling std::get twice
        getF(Global::geInput) = std::tolower(geSlotState);
        std::cin >> geSlotState;
        getF(Global::geInput) = std::tolower(geSlotState);
        switch (getF(Global::geInput)) {
            case 'b': getF(Global::slots[getS(Global::geInput)]) = 1; break; // Should only apply if confirmed
            case 's': getF(Global::slots[getS(Global::geInput)]) = 2; break;
        }
        getS(Global::slots[getS(Global::geInput)]) = Search(Items::i_GlobalPool);
        while(getF(Global::geInput) != 'p') {
            system("clear");
            std::cout << getS(Global::slots[getS(Global::geInput)])->name << '\n';
            std::cout << itemValue << " . " << amount << '\n';
            std::cout << itemValue * amount << '\n';
            std::cout << "D) Decrease Price\t" << priceMod << "%\tI) Increase Price\n";
            std::cout << "\t\tAmount of items: " << amount << '\n';
            std::cin >> getF(Global::geInput);
            char input = std::tolower(getF(Global::geInput));
            switch (input) {
                case 'q': {
                    amount -= 5;
                    break;
                }
                case 'e': {
                    amount += 5;
                    break;
                }
                case 'a': { // Fix! Unkown segmentation fault!
                    std::cout << "Manually set amount of items: ";
                    std::cin >> amount;
                    break;
                }
                case 'd': {
                    priceMod -= 0.05;
                    itemValue = getS(Global::slots[getS(Global::geInput)])->value * priceMod;
                    break;
                }
                case 'i': {
                    priceMod += 0.05;
                    int increase = getS(Global::slots[getS(Global::geInput)])->value * priceMod;
                    itemValue = getS(Global::slots[getS(Global::geInput)])->value + increase;
                    break;
                }
            }
        }
        // Purchase
        if(getS(Global::slots[getS(Global::geInput)])->isStackable) {
            int invPosition = FindEmpty(c);
            getS(c.inventory[invPosition]) = amount;
            for(unsigned int i = 1; i <= amount; i++) {
                Item * newItem = new Item(*getS(Global::slots[getS(Global::geInput)]));
                getF(c.inventory[invPosition]) = newItem;
            }
        }
        else {
            for(unsigned int i = 1; i <= amount; i++) {
                Item * newItem = new Item(*getS(Global::slots[getS(Global::geInput)]));
                if(getF(c.inventory[i-1]) != nullptr)
                    getF(c.inventory[i-1]) = newItem;
            }
        }
        // Store remaining items which couldn't be put into character inventory

        // Purchase
            // Price change
            // Amount change
            // GP cost
            // Messaging etc.
    }
}

int main() {
    Character c;
    GrandExchange(c);

    return 0;
}