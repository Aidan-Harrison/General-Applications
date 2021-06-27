#include <iostream>
#include <fstream>

void Search() {
    std::string search = "";
}

void Read() {
    // Print contents
}

int input = 0;

void Interface() {
    std::cout << "What would you like to do:\n";
    std::cout << "1) Search file  | 2) Exit\n";
    std::cin >> input;
    switch(input) {
        case 1: Search(); break;
        case 2: Exit(0); break;
    }
}

void Setup() {
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