// ARPG inventory
#include <iostream>
#include <array>
#include <vector>

struct item {
    int sizeX, sizeY; // SIZE
    int posX, posY;
};

std::array<std::array<bool, 20>, 10> grid{}; 
std::vector<item> items{};

// DO DFS?
/*
    a = 5 x 3
    aPos = 0,0

    b = 2 x 6
    bPos = 6,0

    c = 2 x 2
    cPos = 12,3

    Example:
    bPos = {12, 0}

    is c overlapping?

    if(c.xPos <= b.xPos)
        if(c.yPos < b.y)
            OVERLAP!
    else if(c.yPos <= b.yPos)
        if(c.xPos < b.x)
            OVERLAP!

    a a a a a b b * * * * * * * * * * * * *
    a a a a a b b * * * * * * * * * * * * *
    a a a a a b b * * * * c c * * * * * * *
    * * * * * b b * * * * c c * * * * * * *
    * * * * * b b * * * * * * * * * * * * *
    * * * * * b b * * * * * * * * * * * * *
    * * * * * * * * * * * * * * * * * * * *
*/

void Inventory() {
    // If position is known in grid (Based on top-left corner),
    // boundaries are known, do AABB style collision to check for overlap

    // Mock:
    /*
        Item 1: 5, 5
            Pos: 0,0
        Item 2: 2, 3
            Pos: 3,4
        Overlap!

        if(item2.posX < item1.sizeX || item2.posY < item1.sizeY)
            FALSE
        
    */
    for(unsigned int i = 1 ; i < items.size()-1; i++) {
        if(items[i].posX <= items[i+1].sizeX || items[i].posY <= items[i+1].sizeY)
            return;
        else if(items[i].posX <= items[i-1].sizeX || items[i].posY <= items[i-1].sizeY)
            return;
    }
}

int main() {

    return 0;
}