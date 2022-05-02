#include <iostream>
#include <tuple>
#include <vector>
#include <pair>

const bool isPrime(const int a) { // speed up if possible
    if(a <= 1)
        return false;
    for(uint32_t i = 2; i < a/2; i++)
        if(a % i == 0)
            return false;
    return true;
}

// Check if a destination is reachable from source with only two movements allowed:
    // (x, x+y) then (x+y, y)
    // No negative values
bool ReachableDestinationOther(std::pair<int,int> & src, std::pair<int,int> &des) {
    int yVal = src.first + src.second;
    int xVal = yVal;
    std::pair<int,int> newPair = {xVal,yVal};
    if(newPair== des)
        return true;
    return false;
}

std::string splitString(std::string && str, std::vector<std::pair<int,char>> & slice) {
    for(uint32_t i = 0; i < str.length(); i++)
        if(i % slice[i].first == 0) {
            str.insert(i,slice[i].second);
    return str;
}

// Given an integer n, which refers to the amount of open and closing brackets their are, get all possible permutations of the brackets (Following 'Open-Close')
std::vector<std::string> brackets{};
std::string curPerm = "";

std::vector<std::string> MatchingParentheses(int n, std::string perm, int left, int right) { // Depth First Search
    /*
    if(left == 0 && right == 0)
        return brackets;
    int amountOfBrackets = n * n;
    left = amountOfBrackets / 2;
    right = amountOfBrackets / 2;
    for(auto i : brackets) {
        if(curPerm == i && left < right) {
            curPerm.append("(");
            MatchingParentheses(n, curPerm, left--, right);
        }
    }
    */

    // Know how many brackets to create
        // n^2
    // Choose between appending '(' or ')'
    // Create an open bracket before creating a closing bracket
        // And vice-versa only create a closing bracket if their is an open bracket without a closed bracket
    // Repeat steps 2-3
    // Push permutation to vector
}



int main() {
    std::cout << isPrime(1);
    std::cout << isPrime(2);
    std::cout << isPrime(13);
    std::cout << isPrime(5897);

    std::cout << "Reachable Destination:\n";
    std::tuple<int,int> source1(2,10);
    std::tuple<int,int> source2(26,12);
    std::cout << ReachableDestination(source1, source2);
    putchar('\n');


    return 0;
}