#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <queue>

const bool isOp(const char c) {
    switch(c) {
        case '+': return true; break;
        case '-': return true; break;
        case '*': return true; break;
        case '/': return true; break;
    }
    return false;
}

std::vector<std::pair<int,int>> Brackets(const std::string & str) {
    /*
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
    */
    std::vector<std::pair<int,int>> pos{};
    std::stack<char> s;
    int count = 0, valPos;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            s.push(str[i]);
            valPos = i;
        }
        else {
            if(s.size() == 0)
                continue;
            else if(str[i] == ')' && s.top() == '(') {
                count++;
                pos.push_back({valPos,i});
                s.pop();
            }
        }
    }
    return pos;
}

void Reverse(std::string & str) {
    int left = 0, right = str.length();
    while(left < right) {
        char temp = str[right];
        str[right] = str[left];
        str[left] = temp;
        left++;
        right--;
    }
}

inline const bool isOp(const char c) {
    switch(c) {
        case '+': return true; break;
        case '-': return true; break;
        case '*': return true; break;
        case '/': return true; break;
    }
    return false;
}

float SlidingFinder(const std::string & str) {
    int pointer = 0;
    std::string nStr;
    bool hasFirst = false;
    char operation = ' ';
    float o1, o2;
    for(int i = 0; i < str.length(); i++) {
        if(isdigit(str[i])) {
            pointer = i;
            while(isdigit(str[pointer])) {
                nStr += str[pointer];
                pointer++;
            }
            i = pointer;
            if(!hasFirst)
                o1 = std::stof(nStr);
            else
                o2 = std::stof(nStr);
            hasFirst = true;
            nStr.clear();
        } else if(isOp(str[i]))
            operation = str[i];
    }
    switch(operation) {
        case '+': return o1 + o2; break;
        case '-': return o1 + o2; break;
        case '*': return o1 + o2; break;
        case '/': return o1 + o2; break;
    }
}

float Solver(const std::string & str) { // Solves given string
    float result = 0.0f;
    std::string oStr1, oStr2;
    float o1 = 0.0f, o2 = 0.0f;
    for(char i : str) {
        if(i == '+' || i == '-' || i == '*' || i == '/') {
            int j = i-1, k = i+1;
            while(isdigit(str[j])) {
                j--;
                oStr1.push_back(str[j]);
            }
            Reverse(oStr1);
            o1 = std::stof(oStr1);
            while(isdigit(str[k])) {
                k++;
                oStr2.push_back(str[j]);
            }
            Reverse(oStr2);
            o2 = std::stof(oStr2);
            switch(i) {
                case '+': result = o1 + o2; break;
                case '-': result = o1 + o2; break;
                case '*': result = o1 + o2; break;
                case '.': {
                    // Check if '.' operator not decimal
                    result = o1 + o2; 
                    break;
                }
                case '/': result = o1 + o2; break;
            }
        }
    }
    return result;
}

std::string Reader(const std::string && str) { // Splits string into appropiate components and order
    // Iterate through str
    // Store each term in a map
    // Combine relevant terms
        // Prevent digits from being appended to the map
    std::map<char,int> terms{};
    std::vector<char> operators{};
    std::string result = "";
    std::queue<std::string> order{};
    std::vector<std::pair<int,int>> bPos = Brackets(str); // Prioritise brackets
    for(int i = 0; i < bPos.size(); i++) {
        std::string temp = "";
        for(int j = bPos[i].first; j < bPos[i].second; j++) {
            if(str[j] == '(' && bPos[i].first == j) { // Step in | Check!
                continue;
            }
            temp+=str[j];
        }
        if(temp != "")
            order.push(temp);
    }
    
    /*
    std::cout << "Order: ";
    while(!order.empty()) {
        std::cout << order.front();
        order.pop();
    }
    std::cout << "\tENDED!\n";
    */

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
    Brackets("()()()()()()");
    std::cout << "Answer: " << Reader("47a + 4b + a - (9c + 2b)");

    return 0;
}