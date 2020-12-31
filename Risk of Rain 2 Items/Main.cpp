#include "Characters.h"
#include "RoR2.h"

void RoR2Main(Characters &character);

// Sort return
// Add constructors
void PickCharacter(int choice) { // Decides base stats | Ensure deletion
    if(choice == 1) {
        Characters *Solider = new Characters(250, 8, 10, "Soldier"); RoR2Main(*Solider);
    }
    else if(choice == 2) {
        Characters *Huntress = new Characters(200, 12, 8, "Huntress"); RoR2Main(*Huntress);
    }
    else if(choice == 3) {
        Characters *Engineer = new Characters(275, 8, 1, "Engineer"); RoR2Main(*Engineer);
    }
    else if(choice == 4) {
        Characters *MultT = new Characters(300, 10, 15, "MultT"); RoR2Main(*MultT);
    }
    else if(choice == 5) {
        Characters *Artificer = new Characters(175, 12, 6, "Artificer"); RoR2Main(*Artificer);
    }
    else if(choice == 6) {
        Characters *Acrid = new Characters(375, 10, 8, "Acrid"); RoR2Main(*Acrid);
    }
}

int main() {
    std::cout << "Pick a character to start:\n";
    RoR2::PrintCharacters();
    std::cin >> RoR2::userInput;
    PickCharacter(RoR2::userInput);
    return 0;
}