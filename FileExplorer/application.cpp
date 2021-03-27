#include <iostream>
#include <fstream>

std::string filePath = "";
short input = 0;

int main() {
    std::cout << "Type in file path:\n";
    std::cin >> filePath;
    std::fstream fileHandler;
    fileHandler.open(filePath);
    if(fileHandler.fail())
        std::cerr << "Failed to open specified file\n";
    else
        std::cout << "File opened successefully\n";
    // Print contents
    std::cout << "What would you like to do:\n";
    std::cout << "1) Open file  | 2) Exit\n";
    std::cin >> input;
    if(input == 2)
        fileHandler.close();
    else // Do
        break;
    return 0;
}