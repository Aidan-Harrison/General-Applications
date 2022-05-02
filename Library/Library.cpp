#include <iostream>
#include <map>
#include <thread>
#include <fstream>
#include <sstream>
#include <regex>

void Interface();

enum GENRE{FANTASY, SCIFI, HORROR, THRILLER, ROMANCE, FICTION, CHILDREN};

// Support multi-genre!

struct book {
    std::string title = "";
    uint16_t pageCount = 0;
    uint8_t genre = 0;
    book() {}
    book(const std::string & str, const uint16_t pC, const uint8_t g)
        :title(str), pageCount(pC), genre(g) 
    {
    }
};

std::map<std::string, book*> books{};
std::fstream fileHandler;
std::stringstream stringStream;

bool fileCheck(const std::string && filePath) {
    if(filePath == "") {
        std::cerr << "File path is empty!";
        return false;
    }
    fileHandler.open(filePath);
    if(fileHandler.fail()) {
        std::cerr << "Failed to open file path!";
        return false;
    }
    return true;
}

void Import() {
    if(!fileCheck("Books.txt"))
        return;
    while(!fileHandler.eof()) {
        std::string curLine;
        std::string title = "";
        std::string fTitle  = "";
        int pageCount = 0;
        int genre = 0;
        fileHandler >> curLine;
        fTitle = curLine;
        for(int i = 0; i < curLine.length(); i++) {
            if(curLine[i] == '|') {
                fTitle = curLine.substr(0, i);
                for(int j = i+2; j < curLine.length(); j++) { // Page count
                    if(curLine[j] == ' ' || curLine[j] == '>') 
                        break;
                    stringStream << curLine[j];
                }
            }
            else if(curLine[i] == '>') { // Genre
                stringStream.str(std::string());
                if(curLine[i+1] != ' ') // Handle non integer!!
                    stringStream << curLine[i+1];
                else
                    stringStream << curLine[i+2];
                stringStream >> genre;
            }
        }
        for(char i : fTitle)
            if(i == '_')
                i = ' ';
        book * newBook = new book(fTitle,pageCount,genre);
        books[fTitle] = newBook;
        fTitle = "";
    }   
}

int rand_range(const int a, const int b) {
    int value = rand() % b;
    if(value < a)
        value = a;
    return value;
}

void GenerateBooks(const int amount) {
    for(int i = 0; i < amount; i++) {
        std::string title = "";
        int pageCount = rand_range(50, 600);
        uint8_t genre = rand() % 5;
        book * newBook = new book(title, pageCount, genre);
    }
}

void Display() {
    std::cout << "=BOOKS=\n";
    // Thread display to easily handle very large sets of data ? 
    for(auto it = books.begin(); it != books.end(); it++) {
        std::cout << it->first << '\n';
    }
}

inline void lowerString(std::string str) { // Check inline!
    for(char c : str)
        c = std::tolower(c);
}

void SearchBook() {
    std::string input = "";
    char singInput = ' ';
    uint8_t tag = FANTASY;
    std::cout << "1) Search whole library\n"
            << "2) Search Fantasy\n"
            << "3) Search Sci-fi\n"
            << "4) Search Horror\n"
            << "5) Search Thriller\n"
            << "6) Search Romance\n";
    while(tag <= 0 || tag > 6) 
        std::cin >> tag;
    std::cout << "Enter title of book: ";
    std::cin >> input;
    lowerString(input);
    while(!books.count(input)) {
        std::cout << "Not found!\n";
        std::cout << "Search again? (Y/N) ";
        std::cin >> singInput;
        while(singInput != 'y' || singInput != 'n')
            std::cin >> input;
        if(singInput == 'N')
            return;
        std::cin >> input;
        lowerString(input);
    }
    if(tag != 1) {
        while(books[input]->genre != tag) {
            std::cout << "Book does not exist in section!";
            std::cout << "Try again (0 = Back): ";
            std::cin >> input;
            lowerString(input);
            if(input == "0")
                return;
        }
    }
    std::cout << "Title: " << books[input]->title << '\n';
    std::cout << "Page Count: " << books[input]->pageCount << '\n';
}

void AddBook() {
    book * newBook = new book;
    books[newBook->title] = newBook;
}

// Make safe
void RemoveBook() {
    std::string input = "";
    books[input] = nullptr;
}

void Interface() {
    while(1) {
        return;
    }
}

int main() {
    Import();
    Display();
    Interface();

    return 0;
}