#include <iostream>
#include <array>

// Space invaders

namespace Global {   
    std::array<std::array<char, 6>, 6> invaders;
}

struct Player {
    int x, y;
    int health = 0;
};

using namespace Global;

void Draw() {
    for(unsigned int row = 0; row < invaders.size(); row++) {
        for(unsigned int col = 0; col < invaders.size(); col++)
            std::cout << invaders[row][col] << "   ";
        putchar('\n');
    }
}

void logic() {

}

void Input() {

}

int main() {

    return 0;
}