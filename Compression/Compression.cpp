#include <iostream>
#include <string>
#include <vector>
#include <map>

void Compressor(std::string &_str) {
    std::map<char,int> charApp;
    std::string compressedString;
    for(auto i : _str)
        charApp[i]++;
    for(auto it = charApp.begin(); it != charApp.end(); it++) {
        compressedString.append(std::to_string(it->second));
        compressedString += it->first;
    }
    _str = compressedString;
}

void DeCompress(std::string &_str) {
    std::string uncompressedString = "";
    for(unsigned int i = 0; i < _str.length()-1; i++) 
        if(isdigit(_str[i]))
            for(unsigned int j = 0; j < _str[i] - '0'; j++)
                uncompressedString += _str[i+1];
    _str = uncompressedString;
}

int main() {
    std::string testString = "FFFFFFFFFFFXGGZYY";
    std::cout << testString << '\n';
    Compressor(testString);
    std::cout << testString << '\n';
    DeCompress(testString);
    std::cout << testString;

    return 0;
}