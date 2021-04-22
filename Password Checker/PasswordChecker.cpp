// Password Checker
#include <iostream>
#include <string>

short strength = 1;
bool hasNumber = false;
bool hasSymbol = false;
bool hasUpper = false;
bool correct = false;

int main() {
    std::string pass = "", strengthText = "";
    // Password checker
    while(!correct) {
        system("cls");
        std::cout << "Enter a password (Must-Contain a Uppercase letter, Symbol and a Number)" << '\n'; 
        std::cin >> pass;

        for(int i = 0; i < pass.length(); i++) {
            if(!hasNumber) { // Pointless checking characters if a number, symbol or uppercase has already been found
                if(pass[i] == '0' || pass[i] == '1' || pass[i] == '2' || pass[i] == '3' || pass[i] == '4' || pass[i] == '5'
                || pass[i] == '6' || pass[i] == '7' || pass[i] == '8' || pass[i] == '9') {
                    hasNumber = true;
                }
            }
            if(!hasSymbol) {
                if(pass[i] == '@' || pass[i] == '!' || pass[i] == '#' || pass[i] == '~' || pass[i] == '$' || pass[i] == '*'
                || pass[i] == '?' || pass[i] == '&' || pass[i] == '(' || pass[i] == ')') {
                    hasSymbol = true;
                }
            }
            if(!hasUpper) {
                if(pass[i] == 'A' || pass[i] == 'B' || pass[i] == 'C' || pass[i] == 'D' || pass[i] == 'E' || pass[i] == 'F'
                || pass[i] == 'G' || pass[i] == 'H' || pass[i] == 'I' || pass[i] == 'J' || pass[i] == 'K' || pass[i] == 'L'
                || pass[i] == 'M' || pass[i] == 'N' || pass[i] == 'O' || pass[i] == 'P' || pass[i] == 'Q' || pass[i] == 'R'
                || pass[i] == 'S' || pass[i] == 'T' || pass[i] == 'U' || pass[i] == 'V' || pass[i] == 'W' || pass[i] == 'X'
                || pass[i] == 'Y' || pass[i] == 'Z') {
                    hasUpper = true;
                }
            }
        }

        if(!hasNumber) std::cout << "Your password does not contain a number!  Try Again!\n";
        if(!hasSymbol) std::cout << "Your password does not contain a symbol!  Try Again!\n";
        if(!hasUpper)  std::cout << "Your password does not contain a Uppercase letter!  Try Again!\n";
        
        if(strength < 3) strengthText = "Weak";
        else if(strength > 3 && strength < 6) strengthText == "Good";
        else if(strength > 6 && strength < 9) strengthText == "Great";
        else if(strength > 9 && strength < 12) strengthText == "Excellent";

        hasNumber = false;
        hasSymbol = false;
        hasUpper = false;
        std::cout << "Press enter to continue: ";
        std::cin.get();
        std::cin.get();
    }
    // Password strength

    std::cout << "Your password is: " << pass;
    std::cout << "Password strength: " << std::string("/" + strength) << " " << strengthText;

    return 0;
};