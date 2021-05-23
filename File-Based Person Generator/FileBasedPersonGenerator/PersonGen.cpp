#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

std::ifstream fileHandler;

void GeneratePerson() {
    system("cls");
    std::vector<std::string> contents{};
    int totalLines;
    int randLine = 0;
    std::string line;
    std::cout << "Everything successfully loaded, generating person......\n";
    // Names ================================================================================
    fileHandler.open("Names.txt");
    srand(time(0));
    while(std::getline(fileHandler, line)) {
        totalLines++;
        contents.push_back(line);
    }
    randLine = rand() % totalLines;
    std::cout << "Name: " << contents[randLine] << '\n';
    contents.erase(contents.begin(), contents.end());
    totalLines = 0;
    fileHandler.close();
    // Location =============================================================================
    fileHandler.open("Location.txt");
    srand(time(0));
    while(std::getline(fileHandler, line)) {
        totalLines++;
        contents.push_back(line);
    }
    randLine = rand() % totalLines;
    std::cout << "Location: " << contents[randLine] << '\n';
    contents.erase(contents.begin(), contents.end());
    totalLines = 0;
    fileHandler.close();
    // Occupations =========================================================================
    fileHandler.open("Occupation.txt");
    srand(time(0));
    while(std::getline(fileHandler, line)) {
        totalLines++;
        contents.push_back(line);
    }
    randLine = rand() % totalLines;
    std::cout << "Occupation: " << contents[randLine] << '\n';
    contents.erase(contents.begin(), contents.end());
    totalLines = 0;
    fileHandler.close();
}

// Opens and checks files
void FileSetup() {
    std::string statistic;
    int amountOf;
    // Names ================================================================================
    fileHandler.open("Names.txt");
    if(fileHandler.fail()) {
        std::cerr << "\nFailed to open 'Names.txt' file, either corrupt or does not exist!";
        exit(-1);
    }
    else {
        std::cout << "\n'Names' File successfully opened!\n";
    }
    std::cout << "Names:\n";
    while(!fileHandler.eof()) {
        fileHandler >> statistic;
        amountOf++;
        std::cout << "| " << statistic << '\n';
    }
    std::cout << "Total amount of names: " << amountOf;
    fileHandler.close();
    amountOf = 0;
    // Locations ============================================================================
    fileHandler.open("Location.txt");
    if(fileHandler.fail()) {
        std::cerr << "\nFailed to open 'Location.txt' file, either corrupt or does not exist!";
        exit(-1);
    }
    else {
        std::cout << "\n'Location' File successfully opened!\n";
    }
    std::cout << "Locations:\n";
    while(!fileHandler.eof()) {
        fileHandler >> statistic;
        amountOf++;
        std::cout << "| " << statistic << '\n';
    }
    std::cout << "Total amount of locations: " << amountOf;
    fileHandler.close();
    amountOf = 0;
    // Occupations =========================================================================
    fileHandler.open("Occupation.txt");
    if(fileHandler.fail()) {
        std::cerr << "\nFailed to open 'Occupation.txt' file, either corrupt or does not exist!";
        exit(-1);
    }
    else {
        std::cout << "\n'Occupation' File successfully opened!\n";
    }
    std::cout << "Occupations:\n";
    while(!fileHandler.eof()) {
        fileHandler >> statistic;
        amountOf++;
        std::cout << "| " << statistic << '\n';
    }
    std::cout << "Total amount of occupations: " << amountOf;
    fileHandler.close();
    amountOf = 0;
    std::cout << "\nPress enter to continue: "; std::cin.get();
    GeneratePerson();
}

int main() {
    FileSetup();
    return 0;
}

