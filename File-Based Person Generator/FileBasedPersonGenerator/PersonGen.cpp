#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <unordered_map>

std::vector<std::string> STANDARD_FILES{"Names.txt", "Surnames.txt", "Location.txt", "Occupation.txt", "Hobbies.txt"};
std::vector<std::string> FANTASY_FILES{};

std::ifstream fileHandler;
enum setting{STANDARD = 1, FANTASY};
int setting = 0;

std::string line = "";
int totalLines = 0;
std::vector<std::string> contents{};
int curLine = 0;
int amountOfHobbies = 0;
int age = 0;
bool isMarried = false;
std::unordered_map<int,std::string> map;

void FileParser(const std::string &filePath, const bool display) {
    fileHandler.open(filePath);
    if(fileHandler.fail()) {
        std::cerr << "Failed to open " << filePath << " either corrupt or missing\n";
        exit(1);
    }
    else {
        int amount = 0;
        std::string statistic = "";
        std::cout << filePath << " Opened successfully!\n";
        if(display) {
            while(!fileHandler.eof()) {
                fileHandler >> statistic;
                std::cout << "| " << statistic << "\n";
            }
        }
        std::cout << filePath << " contains: " << amount << " of lines\n";
        fileHandler.close();
    }
}

bool CheckExemptJob(const std::string &str) {
    if(str == "MMA")                  return false;
    else if(str == "Boxer")           return false;
    else if(str == "Athlete")         return false;
    else if(str == "ESports Athlete") return false;
    else if(str == "Gymnast")         return false;
    else if(str == "Dancer")          return false;
    return true;
}

void GenerateStatistic(const std::string &file) {
    srand(time(0));
    fileHandler.open(file);
    while(std::getline(fileHandler, line)) {
        totalLines++;
        contents.push_back(line);
    }
    // Push contents to map?
    curLine = rand() % totalLines;
    if(file == "Names.txt")
        std::cout << "Name: " << contents[curLine] << " ";
    else if(file == "Surnames.txt") {
        std::cout << contents[curLine] << "\n";
        age = rand() % 60;
        age += 16;
        std::cout << "Age: " << age << "\n";
    }
    else if(file == "Location.txt")
        std::cout << "Location: " << contents[curLine] << "\n";
    else if(file == "Occupation.txt") {
        std::cout << "Occuptation: " << contents[curLine] << "\n";
        // Prevent certain jobs from occuring, re-roll | e.g. 70 year old can't be a MMA fighter
        if(age > 60 || age < 18) {
            while(!CheckExemptJob(contents[curLine]))
                curLine = rand() % totalLines;      
        }
    }
    else if(file == "Hobbies.txt") {
        amountOfHobbies = rand() % 4;
        amountOfHobbies++;
        for(unsigned int i = 0; i < amountOfHobbies; i++) {
            std::cout << "Hobby: " << contents[curLine] << "\n";
            curLine = rand() % totalLines;
        }
    }
    else if (file == "Gender.txt") {
        // Match to name (Chance based, more likely to be associated to male and female, 'other' is a low chance)
    }

    contents.clear();
    totalLines = 0;
    fileHandler.close();
}

// Opens and checks files
void FileSetup(const int set, const bool display) {
    if(set == STANDARD)
        for(auto i : STANDARD_FILES)
            FileParser(i, display);
    else if(set == FANTASY) 
        for(auto i : FANTASY_FILES)
            FileParser(i, display); 
    std::cout << "\nEverything successfully loaded\n";
    std::cout << "Press enter to generate:\n"; 
    if(set == STANDARD) {
        while(1) {
            std::cin.get();
            for(auto i : STANDARD_FILES)
                GenerateStatistic(i);
            std::cout << "=================================\n";
        }
    }
    else if(set == FANTASY) {
        while(1) {
            std::cin.get();
            for(auto i : FANTASY_FILES)
                GenerateStatistic(i);
            std::cout << "=================================\n";
        }
    }
}

void Setup() {
    char input = ' ';
    std::cout << "Skip setup (Default settings) Y/N\n"; 
    std::cin >> input;
    char c = std::tolower(input);
    switch (c) {
        case 'y': FileSetup(1, true); break;
        case 'n': break;
    }
    system("cls");
    std::cout << "Pick a settting\n\t" << "1) Standard (Modern-Day)  2) Fantasy\n";
    std::cin >> setting;
    std::cout << "Display file contents?  Y/N\n";
    std::cin >> input;
    char d = std::tolower(input);
    switch (d) {
        case 'y': FileSetup(setting, true); break;
        case 'n': FileSetup(setting, false); break;
    }
}

int main() {
    Setup();

    return 0;
}

