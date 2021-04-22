// Simple State Machine for a remote controlled car
#include <iostream>
#include <algorithm>

int state = 0;
enum states {
    STOP_ENGINE = 1, 
    START_ENGINE, 
    SPEED_DOWN, 
    SPEED_UP, 
    TURN_LEFT, 
    TURN_RIGHT
};

std::string engineState = "";
bool engine = false;
float speed = 0.0f;
float wheelRotation = 0.0f;

void CheckState(int s) {
    // Clamp values | Fix!
    std::min(0.0f, std::max(speed, 5.0f));
    std::min(-180.0f, std::max(wheelRotation, 180.0f)); // Check
    system("cls");
    if(s == STOP_ENGINE) {
        while(speed > 0)
            speed -= 0.5f;
    }
    if(engine)
        engineState = "ON";
    else
        engineState = "OFF";
    std::cout << "\nEngine: " << engineState <<
                 "\nSpeed: " << speed <<
                 "\nWheel-Rotation: " << wheelRotation << '\n';
}

int main() {
        //std::clamp(wheelRotation, -180.0f, 180.0f);
        //std::clamp(speed, 0.0f, 5.0f);
    while(1) {
        std::cout << "Input: "; std::cin >> state;
        switch(state) {
            case STOP_ENGINE:  engine         = false; break;
            case START_ENGINE: engine         = true;  break;
            case SPEED_DOWN:   speed         -= 0.5f;  break;
            case SPEED_UP:     speed         += 0.5f;  break;
            case TURN_LEFT:    wheelRotation -= 45.0f; break;
            case TURN_RIGHT:   wheelRotation += 45.0f; break;
            default:
                engine = false;
                break;
        }
        CheckState(state);
    }

    return 0;
}