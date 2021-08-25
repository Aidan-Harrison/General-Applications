#include <iostream>
#include <vector>

struct Machine {
    unsigned int stock;
    std::vector<std::string> items{};
    std::vector<std::vector<std::string>> contents{};
    std::vector<std::vector<int>> contentsCount{};
    std::vector<std::vector<int>> ID{};
    Machine() {}
    Machine(unsigned int stock) 
        :stock(stock)
    {
        // RE-SIZE contents and contents count
        contents.resize(stock);
        contents[0].resize(stock);
        contentsCount.resize(stock);
        contentsCount[0].resize(stock);
    }

    void Fill(const unsigned int quantity);
    void Sell(const int quantity);
    void Deposit(const std::string &item);
    std::string Withdraw(const int item);
    int GetStock() const { return stock; }

    void Print() const;

    // States
    ~Machine() {};
};

void Machine::Print() const {
    for(unsigned int i = 0; i < contents.size(); i++) {
        for(unsigned int j = 0; j < contents[0].size(); j++) {
            std::cout << contents[i][j] << "|" << contentsCount[i][j] << '\n';
        }
    }
}

void Machine::Fill(const unsigned int quantity) {
    stock += quantity;
}

void Machine::Sell(const int quantity) {
    stock -= quantity;
}

void Machine::Deposit(const std::string &item) {
    for(unsigned int i = 0; i < contents.size(); i++) {
        for(unsigned int j = 0; j < contents[0].size(); j++) {
            if(item == contents[i][j])
                contentsCount[i][j]++;
        }
    }
}

std::string Machine::Withdraw(const int item) {
    for(unsigned int i = 0; i < contentsCount.size(); i++) {
        for(unsigned int j = 0; j < contentsCount.size(); j++) {
            if(item == contentsCount[i][j])
                return contents[i][j];
        }
    }
}

void Interface() {
    Machine vM{10};
    std::vector<std::string> items{};
    int choice = 0;
    vM.Print();
    switch(choice) {
        case 1: std::cout << vM.GetStock(); break;
        case 2: items.push_back(vM.Withdraw(choice)); break; // Change!
        case 3: break;
        case 4: break;
        default: break;
    }
}

int main() {
    int money = 10;
    Interface();

    return 0;
}