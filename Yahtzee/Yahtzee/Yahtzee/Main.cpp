#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <fstream>

// Do encrpytion and decryption
// Include rvalue when needed

void Header(std::string name = " ") {
	std::cout << "Welcome to Chamption Yahtzee " << name << '\n';
}

class Player { // MOVE TO HEADER FILE
private:
	std::string username = "";
	std::string password = "";
	int highestScore = 0;
	int totalGames = 0;
	int accumulatedScore = 0;
	// Write history function
		// Calculate average score
public:
	int score = 0;
    std::vector<std::tuple<bool, int>> dice{}; // Brief wasn't clear how to handle dice, so each player has their own set of integers. Would allow for easy expansion
    std::vector<std::string> diceGraphics{}; // Based on current roll
	Player() {}
	Player(std::string &name, std::string &pass, int hScore)
		:username(name), password(pass), highestScore(hScore)
	{
		// Decrpyt(name, pass);
    }

	void History() const { // MOVE TO .cpp file, define definition there instead
        std::cout << "Highest Score: " << highestScore << '\n'; 
        std::cout << "Total Games: " << totalGames << '\n'; 
        std::cout << "Accumulated Score: " << accumulatedScore << '\n'; 
	}
    void ScoreCard() {
        std::cout << "---- SCORECARD ----\n";
        std::cout << "Aces: ";
        std::cout << "Twos: ";
        std::cout << "Threes: ";
        std::cout << "Fours: ";
        std::cout << "Fives: ";
        std::cout << "Sixes: ";
        std::cout << "-------------------------\n";
	    std::cout << "Total: " << score << '\n';
        std::cout << "-------------------------\n\n";
    }

	~Player() {} // Write to file using destructor
};

void ScoreCard();
void Interface(); // Remove!

void EncrpytAndWrite() { // Encrpyts and writes to file, only happens on 'Exit()'
	// Go through player vector
}

void Decrpyt(std::string str1 = " ", std::string str2 = " ") { // Reads from file and decrpyts. Call in 'Player' constrcutor
}

namespace Global {
	std::fstream fileHandler;
	std::vector<Player*> players{};
    std::unordered_map<int, Player*> playersMap{}; // You will learn hash-tables/hash-maps soon
	bool playing = false;
	int choice = 0;
}

namespace DiceGraphics {
	std::string diceOne = "#########\n"
					      "#     1 #\n"
						  "#     1 #\n"
						  "#     1 #\n"
						  "#     1 #\n"
					      "#     1 #\n"
					      "#########\n";
	// ==============================
	std::string diceTwo = "#########\n"
						  "# 22222 #\n"
						  "#     2 #\n"
						  "# 22222 #\n"
						  "# 2     #\n"
						  "# 22222 #\n"
						  "#########\n";
	// ==============================
	std::string diceThree = "#########\n"
							"# 33333 #\n"
							"#     3 #\n"
							"# 33333 #\n"
							"#     3 #\n"
							"# 33333 #\n"
							"#########\n";
	// ==============================
	std::string diceFour = "#########\n"
						   "# 4   4 #\n"
						   "#     4 #\n"
						   "# 44444 #\n"
						   "#     4 #\n"
						   "#     4 #\n"
						   "#########\n";
	// ==============================
	std::string diceFive = "#########\n"
						   "# 55555 #\n"
						   "# 5     #\n"
						   "# 55555 #\n"
					       "#     5 #\n"
						   "# 55555 #\n"
						   "#########\n";
	// ==============================
	std::string diceSix = "#########\n"
						  "# 66666 #\n"
						  "# 6     #\n"
						  "# 66666 #\n"
						  "# 6   6 #\n"
						  "# 66666 #\n"
						  "#########\n";
}

void PlayerSetup(std::string &name, std::string &pass, std::string &score) {
	int scoreNum = stoi(score);
	// Could also cnvert in player object through constructor definition, however that would mean we couldn't use our initialiser list
	Player* newPlayer = new Player(name, pass, scoreNum); 
	Global::players.push_back(newPlayer);
}

void FileParser(const std::string &&filePath) { // Only needs to run once
	Global::fileHandler.open(filePath);
	if (Global::fileHandler.fail()) {
		std::cerr << "Failed to open " << filePath << " either corrupt or missing!\n";
		exit(1);
	}
	int counter = 1;
	std::string name = "";
	std::string pass = "";
	std::string score = "";
	while (!Global::fileHandler.eof()) { // Parse lines of data per player
		switch (counter) {
		case 1: Global::fileHandler >> name; break;
		case 2: Global::fileHandler >> pass; break;
		case 3: Global::fileHandler >> score; break;
		}
		if (counter == 3) {
			PlayerSetup(name, pass, score);
			counter = 1;
		}
		else
			counter++;
	}
}


void ChoosePlayer() {
	std::string input = "";
	std::cout << "Please enter player name:"; std::cin >> input;
	std::cout << "Please enter player password:"; std::cin >> input;
	// Handle login
}

void Game() {
    int rollsLeft = 3;
    int scoreID   = 0;
    int playerID  = 0;
	while (playerID < Global::players.size()) {
        std::tuple<bool,int> curTuple;
        std::cout << "Turn " << playerID << " out of " << Global::players.size();
        Global::players[playerID]->ScoreCard();            
        std::cout << "Choose keepers (Enter 7 to continue):\n";
        std::cin >> Global::choice;

        std::cout << "Choose how to score your dice:\n" 
                      << "1) Aces\n"
                      << "2) Twos\n"
                      << "3) Threes\n"
                      << "4) Fours\n"
                      << "5) Fives\n"
                      << "6) Sixes\n";
        scoreID = Global::choice;
        if(std::get<1>(Global::players[playerID]->dice[playerID]) == scoreID) {
            Global::players[playerID]->score += scoreID;
        }
        if(rollsLeft > 0)
            rollsLeft--;
        else {
            rollsLeft = 0;
            playerID++;
        }
	}

    // Get winner
    int max = 0;
    for(unsigned int i = 0; i < Global::players.size(); i++) {
        if(Global::players[i]->score > max)
            max = Global::players[i]->score;       
    }
}

void PreGame() {
	Header(); 
	std::cout << "1) Play Game\n"
		      << "2) View Historic Scorecards\n"
		      << "3) Return to player choose screen\n";
	std::cout << "Please choose an option: "; std::cin >> Global::choice;
	while (Global::choice < 1 || Global::choice > 3) {
		switch (Global::choice) {
			case 1: Game(); break;
			case 2: break;
			case 3: Interface(); break;
		}
	}
}

void Interface() {
	Header();
	std::cout << "1) Choose Player\n"
	          << "2) Add Player\n"
			  << "3) Remove Player\n"
			  << "4) Sort Players Alphabetically\n"
			  << "5) Sort by Highest Score\n"
			  << "6) Exit\n\t";
	std::cout << "Please choose an option: "; std::cin >> Global::choice;
	while (Global::choice < 0 || Global::choice > 6) {
		switch (Global::choice) {
			case 1: ChoosePlayer(); break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
			case 6: EncrpytAndWrite(); break;
        }
	}
}

int main() {
	Interface();

	return 0;
}

        // Roll dice
        /*
        for(auto it = Global::playersMap.begin(); it != Global::playersMap.end(); it++) {
            std::cout << "Player" << it->first << " out of " << Global::playersMap.size() << '\n';
            it->second->ScoreCard();
            if(it->second->rollsLeft <= 0)
                std::cout << "Out of rolls!\n";
            for(unsigned int i = 0; i < it->second->dice.size(); i++) {
                std::get<0>(curTuple) = it->second->dice[i];
                std::get<1>(curTuple) = it->second->dice[i];
                bool isKeeper = std::get<0>(curTuple);
                if(!isKeeper) { // Roll dice
                    std::get<1>(curTuple) = rand() % 6;
                    std::get<1>(curTuple)++;
                    std::cout << std::get<1>(curTuple);
                    switch(std::get<1>(curTuple)) { // Change
                        case 1: it->second->diceGraphics[i] = DiceGraphics::diceOne;  break;
                        case 2: it->second->diceGraphics[i] = DiceGraphics::diceTwo;  break;
                        case 3: it->second->diceGraphics[i] = DiceGraphics::diceThree;break;
                        case 4: it->second->diceGraphics[i] = DiceGraphics::diceFour; break;
                        case 5: it->second->diceGraphics[i] = DiceGraphics::diceFive; break;
                        case 6: it->second->diceGraphics[i] = DiceGraphics::diceSix;  break;
                    }
                }
                else {
                    std::cout << "Dice " << i << " is a keeper!\n";
                    break;
                }
            } 

        }
        */