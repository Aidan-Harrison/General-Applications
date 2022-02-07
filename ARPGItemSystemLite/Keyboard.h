#ifndef Keyboard_h
#define Keyboard_h

#include <iostream>

// Using cpp linking could have keyboard be a shortcut to everywhere

struct Keyboard {
    int input = 0;
    int Parse(const int key, bool parseHere);

    Keyboard() {}
    ~Keyboard() {}
};

int Keyboard::Parse(const int key, bool parseHere = false) {
    if(parseHere)
        std::cin >> input;
    else
        input = key;
    switch(input) {
        case 101: exit(1);  break; // EXIT | E
        case 121: return 1; break; // Confirm/Yes | Y
        case 110: return 0; break; // Deny/No | N
    }
    return input;
}

#endif