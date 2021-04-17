// Text editor
#include <iostream>
#include <fstream>
#include <thread>

// Multithread
void Menu() {
    std::cout << "\t====TEXT EDITOR====\n";
    std::cout << "\t\n1) Save\t 2)Open\t 3)Close\n";
    if(std::cin.get() == 1) {
        std::cout << "Pressed 1\n";
    }
}

int main() {
    std::thread menuThread(Menu);
    std::ifstream file;
    file.open("TextFiles/default.txt");
    if(file.fail()) {
        std::cerr << "FAILED TO OPEN FILE!";
        exit(1);
    }
    std::string editText = "";
    while(1) {
        std::cin >> editText;
    }

    menuThread.join();
    return 0;
}