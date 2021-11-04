#include <unordered_map>
#include <conio.h>

#include "Character.h"

namespace globalSettings {
    const int MAXVAULTSIZE = 20;
    int choice = 0;
    enum RARITY{COMMON = 1, RARE, LEGENDARY, EXOTIC};
}

bool StringParser(const std::string &str) { // ?
    if(str.length() == 0 || str == "")
        return false;
    return true;
}

// ================= Weapons ================= | Remove legendary and exotics
namespace handCannonNames {
    std::vector<std::string> hcNames{"Proxima-M1", "A Cold Sweat", "Agamid", "Acienct Gospel", "Annual Skate", "Austringer", "Bad News", "Better Devils",
                                     "Bottom Dollar", "D.F.A", "Dire Promise", "Fatebringer", "Finite Impactor", "Judgement", "IKELOS_HC_v1.0.1"};
    std::vector<std::string> exotic_hcNames{"The Last Word", "Thorn", "Hawkmoon", "Ace of Spades", "Lumina", "Crimson", "Sturm", "Sunshot", "Malfeasance", "Eriana's Vow"};
}

namespace autoRifleNames {
    std::vector<std::string> arNames{""};
    std::vector<std::string> exotic_arNames{"Cerebus+1", "Hard Light", "Monte Carlo", "SUROS Regime", "Sweet Business", "Tommy's Matchbook"};
}

namespace shotgunNames {
    std::vector<std::string> sNames{""};
    std::vector<std::string> exotic_sNames{"Duality", "Legends of Acrius", "Lord of Wolves", "The Chaperone", "The Fourth Horseman", "Tractor Cannon"};
}

namespace sniperNames {
    std::vector<std::string> snNames{"Adored", "Alone as a god", "A Single Clap", "Beloved"};
    std::vector<std::string> exotic_snNames{"Borealis", "Cloudstrike", "D.A.R.C.I.", "Izanagi's Burden", "Whisper of the Worm"};
}

namespace scoutNames {
    std::vector<std::string> scNames{""};
    std::vector<std::string> exotic_scNames{"Dead Man's Tale", "MIDA Multi-Tool", "Polaris Lance", "Skyburner's Oath", "Symmetry", "The Jade Rabbit"};
}

namespace fusionNames {
    std::vector<std::string> fNames{""};
    std::vector<std::string> exotic_fNames{"Bastion", "Jotunn", "Merciless", "One Thousand Voices", "Telesto", "Vex Mythoclast"};
}

namespace rocketNames {
    std::vector<std::string> rNames{""};
    std::vector<std::string> exotic_rNames{"Deathbringer", "Eyes of Tomorrow", "The Wardcliff Coil", "Truth", "Two-Tailed Fox"};
}

namespace grenadeNames {
    std::vector<std::string> gNames{""};
    std::vector<std::string> exotic_gNames{""};
}

// ================= Armor =================
namespace helmetNames {
    std::vector<std::string> hNames{""};
}

namespace chestNames {
    std::vector<std::string> cNames{""};
}

namespace gauntletNames {
    std::vector<std::string> gNames{""};
}

namespace legNames {
    std::vector<std::string> lNames{""};
}

namespace classItemNames {
    std::vector<std::string> cINames{""};
}

namespace artifactNames {
    std::vector<std::string> aNames{""};
}

using namespace globalSettings;

namespace PerkPool { // Push to vector at start, call after main()
    std::vector<WeaponPerk*> globalPerks{};    
    WeaponPerk *deadeye = new WeaponPerk("Deadeye");
}

namespace ModPool {
    std::vector<ArmorMod*> globalMods{};
    ArmorMod *fastHands = new ArmorMod("Fast Hands", 1);
}

void RollWeapon(Character &c) {
    int value = 0;
    std::string name;
    choice = rand() % 10;
    choice++;
    Weapon *newWeapon = new Weapon("Default Weapon", choice);
    // Name & Type
    value = rand() % 11;
    value++;
    newWeapon->type = value;
    switch(newWeapon->type) {
        case newWeapon->HAND_CANNON: 
            std::cout << "Type: Hand Cannon\n"; 
            newWeapon->weaponType = "HAND CANNON"; break;
            value = rand() % handCannonNames::hcNames.size();
            newWeapon->weaponName = handCannonNames::hcNames[value];
            break;
        case newWeapon->SIDEARM: 
            std::cout << "Type: Sidearm\n"; 
            newWeapon->weaponType = "SIDEARM"; break;
            break;
        case newWeapon->SHOTGUN: 
            std::cout << "Type: Shotgun\n";
            newWeapon->weaponType = "SHOTGUN"; break;
            value = rand() % shotgunNames::sNames.size();
            newWeapon->weaponName = shotgunNames::sNames[value];
            break;
        case newWeapon->SNIPER_RIFLE: 
            std::cout << "Type: Sniper Rifle\n"; 
            newWeapon->weaponType = "SNIPER RIFLE"; break;
            value = rand() % sniperNames::snNames.size();
            newWeapon->weaponName = sniperNames::snNames[value];
            break;
        case newWeapon->AUTO_RIFLE: 
            std::cout << "Type: Auto Rifle\n"; 
            newWeapon->weaponType = "AUTO RIFLE"; break;
            value = rand() % autoRifleNames::arNames.size();
            newWeapon->weaponName = autoRifleNames::arNames[value];
            break;
        case newWeapon->SMG: 
            std::cout << "Type: SMG\n"; 
            newWeapon->weaponType = "SMG"; break;
            break;
        case newWeapon->SCOUT_RIFLE: 
            std::cout << "Type: Scout Rifle\n"; 
            newWeapon->weaponType = "SCOUT RIFLE"; break;
            value = rand() % scoutNames::scNames.size();
            newWeapon->weaponName = scoutNames::scNames[value];
            break;
        case newWeapon->FUSION_RIFLE: 
            std::cout << "Type: Fusion Rifle\n"; 
            newWeapon->weaponType = "FUSION RIFLE"; break;
            value = rand() % fusionNames::fNames.size();
            newWeapon->weaponName = fusionNames::fNames[value];
            break;
        case newWeapon->ROCKET_LAUNCHER: 
            std::cout << "Type: Rocket Launcher\n"; 
            newWeapon->weaponType = "ROCKET LAUNCHER"; break;
            value = rand() % rocketNames::rNames.size();
            newWeapon->weaponName = rocketNames::rNames[value];
            break;
        case newWeapon->GRENADE_LAUNCHER: 
            std::cout << "Type: Grenade Launcher\n"; 
            newWeapon->weaponType = "GRENADE LAUNCHER"; break;
            value = rand() % grenadeNames::gNames.size();
            newWeapon->weaponName = grenadeNames::gNames[value];
            break;
        case newWeapon->SWORD: 
            std::cout << "Type: Sword"; 
            newWeapon->weaponType = "SWORD"; break;
            break;
    }
    for(unsigned int i = 0; i < newWeapon->weaponStats.size(); i++) {
        value = rand() % c.lightPower;  
        newWeapon->lightLevel = value;
        // value = rand() % newWeapon.lightLevel / 3;
        newWeapon->weaponStats[i] = value;
        std::cout << newWeapon->statNames[i] << "| " << newWeapon->weaponStats[i] << std::string("/", newWeapon->weaponStats[i]/10);
    }
}

void RollArmor(Character &c) {
    int value = 0;
    std::string name;
    choice = rand() % 4;
    choice++;
    ArmorPiece *newArmor = new ArmorPiece("Default Armor", choice);
    value = rand() % 6;
    value++;
    newArmor->type = value;
    switch(newArmor->type) {
        case newArmor->HELMET:
            std::cout << "Type: Helmet\n";
            newArmor->armorType = "HELMET"; break;
            value = rand() % helmetNames::hNames.size();
            newArmor->armorName = helmetNames::hNames[value];
            break;
        case newArmor->CHEST:
            std::cout << "Type: Chest\n";
            newArmor->armorType = "CHEST"; break;
            value = rand() % chestNames::cNames.size();
            newArmor->armorName = chestNames::cNames[value];
            break;
        case newArmor->LEGS:        
            std::cout << "Type: Legs\n";
            newArmor->armorType = "LEGS"; break;
            value = rand() % legNames::lNames.size();
            newArmor->armorName = legNames::lNames[value];
            break;
        case newArmor->GAUNTLETS:   
            std::cout << "Type: Gauntlets\n";
            newArmor->armorType = "GAUNTLETS"; break;
            value = rand() % gauntletNames::gNames.size();
            newArmor->armorName = gauntletNames::gNames[value];
            break;
        case newArmor->CLASS_PIECE: 
            std::cout << "Type: Class Piece\n";
            newArmor->armorType = "CLASS PIECE"; break;
            value = rand() % classItemNames::cINames.size();
            newArmor->armorName = classItemNames::cINames[value];
            break;
        case newArmor->ARTIFACT:    
            std::cout << "Type: Artifact\n";
            newArmor->armorType = "ARTIFACT"; break;
            value = rand() % artifactNames::aNames.size();
            newArmor->armorName = artifactNames::aNames[value];
            break;
    }
    std::cout << newArmor->armorName << '\n';
    for(unsigned int i = 0; i < newArmor->stats.size(); i++) {
        value = rand() % c.lightPower;  
        newArmor->lightLevel = value;
        // value = rand() % newArmor.lightLevel / 3;
        newArmor->stats[i] = value;
        std::cout << newArmor->statNames[i] << "| " << newArmor->stats[i] << std::string('/', newArmor->stats[i]/10) << '\n';
    }
}

void Interface(Character &c) {
    std::cout << "=====DESTINY 2=====\n";
    c.DisplayGear();
    std::cout << "====================\n";
    std::cout << "1) ROLL WEAPON \t 2)ROLL ARMOR \t 3)CHARACTER\n";
    std::cin >> choice;
    switch(choice) {
        case 1: {
            Weapon newWeapon;     
            RollWeapon(c); 
            break;
        }
        case 2: {
            RollArmor(c);
        }
        case 3: {
            c.Interaction(); break;
        }
    }
}

int main() {
    // F1 = 3b
    // F2 = 3c

    // Write auto function for this, don't want to manually be adding every single perk and/or mod
    PerkPool::globalPerks.push_back(PerkPool::deadeye);
    ModPool::globalMods.push_back(ModPool::fastHands);

    Character c;
    Interface(c);

    return 0;
}

