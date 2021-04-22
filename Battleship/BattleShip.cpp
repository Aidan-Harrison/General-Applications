#include <iostream>
#include <vector>

void Game();

short input = 0;
short amountDestroyed = 0;
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
            else if(ships[i][j] == 3) putchar('!');
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
        if(ships[yGuess-1][xGuess-1] == 1) {
            std::cout << "Hit\n";
            ships[yGuess-1][xGuess-1] = 2;
            correctGuesses++;
        }
        else {
            std::cout << "Miss\n";
            ships[yGuess][xGuess] == 3;
        }
        // DEBUG
            if(ships[xGuess-1][yGuess] == 1) std::cout << "SHIP-LEFT!\n";
            if(ships[xGuess+1][yGuess] == 1) std::cout << "SHIP-RIGHT!\n";
            if(ships[xGuess][yGuess+1] == 1) std::cout << "SHIP-DOWN\n";
            if(ships[xGuess][yGuess-1] == 1) std::cout << "SHIP-UP\n";
    }
    else if(input == 2) {
        gameOver = true;
    }
    std::cout << "Correct Guesses: " << correctGuesses << '\n';
    std::cin.get();
    std::cin.get();
    // Check board
    for(unsigned int i = 0; i < ships.size(); i++)
        for(unsigned int j = 0; j < ships[0].size(); i++)
            if(ships[i][j] == 1)
                amountDestroyed++;
    if(amountDestroyed == ships.size()) {
        gameOver = true;
        std::cout << "You win!\n";
    }
}

int main() {
    while(!gameOver)
        Game();
    return 0;
}