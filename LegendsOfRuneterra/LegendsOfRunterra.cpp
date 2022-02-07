// Legends of Runeterra

#include <iostream>
#include <algorithm>
#include <tuple>
#include "Deck.h"

namespace Board {
    Deck *curDeck = nullptr;
    // Spell Stack
    int top = 0;
    std::vector<Card*> spells{};
    // Moved from game function to make cleaner
    std::vector<Card*> playerBench{}; // Change ALL to array of size 6/7
    std::vector<Card*> enemyBench{};
    std::vector<Card*> playerBoard{};
    std::vector<Card*> enemyBoard{};
}

namespace ShadowIslesCards {
    Card *shadowTestCard = new Card("Test Shadow Card", 1, 1, 1);
    std::vector<Card*> shadowIslesCards = {shadowTestCard}; 
}

namespace PiltoverZaunCards {
    Card *piltZaunTestCard = new Card("Test PiltZuan Card", 1, 1, 1);
    std::vector<Card*> piltoverZaunCards = {piltZaunTestCard}; 
}

namespace Decks {
    Deck *defaultDeck = new Deck("Default Deck");
    std::vector<Deck*> decks{defaultDeck};
}

void FillDeck(Deck &deck) {
    for(unsigned int i = 0; i < 40; i++) {
        Card *newCard = new Card("Default Card", 1, 1, 1);
        deck.cards[i] = newCard;
    }
}

// Shuffles deck 
void Shuffle(Deck &deck, const int amount = 40) { // Check '*'
    int firstCard = 0, secondCard = 1;
    for(int i = 0; i < amount; i++) {
        firstCard = rand() % amount;
        secondCard = rand() % amount;
        Card *tempCard = deck.cards[firstCard];
        deck.cards[firstCard] = deck.cards[secondCard];
        deck.cards[secondCard] = tempCard;
    }
}

// Enemy AI/Turn
char Enemy(int nexusHealth, int mana, Deck &eDeck, std::vector<Card*> &eHand, const bool isBlocking = false) {
    // Key:
    // 'a' == Attacking
    // 's' == skipping
    // ADD MORE!
    
    // Get game state
    // Loop through board if blocking!
    std::vector<int[3]> cardValues{}; // Check!
    std::vector<Card*> data{}; // Universal system, cuts down on code
    // Works on bench, board, hand, deck etc.
    if(isBlocking)
        data = Board::enemyBoard;
    else
        data = Board::enemyBench;
    for(unsigned int i = 0; i < data.size(); i++) {
        int cardState[3] = {};
        cardState[0] = data[i]->cardCost;
        cardState[1] = data[i]->cardPower;
        cardState[2] = data[i]->cardToughness;
        cardValues.push_back(cardState);
    } 

    // Hand/Play
    // Currently plays the first card it can
    for(unsigned int i = 0; i < data.size(); i++) {
        if(mana >= data[i]->cardCost) {
            return 'p';
        }
    }

    // Choose choice base on current 'self' state
    // Recursive based?
    // Narrow down options

    // Attack
    if(Board::enemyBench.size() == 0)
        return 's';
    else {
        for(unsigned int i = 0; i < Board::enemyBench.size(); i++) {
            if(Board::enemyBoard[i]->cardPower <= 0 || Board::enemyBoard[i]->cardToughness == 1) // Improve
                continue;
        }
        // Check if players cards are too much of a threat to worth attacking
        // Check if nexus is open
        // Check if current cards are worth using
    }

    return 's';
}

void DrawHand(bool isStarting, std::vector<Card*> &pHand) {
    if(isStarting)
        for(int i = 0; i <= 4; i++)    
            std::cout << pHand[i]->GetName() << " | ";
    else
        for(int i = 0; i < pHand.size(); i++)    
            std::cout << pHand[i]->GetName() << " | ";
}   

void StartingHand(Deck & pDeck, std::vector<Card*> *pHand, Deck &eDeck, std::vector<Card*> *eHand) {
    // Pushes 4 to the hand
    // Gives user choice to keep or throw
    std::string choice = "";
    std::vector<bool> markedCards{false}; // Check!
    for(unsigned int i = 0; i <= 4; i++) {
        pHand->push_back(pDeck.Draw());
        eHand->push_back(eDeck.Draw());
    }
    std::cout << "===STARTING HAND===\n";
    DrawHand(true, *pHand);
    std::cout << "Mark cards to discard: (Input as string)";
    std::cin >> choice;
    while(choice.length() > 4) {
        std::cout << "You have marked too many cards, must be 4 numbers!\n";
        std::cin >> choice;
    }
    for(int i = 0; i < 4; i++) { // Duplicate check | Optimise! | Fix!
        std::sort(choice.begin(), choice.end());
        while(choice[i] == choice[i+1]) {
            std::cout << "You have entered a duplicate, each number must be different!\n";
            std::cout << "First: " << choice[i] << " | Second: " << choice[i+1];
            std::cin >> choice;
        }
    } 
    if(choice.find('1')) markedCards[0] = true;
    if(choice.find('2')) markedCards[1] = true;
    if(choice.find('3')) markedCards[2] = true;
    if(choice.find('4')) markedCards[3] = true;
    for(int i = 0; i <= 4; i++) {
        if(markedCards[i] == true) {
            pDeck.Add(pHand->at(i));
            pHand->push_back(pDeck.Draw());
        }
    }
    DrawHand(false, *pHand);
}

void Game(Deck &pDeck, Deck &eDeck) {
    int choice = 0;
    std::vector<Card*> yourHand{};
    std::vector<Card*> enemyHand{};
    Card * currentCard = nullptr;
    int curTurn = 0;
    bool yourTurn = true;
    bool hasAttackToken = true;
    int yourNexusHealth = 20;
    int enemyNexusHealth = 20;
    int yourCurMana = 1, yourMaxMana = 1;
    int enemyCurMana = 1, enemyMaxMana = 1;

    Shuffle(pDeck);
    Shuffle(eDeck);
    StartingHand(pDeck, &yourHand, eDeck, &enemyHand);

    while(yourNexusHealth > 0 || enemyNexusHealth > 0) {
        // Start of Turn:
        if(yourHand.size() < 8)
            yourHand.push_back(pDeck.Draw());
        if(enemyHand.size() < 8)
            enemyHand.push_back(eDeck.Draw());

        std::cout << "Turn: " << curTurn;
        if(yourTurn)
            std::cout << "\tYour turn!\n\n";
        else
            std::cout << "\tEnemy turn!\n\n";
        std::cout << "Enemy Nexus: " << enemyNexusHealth << "\t\tEnemy Mana: " << enemyCurMana << '\n';
        std::cout << "Your Nexus: " << yourNexusHealth << "\t\tYour Mana: " << yourCurMana << '\n';

        std::cout << "Your Deck: " << pDeck.GetName() << '\t';
        std::cout << "Cards Left: " << pDeck.top << '\n';

        std::cout << "Enemy Deck: " << eDeck.GetName() << '\t';
        std::cout << "Cards Left: " << eDeck.top << '\n';

        DrawHand(false, yourHand);

        if(yourTurn) {
            std::cout << "Pick a card or enter (0) to skip!\n";
            std::cin >> choice;
            if(choice == 0)
                continue;
            currentCard = yourHand[choice-1];
            std::cout << currentCard->GetName();
            if(currentCard->type == 1) { // Spells
                if(currentCard->spellType == 0 || currentCard->spellType == 1)
                    Board::spells.push_back(currentCard);
                else {// Must be burst, use!
                    return;
                }
            }
            else if(currentCard->type == 0 || currentCard->type == 2) {
                Board::playerBoard.push_back(currentCard);
            }
            if(hasAttackToken) {
                std::cout << "Do you want to attack?: Y/N";
                std::cin >> choice; // Change to char
                if(choice == 1) {
                    std::string strChoice = "";
                    std::cout << "Choose each cards position on board: ";
                    std::cout << "Use format: '1>2,3>1' etc...\n"; // Add safety
                    std::cin >> strChoice;
                    std::string curBlock = "";
                    std::vector<std::string> blocks{};
                    for(unsigned int i = 0; i < strChoice.length(); i++) {
                        curBlock += strChoice[i];
                        if(strChoice[i] == ',') {
                            blocks.push_back(curBlock);
                            curBlock.clear();
                        }
                    }
                    for(unsigned int i = 0; i < blocks.size(); i++) { // Move don't copy!
                        Board::playerBoard[blocks[i].at(2)-1] = Board::playerBench[blocks[i].at(0)-1];
                        Board::playerBench.erase(Board::playerBench.begin() + blocks[i].at(0)-1); // Check!
                    }
                    // Once done, return cards to bench if possible
                    std::cout << "Confirm attack?: Y/N\n";
                    std::cin >> choice; // Do!
                    for(unsigned int i = 0; i < Board::playerBoard.size(); i++) {
                        if(Board::playerBoard[i] != nullptr && Board::enemyBoard[i] != nullptr) {
                            Board::enemyBoard[i]->cardToughness -= Board::playerBoard[i]->cardPower;
                            Board::playerBoard[i]->cardToughness -= Board::enemyBoard[i]->cardPower;
                            if(Board::enemyBoard[i]->cardToughness <= 0) {
                                std::cout << "Enemies " << Board::enemyBoard[i]->GetName() << " was destroyed!\t";
                                Board::enemyBoard[i] = nullptr;
                            }
                            if(Board::playerBoard[i]->cardToughness <= 0) {
                                std::cout << "Your " << Board::playerBoard[i]->GetName() << " was destroyed!\t";
                                Board::playerBoard[i] = nullptr;
                            }
                        }
                        else
                            enemyNexusHealth -= Board::playerBoard[i]->cardPower;
                    }
                    // Send back to bench | Account for destroyed cards | Implement death system
                    for(unsigned int i = 0; i < Board::playerBoard.size(); i++) {
                        Board::playerBench.push_back(Board::playerBoard[i]); // Check! | These are pointers
                        Board::playerBoard.erase(Board::playerBoard.begin() + i);
                    }
                    for(unsigned int i = 0; i < Board::enemyBoard.size(); i++) {
                        Board::enemyBench.push_back(Board::enemyBoard[i]);
                        Board::enemyBoard.erase(Board::enemyBoard.begin() + i);
                    }
                }
                else
                    continue;
            }
        }
        else {
            char state = Enemy(enemyNexusHealth, enemyCurMana, eDeck, enemyHand);
            switch(state) { // ??
                case 's': continue; break; // Skip
                case 'p': break; // Play 
                case 'a': break; // Attack 
                default: continue; break;
            }
            if(state == 'a') { // Blocking!
                std::string choice = "";
                std::cout << "Choose each cards target: ";
                if(Board::enemyBoard.size() != 0)
                    for(int i = 0; i < Board::enemyBoard.size(); i++)
                        std::cout << Board::enemyBoard[i]->GetName() << " | ";
                putchar('\n');
                std::cout << "Use format: '1>2,3>1' etc...\n"; // Add safety
                std::cin >> choice;
                std::string curBlock;
                std::vector<std::string> blocks{};
                for(unsigned int i = 0; i < choice.length(); i++) {
                    curBlock += choice[i];
                    if(choice[i] == ',') {
                        blocks.push_back(curBlock);
                        curBlock.clear();
                    }
                }
                // Move from bench to board
                for(int i = 0; i < blocks.size(); i++) // Move don't copy!
                    Board::playerBoard[blocks[i].at(2)-1] = Board::playerBench[blocks[i].at(0)-1];
            }
        }

        // End of turn:
        curTurn++;
        if(yourTurn)
            yourTurn = false;
        else
            yourTurn = true;
        // Change!
        if(hasAttackToken)
            hasAttackToken = false;
        else
            hasAttackToken = true;
        yourMaxMana++;
        enemyMaxMana++;
        yourCurMana = yourMaxMana;
        enemyCurMana = enemyMaxMana;
    }
}

void PreGame() {
    // Add deck selection
    Deck *playerDeck = new Deck("Player Deck");
    Deck *enemyDeck = new Deck("Enemy Deck");
    FillDeck(*playerDeck);
    FillDeck(*enemyDeck);

    std::cout << playerDeck->Draw()->GetName(); // Works! | Deck is fine!

    Game(*playerDeck, *enemyDeck);
}

void DeckBuilder() {

}

int main() {
    PreGame();

    return 0;
}