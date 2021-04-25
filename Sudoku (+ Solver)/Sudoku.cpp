// Sudoku

#include <iostream>

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
short rows = 0, columns = 0;

// DONE:
    // Row and column checks
// TO-DO:
    // Cell checking (3x3)
    // Solving algorithm
    // Playing

void PrintBoard() {
    for(short i = 0; i < 9; i++) {
        for(short j = 0; j < 9; j++) {
            std::cout << grid[i][j] << ' ';
            columns++;
            if(columns % 3 == 0)
                std::cout << " | ";
        }
        rows++;
        putchar('\n');
        if(rows % 3 == 0) {
            std::cout << "--------------------------";
            putchar('\n');
        }
    }
}

bool CheckRow(short cellX, short cellY) {
    for(short rows = cellX; rows < cellX + 1; rows++) {
        for(short columns = 0; columns < 9; columns++) {
            std::cout << grid[rows][columns] << ' ';
            if(grid[rows][columns] == cellX && grid[0][rows] == cellY) // Found duplicate
                return false;
        }
    }
    return true;
}

bool CheckColumn(short cellX, short cellY) {
    for(short rows = 0; rows < 9; rows++) {
        for(short columns = cellY; columns < cellY + 1; columns++) {
            std::cout << grid[rows][columns] << ' ';
            if(grid[columns][0] == cellX && grid[0][rows] == cellY) // Check if cell == grid[][] is faster!?
                return false;
        }
    }
    return true;
}

bool CheckRegion() {

}

/*
void SolvePuzzle() {
    bool validity = false;
    for(int rows = 0; rows < 9; rows++) {
        CheckRow(grid[rows][0]);
        for(int columns = 0; columns < 9; columns++) {
            CheckColumn(grid[0][columns]);
        }
    }
    //CheckRow();
    //CheckColumn();
}
*/

void PlayPuzzle() {

}

int main() {
    // PrintBoard();
    CheckRow(4, 2);
    putchar('\n');
    CheckColumn(6, 4);
    return 0;
}