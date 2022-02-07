#include <iostream>
#include <array>
#include <vector>
#include <utility>

// Heroes of Might and Magic III
// ==== TILE TEST ==== | REMOVE EVENTUALLY
struct Grid {
    std::vector<std::vector<Creature*>> grid{};
    inline void Add(const int src, const int des, Creature &c) {
        grid[src][des] = creature;
    }
    inline void Remove(const int src, const int des) {
        grid[src][des] = nullptr;
    }
}
// =============================

struct Creature {
    char id = 'c';
    std::string name = "";
    int damage = 0, health = 0, cost = 0;
    Creature(const std::string &_name) 
        :name(_name)
    {
    }
};

struct Building {
    char id = 'b';
    std::string name = "";
    std::array<int, 3> cost{};
        // GOLD | GEMS | STONE
    bool canBuild = false;
    Building(const std::string &_name, const std::array<int, 3> &_cost, bool _canBuild = false)
        :name(_name), cost(_cost), canBuild(_canBuild);
    {
    }
    virtual ~Building() {}
};

struct CreatureBuilding : public Building {
    std::vector<Creature*> creatures{};
    std::vector<Creature*> available_Creatures{};
    int curTurn = 0, turnCount = 0;

    CreatureBuilding(const std::string &&_name, const std::array<int, 3> _cost, const std::vector<Creature*> _creatures)
        :creatures(_creatures)
    {
        Building(_name, _cost);
    }

    void Create() {
        curTurn++;
        if(curTurn >= turnCount) {
            curTurn = 0;
            available_Creatures.push_back();
        }
    }
};

namespace Creatures {
    Creature * elf = new Creature("Elf");
    std::vector<Creature*> creaturePool{elf};
}

namespace CreatureBuildings {
    // Elven Camp
    std::vector<Creature*> elvenCampCreatures{Creatures::elf};
    CreatureBuilding * elf_Camp = new CreatureBuilding("Elven Camp", std::array<int, 3>{1000, 500, 250}, elvenCampCreatures);

    std::vector<CreatureBuildings*> c_Buildings{elf_Camp};
}

struct Base {
    std::string baseName;
    std::array<Creature, 8> creatures{};
    std::array<std::pair<Building, bool>, 8> buildings{};
    std::array<std::pair<CreatureBuilding*, bool>, 4> creature_buildings{};
    Base(const std::string &&_name)
        :baseName(_name)
    {
    }
    virtual ~Base() {}
};

namespace Bases {
    Base * testBase = new Base("New Base");
    std::vector<Base*> bases{testBase}; 
}

struct Player {
    Base *pBase;
    int turn = 0, movesRemaining = 10;
    std::array<std::pair<Creature, int>, 6> units{};
    std::array<std::pair<std::string, int>, 3> resources{};
    // GOLD | GEMS | STONE
    Player(const Base * _base = nullptr)
        :pBase(_base)
    {
    }
};

template<typename T>
T Tick(Base &b) { // Causes bases to generate what they need | CONTINUE!
    for(unsigned int i = 0; i < b.creature_buildings.size(); i++) {
        if(std::get<0>(b.creature_buildings[i]) != nullptr) {
            b.creature_buildings[i]->Create();
        }
    }
    return false;
}

void PrintPlayer(Player &p) {
    std::cout << "=PLAYER=\n";
    std::cout << "Moves remaining: " << p.movesRemaining << '\n';
    std::cout << "Resources: ";
    for(unsigned int i = 0; i < p.resources.size(); i++)
        std::cout << std::get<0>(p.resources[i]) << "| " << std::get<1>(p.resources[i]) << '\t';
}

template<typename T>
bool CheckResources(Player &p, T _entity) { // Checks player resources against cost
    if(_entity.id == 'c')
        if(p.resources[0] < _entity.cost)
            return false;
    else if(_entity.id == 'b') {
        for(unsigned int i = 0 ; i < _entity.cost.size(); i++)
            if(_entity.cost[i] != 0)
                if(p.resources[i] < _entity.cost[i])
                    return false;
    }
    return true;
}

void PurchaseUnits(Player &p, CreatureBuilding &cB) {
    int unit = 0, amount = 0;
    for(unsigned int i = 0; i < cB.creatures.size(); i++)
        std::cout << cB.creatures[i]->name << '\n';
    std::cout << "Choose a unit: ";
    std::cin >> unit;
    if(unit == 0 || unit > cB.creatures.size()+1) {
        std::cout << "You have entered an invalid value!\n" << "Enter new amount: ";
        std::cin >> unit;
    }
    std::cout << "Define amount: ";
    std::cin >> amount;
    while(p.resources[0] < cB.creatures[unit-1]->cost * amount) {
        std::cout << "You cannot afford that many " << cB.creatures[unit-1]->name << "!\n" << "Enter new amount: ";
        std::cin >> amount;
    }
    // Add confirmation
    p.resources[0] -= cB.creatures[unit-1]->cost * amount;
}

void Swap(Creature * c1, Creature * c2) { // Check!
    Creature * temp = c2;
    c2 = c1;
    c1 = temp;
}

void SortUnits(Player &p) {
    if(p.units[0] == nullptr) {
        std::cout << "You have no units to sort!";
        return;
    }
    for(unsigned int i = 0; i < p.units.size(); i++) {
        int min = i;
        for(unsigned int j = i+1; j < p.units.size(); j++)
            if(std::get<1>(p.units[j]) < std::get<1>(p.units[min]))
                min = j;
        if(min != i)
            Swap(std::get<0>(p.units[i]), std::get<0>(p.units[min]));
    }
}

void BuildPlanner(Player &p, Base &b) {
    bool building = true;
    int choice = 0;
    while(building) {
        PrintPlayer(p);
        for(unsigned int i = 0; i < b.buildings.size(); i++) {
            if(i % 3 == 0 && i != 0)
                putchar('\n');
            std::cout << std::get<0>(b.buildings[i]).name << '/t';
        }
        std::cout << "Select a building: ";
        std::cin >> choice;
        if(choice == 100)
            building = false;
        if(choice <= 8) {
            if(!std::get<0>(b.buildings[choice-1])->canBuild)
                return;
        }
        else {
            if(!std::get<0>(b.creature_buildings[choice-1])->canBuild)
                PurchaseUnits(p, std::get<0>(b.creature_buildings[choice-1]));
        }
        std::cout << "=BUILDING=\n";
        std::cout << std::get<0>(b.buildings[choice-1]).name << '\n';
        for(unsigned int i = 0; i < std::get<0>(b.buildings[choice-1]).cost.size(); i++)
            std::cout << std::get<0>(b.buildings[choice-1]).cost[i] << '\t';
        if(CheckResources(p, b.buildings[choice-1])) {
            std::cout << "Would you like to purchase this building? ";
            std::cin >> choice;
            if(choice == 1) {
                std::get<0>(b.buildings[choice-1]).canBuild = false;
                
                // Do resources
            }
        }
    }
}

void Game(Player &p) {
    int choice = 0;
    while(1) {
        if(p.movesRemaining <= 0) {
            std::cout << "End turn? ";
            std::cin >> choice;
            if(choice == 1) {
                p.turn++;
                for(auto i : Bases::bases) {
                    Tick(i);
                }
                p.movesRemaining = 10;
            }
            else
                continue;
        }
        else {
            std::cout << "1) Base Menu\n";
            std::cin >> choice;
            switch(choice) {
                case 1: BuildPlanner(p, p.pBase); break;
                case 2: SortUnits(p); break;
            }
            p.movesRemaining--;
        }
    }
}

int main() {
    Player newPlayer(Bases::bases[0]);
    Game(newPlayer)

    return 0;
}