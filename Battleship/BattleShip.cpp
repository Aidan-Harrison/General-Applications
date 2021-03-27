#include <iostream>
#include <vector>

short input = 0;
bool gameOver = false;
int correctGuesses = 0, incorrectGuesses = 0, amountOfGuesses = 0;
int xGuess = 0, yGuess = 0;
std::vector<std::vector<short>> ships = { {1, 1, 1, 0, 1, 0},
                                          {0, 0, 0, 0, 1, 0},
                                          {0, 0, 0, 0, 1, 0},
                                          {0, 0, 0, 0, 1, 1},
                                          {1, 1, 0, 0, 0, 1} };
void Game() {
    system("cls");
    for(unsigned int i = 0; i < ships.size(); i++) {
        for(unsigned int j = 0; j < ships[0].size(); j++) {
            if(ships[i][j] == 2) putchar('X');
            else putchar('.');
        }
        std::cout << '\n';
    }
    std::cout << "Board Size| " << "X: " << ships[0].size() << " Y: " << ships.size() << '\n';
    std::cout << "What would you like to do:\n";
    std::cout << "1) Make a guess  | 2) Give up\n";
    std::cin >> input;
    if(input == 1) {
        std::cout << "\nEnter the X coordinate: "; std::cin >> xGuess;
        std::cout << "Enter the Y coordinate: ";   std::cin >> yGuess;
        amountOfGuesses++;
        if(ships[xGuess][yGuess] == 1) {
            std::cout << "Hit\n";
            ships[xGuess][yGuess] = 2;
            correctGuesses++;
        }
        else {
            std::cout << "Miss\n";
        }
        if(ships[xGuess-1][yGuess-1] == 1)
            std::cout << "SHIP-LEFT!\n";
        if(ships[xGuess+1][yGuess+1] == 1)
            std::cout << "SHIP-RIGHT!\n";
    }
    else if(input == 2) {
        gameOver = false;
        std::cout << "Miss!\n";
    }
    std::cout << "Correct Guesses: " << correctGuesses << '\n';
    std::cin.get();
    std::cin.get();
}

int main() {
    while(!gameOver)
        Game();
    return 0;
}