#include <map>

#include "KeyboardParser.h"

// Fix wand fire function causing segmentation fault

namespace Database {
    // Spells
    Spell *fireBall  = new Spell("Fireball");
    Spell *iceShot   = new Spell("Ice Shot");
    Spell *lightBolt = new Spell("Light Bolt");
    std::map<int, Spell*> spells;

    // Wands
    Wand *basicWand = new Wand("Basic Wand");
    Wand *fireWand  = new Wand("Fire Wand");
    Wand *iceWand   = new Wand("Ice Wand");
    Wand *lightWand = new Wand("Light Wand");

    std::map<int, Wand*> wands;
}

// If one-time use, else vector
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

void Interface(Keyboard &key, Player &p) {
    char keyInput;
    while(1) {
        system("cls");
        std::cout << "===NOITA WAND SYSTEM===\n";
        std::cin >> keyInput;
        key.Push((int)keyInput);
        key.Parse(p);
    }
}

void Setup(Keyboard &k, Player &p) {
    p.wands[0] = Database::basicWand;
    p.wands[1] = Database::fireWand;
    p.wands[2] = Database::iceWand;
    p.wands[3] = Database::lightWand;

    Database::basicWand->AddSpell(Database::fireBall);
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