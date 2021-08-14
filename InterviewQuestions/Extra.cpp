#include <iostream>
#include <tuple>
#include <vector>

// Check if a destination is reachable from source with only two movements allowed:
    // (x, x+y) then (x+y, y)
    // No negative values
bool ReachableDestination(std::tuple<int,int> &source, std::tuple<int,int> &destination) {
    std::tuple<int,int> movement;
    int yValue = std::get<0>(source) + std::get<1>(source);
    std::get<1>(movement) = yValue;
    std::get<0>(movement) = std::get<0>(source) + yValue;
    if(std::get<0>(movement) == std::get<0>(destination) || std::get<1>(movement) == std::get<1>(destination))
        return true;
    return false;
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
    std::cout << "Reachable Destination:\n";
    std::tuple<int,int> source1(2,10);
    std::tuple<int,int> source2(26,12);
    std::cout << ReachableDestination(source1, source2);
    putchar('\n');


    return 0;
}