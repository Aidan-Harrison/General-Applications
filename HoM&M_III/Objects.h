#ifndef Objects_h
#define Objects_h

#include <iostream>
#include <array>
#include <vector>

struct Creature {
    char id = 'c';
    std::string name = "";
    int damage = 0, health = 0, cost = 0;
    Creature() {}
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
    Building() {}
    Building(const std::string &_name, const std::array<int, 3> &_cost, bool _canBuild = false)
        :name(_name), cost(_cost), canBuild(_canBuild)
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
            // available_Creatures.push_back();
        }
    }
};

struct Base {
    std::string baseName;
    std::array<Creature, 8> creatures;
    std::array<std::pair<Building, bool>, 8> buildings;
    std::array<std::pair<CreatureBuilding*, bool>, 4> creature_buildings;
    Base() {}
    Base(const std::string &&_name)
        :baseName(_name)
    {
    }
    virtual ~Base() {}
};

struct Hero {
    Base *pBase;
    int turn = 0, movesRemaining = 10;
    std::array<std::pair<Creature*, int>, 6> units;
    std::array<std::pair<std::string, int>, 3> resources;
    // GOLD | GEMS | STONE
    Hero(Base * _base = nullptr)
        :pBase(_base)
    {
    }
};

#endif