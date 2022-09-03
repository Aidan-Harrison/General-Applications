#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>

const bool isOp(const char c) {
    switch(c) {
        case '+': return true; break;
        case '-': return true; break;
        case '*': return true; break;
        case '/': return true; break;
    }
    return false;
}

void BracketPair(const std::string && str) {
    std::stack<int> pairs{};
    int pairsFound = 0;
    for(int i = 0; i < str.length(); i++)
        if(str[i] == '(')
            pairs.push(i);
    std::vector<bool> markedEnds{};
    while(!pairs.empty()) {
        bool found = false;
        for(int i = pairs.top(); i < str.length(); i++) {
            if(str[i] == ')') {
                for(int j : markedEnds) {
                    if(j == i) {
                        found = true;
                        continue;
                    } 
                }
                markedEnds.push_back(i);
                if(!found)
                    pairsFound++;
            }
        }
        pairs.pop();
    }
    std::cout << pairsFound << '\n';
}

std::vector<int> BracketSearch(const std::string & str) {
    std::vector<int> bPos{};
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            bool found = false;
            bPos.push_back(i);
            int j = i+1;
            while(str[j] != ')' || j < str.length()) {
                if(str[j] == '(') // Backtrack algo?
                    found = true;
                j++;
            }
            if(str[j] == ')')
                bPos.push_back(j);
        }
    }
    return bPos;
}

std::string Solver(const std::string && str) {
    // Iterate through str
    // Store each term in a map
    // Combine relevant terms
        // Prevent digits from being appended to the map
    std::map<char,int> terms{};
    std::vector<char> operators{};
    std::string result = "";
    std::vector<int> bPos = BracketSearch(str);
    for(int i = 0; i < str.length(); i++) {
        if(!isdigit(str[i]) && str[i] != ' ' && !isOp(str[i])) {
            if(!isdigit(str[i-1]))
                terms[str[i]]++;
            else {
                std::string curVal = "";
                int j = i-1;
                while(isdigit(str[j])) {
                    curVal += str[j];
                    j--;
                }
                std::reverse(curVal.begin(), curVal.end());
                terms[str[i]] += std::stoi(curVal);
            }
        } else if(isOp(str[i])) {
            operators.push_back(str[i]);
        }
    }
    
    int opCount = 0;
    for(auto it = terms.begin(); it != terms.end(); it++) { // Reconstruct
        // std::cout << it->first << " | " << it->second << '\n';
        if(!isOp(it->first)) {
            result += std::to_string(it->second);
            result += it->first;
            result += " ";
            if(opCount < operators.size()) {
                result += operators[opCount];
                result += " ";
            }
            opCount++;
        }
    }
    return result;
}

int main() {
    BracketPair("()()()()()()");
    std::cout << Solver("47a + 4b + a - 9c + 2b");

    return 0;
}