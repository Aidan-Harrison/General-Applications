#ifndef Keyboard_h
#define keyboard_h

#include <iostream>
#include <typeinfo>

// Do logic, then template 

template<typename T>
struct Keyboard {
    int key;

    auto Input(bool _parse = true) {
        std::cin >> key;
        if(typeid(key).name() == "i")
            return key;
        parse(key);
        return -1;
    }

    void parse(const int _key) {
        switch (_key) {
        }
    }

    Keyboard() {}
    ~Keyboard() {}
};

#endif