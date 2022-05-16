#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <string>
#include <sstream>

std::string test = "1:(FT)8Z_3C_5sC_1T_24G/";
std::map<int,int> waves{};
std::vector<char> enemies{};
std::array<bool, 5> modFlags{0,0,0,0,0};
std::vector<int> numOfEnemies{};

inline const bool ContainsExcluded(const char ch) {
    return ch != ':' && ch != '_' && ch != '/';
}

const char parseChar(const char ch) {
    if(!isdigit(ch))
        return ' ';
    return ch;
}

void interp(const std::string && str) noexcept {
    int totalEnemies = 0, totalWaves = 0;
    int wave = 0, eCount = 0, marcher = 0;
    // Multi-char
    bool has_sC = false, has_vO = false, has_sK = false;
    std::stringstream value;
    for(int i = 0; i < str.length(); i++) { // Replace with atoi()!
        if(str[i] == ':') {
            if(isdigit(waves[i-2]))
                value << waves[i-2];
            value << waves[i-1];
            value >> eCount;
            waves[wave] = 0;
            totalWaves++;
        }
        else if(str[i] == '(') {
            while(str[marcher] != ')') {
                switch(str[marcher]) {
                    case 'F': modFlags[0] = true; break;
                    case 'D': modFlags[1] = true; break;
                    case 'T': modFlags[2] = true; break;
                    case 'X': modFlags[3] = true; break;
                    case 'S': modFlags[4] = true; break;
                }
                marcher++;
            }
            i = marcher;
        }
        else if(!isdigit(str[i]) && ContainsExcluded(str[i])) {
            std::string result = "";
            bool specified = false;
            if(!isdigit(str[i-1])) {
                eCount = 1; // Calculate best default value
                specified = true;
            }
            else if(isdigit(str[i-1])) {
                if(isdigit(str[i-2]))
                    result += str[i-2];
                result += str[i-1];
                value << result;
            }
            if(!specified)
                eCount = atoi(result.c_str());
            totalEnemies += eCount;
            for(int j = 0; j < eCount; j++)
                enemies.push_back(str[i]);
        }
    }
    /*

    for(int i : totalWaves) {
        waves[i]+=totalEnemies;
    }
    */
}

int main() {
    interp("1:(FT)8Z_3C_5sC_1T_24G/");

    std::cout << "=MODS=\n";
    for(auto i : modFlags)
        std::cout << i << '|';
    std::cout << "\n=ENEMIES=\n";
    for(char i : enemies)
        std::cout << i << ',';

    return 0;
}