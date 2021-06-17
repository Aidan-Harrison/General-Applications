#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

// Returns all duplicate characters in string format | Change!/Fix! Return
std::string GetDuplicates(const std::string &&str) {
    if(str.length() == 0)
        return str;
    else {
        // std::sort(str.begin(), str.end()); // Check need!
        std::vector<char> duplicates{};
        std::map<int, char> m;
        for(char i : str)
            m[i]++; // Add to map
        for(char i = 'a'; i <= 'z'; i++)
            if(m.count(i) > 0)
                duplicates.push_back(i);
    }
    return str;
}

// Check if the specified char exists in the string
bool CheckExists(const char target, const std::string &&str) { // Pointer char???
    if(str.size() == 0)
        return false;
    else {
        std::map<int,char> m;
        for(char i : str)
            m[i]++;
        if(m.count(target) > 0)
            return true;
    }
    return false;
}

// Reverse a string without creating aditional memory regarding the input
std::string Swap(std::string &str, int start, int end) {
    while(start < end) {
        char temp = str[start]; // This is still in-place
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}

std::string ReverseStringInPlace(std::string &&str) {
    if(str.length() == 0)
        return str;
    return Swap(str, 0, str.length()-1);
}

// Checks if a string contains only digits | Sort? Could be faster is numbers are sorted first
bool OnlyDigits(std::string &&str) {
    if(str.length() == 0)
        return false;
    else {
        std::sort(str.begin(), str.end()); // We want to sort as digits come before letters, given a large string, we can cut back on the amount of iterating
        for(int i = 0; i < str.length(); i++)
            if(!isdigit(str[i]))
                return false;
    }
    return true;
}

// Gets all possible permutations (Arrangements) of the given string | Fix!
void Permutations(std::string &&str, int start, int end) {
    // Nothing is considered an arragement, no edge case
    if(start == end)
        std::cout << str << '\n';
    else {
        for(int i = start; i <= end; i++) {
            std::swap(str[start], str[i]);
            Permutations(std::forward<std::string>(str), start++, end); // Check!
            std::swap(str[start], str[i]);
        }
    }
}

// Prints all vowels and consonants seperately | Come back to this
void VowelsConsonants(const std::string &str) {
    if(str.length() == 0)
        std::cerr << "String is empty!\n";
    else {
        std::map<int,char> m;
        char vow[5] = {'a','e','i','o','u'};
        char con[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','w','v','x','y','z'};
        for(char i : str) {
            char c = std::tolower(i);
            m[c]++;
        }
        for(std::map<int,char>::iterator it = m.begin(); it != m.end(); it++) {
            for(char i : vow)
                if(it->second == i)
                    std::cout << i << ", ";
            for(char i : con)
                if(it->second == i)
                    std::cout << i << ", ";
        }
    }
}

int CountVowels(const std::string &str) {
    if(str.length() == 0)
        return -1;
    else {
        int count = 0;
        for(char i : str) {
            char c = std::tolower(i);
            switch(c) {
                case 'a': count++; break;
                case 'e': count++; break;
                case 'i': count++; break;
                case 'o': count++; break;
                case 'u': count++; break;
            }
        }
        return count;
    }
    return -1;
}

// Prints the character which occurs the most and how many times | If two character occur the same amount of time, prints first
void MaxOccuringCharacter(const std::string &str) {
    if(str.length() == 0)
        std::cerr << "String is empty!\n";
    else {
        char maxChar = 0;
        int amount = 0;
        std::map<char,int> m;
        for(char i : str) {
            char c = std::tolower(i);
            m[c]++;
        }
        for(std::map<char,int>::iterator it = m.begin(); it != m.end(); it++) {
            if(amount < it->second) {
                amount = it->second;
                maxChar = it->first;
            }
        }
        std::cout << "Character: " << maxChar << " | " << amount << '\n';
    }
}

char FindFirstNonDuplicate(std::string &&str) { // Fix!
    if(str.length() == 0)
        return ' ';
    else {
        std::map<char,int> m;
        for(char i : str)
            m[i]++;
        for(char i = 'a'; i <= 'z'; i++)
            if(m.count(i) == 1) // Check!
                return i;
    }
    return ' ';
}

bool Palindrome(std::string &&str) {
    if(str.length() == 0)
        return true; // Nothing is the same as nothing, so it is declared as true
    std::string revStr = ReverseStringInPlace(std::forward<std::string>(str));
    if(revStr == str)
        return true;
    else
        return false;
}

// Using std::equal we can condense this to a single line
bool PalindromeOneLine(std::string &&str) { // Check!
    return std::equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}

bool Anagram(std::string &&str1, std::string &&str2) {
    if(str1.length() != str2.length())
        return false;
    else {
        std::sort(str1.begin(), str1.end());
        std::sort(str2.begin(), str2.end());
        for(unsigned int i = 0; i < str1.length(); i++) {
            char s1 = std::tolower(str1[i]);
            char s2 = std::tolower(str2[i]);
            if(s1 != s2)
                return false;
        }
    }
    return true;
}

bool AnagramMap(std::string &&str1, std::string &&str2) {
    if(str1.length() == str2.length())
        return false;
    else {
        std::map<int, char> m1;
        std::map<int, char> m2;
        for(char i : str1)
            m1[i]++;
        for(char i : str2)
            m2[i]++;
        return std::equal(m1.begin(), m1.end(), m2.end());
    }
}

int main() {
    std::cout << CheckExists('a', "Hello World") << '\n';
    std::cout << CheckExists('o', "Hello World");
    putchar('\n');

    std::cout << ReverseStringInPlace("Hello World");
    putchar('\n');

    std::cout << OnlyDigits("123456789") << '\n';
    std::cout << OnlyDigits("123h56789");

    // Permutations("Hello", 0, 4); // Check!

    VowelsConsonants("AlienPls");

    putchar('\n');
    std::cout << CountVowels("AlienPls");
    putchar('\n');
    MaxOccuringCharacter("Hello World");

    putchar('\n');

    std::cout << Anagram("Ram", "maR");
    std::cout << Anagram("cat", "tac");
    std::cout << Anagram("leg", "rib");

    return 0;
}