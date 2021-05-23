#include <iostream>
#include <string>
#include <vector>

bool playing = false;
void DrawMan(std::string word, short amountOfGuesses);

void Game(std::string word) {
	system("cls");
	short lives = 10;
	char guess = ' ';
	short correctGuesses = 0, incorrectGuesses = 0;
	std::cout << "Word length: " << word.length() << " | Correct guesses: " << correctGuesses << " | Incorrect guesses: " << incorrectGuesses;
	std::cout << "\nLives left: " << lives << '\n';
	std::cout << "\nMake a guess: "; std::cin >> guess;
	DrawMan(word, incorrectGuesses);
}

void DrawMan(std::string word, short amountOfGuesses) {
	if (amountOfGuesses == 1)
		std::cout << "\n_______";
	else if (amountOfGuesses == 2)
		std::cout <<"|		\n" <<
					"|		\n" <<
					"|		\n" <<
					"|		\n" <<
					 "_______";
	else if (amountOfGuesses == 3)
		std::cout << "_____" <<
					"|		\n" <<
					"|		\n" <<
					"|		\n" <<
					"|		\n" <<
					"_______";
	else if (amountOfGuesses == 4)
		std::cout << "_____" <<
					"|   |	\n" <<
					"|		\n" <<
					"|		\n" <<
					"|		\n" <<
					"_______";
	else if (amountOfGuesses == 5)
		std::cout << "_____" <<
					"|   |  \n" <<
					"|   0  \n" <<
					"|		\n" <<
					"|		\n" <<
					"_______";
	else if (amountOfGuesses == 6)
		std::cout << "_____" <<
					"|   |  \n" <<
					"|   0  \n" <<
					"|   |  \n" <<
					"|		\n" <<
					"_______";
	else if (amountOfGuesses == 7)
		std::cout << "_____" <<
					"|   |	\n" <<
					"|   0	\n" <<
					"|   |--\n" <<
					"|		\n" <<
					"_______";
	else if (amountOfGuesses == 8)
		std::cout << "_____" <<
					"|   |	\n" <<
					"|   0	\n" <<
					"| --|--\n" <<
					"|		\n" <<
					"_______";
	else if (amountOfGuesses == 9)
		std::cout << "_____" <<
					"|   |  \n" <<
					"|   0  \n" <<
					"| --|--\n" <<
					"|  /	\n" <<
					"_______";
	else if (amountOfGuesses == 10)
		std::cout << "_____" <<
					"|   |	\n" <<
					"|   0	\n" <<
					"| --|--\n" <<
					"|  / \\" << '\n' <<
					"_______"; 
	std::cin.get();
	Game(word);
}

void Setup() { // Setup two and one player modes
	std::string word = " ";
	short lives;
	std::cout << "Enter a word for your opponent to guess: "; std::cin >> word;
	playing = true;
	Game(word);
}

int main() {
	Setup();
	std::cin.get();
	return 0;
}