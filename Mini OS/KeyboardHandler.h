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

class KEYINPUT { // Make Singleton
private:
public:
    static KEYINPUT& getInstance() 
    {
        static KEYINPUT instance; // Test
        return instance;
    }
    int top = -1;
    int BACKLOGSIZE = 10; // Extra buffer
    int STACK_SIZE = 20;
    std::vector<char> input{};
    std::vector<std::string> shortcuts{"Clear Screen"};
    std::vector<char> backlog{};

    KEYINPUT() 
    {
        shortcuts[0] = "l";
        shortcuts[1] = "cls";
    } // Move to private

    std::vector<std::string> storage{};
    // Add to storage vector:
        // - Search
        // - Clear
        // - Move to DUMP or PERSONAL
        // - Write + Overwrite

    void Wrapper();

    inline bool IsFull();
    inline bool IsEmpty();
    void Push(const char c, bool parse);
    char Pop();
    int CurrentSize();
    void Parser();
    void StoreInput();

    void PrintStack();
    void ShortcutParser(const std::string &&str);
    void PrintShortcuts() const;

    // Modifications
    void ChangeShortcuts();
    void ChangeStackSize();
    void ChangeBufferSize();

    ~KEYINPUT() {}
};

void KEYINPUT::Wrapper() {
    if(IsFull()) {
        input.resize(STACK_SIZE);
    }
}

inline bool KEYINPUT::IsFull() {
    return (top == STACK_SIZE) ? true : false;
}

inline bool KEYINPUT::IsEmpty() {
    return (top == -1) ? true : false;
}

void KEYINPUT::Push(const char c, bool parse) {
    if(IsFull())
        std::cerr << "Keyboard stack is full!\n"; // Stop input
    else {
        top++;
        input[top] = c;
    }
    if(parse)
        Parser(); // Have bool to check whether to run parser per push
}

char KEYINPUT::Pop() {
    if(IsEmpty())
        putchar('\n');
    else {
        char item = input[top];
        backlog.push_back(input[top]);
        if(backlog.size() == BACKLOGSIZE)
            backlog.pop_back();
        top--;
        return item;
    }
    return ' ';
}

int KEYINPUT::CurrentSize() {
    return top;
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

// Modifications
void KEYINPUT::ChangeShortcuts() {
    PrintShortcuts();
}

void KEYINPUT::ChangeStackSize() {
    int sizeInput = 0;
    std::cin >> sizeInput;
    if(sizeInput < CurrentSize()) {
        std::cerr << "New max size of " << sizeInput << " must exceed current input size " << CurrentSize() << '\n';
    }   
    else {
        // Change from std::array to vector and write a wrapper instead
    }
}

void KEYINPUT::ChangeBufferSize() {
    int newSize = 0;
    std::cin >> newSize;
}

#endif
