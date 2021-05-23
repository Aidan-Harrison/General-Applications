#include <stdio.h>

struct dungeon {
    int width; 
    int height;
};

struct player {
    int xPos, yPos;
    union position {
        int x, y;
    };
};

int main() {
   printf("Dungeon");
}