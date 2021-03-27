// Translating
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

#include "french.h"
#include "german.h"

std::fstream fileHandler;
std::string message = " ", tMsg = " ", line = " ";
int amountOfLines = 0, input = 0;

// Optimise entire function (Maps, different method, etc.)
std::string ReadLinesFrench(const French &french, std::string &msg) { // Check current line and gets appropiate translation
    for(unsigned int i = 0; i < msg.length(); i++)
        tolower(msg[i]);
    for(unsigned int i = 0; i < french.words.size(); i++) {
        if(msg.find("Hello")) {
            for(unsigned int i = 0; i <= french.words.size(); i++)
                if(french.words[i] == "Bonjour")
                    tMsg.append(french.words[i]); 
        }
        else if(msg.find("Thank you")) {
            for(unsigned int i = 0; i <= french.words.size(); i++)
                if(french.words[i] == "Merci")
                    tMsg.append(french.words[i]);
        }
    }
    tMsg.append(" ");
}

std::string ReadLinesGerman(const German &german, std::string &msg) {
    return " ";
}

void Reset(std::string &msg) {
    msg.clear();
    // Return to proper function
}

int main() {
    French f;
    German g;
    std::cout << "Amount of lines: "  << amountOfLines << '\n';
    std::cout << "Enter a message to translate (In English):\n";
    std::cin >> message;
    std::cout << "Pick a language to translate to:\n";
    std::cout << "1) French  2) German\n";
    switch(input) {
        case 1: ReadLinesFrench(f, message); break; // Remove break!?
        case 2: ReadLinesGerman(g, message); break; // Remove break!?
        default: ReadLinesFrench(f, message); break;
    }
    std::cout << tMsg;
    return 0;
}