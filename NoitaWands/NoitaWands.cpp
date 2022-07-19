#include <map>

#include "KeyboardParser.h"

// Want null spells in wand?????
    // - Convert wand spell loadout to std::array??

#define wandSpells p.wands[p.curWand]->spellLoadout

namespace SpellProperties {
    std::vector<std::string> prefixProperties = {"Bouncing", "Single Shot", "Double Shot", "Rapid-Shot", "Large", "Small", "Nimble"};
    std::vector<std::string> affixProperties = {"Bomb", "Fire Bomb"};
    std::vector<std::string> suffixProperties = {""};
}

namespace Database {
    // Spells
    Spell * fireBall  = new Spell("Fireball");
    Spell * iceShot   = new Spell("Ice Shot");
    Spell * lightBolt = new Spell("Light Bolt");
    Spell * fireBomb  = new Spell("Fire Bomb");
    Spell * caltrops  = new Spell("Caltrops");
    std::map<int, Spell*> spells {
        {1, fireBall}, 
        {2, iceShot}, 
        {3, lightBolt},
        {4, fireBomb},
        {5, caltrops}
    };
    std::vector<Spell*> spellsTest{}; // Remove?

    // Wands
        // -- STARTING
    Wand * basicWand = new Wand("Basic Wand");
    Wand * fireWand  = new Wand("Fire Wand");
    Wand * iceWand   = new Wand("Ice Wand");
    Wand * lightWand = new Wand("Light Wand");
    Wand * darkWand  = new Wand("Dark Wand");
    Wand * bombWand  = new Wand("Bomb Wand");
        // -- CORE
    std::map<int, Wand*> wands {
        {1, basicWand},
        {2, fireWand},
        {3, iceWand},
        {4, lightWand},
        {5, darkWand},
        {6, bombWand}
    };
}

// If one-time use, else vector
// Pointless!
struct SpellQueue {
    int front = -1;
    int rear = -1;

    std::vector<Spell*> spells{};

    bool isFull();
    bool isEmpty();
    void Enqueue(Spell &spell);
    Spell* Dequeue();

    SpellQueue() {}
    ~SpellQueue() {}
};

Spell* SpellCreation() {
    std::string newProperty;
    Spell * newSpell = new Spell("Crafted Spell");
    std::cout << "Spell Creation: \n";
    int choice = 0;
    for(int i = 0; i <= 4; i++) {
        std::cin >> choice;
        if(i <= 2) 
            newProperty.append(SpellProperties::prefixProperties[choice]);
        else if(i == 3)
            newProperty.append(SpellProperties::affixProperties[choice]);
        else
            newProperty.append(SpellProperties::suffixProperties[choice]);
    }
    newSpell->properties = newProperty;
    std::cout << "Give your spell a name?: ";
    std::cin >> newProperty;
    return newSpell;
}

// Possible split - Purchase Spell with a Spell* return??
void PurchaseSpells(Player &p) {
    int choice = 0;
    char confirm = ' ';
    if(p.storedSpells[10] != nullptr) {
        std::cout << "You have no room to store anymore spells";
        std::cout << "Replace one? Y/N";
        std::cin >> confirm;
        char c = std::tolower(confirm);
        if(c == 'y') {
            int markedSpell = 0;
            std::cin >> markedSpell;
        }
        else
            return;
    }
    std::cout << "===SPELLS===\n";
    for(auto i = Database::spells.begin(); i != Database::spells.end(); i++)
        std::cout << i->first << "| " << i->second->spellName << '\n'; 
    std::cin >> choice;
    int abChoice = abs(choice);
    while(abChoice > Database::spells.size()) {
        std::cout << "\nYou have entered an invalid value: ";
        std::cin >> choice;
        abChoice = abs(choice);
    }
    p.storedSpells_r.push_back(Database::spells[abChoice-1]);
    std::cout << "You purchased " << p.storedSpells_r[p.storedSpells_r.size()-1]->spellName << '\n';


}

void PrintInventory(Player &p, bool detailSpells = false, bool detailWands = false) {
    std::cout << "===INVENTORY===\n";
    for(int i = 0; i < p.storedSpells.size(); i++) {
        std::cout << p.storedSpells[i]->spellName << '\n';
        if(detailSpells) {
            // Print all the parameters of spells
        }
    }
    for(int i = 0; i < p.wands.size(); i++) {
        std::cout << p.wands[i]->wandName << '\n';
        if(detailWands) {

        }
    }
}

void PrintWand(Wand &w, bool printSpells = false) {
    std::cout << w.wandName << '\n';
    if(printSpells) {
        for(int i = 0; i < w.spellLoadout.size(); i++) {
            if(w.curSpell == i)
                std::cout << "|| " << w.spellLoadout[i]->spellName << " ||";
            else
                std::cout << w.spellLoadout[i]->spellName << " ";
        }
    }
    std::cout << "========================\n";
}

// Destroys a wand and gives the player the spells it was holding
void RecycleWand(Player &p) {
    /*
    if(p.storedSpells_r[p.storedSpells_r.size()-1] != nullptr) { // Change to support gaps
        std::cout << "You have no available spell space to recycle a wand";
        return;
    }
    */
    int choice = 0;
    for(int i = 0; i < p.wands.size(); i++) {
        std::cout << i << ") ";
        PrintWand(*p.wands[i]);
    }
    std::cout << "Pick a wand to recycle: ";
    std::cin >> choice;
    int abChoice = abs(choice);
    p.wands[abChoice-1];
    // Find available spots in stored spells, push spells from wand into there, delete wand
        // - Wand should be a copy from the database or the customly created ones
        // - Re-do spell storage system to support gaps, don't want to have everything order, give freedom.
    // Wand recycling:
        // Wand is recycled as long as there is at least a single space left in the stored spells
        // Spell recycling is chosen at random
            // This refers to both amount of spells recycled and the spell itself
            // Takes into account the amount of spells missing and the amount of spells in the wand
    if(p.storedSpells[p.storedSpells_r.size()-1] != nullptr)
        return;
    for(int i = 0; i < p.storedSpells_r.size(); i++) {
        if(p.storedSpells_r[i] == nullptr) {
            int spellChoice = rand() % wandSpells.size();
            p.storedSpells_r[i] = wandSpells.at(spellChoice);
            std::cout << "You recycled " << wandSpells.at(spellChoice)->spellName << " from " << p.wands[spellChoice]->wandName << '\n';
            wandSpells.erase(wandSpells.begin() + spellChoice); // Check!
        }
    }
    // Delete wand from memory!!
        // - Vector erase will cause issues here
            // - Vector erase may delete element
            // As we are not cloing pointer, this will cause several issues
}

void PrintSpells(Player &p) {
    for(int i = 0; i < p.storedSpells.size(); i++) {
        std::cout << p.storedSpells[i]->spellName << ", ";
    }
    std::cout << "========================\n";
}

void ModifyWands(Player &p) {
    int wand = 0;
    int fChoice, sChoice = 0;
    std::cout << "===MODIFY WANDS===\n";
    // An odd way of handling it, just write a universal function for wands?
    for(int i = 0; i < p.wands.size(); i++) {
        PrintWand(*p.wands[i]);
    }
    PrintSpells(p);
    std::cout << "Choose a wand to modify: \n";
    std::cin >> wand;
    int aWand = abs(wand);
    PrintWand(*p.wands[aWand-1]);
    while(fChoice > wandSpells.size() || sChoice > wandSpells.size()) {
        std::cout << "Choose two spells to swap: \n";
        std::cin >> fChoice;
        std::cin >> sChoice;
        Spell temp = *p.wands[aWand-1]->spellLoadout[fChoice];
        *p.wands[aWand-1]->spellLoadout[fChoice] = *p.storedSpells[sChoice];
        *p.storedSpells[sChoice] = temp; // Check!
    }
}

void Interface(Keyboard &key, Player &p) {
    char keyInput;
    while(1) {
        system("clear");
        switch (p.expandInterface) {
            case 0: PrintWand(*p.wands[p.curWand]); break;
            case 1: PrintWand(*p.wands[p.curWand], true); break;
            default: PrintWand(*p.wands[p.curWand]); break;
        }
        std::cout << "===NOITA WAND SYSTEM===\n";
        for(int i = 1; i <= 4; i++) {
            if(i == p.curWand)
                std::cout << "| " << 'x' << " |";
            else
                std::cout << "| " << i << " |";
        }
        putchar('\n');
        std::cin >> keyInput;
        key.Push((int)keyInput);
        key.Parse(p);
    }
}

// Generates wands and there respective spells from an existing pool
void Setup(Keyboard &k, Player &p) {
    p.wands[0] = Database::basicWand;
    for(int i = 1; i < p.maxWands; i++) {
        int randomChoice = rand() % Database::wands.size();
        p.wands[i] = Database::wands[randomChoice];
        randomChoice = rand() % Database::spells.size();
        p.wands[i]->spellLoadout.push_back(Database::spells[randomChoice]);
    }

    // Core
    Database::basicWand->AddSpell(Database::fireBall);
    Database::bombWand->spellLoadout.push_back(Database::fireBomb);

    std::cout << Database::basicWand->spellLoadout.size() << '\n';

    Interface(k,p);
}

int main() {
    Player player;
    Keyboard keyboard; // Want to avoid global and pass object around where needed
    // Saves on constant memory creation + deletion
    // Database::fireBall->Use();

    Setup(keyboard, player);

    return 0;
}