// Library
#include <iostream>
#include <fstream>

bool LoadBook(std::fstream &fH, const std::string &_book) {
    if(_book == "") {
        std::cout << "File path is invalid!\n";
        return false;
    }
    else {
        if(!fH.open(_book)) {
            std::cout << "File path is either invalid or corrupt!\n";
            return false;
        }
        
        return true;
    }
    return false;
}

void Interface(std::fstream &fH) {

}   

int main() {
    std::fstream fileHandler;
    Interface(fielHandler);


    return 0;
}