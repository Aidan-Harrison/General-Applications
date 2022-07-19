// File based person generator
// Aidan Harrison
/*
    Temporary storage (6 people)
    Can write to .txt file
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::fstream fileHandler, fileWriter;
enum setting{STANDARD = 1, FANTASY};

std::vector<std::string> contents{};
std::vector<std::string> fNames{};
std::vector<std::string> sNames{};
std::vector<std::string> occupations{};
std::vector<std::string> locations{};

void clear_screen() {
    #ifdef _WIN64
        system("cls");
    #elif __APPLE__ || __MACH__
        system("clear"); 
    #endif
}

struct person {
    int age = 1;
    std::string fName;
    std::string sName;
    std::string occupation;
    std::string location;
    bool married = false;

    void print() const {
        std::cout << fName << sName << '\n';
        std::cout << age << '\n';
        std::cout << occupation << '\n';
        std::cout << location << '\n';
    }
};

std::vector<person> tempPeople{};

void FileParser(const int set, bool display = false) {
    std::string curFile ="";
    switch(set) {
        case 0: curFile = "StandardGen.txt"; break;
        case 1: curFile = "FantasyGen.txt"; break;
    }
    fileHandler.open(curFile);
    if(fileHandler.fail()) {
        std::cerr << "Failed to open " << curFile << " either corrupt or missing\n";
        exit(1);
    }
    int amount = 0;
    std::string statistic = "";
    std::cout << curFile << " Opened successfully!\n";
    if(display) {
        while(!fileHandler.eof()) {
            fileHandler >> statistic; // Check!
            std::cout << "| " << statistic << "\n";
        }
        std::cout << curFile << " contains: " << amount << " of lines\n";
    }
}

// Adds data to a specified file but checks if field already exists
void AddField() {
    std::string field, line;
    std::cin >> field;
    while(std::getline(fileHandler, line)) {
        while(line.find(field) != std::string::npos) {
            std::cout << "Identical field found\nInput: ";
            std::cin >> field;
        }
    }
    fileHandler << field; // Check where it is added!
}

// If 'exemptChecker' is set to true, checks if certain generations don't make sense
    // e.g. 99 year old MMA fighter or 17 year old CEO
// Codes:
/*
    -1: Success
    0: Change job
    1: Change age
    2: Change Location
*/
int ExemptionCheck(person & p) {
    if(p.age < 16) { 
        p.occupation = "Unemployed";
    } else if(p.age > 16 && p.age < 21) { // Unlikely to have certain jobs, thus just exempt them
        while(p.occupation == "CEO" || p.occupation == "")
            p.occupation = occupations[rand() % occupations.size()];
    } else if(p.age > 60) {
        if(p.occupation == "MMA" || p.occupation == "Boxer")
            return 1;
    }
    // Location checks
        // e.g. CEO in central africa
    if(p.location == "Central Africa") {
        while(p.occupation == "CEO")
            p.occupation = occupations[rand() % occupations.size()];
    }
    return -1;
}

// Sorts each section of the given file in alphabetical order
void SortFile() {
    std::sort(contents.begin(), contents.end());
    for(std::string i : contents)
        fileWriter << i; // Store to appropiate section 
}

void Save(bool choose = false) {
    person *saveP = &tempPeople[tempPeople.size()-1];
    fileWriter.open("People.txt");
    fileWriter << saveP->fName << " " << saveP->sName;
    fileWriter << saveP->age;
    fileWriter << saveP->occupation;
    fileWriter << saveP->location;
    fileWriter << "=====================";
    tempPeople.pop_back();
}

person GeneratePerson() {
    person newPerson;
    newPerson.fName = fNames[rand() % fNames.size()];
    newPerson.sName = sNames[rand() % sNames.size()];
    newPerson.age = rand() % 100;
    newPerson.occupation = occupations[rand() % occupations.size()];
    newPerson.location = locations[rand() % locations.size()];
    switch(ExemptionCheck(newPerson)) {
        case 0: break;
        case 1: break;
        case 2: break;
    }
    return newPerson;
}

// Stores data from .txt file appropiately
void Store(bool sort = false) {
    std::string line;
    int sectionCounter = 0;
    std::string firstname, surname, occupation, location;
    while(std::getline(fileHandler, line)) {
        if(line == "#FirstNames" || line == "#SurNames" || line == "#Jobs" || line == "#Locations") {
            if(contents.size() != 0) {
                switch (sectionCounter) {
                    case 0: {
                        for(std::string l : contents)
                            fNames.push_back(l);
                        break;
                    } case 1: {
                        for(std::string l : contents) 
                            sNames.push_back(l);
                        break;
                    } case 2: {
                        for(std::string l : contents)
                            occupations.push_back(l);
                        break;
                    } case 3: {
                        for(std::string l : contents)
                            locations.push_back(l);
                        break;
                    }
                }
                contents.clear();
                printf("%d\n", sectionCounter);
            }
            sectionCounter++;
        } 
        else
            contents.push_back(line);
    }
    if(sort)
        SortFile();
}

void Setup() {
    char input = ' ';
    int set{};
    std::cout << "Skip setup (Default settings) Y/N\n"; 
    std::cin >> input;
    char c = std::tolower(input);
    while(c != 'y')  {
        std::cout << "Please enter a valid input (You entered " << c << "): ";
        std::cin >> c;
        c = std::tolower(c);
    }
    if(c == 'y') {
        std::cout << "Select type: STANDARD | FANTASY\n";
        std::cin >> set;
        while(set < 0 || set > 2) {
            std::cout << "Invalid input " << set << ", try again: ";
            std::cin >> set;
        }
    }
    FileParser(set);
    while(1) {
        clear_screen();
        if(tempPeople.size() > 0)
            for(person p : tempPeople)
                p.print();
        Store();
        tempPeople.push_back(GeneratePerson());
        std::cout << "Do you want to store last person?\nInput(Y/N): ";
        std::cin >> input; 
        c = std::tolower(input);
        while(c != 'y' || c != 'n')  {
            std::cout << "Please enter a valid input (You entered " << c << "): ";
            std::cin >> input;
        }
        if(c == 'y')
            Save();
        else {
            std::cout << "Do you want to store another person?\n";
            std::cin >> input; 
            c = std::tolower(input);
            while(c != 'y' || c != 'n')  {
                std::cout << "Please enter a valid input (You entered " << c << "): ";
                std::cin >> input;
            }
            if(c == 'y')
                Save(true);
        }
    }
}

int main() {
    Setup();

    fileHandler.close();
    return 0;
}