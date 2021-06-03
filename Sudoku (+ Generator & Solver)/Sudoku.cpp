#include <iostream>
#include <tuple>

short grid[9][9] = {
    0,0,0, 0,7,0, 2,0,0,
    3,5,0, 0,0,1, 0,7,9,
    1,0,0, 2,8,0, 0,6,3,

    0,8,0, 0,0,0, 9,0,5,
    6,0,5, 9,0,8, 4,0,7,
    7,0,3, 0,0,0, 0,8,0,

    5,7,0, 0,9,6, 0,0,8,
    9,2,0, 8,0,0, 0,5,4,
    0,0,8, 0,5,0, 0,0,0
};

std::tuple<int,int> pos(0,0);

void PrintBoard() {
    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0)
            std::cout << "=======================\n";
        for(int j = 0; j < 9; j++) {
            if(j % 3 == 0 && j != 0)
                std::cout << " | ";
            if(j == 8)
                std::cout << grid[i][j];
            else
                std::cout << grid[i][j] << " ";
        }
        putchar('\n');
    }
}

bool IsValid(short value, std::tuple<int,int> &pos) {
    // Row
    for(int i = 0; i < 9; i++)
        if(grid[std::get<0>(pos)][i] == value && std::get<0>(pos) != i)
            return false;
    // Column
    for(int i = 0; i < 9; i++)
        if(grid[i][std::get<1>(pos)] == value && std::get<0>(pos) != i)
            return false;

    // Region | Check floor division
    short box_X = std::get<0>(pos) /= 3;
    short box_Y = std::get<1>(pos) /= 3;

    for(int i = box_Y * 3; i < box_Y * 3 + 3; i++) { // Check order!
        for(int j = box_X * 3; j < box_X * 3 + 3; j++) {
            if(grid[box_Y][box_X] == value && i != std::get<0>(pos) && j != std::get<1>(pos)) { // See if possible to shorten! | Check!
                return false;
            }
        }
    }
    return true;
}

bool IsEmpty() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(grid[i][j] == 0) {
                std::get<0>(pos) = i;
                std::get<1>(pos) = j;
                return true;
            }
        }
    }
    return false;
}

bool Solve() {
    bool found = IsEmpty();
    if(!found)
        return true;
    for(int i = 0; i < 9; i++) {
        if(IsValid(i, pos)) {
            grid[std::get<0>(pos)][std::get<1>(pos)] = i; // Check!
            if(Solve())
                return true;
            grid[std::get<0>(pos)][std::get<1>(pos)] = 0;
        }
    }
    return false;
}

void PlayPuzzle() {
    int posX, posY, value;
    std::cout << "Pick a position and its value:\n";
    std::cin >> posX >> posY >> value;
}

void GeneratePuzzle() {

}

int main() {
    PrintBoard();
    Solve();
    std::cout << "///////////////////////////////\n";
    PrintBoard();

    return 0;
}