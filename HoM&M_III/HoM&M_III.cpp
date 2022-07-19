#include <utility>

#include "Objects.h"

// Heroes of Might and Magic III
namespace Creatures {
    Creature * elf = new Creature("Elf");
    std::vector<Creature*> creaturePool{elf};
}

namespace CreatureBuildings {
    // Elven Camp
    std::vector<Creature*> elvenCampCreatures{Creatures::elf};
    CreatureBuilding * elf_Camp = new CreatureBuilding("Elven Camp", std::array<int, 3>{1000, 500, 250}, elvenCampCreatures);

    std::vector<CreatureBuilding*> c_Buildings{elf_Camp};
}

namespace Bases {
    Base * testBase = new Base("New Base");
    std::vector<Base*> bases{testBase}; 
}

struct Player {
    std::array<Hero*, 8> heroes;
};

template<typename T>
T Tick(Base * b) { // Causes bases to generate what they need | CONTINUE!
    for(unsigned int i = 0; i < b.creature_buildings.size(); i++) {
        if(std::get<0>(b.creature_buildings[i]) != nullptr) {
            b.creature_buildings[i]->Create();
        }
    }
    return false;
}

void PrintHero(Hero &p) {
    std::cout << "=Hero=\n";
    std::cout << "Moves remaining: " << p.movesRemaining << '\n';
    std::cout << "Resources: ";
    for(unsigned int i = 0; i < p.resources.size(); i++)
        std::cout << std::get<0>(p.resources[i]) << "| " << std::get<1>(p.resources[i]) << '\t';
}

template<typename T>
bool CheckResources(Hero &p, T _entity) { // Checks Hero resources against cost
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

void PurchaseUnits(Hero &p, CreatureBuilding &cB) {
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
    while(std::get<1>(p.resources[0]) < cB.creatures[unit-1]->cost * amount) {
        std::cout << "You cannot afford that many " << cB.creatures[unit-1]->name << "!\n" << "Enter new amount: ";
        std::cin >> amount;
    }
    // Add confirmation
    std::get<1>(p.resources[0]) -= cB.creatures[unit-1]->cost * amount;
}

void Swap(Creature * c1, Creature * c2) { // Check!
    Creature * temp = c2;
    c2 = c1;
    c1 = temp;
}

void SortUnits(Hero &p) {
    if(std::get<0>(p.units[0]) == nullptr) {
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

void BuildPlanner(Hero &p, Base &b) {
    bool building = true;
    int choice = 0;
    while(building) {
        PrintHero(p);
        for(unsigned int i = 0; i < b.buildings.size(); i++) {
            if(i % 3 == 0 && i != 0)
                putchar('\n');
            std::cout << b.buildings[i].first.name << '/t';
        }
        std::cout << "Select a building: ";
        std::cin >> choice;
        if(choice == 100)
            building = false;
        if(choice <= 8) {
            if(!b.buildings[choice-1].first.canBuild)
                return;
        }
        else {
            if(!std::get<0>(b.creature_buildings[choice-1])->canBuild)
                PurchaseUnits(p, *std::get<0>(b.creature_buildings[choice-1]));
        }
        std::cout << "=BUILDING=\n";
        std::cout << b.buildings[choice-1].first.name << '\n';
        for(unsigned int i = 0; i < b.buildings[choice-1].first.cost.size(); i++)
            std::cout << b.buildings[choice-1].first.cost[i] << '\t';
        if(CheckResources(p, b.buildings[choice-1])) {
            std::cout << "Would you like to purchase this building? ";
            std::cin >> choice;
            if(choice == 1) {
                b.buildings[choice-1].first.canBuild = false;
                // Do resources
            }
        }
    }
}

void Game(Hero &p) {
    int choice = 0;
    while(1) {
        if(p.movesRemaining <= 0) {
            std::cout << "End turn? ";
            std::cin >> choice;
            if(choice == 1) {
                p.turn++;
                for(Base * i : Bases::bases) {
                    Tick<Base>(i);
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
                case 1: BuildPlanner(p, *p.pBase); break;
                case 2: SortUnits(p); break;
            }
            p.movesRemaining--;
        }
    }
}

int main() {
    Hero newHero(Bases::bases[0]);
    Game(newHero);

    return 0;
}