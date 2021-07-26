#include "KeyboardHandler.h"
#include "User.h"

KEYINPUT kI;

void Login() {

}

void Home() {
    std::cout << "Home\n";    
    std::cin >> PARAMETERS::C_INPUT;
    kI.Push(PARAMETERS::C_INPUT, true);
}

int main() {
    Home();

    return 0;
}