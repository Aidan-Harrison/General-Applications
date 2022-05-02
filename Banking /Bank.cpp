#include <iostream>
#include <array>
#include <vector>
#include <utility>

#include "Account.h"

// Create weighted adjacency list graph
// Use to create map
struct node {
    bool hasBank = false;
    int weight = 0;
    node * next;
};

struct map {
    std::vector<node> vertices{};
};

map m;

void Print(map & m) {
    for(int i = 0; i < m.vertices.size(); i++) {
        node * traversePointer = &m.vertices[i];
        while(traversePointer != nullptr) {
            std::cout << traversePointer->hasBank << "->";
            traversePointer = traversePointer->next;
        }
        putchar('\n');
    }
}

void Distance(map & m, int maxMiles = 3) {
    int distanceTravelled = 0;
    for(int i = 0; i < m.vertices.size(); i++) {
        node * traversePointer = &m.vertices[i];
        while(traversePointer != nullptr) {
            distanceTravelled += traversePointer->weight;
            if(distanceTravelled > maxMiles) {
                distanceTravelled = 0;
                break;
            }
            traversePointer = traversePointer->next;
        }
    } 
}

// Luhn's Algorithm
uint8_t LuhnsAlgorithm(std::array<int,10> && number) {
    std::array<int, 10> payload{};
    std::string result = "";
    int sum = 0;
    for(uint8_t i = 0; i < number.size(); i++) {
        if(i % 2 == 0) { // Multiply value by 2
            number[i] *= 2;
        }
        payload[i] = number[i];
    }
    for(uint8_t i = 0; i < number.size(); i++) {
        if(number[i] >= 10) {
            int digit = number[i] / 10;
            int remainder = number[i] % 10;
            result.push_back(digit + remainder);
        }
        else {
            result.push_back(number[i]);
        }
    }
    for(char c : result)
        sum += (int)c;
    uint8_t checkDigit = 10 - (sum % 10);
    return checkDigit;
}

void Store() {

}

void LocalBanks() {
    int input;
    std::cout << "Set custom distance: (Y/N)\n" << "INPUT: ";
    std::cin >> input;
    if(input == 1) {
        std::cout << "Max miles: ";
        std::cin >> input;
        Distance(m, input);
    }
    else
        Distance(m);
}

void Statement() {

} 

void Interface() {

}

int main() {
    std::cout << "Bank!\n";
    std::cout << LuhnsAlgorithm({7,9,9,2,7,3,9,8,7,1});

    return 0;
}