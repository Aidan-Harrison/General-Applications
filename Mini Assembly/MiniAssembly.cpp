/*
    - Mini Language
    - Aidan Harrison
    - C++20

    DO TOKENISATION
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <unordered_map>

// Flags
    // Line types
/*
    0: Comment
    1: function
    2: section
    3: standard
    4: new line
    5: PASS
    6: branch
*/

template<typename...> struct pair;

template<typename a, typename b>
struct pair<a,b> {
    a f;
    b s;
    pair() {}
    pair(a _a, b _b)
        :f(_a), s(_b)
    {
    }
    pair(pair & other)
        :f(other.f), s(other.s)
    {
    }
};

std::fstream fileHandler;
std::unordered_map<int, std::string> lines{};
std::vector<int> functionIndexes{};
std::vector<int> indentationIndexes{};
int mainIndex{};

enum TYPES{COMMAND,BRANCH,IF,FUNCTION};

struct BUFFER { // Stores temp information, used for parsing
    std::string lastLine = "";
};

BUFFER buffer;

std::unordered_map<std::string, bool> commands{
    {"PRT", true},
    {"ADD", true},
    {"SUB", true},
    {"MUL", true},
    {"DIV", true},
    {"STR", true},
};

bool BoundsCheck(const int value, const int size) {
    return value >= 0 && value < size;
}

const std::string Reverse(std::string str) {
    uint32_t left = 0;
    uint32_t right = str.length();
    while(left < right) {
        char temp = str[right];
        str[right] = str[left];
        str[left] = temp;
        left++;
        right--;
    }
    return str;
}

void StoreVariable(const std::string & name, const std::string & type, const std::string & value) {

}

// Executes command line
void ParseCommandLine(const int index) {
    if(lines[index] == buffer.lastLine) {
    }
}

void ParseBranch(const int index) {

}

// Iterates until ':' | Line, index pos
const pair<uint32_t, uint32_t> ObtainScope(const int index) {
    //if(lines[index].at(lines[index].length()-1) == ':')
        //return index;
    for(int i = index; i >= 0; i--) {
        for(int j = lines[index].length()-1; j >= 0; j--) {
            if(lines[index].at(j) == ':') {
                pair<uint32_t,uint32_t> result(i,j);
                return result;
            }
        }
    }
    pair<uint32_t,uint32_t> none(-1,-1);
    return none;
}

pair<int,int> TwoSidedOp(const std::string & str, const int index) { // Check templating!
    int i,j;
    while(i >= 0 && j < str.length()) {
        if(i != 0)
            i--;
        if(j != str.length()-1)
            j++;
    }
    pair<int,int> newPair;
    return newPair;
}

// Reads type and stores values appropiate data
const uint8_t ReadLine(const int curLine) {
    uint32_t pos[4]{};
    uint8_t count = -1;
    std::string value = "";
    std::string line = lines[curLine];
    buffer.lastLine = line;
    bool keyWordFound = false; // Used to skip uneeded operations
    for(unsigned int i = 0; i < line.length(); i++) { // Optimise, skip whitespace if known start location
        if(line[0] == '.') { // Function check
            if(line[line.length()-1] == ':') {
                // std::cout << "SCOPE!\n";
            }
            // std::cerr << "Function syntax fail!\n";
        }
        else if(line[0] == '?') // Branch
            return 6;
        if(line[i] == ',') {
            for(unsigned int j = i-1; j > 0; j--) {
                if(line[j] != ' ') {
                    if(line[j] == ',')
                        break;
                    value += line[j];
                }
            }
            if(value.length() > 1)
                value = Reverse(value);
            // Store value in buffer
                // Not calculated at runtime to allow for optimisations?

            // Command/operand check
                // Get type of cmd/op
                    // Appropiate code
            if(commands[value]) {
                keyWordFound = true; 
                for(unsigned int j = 2; j < line.length(); j++) { // Minimum command length of 3
                    if(line[j] == ',') {

                    }            
                }
            }
            value = "";
        }
        else if(line[i] == '_') { // New line, make more elaborate
            if(line[i-1] == ' ' && line[i+1] == ' ')
                return 4;
        }
        else if(line[i] == 'P' && !keyWordFound) { // PASS
            char identifier[4]{'P','A','S','S'};
            for(unsigned int j = i; j < 3; j++)
                if(line[j] != identifier[j])
                    continue;
            return 5;
        }
        else if(line[i] == '<') { // Return operator or comparison
            if(!BoundsCheck(i+1, line.length()))
                continue;
            if(line[i+1] == '-') {
                if(ObtainScope(curLine).f) { // DO!
                    // Get return type

                    // Return

                }
            }
            else if(line[i+1] == '=') { // <=
                TwoSidedOp(line, i);
            }
            else { // <
                // pair<int,int> newPair(TwoSidedOp(line, i));
                // if(newPair.f < newPair.s)
                    std::cout << "LESS THAN!";
            }
        }
        else if(line[i] == '>') { // Return indicator or comparison
            if(!BoundsCheck(i-1, line.length()))
                continue;
            if(line[i-1] == '-') {
                if(ObtainScope(curLine).f) { // DO!
                    // Get return type

                    // Return

                }
            }
            else if(line[i+1] == '=') { // >=
                TwoSidedOp(line,i);
            }
            else { // >
                TwoSidedOp(line, i);
            }
        }
        keyWordFound = false;
    }
    return 3; // Command line
}

// Fix
const int Find(const std::string & line, const std::string && target) {
    int counter = 0;
    for(unsigned int i = 0; i < line.length(); i++) {
        if(line[i] == target[counter]) {
            counter++;
            if(counter == target.length()-1)
                return i-target.length()+1;
        } else {
            counter = 0;
        }
    }
    return -1;
}

void Tokeniser(const std::string & line) {
    pair<std::string,std::string> token;
    if(Find(line, "PRT]") != -1) {
        token.f = "print";
        std::cout << Find(line,"PRT]") << '\n';
    } else if(Find(line, "ADD]") != -1) {
        token.f = "+"; token.s = "";
    } 
    for(int i = 0; i < line.length(); i++) {
        if(line[i] == ':') { // Type
            if(line.find("i32"))
                token.f = "integer";
            else if(line.find("f32"))
                token.f = "float";
        }
    }
}

void Lexer() {
    // Main search and error handle | Checks for multiple mains
    /*
    char mainCheck[4]{'M','A','I','N'};
    bool hasMain = false;
    for(unsigned int i = 0; i < functionIndexes.size(); i++) {
        int counter = 0;
        for(unsigned int j = 0; j < lines[functionIndexes[i]].length(); j++) {
            if(lines[functionIndexes[i]][j] != mainCheck[counter])
                break;
            else {
                counter++;
                if(counter == 4) {
                    if(hasMain) {
                        std::cerr << "You have multiple main functions!\n";
                        return;
                    }
                    hasMain = true;
                }
            }
        }
        mainIndex = i;
    }
    */
    std::cout << "Main function found!\n";
    for(auto it = lines.begin(); it != lines.end(); it++) {
        Tokeniser(it->second);
        switch(ReadLine(it->first)) {
            case 0: 
                break;
            case 1: { 
                // Add function parsing
                break;
            }
            case 2: 
                break;
            case 3: {
                ParseCommandLine(it->first);
                break;
            }
            case 4: {
                break;
            }
            case 5: { 
                continue;
                break;
            }
            case 6: {
                ParseBranch(it->first);
                break;
            }
        }
    } 
}

/*
void Lexer() {
    std::string curValue = "";
    std::vector<int> commandIndexes{};
    bool varFlags[3] = {false,false,false};
    for(unsigned int i = 0; i < _code.length(); i++) {
        if(_code[i] == '>') {  
            if(_code[i+1] == 'c') { // data section
                std::string name, type, value;
                int k;
                for(unsigned int j = i; j < _code.length(); j++) {
                    if(!varFlags[0] && !varFlags[1] && !varFlags[2])
                        name += _code[j];
                    else if(!varFlags[1])
                        type += _code[j];
                    else if(!varFlags[2])
                        value += _code[j];
                    if(_code[j] == ',') {
                        varFlags[k] = true;
                        k++;
                        StoreVariable(name,type,value);
                        name = "";
                        type = "";
                        value = "";
                    }
                }
            }
        }
    }
}
*/

// Get necessary data at read
    // Function locations
    // Indented lines and not
    // etc.


void ParseFile(const std::string && _filePath, bool print = false) {
    fileHandler.open(_filePath);
    if(fileHandler.fail())
        return;
    std::cout << "File opened succesffuly, parsing...\n";
    int counter = 1;
    std::string line = "";
    while(std::getline(fileHandler, line)) {
        lines[counter] = line;
        if(line.length() <= 1) // Not always empty!!
            continue;
        if(line[0] == '.')
            functionIndexes.push_back(counter);
        else if(line[0] == ' ')
            indentationIndexes.push_back(counter);
        std::cout << counter << "   Ending char: " << line[line.length()-1] << '\n';
        if(line[line.length()-1] == ' ') { // Clears trailing whitespace
            int endPos = line.length()-1;
            for(int i = endPos; i >= 0; i--)
                if(line[i] == ' ')
                    endPos = i;
            line.resize(endPos);
            std::cout << counter << " Line| " << line <<  " |End| " << line[endPos] << '\n';
        }
        counter++;
    }
    fileHandler.close();
}

int main() {
    ParseFile("Assembly.txt");
    Lexer();

    return 0;
}