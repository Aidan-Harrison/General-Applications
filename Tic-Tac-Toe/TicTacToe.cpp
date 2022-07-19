#include <iostream>
#include <stack>
#include <utility>

char grid[3][3] = {
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '
};
bool checkGrid[3][3] = {
    false, false, false,
    false, false, false,
    false, false, false
};

int inputX = 0, inputY = 0;
bool gameOver = false;

void PrintGame() {
    system("cls");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            std::cout << grid[i][j] << " | ";
        putchar('\n');
    }
}

const std::pair<int,int> PickSquare(const int input) { // Replace with maths?
    switch(input) {
        case 1: { 
            if(!checkGrid[0][0]) { 
                grid[0][0] = 'X'; 
                checkGrid[0][0] = true; 
                return {0,0};
            } break; } 
        case 2: { 
            if(!checkGrid[0][1]) { 
                grid[0][1] = 'X'; 
                checkGrid[0][1] = true; 
                return {0,1};
            } break; } 
        case 3: { 
            if(!checkGrid[0][2]) { 
                grid[0][2] = 'X'; 
                checkGrid[0][2] = true; 
                return {0,2};
                } break; } 
        case 4: { 
            if(!checkGrid[1][0]) { 
                grid[1][0] = 'X'; 
                checkGrid[1][0] = true; 
                return {1,0};
            } break; } 
        case 5: { 
            if(!checkGrid[1][1]) { 
                grid[1][1] = 'X'; 
                checkGrid[1][1] = true; 
                return {1,1};
                } break; } 
        case 6: { 
            if(!checkGrid[1][2]) { 
                grid[1][2] = 'X'; 
                checkGrid[1][2] = true; 
                return {1,2};
                } break; } 
        case 7: { 
            if(!checkGrid[2][0]) { 
                grid[2][0] = 'X'; 
                checkGrid[2][0] = true; 
                return {2,0};
                } break; } 
        case 8: { 
            if(!checkGrid[2][1]) { 
                grid[2][1] = 'X'; 
                checkGrid[2][1] = true; 
                return {2,1};
                } break; } 
        case 9: { 
            if(!checkGrid[2][2]) { 
                grid[2][2] = 'X'; 
                checkGrid[2][2] = true; 
                return {2,2};
                } break; } 
    }    
    return {-1,-1};
}

void ReWrite() {
    int input = 0;
    int correct = 0;
    PrintGame();
    std::cin >> input;
    std::stack<std::pair<int,int>> s;
    auto boundsCheck = [&](const int x, const int y) {
        return x > 0 && x < 3 && y > 0 && y < 3;
    };
    std::pair<int,int> direections[8] = {{0,1}, {1,0}, {-1,0}, {0,1}, {1,1}, {-1,1}, {-1,-1}, {1,-1}};
    s.push(PickSquare(input));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] == 'X' && !checkGrid[i][j]) {
                while(!s.empty()) {
                    std::pair<int,int> cur = s.top();
                    s.pop();
                    for(std::pair<int,int> dir : direections) {
                        std::pair<int,int> newLoc;
                        newLoc.first = dir.first + i;
                        newLoc.second = dir.second + j;
                        if(grid[newLoc.first][newLoc.second] == 'X' && !checkGrid[newLoc.first][newLoc.second]) {
                            
                            
                        }
                    }
                }
            }
        }
    }
}

void TicTacToe() { // Make recursive
    std::cin >> inputX >> inputY;
    grid[inputY][inputX] = 'X'; // Change after chars set

    if(grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X') gameOver = true; std::cout << "X wins!"; // Top
    if(grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') gameOver = true; std::cout << "X wins!"; // Left
    if(grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') gameOver = true; std::cout << "X wins!"; // Middle H
    if(grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X') gameOver = true; std::cout << "X wins!"; // Middle V
    if(grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X') gameOver = true; std::cout << "X wins!"; // Bottom
    if(grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X') gameOver = true; std::cout << "X wins!"; // Right
    if(grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') gameOver = true; std::cout << "X wins!"; // Diagonal L-R
    if(grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X') gameOver = true; std::cout << "X wins!"; // Diagonal R-L

    if(grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O') gameOver = true; std::cout << "O wins!"; 
    if(grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') gameOver = true; std::cout << "O wins!"; 
    if(grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O') gameOver = true; std::cout << "O wins!"; 
    if(grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O') gameOver = true; std::cout << "O wins!"; 
    if(grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O') gameOver = true; std::cout << "O wins!"; 
    if(grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O') gameOver = true; std::cout << "O wins!"; 
    if(grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') gameOver = true; std::cout << "O wins!"; 
    if(grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O') gameOver = true; std::cout << "O wins!"; 
}

int main() {
    while(!gameOver)
        TicTacToe();

    return 0;
}