#include <iostream>

std::string current;

void Home();

void Pad() {
    std::cout << "Notepad!";
    std::cin >> current;
    if(current == "^^")
        Home(); // Add call stack to not always go back to home but rather last window
    // Check for CTRL-S
    // Check for termination character
}