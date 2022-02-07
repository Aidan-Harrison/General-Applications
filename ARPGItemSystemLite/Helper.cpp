#include <iostream>
#include <cmath>

// Convert to header file if doing object, else, remove object and
// keep as .cpp file

// Check everything!
struct Random {
    int randi(const int value, bool zero = false); 
    float randf(const int value);
    int randi_range(const int min, const int max);
    float randf_range(const float min, const float max);
};

int Random::randi(const int value, bool zero = false) {
    switch(zero) {
        case true: rand() % value; break;
        case false: rand() % value + 1; break;
    }
    return -1;
}

float Random::randf(const int value) {

}

int Random::randi_range(const int min, const int max) {
    return (int)min + rand() % max + 1;
}

float Random::randf_range(const float min, const float max) { //Check!
    float n = max;
    int whole = floor(max); // Check if affects result!
    float decimal = max - whole;
    return (float)min + rand() % (int)max + decimal;
}