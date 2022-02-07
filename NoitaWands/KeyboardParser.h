#ifndef KeyboardParser_h
#define KeyboardParser_h

// Convert to ring buffer?
#include <iostream>
#include <array>

#include "Player.h"

// Stack is pointless here
struct Keyboard {
    int top = -1;
    std::array<int, 10> buffer{};

    bool IsFull();
    bool IsEmpty();
    void Push(const int key);
    int Pop();

    void Parse(Player &p);

    void Print() const;

    Keyboard() {}
    ~Keyboard() {}
};

void Interface(Keyboard &key, Player &p);
void PurchaseSpells(Player &p);
void RecycleWand(Player &p);

bool Keyboard::IsFull() {
    if(top == buffer.size())
        return true;
    return false;
}

bool Keyboard::IsEmpty() {
    if(top == -1)
        return true;
    return false;
}

void Keyboard::Push(const int key) {
    if(IsFull()) {
        std::cout << "You have reached the max number of inputs!\n";
        return;
    }
    top++;
    buffer[top] = key;
}

int Keyboard::Pop() {
    if(IsEmpty()) {
        std::cout << "You have no keyboard input to pop!\n";
        return 0;
    }
    int item = buffer[top];
    buffer[top] = 0;
    top--;
    return item;
}

void Keyboard::Parse(Player &p) {
    switch(Pop()) {
        case 49: p.curWand = 1; break; // 1
        case 50: p.curWand = 2; break; // 2
        case 51: p.curWand = 3; break; // 3
        case 52: p.curWand = 4; break; // 4 | Fix!
        case 101: p.wands[p.curWand-1]->Fire(); break; // FIRE
        case 105: p.expandInterface = 1; break; // Inventory
        case 112: PurchaseSpells(p); // Spell Shop
        case 114: Interface(*this, p); break; // Interface | ????
        case 120: RecycleWand(p);
        case 108: exit(0);
    }
}

void Keyboard::Print() const {
    for(auto i : buffer)
        std::cout << i << ',';
    putchar('\n');
}

#endif