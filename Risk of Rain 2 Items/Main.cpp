#include "Characters.h"
#include "RoR2.h"

void RoR2Main(Characters &character);

void PickCharacter(int choice) { // Decides base stats | Ensure deletion using auto_ptr
    if(choice == 1)      { Characters *Solider = new Characters  (250, 8, 10, 30, 10, 5,  "Soldier");     RoR2Main(*Solider); }
    else if(choice == 2) { Characters *Huntress = new Characters (200, 12, 8, 40, 20, 5,  "Huntress");    RoR2Main(*Huntress); }
    else if(choice == 3) { Characters *Engineer = new Characters (275, 8,  1, 25, 10, 5,  "Engineer");    RoR2Main(*Engineer); }
    else if(choice == 4) { Characters *MultT = new Characters    (300, 10, 15,25, 10, 10, "MultT");       RoR2Main(*MultT); }
    else if(choice == 5) { Characters *Artificer = new Characters(175, 12, 6, 60, 10, 5,  "Artificer");   RoR2Main(*Artificer); }
    else if(choice == 6) { Characters *Acrid = new Characters    (375, 10, 8, 30, 10, 5,  "Acrid");       RoR2Main(*Acrid); }
}

int main() {
    std::cout << "Pick a character to start:\n";
    RoR2::PrintCharacters();
retry:
    std::cin >> RoR2::userInput;
    if(RoR2::userInput != 1 && RoR2::userInput != 2 && RoR2::userInput != 3 && RoR2::userInput != 4 && RoR2::userInput != 5
        && RoR2::userInput != 6)
        goto retry;
    else
        PickCharacter(RoR2::userInput);
    return 0;
}