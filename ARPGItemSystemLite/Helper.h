#ifndef Helper_h
#define Helper_h

#include <iostream>
#include <cmath>

// Contains several useful functions to improve readability
void clear_screen() {
    #ifdef _WIN64 
        system("cls");
    #elif __APPLE__ || __MACH__
        system("clear");
    #endif 
}

inline void Enter() {
    std::cin.get();
    std::cin.get();
}

int random(int range) { return rand() % range; }
int NonZeroRand(int range) { 
    int result = rand() % range;
    return result+1;
}

void input(const std::string && msg, int * choice) {
    std::cout << msg;
    std::cin >> *choice;
}
int return_input(const std::string && msg, int * choice) {
    std::cout << msg;
    std::cin >> *choice;
    return *choice;
}

int int_input(const std::string && msg) {
    std::cout << msg;
    int inp;
    std::cin >> inp;
    return inp;
}
char char_input(const std::string && msg, bool lower = false) {
    std::cout << msg;
    char c = 'a';
    std::cin >> c;
    if(lower)
        c = std::tolower(c);
    return c;
}

struct Random {
    int randi(const int value, bool zero); 
    float rand_f(const float value, bool zero);
    int randi_range(const int min, const int max);
    float randf_range(const float min, const float max);
};

int Random::randi(const int value, bool zero = false) {
    if(zero)
        return rand() % value;
    return rand() % value + 1;
}

/*
float Random::rand_f(const float value, bool zero = false){
    if(zero)
        return (float)rand() % (int)value;
    return rand() % (int)value + 0.1;
}
*/

int Random::randi_range(const int min, const int max) {
    return (int)min + rand() % max + 1;
}

float Random::randf_range(const float min, const float max) { //Check!
    float n = max;
    int whole = floor(max); // Check if affects result!
    float decimal = max - whole;
    return (float)min + rand() % (int)max + decimal;
}

#endif