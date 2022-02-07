#include "Champion.h"
#include "Keyboard.h"

#include <thread>

// Phase 1: Declare
// Phase 2: Ban
// Phase 3: Pick 1
// Phase 3: Pick 2
// Phase 3: Pick 3
// Phase 3: Pick 4

// Have it so when all players are done, skips timer and moves to next phase

using namespace Champions;

namespace Global {
    int timer = 15, phase = 1;
}

void print(const std::string &_str) {
    const char * cString = _str.c_str();
    printf("%s", cString);
}

struct Player {
    int declaredChamp, choice = 0, team = 1;
    std::string name = " ";
    Champion * champ = nullptr;
    Player(const std::string &_name) 
        :name(_name)
    {
    }
};

namespace Players {
    std::vector<std::string> names {"AatroxPlayer", "COVVA", "Peachsora", "AndroidTwenny", "TestName", "GorgC", "NoTail"
    };
    std::vector<Player> players{}; 
}

void DisplayChampions(bool _isExpanded = false) {
    for(unsigned int i = 1; i < champions.size()+1; i++) {
        if(i % 8 == 0)
            putchar('\n');
        if(champions[i-1]->isBanned)
            std::cout << "B|";
        std::cout << champions[i-1]->GetName() << "      ";
        if(_isExpanded) {
            for(auto i : champions[i-1]->tags) 
                std::cout << i << " | ";
            putchar('\n');
        }
    }
}

void DisplayPlayers() {
    for(unsigned int i = 0; i < Players::players.size(); i++) {
        // std::cout << i << ") " << Players::players[i].name << '\n';
        print(") " + Players::players[i].name + "| ");
    }
    putchar('\n');
}

bool SafetyCheck(const int _choice) { // Ensures a selection of a champion hasn't already been made
    for(unsigned int i = 0; i < Players::players.size(); i++)
        if(_choice == Players::players[i].choice)
            return true;
    return false;
}

void PlayerChoices(const int _type) {
    int value = 0;
    if(_type == 1) { // Declare
        for(unsigned int i = 0; i < Players::players.size(); i++) {
            value = rand() % champions.size();
            while(SafetyCheck(value)) 
                value = rand() % champions.size();
            Players::players[i].declaredChamp = value;
            std::cout << Players::players[i].name << " declared: " << champions[value]->GetName() << '\n';
        }
    }
    else if(_type == 2) { // Ban
        for(unsigned int i = 0; i < Players::players.size(); i++) {
            value = rand() % champions.size();
            while(SafetyCheck(value))
                value = rand() % champions.size();
            Players::players[i].choice = value;
            std::cout << Players::players[i].name << " banned: " << champions[value]->GetName() << '\n';
        } 
    }
    else if(_type == 3) { // Pick | Add phases
        for(unsigned int i = 0; i < Players::players.size(); i++) {
            value = rand() % champions.size();
            while(SafetyCheck(value))
                value = rand() % champions.size();
            Players::players[i].choice = value;
            std::cout << Players::players[i].name << " picked: " << champions[value]->GetName() << '\n';
        } 
    }
    std::cout << "Press ENTER to continue: ";
    std::cin.get();
    std::cin.get();
}

void Time() {
    while(Global::phase != 6) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout << "Phase: " << Global::phase << '\n';
        std::cout << "Time: " << Global::timer << '\n';
        Global::timer--;
        if(Global::timer == 0) {
            Global::phase++;
            switch (Global::phase) {
                case 2: Global::timer = 30; break; // Ban phase
                case 3: Global::timer = 60; break; // Pick 1
                case 4: Global::timer = 60; break; // Pick 2
                case 5: Global::timer = 45; break; // Pick 3
            }
        }
    }
}

void Interface() {
    Keyboard<void> keyboard;
    int phase = 0; // Add phasing
    bool altDisplay = false;
    while(1) {
        DisplayPlayers();
        DisplayChampions(altDisplay);
        // Declare
        std::cout << "\nDeclare a champion: ";
        std::cin >> Players::players[0].declaredChamp;
        // keyboard.Input();
        std::cout << "\nPlayer declared: " << champions[Players::players[0].declaredChamp]->GetName() << '\n';
        PlayerChoices(1);
        // Ban
        std::cout << "\nBan a champion: ";
        std::cin >> Players::players[0].choice;
        while(champions[Players::players[0].declaredChamp]->isBanned) {
            std::cout << "This champion has been banned, choose another: ";
            std::cin >> Players::players[0].declaredChamp;
        }
        PlayerChoices(2);
        std::cout << "\nPlayer banned: " << champions[Players::players[0].declaredChamp]->GetName() << '\n';
        // Pick
        std::cout << "\nPick a champion: ";
        if(Global::phase == 3) { // Can probably convert to Switch
            for(unsigned int i = 0; i < 2; i++) {
            }
        }
        else if(Global::phase == 4) { // Player pick
            std::cin >> Players::players[0].declaredChamp;
            while(champions[Players::players[0].declaredChamp]->isPicked) {
                std::cout << "This champion has been picked, choose another: ";
                std::cin >> Players::players[0].declaredChamp;
            }
            std::cout << "\nPlayer locked in: " << champions[Players::players[0].declaredChamp]->GetName() << '\n';
        }
        else if(Global::phase == 5) {

        }
        PlayerChoices(3);
    }
}

void CreatePlayers() {
    int choice = 0;
    // User
    Player user("User");
    Players::players.push_back(user);
    // Teams
    for(unsigned int i = 0; i < 9; i++) {
        choice = rand() % Players::names.size();
        for(unsigned int j = 0; j < Players::players.size(); j++) // Optimise?
            while(Players::names[choice] == Players::players[j].name)
                choice = rand() % Players::names.size();
        Player newPlayer(Players::names[choice]);
        Players::players.push_back(newPlayer);
    }
}

int main() {
    CreatePlayers();
    // std::thread timeThread(Time);
    Interface();

    // timeThread.join();

    return 0;
}