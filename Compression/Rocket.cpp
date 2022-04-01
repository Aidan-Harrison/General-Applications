// Discord/Text Chat system
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <array>
#include <thread>

#define GetX std::get<0>
#define GetY std::get<1>

struct Engine {
    bool DESTROYED = false;
    bool ACTIVE = false;
    float THRUST = 0.0f;
    double HEAT = 0.0;
    constexpr static float meltingPoint = 2200.0f; // Engine shuts down and has a chance to be destroyed
};

class Rocket {
private:
public:
    std::vector<std::vector<Engine>> m_Engines{};
    float m_Velocity = 0.0f;
    float power = 0.0f;
    float accelRate = 0.0f;
    float fuel = 3750.0f;
    float x = 0.0f, y = 0.0f;
    std::pair<float,float> centreOfMass;
    std::pair<float,float> trajectory; // Moves towards this
    float weight = 500.0f;
    Rocket(const int _eCount)
    {
        m_Engines.resize(_eCount/2);
        for(int i = 0; i < _eCount/2; i++)
            m_Engines[i].resize(_eCount/2);
        Engine e1, e2, e3, e4, e5, e6, e7, e8, e9;
        m_Engines[0][0] = e1;
        m_Engines[0][1] = e2;
        m_Engines[0][2] = e3;
        m_Engines[1][0] = e4;
        m_Engines[1][1] = e5;
        m_Engines[1][2] = e6;
        m_Engines[2][0] = e7;
        m_Engines[2][1] = e8;
        m_Engines[2][2] = e9;
    }

    inline void Ignite() {
        for(int i = 0; i < m_Engines.size(); i++)
            for(int j = 0; j < m_Engines[0].size(); j++)
                m_Engines[i][j].ACTIVE = true;
    }

    virtual ~Rocket() {}
};

namespace World {
    // X, Y, Strength
    std::vector<std::array<float,3>> turbulence;
    float drag = 100.0f; // Air density
    float gravity = 9.8f;
}

void Clamp(float *valToClamp, float clamp) {
    if(*valToClamp >= clamp)
        *valToClamp = clamp;
    else if(*valToClamp <= -clamp)
        *valToClamp = -clamp;
}

void Display(Rocket &r, float thrust) {
    int counter = 1;
    std::cout << "===ROCKET STATUS===\n";
    std::cout << "Velocity: " << r.m_Velocity << " m/s\n";
    std::cout << "Acceleration: " << r.accelRate << " m/s\n";
    std::cout << "Fuel: " << r.fuel<< '\n';
    std::cout << "Height: " << r.y << "m\n";
    std::cout << "Total thrust: " << thrust << '\n';
    for(unsigned int i = 0; i < r.m_Engines.size(); i++) {
        for(unsigned int j = 0; j < r.m_Engines[0].size(); j++) {
            if(r.m_Engines[i][j].DESTROYED)
                std::cout << "Engine " << counter << " destroyed!\n";
            else {
                std::cout << "Engine " << counter << ": " << r.m_Engines[i][j].ACTIVE << " | " << r.m_Engines[i][j].THRUST << " | " << r.m_Engines[i][j].HEAT;
                if(r.m_Engines[i][j].HEAT > Engine::meltingPoint)
                    std::cout << " WARNING!\n";
                else
                    putchar('\n');
            }
            counter++;
        }
        counter++;
    }

}

void RunRocket(Rocket &r) {
    float totalThrust = 0.0f;
    r.Ignite();
    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        system("clear");
        for(unsigned int i = 0; i < r.m_Engines.size(); i++) {
            for(unsigned int j = 0; j < r.m_Engines[i].size(); j++) {
                r.m_Engines[i][j].THRUST += 0.1f;
                r.fuel -= r.m_Engines[i][j].THRUST * 0.01f;
                Clamp(&r.m_Engines[i][j].THRUST, 70.0f);
                totalThrust += r.m_Engines[i][j].THRUST;
                Clamp(&totalThrust, r.m_Engines[i][j].THRUST * r.m_Engines.size());
                r.y -= World::gravity;
                r.y += (totalThrust / r.weight);
                r.m_Engines[i][j].HEAT += (r.m_Engines[i][j].THRUST / r.y); // Takes into account local engine heat | Do atmosphere
                    // Engines are on under side of rocket so air density has little effect on temperature
                // Local Engine Heat | Make heat falloff
                if(!j+1 > r.m_Engines[0].size())
                    r.m_Engines[i][j].HEAT += r.m_Engines[i][j+1].HEAT * 0.001f;
                if(!j-1 < 0)
                    r.m_Engines[i][j].HEAT += r.m_Engines[i][j-1].HEAT * 0.001f;
                if(!i+1 > r.m_Engines.size())
                    r.m_Engines[i][j].HEAT += r.m_Engines[i+1][j].HEAT * 0.001f;
                if(!i-1 < 0)
                    r.m_Engines[i][j].HEAT += r.m_Engines[i-1][j].HEAT * 0.001f;

                if(r.m_Engines[i][j].HEAT >= Engine::meltingPoint) {
                    int shutdownChance = rand() % 1;
                    if(shutdownChance > 0.9) {
                        std::cout << "FAILED TO SHUTDOWN!";
                        r.m_Engines[i][j].DESTROYED = true;
                    }
                    else
                        r.m_Engines[i][j].ACTIVE = false;
                }
            }
        }
        World::drag -= r.y / 2;
        r.accelRate += totalThrust - World::drag; // Take into account velocity
        Clamp(&r.accelRate, 500.0f);
        Clamp(&World::drag, 0.0f);
        Clamp(&GetX(r.trajectory), 3.0f);
        Clamp(&GetY(r.trajectory), 1.0f);
        Display(r, totalThrust);
    }
}

int main() {
    Rocket mainRocket(6);

    RunRocket(mainRocket);

    return 0;
}