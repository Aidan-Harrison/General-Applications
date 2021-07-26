#ifndef KeyboardHandler_h
#define KeyboardHandler_h

#include <iostream>
#include <array>
#include <vector>
#include <cctype>

// Add prefix '>' | CHANGE BOOL TO PREFIX
void Pad();
void Help();
void FileSearch(const std::string &&str);
void DUMP();
void Home();

class KEYINPUT { // Singleton
private:
public:
    KEYINPUT() 
    {
        shortcuts[0] = "l";
        shortcuts[1] = "cls";
    } // Move to private
    int top = -1;
    int BACKLOGSIZE = 10;
    std::array<char, 20> input{};
    std::vector<std::string> shortcuts{"clear"};
    std::vector<char> backlog{};

    std::vector<std::string> storage{};
    // Add to storage vector:
        // - Search
        // - Clear
        // - Move to DUMP or PERSONAL
        // - Write + Overwrite

    inline bool IsFull();
    inline bool IsEmpty();
    void Push(const char c, bool parse);
    char Pop();
    void Parser();
    void StoreInput();

    void PrintStack();
    void ShortcutParser(const std::string &&str);
    void PrintShortcuts() const;

    ~KEYINPUT() {}
};

inline bool KEYINPUT::IsFull() {
    if(top == 20) // Change!
        return true;
    return false;
}

inline bool KEYINPUT::IsEmpty() {
    if(top == 0)
        return true;
    return false;
}

void KEYINPUT::Push(const char c, bool parse) {
    if(IsFull())
        std::cerr << "Keyboard stack is full!\n"; // Stop input
    else {
        top++;
        input[top] = c; // Check every other implementation of stack with this 'top++' | May be an std::array specific issue
    }
    if(parse)
        Parser(); // Have bool to check whether to run parser per push
}

char KEYINPUT::Pop() {
    if(IsEmpty())
        putchar('\n');
    else {
        char item = input[top];
        backlog.push_back(input[top]); // Check!
        if(backlog.size() == BACKLOGSIZE)
            backlog.pop_back();
        top--;
        return item;
    }
    return ' ';
}

void KEYINPUT::Parser() {
    // Read top of stack, run command
    char c = std::tolower(input[top]);
    switch(c) {
        case 'p': std::cout << "PERSONAL"; break; // Open personal folder
        case 'd': DUMP(); break;
        case 'h': Help(); break;
        case 'n': Pad(); break;
        case 'H': Home(); break;
    }
}

void KEYINPUT::StoreInput() { // Long term storage
     
}

void KEYINPUT::ShortcutParser(const std::string &&str) {
    if(str == shortcuts[0])
        putchar('l');
    if(str == shortcuts[1]) 
        system("cls");
}

void KEYINPUT::PrintStack() {
    for(auto i : input)
        std::cout << i << " ";
}

void KEYINPUT::PrintShortcuts() const {
    std::cout << shortcuts[1] << " - Clears screen\n";
}

#endif
