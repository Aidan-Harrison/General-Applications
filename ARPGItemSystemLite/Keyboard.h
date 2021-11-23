#ifndef Keyboard_h
#define Keyboard_h

#include <iostream>

// Using cpp linking could have keyboard be a shortcut to everywhere

struct Keyboard {

    bool Parse(const int key) const;

    Keyboard() {}
    ~Keyboard() {}
};

bool Keyboard::Parse(const int key) const {
    switch(key) {
        case 101: exit(1);  break; // EXIT | E
        case 121: return 1; break; // Confirm/Yes | Y
        case 110: return 0; break; // Deny/No | N
    }
    return false;
}

#endif