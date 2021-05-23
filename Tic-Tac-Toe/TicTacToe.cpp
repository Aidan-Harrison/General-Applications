#include <iostream>

char grid[3][3] = {
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '
};
int inputX = 0, inputY = 0;
bool gameOver = false;

void PrintGame(char g[3][3]) {
    system("cls");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << g[i][j] << " | ";
        }
        putchar('\n');
    }
}

void TicTacToe() { // Make recursive
    PrintGame(grid);
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