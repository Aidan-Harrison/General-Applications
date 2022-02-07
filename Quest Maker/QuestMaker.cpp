#include <iostream>
#include <vector>
#include <tuple>

// Quest Maker
/*
    General quest concept
    Quest requirements
    Quest steps
    rewards
    Quest log

    Sub-quest step system
*/

// Done to allow for sub steps and several other features
struct Step {
    std::string mainStep;
    std::vector<std::tuple<std::string, bool>> subSteps;
};

struct Quest {
    std::string name;
    bool isActive = false;
    bool hasOptional = false;
    int levelReq;
    std::vector<std::string> customRequirements{};
    std::vector<std::tuple<std::string, bool>> questSteps{}; // Set?
    std::vector<std::string> rewards{};
    std::vector<std::string> optionalRewards{};
    Quest(std::vector<std::tuple<std::string, bool>> &steps, const std::string &_qName = "Default Quest") 
        :name(_qName), questSteps(steps)
    {
    }
};

namespace global {
    std::vector<Quest*> questDatabase{}; 
}

struct Player {
    int level = 1;
    std::vector<Quest*> quests{};
};

void Guide() {
    std::cout << "Mark a keywords/sections by adding '_' before and after it"; // Improve English
}

void PlayerInterface(Player &p) {
    std::cout << "Player:\n";
    std::cout << p.level << '\n';
    std::cout << "Quests";
    for(unsigned int i = 0; i < p.quests.size(); i++) {
        std::cout << i << ") " << p.quests[i]->name << '\n';
    }
}

void Creator(Player &p) {
    bool hasRequirements = false;
    int step = 1;
    std::string questName;
    std::string stepString;
    std::vector<std::tuple<std::string,int>> steps{};
    std::cout << "Enter a quest name (This can be changed at any point): ";
    std::cin >> questName;
    std::cout << "=============\n";
    while(stepString != "E") {
        std::cout << "Enter a step: \n" << step << ") ";
        std::cin >> stepString;
        step++;
        steps.push_back(stepString);
    }
    std::cout << "Would you like to enter any requirements (This can be changed at any point)?";
    std::cin >> stepString;
    if(stepString.find('y') || stepString.find('Y'))
        hasRequirements = true;
    if(hasRequirements) {
        while(stepString != "E") {
            std::cout << "Enter a requirement: \n";
            std::cin >> stepString;
        }
    }
    Quest *createdQuest = new Quest(steps, questName);
    p.quests.push_back(createdQuest);
    steps.clear();
    PlayerInterface(p);
}

void QuestBoard() {
    std::cout << "===QUEST BOARD===";
    for(unsigned int i = 0; i < Global::questDatabase.size(); i++) {
        std::cout << i << ") " << Global::questDatase[i]->name << '\n';
    }
}

void QuestScreen(Quest &q) {
    std::cout << "===== " << q.name << " =====\n";
    std::cout << "===============================\n";
    for(auto i : q.customRequirements)
        std::cout << i << '\n';
    std::cout << "===============================\n";
    for(unsigned int i = 0; i < q.questSteps.size(); i++) {
        for(unsigned int j = 0; j < std::get<0>(q.questSteps[i].length()); j++) { // Do more effcient method
            if(std::get<0>(q.questSteps[i].at(j)) == '_')
                std::cout << "|";
        }
        std::cout << "Step " << i << ": " << std::get<0>(q.questSteps[i]) << '\n';
    }
}

void Reward(Quest &q) {
    std::cout << "You recieved\n";
    
}

int main() {
    Player p;
    Creator(p);

    return 0;
}