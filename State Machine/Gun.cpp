#include <iostream>
#include <array>
#include <tuple>

struct Magazine {
    enum ammoType{};
    int capacity = 0;
    int ammo = 30; // Change depending on ammo type
    Magazine() {}
    Magazine(const int ammoCount) 
        :ammo(ammoCount)
    {
    }
    ~Magazine() {}
};

struct Weapon {
    std::string wepName = "";
    bool isHolstered = false;
    Magazine *curMag;
    int ammoType = 0;
    Weapon() {}
    ~Weapon() {}
};

namespace Belt {
    int magazinesRemaining = 3;
    std::array<Magazine, 3> reserves; // Hold empty or partially filled magazines for re-use
    Weapon *otherWeapon;
    Weapon *curWeapon;
    std::tuple<Weapon*, Weapon*, Weapon*> weapons{}; // 3rd is a temp
    bool isEquipped[2];
}

void Machine(Weapon &wep) {
    Belt::curWeapon = &wep;

    while(1) {
        std::cout << wep.wepName << '\n';
        switch(wep.isHolstered) {
            case false: std::cout << "Weapon Un-Holstered\n"; break;
            case true: std::cout << "Weapon Holstered\n"; break;
        }
        std::cout << wep.curMag->ammo << '\n';

        int input = 0;
        std::cout << "Input: "; std::cin >> input;
        switch(input) {
            case 0: {
                if(wep.isHolstered) 
                    wep.isHolstered = false;
                else
                    wep.isHolstered = true;
                break;
            }
            case 1: { 
                if(!wep.isHolstered)
                    wep.curMag->ammo-=1; 
                break; 
            }
            case 2: {
                Magazine newMag(30);
                wep.curMag = &newMag; 
                // Send to reserves
                break; 
            }
            case 4: {
                if(Belt::isEquipped[0]) {
                    std::get<2>(Belt::weapons) = std::get<0>(Belt::weapons);
                    std::get<0>(Belt::weapons)->isHolstered = true;
                    std::get<0>(Belt::weapons) = std::get<1>(Belt::weapons);
                    Belt::isEquipped[0] = false;
                }
                else {
                    std::get<0>(Belt::weapons)->isHolstered = true;
                    std::get<0>(Belt::weapons) = std::get<2>(Belt::weapons);
                    Belt::isEquipped[0] = true;
                }
            }
            default: wep.isHolstered = true; break;
        }
        std::cin.get();
        system("cls");
    }
}

int main() {
    std::cout << "Weapon System\n";
    Magazine starterMag(30);
    Weapon wep;
    wep.curMag = &starterMag;
    Machine(wep);

    return 0;
}