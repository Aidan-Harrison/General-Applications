#include <utility>
#include <fstream>

#include "Queue.h"

// Automate ID?

// Tarkov
#define Get_VAL std::get<1>

struct Entity {
    std::string name = "";
    enum type{WEAPON,ATTACHMENT,AID,JUNK};
    int id = 0, type = 0, INTERNAL_ID = 0;
    int cost = 0;
    float condition = 1.0f; // 0-1 range
    Entity() {}
    Entity(const std::string &name, const int id) 
    {
        condition = rand() % 1;
    }
    Entity(Entity &e) 
    {
        name = e.name;
        condition = e.condition;
    }
    virtual ~Entity() {}
};

struct Attachment : public Entity {
    enum type{SCOPE,RAIL,BARREL,MAG,STOCK};
    int t;
    Attachment(const std::string &name, const int id) 
    {
        INTERNAL_ID = 1;
        Entity(name, id);
    }
};

struct Weapon : public Entity {
    int ammo = 0, t;
    enum type{PISTOL,SHOTGUN,AR,SNIPER}; // Defines number of attachments
    std::vector<bool> acceptedAttachments{};
    std::vector<Attachment*> attachments{};
    Weapon(const std::string &name, const int id, const int numOfAttach) 
    {
        INTERNAL_ID = 2;
        attachments.resize(numOfAttach);
        Entity(name, id);
    }
};

template<typename T>
struct Player {
    std::vector<T*> inventory{};
};


namespace Items {
    template<typename T>
    std::vector<T> items(0,0);
    template<typename T>
    std::vector<T> market(0,0);
}

namespace System {
    int marketSize = 20;
    std::fstream fileHandler;
    template<typename T>
    Player<T> * player;
}

template<typename T>
T* Clone(T &e) {
    // Type id
    T * c;
    if(e.INTERNAL_ID == 0)
    switch(e.INTERNAL_ID) {
        case 0: c = new Entity(e); break;
        case 1: c = new Weapon(e); break;
        case 2: c = new Attachment(e); break;
    }
    return c;
}

void FileRead(const std::string &&_filePath) {
    System::fileHandler.open(_filePath);
    if(System::fileHandler.fail()) {
        std::cerr << "Failed to open file!\n";
        return;
    }
    std::string name = "";
    std::vector<std::pair<bool,int>> constructorValues{};
    int reader = 0, value = 0;
    std::string curLine;
    while(!System::fileHandler.eof()) {
        // Write to curLine!
        std::getline(System::fileHandler, curLine);
        std::cout << curLine;
        if(curLine[0] == '/')
            continue;
        if(!isdigit(curLine[0]) && isalnum(curLine[0])) {
            while(curLine[reader] != ';' || curLine[reader] != ' ') {
                if(curLine[reader] == '_')
                    name += ' ';
                else
                    name += curLine[reader];
                reader++;
            }
            reader = 0;
        }
        for(unsigned int i = 0; i < curLine.length(); i++) {
            if(curLine[i] == ';' && isdigit(curLine[i-1])) {
                int counter = i-1;
                while(curLine[counter] != ' ') {
                    value += (int)curLine[counter];
                    counter--;
                }
                constructorValues.push_back({true, value});
                value = 0;
                // Read until next ;, store into constructor
                for(std::pair<bool,int> state : constructorValues) 
                    if(state.first)
                        break;
            }
        }
        if(Get_VAL(constructorValues[0]) == 0) // WEAPON
            Weapon * newWep = new Weapon(name, Get_VAL(constructorValues[1]), Get_VAL(constructorValues[2]));
        else if(Get_VAL(constructorValues[0]) == 1) // ATTACHMENT
            Attachment * newAttach = new Attachment(name, Get_VAL(constructorValues[1]));
        //else if(std::get<1>(constructorValues[0]) == 2) // Food/Aid
            //Attachment * newAttach = new Attachment(name, std::get<1>(constructorValues[1]));
        constructorValues.clear();
    }
}

// Do Diablo style inventory
template<typename T>
void Inventory(Player<T> * player) {
    for(unsigned int i = 0; i < System::player<Attachment*>->inventory.size(); i++) {
        std::cout << System::player<Attachment>->inventory[i]->name;
    }
}

void GunScreen(Weapon &wep) {
    int attSlot = 0, attChoice = 0;
    std::cout << "===ATTACHMENTS===\n";
    for(unsigned int i = 0; i < wep.attachments.size(); i++) {
        if(i % 4 == 0 && i != 0)
            putchar('\n');
        std::cout << i << ") " << wep.attachments[i]->name << '\t';
    }
    std::cin >> attSlot;
    // Check attachment compatability
    for(unsigned int i = 0; i < System::player<Attachment>->inventory.size(); i++) {
        if(System::player<Attachment>->inventory[i]->t != wep.attachments[attSlot]->t)
            std::cout << System::player<Attachment>->inventory[i]->name;
    }
    std::cin >> attChoice;
    wep.attachments[attSlot] = System::player<Attachment>->inventory[attChoice];
}

void Transaction() {
}

template<typename T>
void Market() {
    int wepCount = 0, modifier = 0;
    // Generate market
    modifier = rand() % 6;
    for(unsigned int i = 0; i < System::marketSize - modifier; i++) {
        int choice = rand() % Items::items<T>.size();
        Items::market<T>.push_back(Clone(Items::items<T>[choice]));
        if(Items::market<T>[Items::market.end()].INTERNAL_ID == 2)
            wepCount++;
        if(wepCount == 10)
            return;
    }
    // GENERAL TO-DO List:
        // Count amount of weapons generated
        // Declare items which cannot be purchased in RED (Use NCurses)
        // Tarkov style inventory, write universal system! Re-use everywhere
        // Add gun modification system, have price be affected
        // Add entity condition to weapons and attachments, worse condition = less value
        // Add inidividual market sellers, Tarkov contractors
}



int main() {
    FileRead("data.txt");


    return 0;
}