#include "Characters.h"
#include "RoR2.h"

void RoR2Main(Character &character);

void PickCharacter(int choice) { // Decides base stats | Ensure deletion using auto_ptr
    switch(choice) {
        case 1: { Character Solider  (250, 8, 10, 30, 10, 5,  "Soldier");   RoR2Main(Solider);   break; }
        case 2: { Character Huntress (200, 12, 8, 40, 20, 5,  "Huntress");  RoR2Main(Huntress);  break; }
        case 3: { Character Engineer (275, 8,  1, 25, 10, 5,  "Engineer");  RoR2Main(Engineer);  break; }
        case 4: { Character MultT    (300, 10, 15,25, 10, 10, "MultT");     RoR2Main(MultT);     break; }
        case 5: { Character Artificer(175, 12, 6, 60, 10, 5,  "Artificer"); RoR2Main(Artificer); break; }
        case 6: { Character Acrid    (375, 10, 8, 30, 10, 5,  "Acrid");     RoR2Main(Acrid);     break; }
    }
}

int main() {
    srand(time(0));
    std::cout << "Pick a character to start:\n";
    std::cin >> RoR2::userInput;
    // Add loop


    PickCharacter(RoR2::userInput);
    return 0;
}