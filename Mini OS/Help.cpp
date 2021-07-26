#include <fstream>
#include <iostream>

void Home();

void Help() {
    std::fstream file;
    file.open("HELP.txt");
    if(file.fail())
        std::cerr << "Failed to load 'HELP.txt', press enter to return home\n";
    // Convert to keyboard handler!
    std::cin.get();
    std::cin.get();
    Home();
    // Display HELP.txt
}