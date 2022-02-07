#include <unordered_map>
#include <iostream>
// #include <conio.h>

#include "Character.h"

void Interface();

namespace globalSettings {
    const int MAXVAULTSIZE = 20;
    int choice = 0;
    enum RARITY{COMMON = 1, RARE, LEGENDARY, EXOTIC};
    Character curCharacter;

    // Test Characters
    Character *testChar1 = new Character("Test Character 1");
    Character *testChar2 = new Character("Test Character 2");

    std::vector<Character*> characters{}; 
}

bool StringParser(const std::string &str) { // ?
    if(str.length() == 0 || str == "")
        return false;
    return true;
}

// ================= Perk ================= 
namespace PerkPool {
    // Global Perks
    WeaponPerk * deadeye = new WeaponPerk("Deadeye");
    std::vector<WeaponPerk*> globalPerks{deadeye};    

    // Hand-Cannone Perks
    WeaponPerk * triggerFinger = new WeaponPerk("Trigger Finger");
    std::vector<WeaponPerk*> handCannonPerks{triggerFinger};

    WeaponPerk * fastBolt = new WeaponPerk("Fast Bolt");
    std::vector<WeaponPerk*> autoRiflePerks{fastBolt};
}
// ================= Weapons =================
// Re-Write
// ==== Hand-Cannons ====
namespace LegendaryHandCannons {
    Weapon * fateBringer  = new Weapon("Fatebringer",      3, 4); 
    Weapon * direPromise  = new Weapon("Dire Promise",     3, 3);
    Weapon * betterDevils = new Weapon("Better Devils",    3, 3);
    Weapon * ikelosHC_v1  = new Weapon("IKELOS_HC_v1.0.1", 3, 5);
    std::vector<Weapon*> legendary_HandCannons{fateBringer, direPromise, betterDevils, ikelosHC_v1};
}

namespace ExoticHandCannons {
    Weapon * lastWord    = new Weapon("The Last Word", 4, 4);
    Weapon * thorn       = new Weapon("Thorn",         4, 4);
    Weapon * hawkmoon    = new Weapon("Hawkmoon",      4, 4);
    Weapon * aceOfSpades = new Weapon("Ace of Spades", 4, 4);
    std::vector<Weapon*> exotic_HandCannons{lastWord, thorn, hawkmoon, aceOfSpades};
}

namespace LegendaryAutoRifles {
    Weapon * hardLight     = new Weapon("Hard Light",     3, 3);
    Weapon * monteCarlo    = new Weapon("Monte Carlo",    3, 3);
    Weapon * surosRegime   = new Weapon("SUROS Regime",   3, 3);
    Weapon * sweetBusiness = new Weapon("Sweet Business", 3, 3);
    std::vector<Weapon*> legendary_AutoRifles{hardLight, monteCarlo, surosRegime, sweetBusiness};
}

namespace handCannonNames {
    std::vector<std::string> legendary_hcNames{"Proxima-M1", "A Cold Sweat", "Agamid", "Acienct Gospel", "Annual Skate", "Austringer", "Bad News", "Better Devils",
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

// ================= Armor Mods =================
namespace ModPool {
    ArmorMod *fastHands = new ArmorMod("Fast Hands", 1);
    std::vector<ArmorMod*> globalMods{fastHands};
}

using namespace globalSettings;

void RollWeaponNew(Character &c) { // Replace value with choice?
    int value = 0;
    value = rand() % 50;
    value++;
    Weapon *copyWep;
    if(value > 45) { // Exotic
        value = rand() % 2;
        switch (value) {
            case 0: copyWep = LegendaryHandCannons::legendary_HandCannons[value = rand() % LegendaryHandCannons::legendary_HandCannons.size()]; break;
            case 1: copyWep = LegendaryAutoRifles::legendary_AutoRifles[value = rand() % LegendaryAutoRifles::legendary_AutoRifles.size()]; break;
        }
    }
    else if(value < 45 && value > 30) {
        value = rand() % 2;
        switch (value) {
            case 0: copyWep = LegendaryHandCannons::legendary_HandCannons[value = rand() % LegendaryHandCannons::legendary_HandCannons.size()]; break;
            case 1: copyWep = LegendaryAutoRifles::legendary_AutoRifles[value = rand() % LegendaryAutoRifles::legendary_AutoRifles.size()]; break;
        }
    }
    // Randomize perks from a set pool
        // Uses operator overloaded '='
    // Perks
    // Add global perks also
    switch (copyWep->type) {
        // Hand-Cannon
        case 1: for(int i = 0; i <= copyWep->perkCount; i++) copyWep->perks.push_back(PerkPool::handCannonPerks[0]); break; 
        // Auto-Rifle
        case 5: for(int i = 0; i <= copyWep->perkCount; i++) copyWep->perks.push_back(PerkPool::autoRiflePerks[0]); break;
    }
    c.AddEquipment(copyWep);
}

void DisplayWeapon(Weapon &wep) {
    std::cout << "\n========" << wep.weaponName << "========\n"; 
    std::cout << wep.weaponType << '\n'; 
    for(auto i : wep.perks)
        std::cout << i->isActive << " | " << i->perkName << '\n';
    for(std::tuple<std::string, int> i : wep.weaponStats) {
        std::cout << std::get<0>(i) << " | " << std::get<1>(i);
    }
    std::cout << wep.weaponDescription << '\n';
    std::cout << "================\n";
}


void ChangeCharacters() {
    std::cout << "Available characters: \n";
    if(characters.size() <= 0) {
        std::cout << "You have no available characters to swap to, make a new one\n";
        Interface();
    }
    for(auto i : characters)
        std::cout << i->className << " | " << i->charName << '\n';
    std::cin >> choice;
    curCharacter = *characters[choice-1]; // Check!
    Interface();
}

/*
void RollWeapon(Character &c) {
    int value = 0;
    std::string name;
    choice = rand() % 10;
    choice++;
    Weapon *newWeapon = new Weapon("Default Weapon", choice);
    // Rarity
        // Defines what can be rolled
    value = rand() % 4;
    value++;
    switch (value) {
    } 
    // Name & Type
    value = rand() % 11;
    value++;
    newWeapon->type = value;
    switch(newWeapon->type) {
        case newWeapon->HAND_CANNON:  {
            std::cout << "Type: Hand Cannon\n"; 
            newWeapon->weaponType = "HAND CANNON";
            newWeapon->weaponName = handCannonNames::hcNames[value = rand() % handCannonNames::hcNames.size()];
            break;
        }
        case newWeapon->SIDEARM:  {
            std::cout << "Type: Sidearm\n"; 
            newWeapon->weaponType = "SIDEARM";
            break;
        }
        case newWeapon->SHOTGUN: {
            std::cout << "Type: Shotgun\n";
            newWeapon->weaponType = "SHOTGUN";
            newWeapon->weaponName = shotgunNames::sNames[value = rand() % shotgunNames::sNames.size()];
            break;
        }
        case newWeapon->SNIPER_RIFLE: {
            std::cout << "Type: Sniper Rifle\n"; 
            newWeapon->weaponType = "SNIPER RIFLE";
            newWeapon->weaponName = sniperNames::snNames[value = rand() % sniperNames::snNames.size()];
            break;
        }
        case newWeapon->AUTO_RIFLE:  {
            std::cout << "Type: Auto Rifle\n"; 
            newWeapon->weaponType = "AUTO RIFLE"; 
            newWeapon->weaponName = autoRifleNames::arNames[value = rand() % autoRifleNames::arNames.size()];
            break;
        }
        case newWeapon->SMG: {
            std::cout << "Type: SMG\n"; 
            newWeapon->weaponType = "SMG";
            break;
        }
        case newWeapon->SCOUT_RIFLE: {
            std::cout << "Type: Scout Rifle\n"; 
            newWeapon->weaponType = "SCOUT RIFLE";
            newWeapon->weaponName = scoutNames::scNames[value = rand() % scoutNames::scNames.size()];
            break;
        }
        case newWeapon->FUSION_RIFLE: {
            std::cout << "Type: Fusion Rifle\n"; 
            newWeapon->weaponType = "FUSION RIFLE"; 
            newWeapon->weaponName = fusionNames::fNames[value = rand() % fusionNames::fNames.size()];
            break;
        }
        case newWeapon->ROCKET_LAUNCHER: {
            std::cout << "Type: Rocket Launcher\n"; 
            newWeapon->weaponType = "ROCKET LAUNCHER"; 
            newWeapon->weaponName = rocketNames::rNames[value = rand() % rocketNames::rNames.size()];
            break;
        }
        case newWeapon->GRENADE_LAUNCHER: {
            std::cout << "Type: Grenade Launcher\n"; 
            newWeapon->weaponType = "GRENADE LAUNCHER";
            newWeapon->weaponName = grenadeNames::gNames[value = rand() % grenadeNames::gNames.size()];
            break;
        }
        case newWeapon->SWORD: {
            std::cout << "Type: Sword"; 
            newWeapon->weaponType = "SWORD";
            break;
        }
    }
    for(unsigned int i = 0; i < newWeapon->weaponStats.size(); i++) {
        value = rand() % c.lightPower;  
        newWeapon->lightLevel = value;
        value = rand() % newWeapon->lightLevel / 3;
        newWeapon->weaponStats[i] = value;
        std::cout << newWeapon->statNames[i] << "| " << newWeapon->weaponStats[i] << std::string("/", newWeapon->weaponStats[i]/10);
    }
}
*/

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
        case newArmor->HELMET: {
            std::cout << "Type: Helmet\n";
            newArmor->armorType = "HELMET";
            newArmor->armorName = helmetNames::hNames[value = rand() % helmetNames::hNames.size()];
            break;
        }
        case newArmor->CHEST: {
            std::cout << "Type: Chest\n";
            newArmor->armorType = "CHEST"; 
            newArmor->armorName = chestNames::cNames[value = rand() % chestNames::cNames.size()];
            break;
        }
        case newArmor->LEGS: {
            std::cout << "Type: Legs\n";
            newArmor->armorType = "LEGS"; 
            newArmor->armorName = legNames::lNames[value = rand() % legNames::lNames.size()];
            break;
        }
        case newArmor->GAUNTLETS: {  
            std::cout << "Type: Gauntlets\n";
            newArmor->armorType = "GAUNTLETS"; 
            newArmor->armorName = gauntletNames::gNames[value = rand() % gauntletNames::gNames.size()];
            break;
        }
        case newArmor->CLASS_PIECE: {
            std::cout << "Type: Class Piece\n";
            newArmor->armorType = "CLASS PIECE"; 
            newArmor->armorName = classItemNames::cINames[value = rand() % classItemNames::cINames.size()];
            break;
        }
        case newArmor->ARTIFACT: {
            std::cout << "Type: Artifact\n";
            newArmor->armorType = "ARTIFACT"; 
            newArmor->armorName = artifactNames::aNames[value = rand() % artifactNames::aNames.size()];
            break;
        }
    }
    std::cout << newArmor->armorName << '\n';
    for(unsigned int i = 0; i < newArmor->stats.size(); i++) {
        value = rand() % c.lightPower;  
        newArmor->lightLevel = value;
        value = rand() % newArmor->lightLevel / 3;
        newArmor->stats[i] = value;
    }
    for(unsigned int i = 0; i < newArmor->stats.size(); i++)
        std::cout << newArmor->statNames[i] << "| " << newArmor->stats[i] << std::string('/', newArmor->stats[i]/10) << '\n';
}

void Interface(Character &c) {
    std::cout << "=====DESTINY 2=====\n";
    c.DisplayGear();
    std::cout << "====================\n";
    std::cout << "1) ROLL WEAPON \t 2)ROLL ARMOR \t 3)CHARACTER\n";
    std::cout << "Enter: ";
    std::cin >> choice;
    switch(choice) {
        case 1: {  
            RollWeaponNew(c); 
            break;
        }
        case 2: {
            RollArmor(c);
            break;
        }
        case 3: {
            c.Interaction(); 
            break;
        }
        case 4: {
            ChangeCharacters();
            break;
        }
    }
}

int main() {
    // F1 = 3b
    // F2 = 3c

    // Write auto function for this, don't want to manually be adding every single perk and/or mod
    PerkPool::globalPerks.push_back(PerkPool::deadeye);
    ModPool::globalMods.push_back(ModPool::fastHands);

    // Add character loading and writing!
    Character c("Test Character");
    Interface(c);

    return 0;
}

