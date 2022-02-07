#include <iostream>
#include <fstream>

// ASCII Shift
    // Shift characters over in alphabet by n amount
    // Decrpyt by shifting opposite of n amount

// ASCII Spiral Shift
    // Same as previous but alphabet is scrambled
        // Have to know how alphabet is scrambled to be able to decrpyt

// Take string
// Shift characters n amount
    // To shift:
        // Swap character with character at i + n
        // Take into account looping
        // Array rotation?
// Un-shift characters by n amount to decrypt

namespace SpiralShift {
    // Every 2 chars are swapped
    char spiral[26] = {c,a,d,b,g,e,h,f};
}

void Encrypt_ASCII_Shift(std::string &data, const int shiftAmount = 3) {
    for(unsigned int i = 0; i < data.length()-shiftAmount+1; i++) {
        char temp = data[i];
        data[i] = data[i+shiftAmount];
        data[i+shiftAmount] = temp;
    }
}

void Decrypt_ASCII_Shift(std::string &data) {
    std::cout << data << '\n';
    std::string decryptedString = "";
    for(unsigned int i = 3; i < data.length(); i++) {
        std::cout << data[i-3];
    }
}

void Encrypt_Spiral_Shift(std::string &data) {
    
}

void Decrypt_Spiral_Shift(std::string &data) {
    
}

int main() {
    std::string testString = "Test String";
    Encrypt_ASCII_Shift(testString, 3);
    Decrypt_ASCII_Shift(testString);

    return 0;
}

