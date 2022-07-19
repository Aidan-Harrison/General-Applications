// ARPG inventory
#include <iostream>
#include <array>
#include <vector>

struct item {
    int sizeX, sizeY; // SIZE
    int posX, posY;
    char code = 'A';
    item(const char c, const int sX, const int sY, const int pX, const int pY)
        :code(c), sizeX(sX), sizeY(sY), posX(pX), posY(pY)
    {
    }
};

std::array<std::array<char, 20>, 10> grid{}; 
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

void SetDisplay() {
    for(unsigned int i = 0; i < items.size(); i++) {
        for(unsigned int j = items[i].posX; j < items[i].posX + items[i].sizeX; j++) 
            for(unsigned int k = items[i].posY; k < items[i].posY + items[i].sizeY; k++)
                grid[j][k] = items[i].code;
    }
}

void Display() {
    for(unsigned int i = 0; i < grid.size(); i++) {
        for(unsigned int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == ' ')
                std::cout << "@,";
            else
                std::cout << grid[i][j] << ',';
        }
        putchar('\n');
    }
}

bool Inventory() {
    // If position is known in grid (Based on top-left corner),
    // boundaries are known, do AABB style collision to check for overlap

    // Mock:
    /*2
        Item 1: 5, 5
            Pos: 0,0
        Item 2: 2, 3
            Pos: 3,4
        Overlap!

        if(item2.posX < item1.sizeX || item2.posY < item1.sizeY)
            FALSE
        
    */
    for(unsigned int i = 1 ; i < items.size()-1; i++) {
        if(items[i].posX <= items[i+1].sizeX + items[i+1].sizeX) {// || items[i].posX >= items[i+1].sizeX + items[i+1].sizeX)
            std::cout << items[i].code << " is colliding with " << items[i+1].code << '\n';
            // return false;
        }
        else if(items[i].posX >= items[i-1].sizeX - items[i-1].sizeX)
            std::cout << items[i].code << " is colliding with " << items[i-1].code << '\n';
        /*
        if(items[i].posX <= items[i+1].sizeX || items[i].posY <= items[i+1].sizeY)
            return false;
        else if(items[i].posX <= items[i-1].sizeX || items[i].posY <= items[i-1].sizeY)
            return false;
        */
    }
    return true;
}

int main() {
    item item1('A',0,0,4,4);
    item item2('B',1,1,2,2);
    item item3('C',3,4,3,3);
    item item4('D',8,8,1,1);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    items.push_back(item4);
    SetDisplay();
    Display();
    if(!Inventory())
        std::cout << "HIT!\n";
    else
        std::cout << "SAFE!\n";

    return 0;
}