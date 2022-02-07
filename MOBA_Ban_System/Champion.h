#ifndef Champion_h
#define Champion_h

#include <iostream>
#include <vector>
#include <array>

// Remove ID? Index of champion vector can be used instead

namespace Tags { // Remove?
    std::array<std::string, 3> tags{"Nuker", "Ganker","Support"};
}

class Champion {
private:
    std::string name;
    int id = -1;
public:
    std::vector<std::string> tags{};
    bool isBanned = false, isPicked = false;
    inline int GetID() const;
    inline std::string GetName() const;
    Champion(const std::string &&_name, const int _id, const std::vector<std::string> &&tags) 
        :name(_name), id(_id)
    {
    }
    virtual ~Champion() {}
};

inline int Champion::GetID() const {
    return id;
}

inline std::string Champion::GetName() const {
    return name;
}

namespace Champions {
    Champion *Abbadon    = new Champion("Abbadon",     0, std::vector<std::string>{"Tank"});
    Champion *Brewmaster = new Champion("Brewmaster",  1, std::vector<std::string>{"Carry", "Ganker"});
    Champion *DrowRanger = new Champion("Drow Ranger", 2, std::vector<std::string>{"Carry"});
    Champion *Jakiro     = new Champion("Jakiro",      3, std::vector<std::string>{"Nuker"});

    std::vector<Champion*> champions{Abbadon, Brewmaster, DrowRanger, Jakiro};
}

#endif