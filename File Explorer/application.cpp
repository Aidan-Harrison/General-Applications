#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

int input = 0;

using namespace std::filesystem; // Fix! Compiler issue!

void Search() {
    std::string search = "";
    // Loop through current directory
}

void Interface() {
    std::cout << "What would you like to do:\n";
    std::cout << "1) Search file  | 2) Exit\n";
    std::cin >> input;
    switch(input) {
        case 1: Search(); break;
        case 2: exit(0); break;
    }
}

void Setup() { // Move file handler somewhere else
    std::fstream fileHandler;
    std::string filePath = "";
    fileHandler.open(filePath);
    if(fileHandler.fail())
        std::cerr << "Failed to open specified file\n";
    else
        std::cout << "File opened successefully\n";
}

int main() {
    Setup();

    return 0;
}
