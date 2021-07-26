#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>

// Returns all duplicate characters in string format | Change!/Fix! Return
std::string GetDuplicates(const std::string &&str) {
    if(str.length() == 0)
        return str;
    else {
        // std::sort(str.begin(), str.end()); // Check need!
        std::string dupStr= ""; // Use
        std::map<int, char> m;
        for(char i : str)
            m[i]++; // Add to map
        for(char i = 'a'; i <= 'z'; i++)
            if(m.count(i) > 0)
                dupStr.append(std::to_string(i));
        return dupStr;
    }
    return str;
}

std::string DeleteDuplicates(std::string &str) {
   if(str.length() == 0)
    return str;
    else {
        std::map<int, char> m;
        for(auto i : str)
            m[i]++;
        for(char i = 'a'; i < 'z'; i++)
            if(m.count(i) > 0)
                str.erase(i); // Check!
    }
    return str;
}

// Rotate a string x amount of times either left or right
std::string RotateString(std::string &str, char dir, int amount) {
    if(dir == 'l') {
        for(int i = 0; i < amount; i++) {
            char starter = str[0];
            for(int j = 0; j < str.length(); j++) {
                str[j] = str[j+1];
            }
            str[str.length()-1] = starter;
            // std::cout << str;
        }
    }
    else if(dir == 'r') { // Check!
        for(int i = 0; i < amount; i++) {
            char starter = str[0];
            for(int j = 0; j < str.length(); j++) {
                str[j] = str[j-1];
            }
            str[str.length()-1]; 
        }    
    }
    return str;
}

// Check if a string is a rotation of another string
bool StringRotation(std::string &&str1, const std::string &&str2) { // Check!
    if(str1.length() == 0 || str2.length() == 0 || str1.length() != str2.length())
        return false;
    else {
        int passedChars = 0;
        int amount = 1;
        char direction = 'l';
        while(amount < str1.length()) {
            std::string curRotation = RotateString(str1, direction, amount);
            amount++;
            if(amount == str1.length()) { // Might cause issues | Skips a character | Check!
                direction = 'r';
                amount = 1;
            }
            for(unsigned int i = 0; i < curRotation.length(); i++) {
                if(curRotation[i] == str2[i]) {
                    passedChars++; // Should reset at some point!
                    if(passedChars == curRotation.length())
                        return true;
                }
            }
            passedChars = 0;
        }
    }
    return false;
}

// Remove any character from str1 which is found in str2 (Case sensitive) | Have remove all instance of a letter!
std::string RemoveFirstFromSecondSlow(std::string &&str1, std::string &&str2) {
    if(str1.length() == 0 || str2.length() == 0)
        return "";
    else {
        std::sort(str1.begin(), str1.end());
        std::sort(str2.begin(), str2.end());    
        for(unsigned int i = 0; i < str1.size(); i++)
            if(str1[i] == str2[i])
                for(unsigned int j = 0; j < str2.size(); j++)
                    if(str2[j] == str1[i])
                        str2.erase(str2.begin()+j);
    }
    return str2;
}

std::string RemoveFirstFromSecond(const std::string &&str1, std::string &&str2) { // Fix!
   if(str1.length() == 0 || str2.length() == 0)
        return "";
    else {
        std::unordered_map<int,char> m;
        for(auto i : str2)
            m[i]++;
        str2.clear();
        for(unsigned int i = 0; i < str1.length(); i++) {
            if(m.count(str1[i]) > 0)
                m.erase(i);
        }
        for(std::unordered_map<int,char>::iterator it; it != m.end(); it++) {
            str2.append(&it->second);
            std::cout<< it->second << '\n';
        }
    }
    return str2; 
}

// Check if the specified char exists in the string
bool CheckExists(const char target, const std::string &&str) { // Pointer char???
    if(str.size() == 0)
        return false;
    else {
        std::unordered_map<int,char> m;
        for(char i : str)
            m[i]++;
        if(m.count(target) > 0)
            return true;
    }
    return false;
}

// Reverse a string without creating aditional memory regarding the input
std::string Reverse(std::string &str, int start, int end) {
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
    return Reverse(str, 0, str.length()-1);
}

// Checks if a string contains only digits
bool OnlyDigits(std::string &&str) {
    if(str.length() == 0)
        return false;
    else {
        // std::sort(str.end(), str.begin(), std::greater<char>()); // Check! 
        for(int i = 0; i < str.length(); i++)
            if(!isdigit(str[i]))
                return false;
    }
    return true;
}

// Just like before, except no direct sorting and using a map for fast searching | Can be reversed to check if only chars
bool OnlyDigitsMap(const std::string &&str) {
    if(str.length() == 0)
        return false;
    else {
        std::unordered_map<int, char> m;
        for(auto i : str)
            m[i]++;
        for(char i = 'a'; i < 'z'; i++) // We can loop through all 26 characters and quickly check instead, as long as one is found, return false
            if(m.count(i) > 0)
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

// Prints the vowels and consonants which exist seperately
void VowelsConsonants(const std::string &&str) {
    if(str.length() == 0)
        std::cerr << "String is empty!\n";
    else {
        std::unordered_map<int,char> m;
        char vow[5] = {'a','e','i','o','u'};
        char con[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','w','v','x','y','z'};
        for(char i : str) {
            char c = std::tolower(i);
            m[c]++;
        }
        for(char i : vow)
            if(m.count(i) > 0)
                std::cout << i << ", ";
        for(char i : con)
            if(m.count(i) > 0)
                std::cout << i << ", ";
    }
}

// Prints ALL vowels and consonants for the amount of times they appear
void VowelsConsonantsAll(const std::string &&str) {  // Check, not counting map properly!
    if(str.length() == 0)
        std::cerr << "String is empty!\n";
    else {
        int count = 0;
        std::unordered_map<int,char> m;
        char vow[5] = {'a','e','i','o','u'};
        char con[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','w','v','x','y','z'};
        for(char i : str) {
            char c = std::tolower(i);
            m[c]++;
        }
        for(char i : vow) {
            count = m.count(i);
            for(unsigned int i = 0; i < count; i++)
                std::cout << i << ", ";
            count = 0;
        }
        putchar('\n');
        for(char i : con) {
            count = m.count(i);
            for(unsigned int i = 0; i < count; i++)
                std::cout << i << ", ";
            count = 0;
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

// Prints the character which occurs the most and how many times | If two character occur the same amount of times, prints first
void MaxOccuringCharacter(const std::string &&str) {
    if(str.length() == 0)
        std::cerr << "String is empty!\n";
    else {
        char maxChar = 0;
        int amount = 0;
        std::unordered_map<char,int> m;
        for(char i : str) {
            char c = std::tolower(i);
            m[c]++;
        }
        for(std::unordered_map<char,int>::iterator it = m.begin(); it != m.end(); it++) {
            if(amount < it->second) {
                amount = it->second;
                maxChar = it->first;
            }
        }
        std::cout << "Character: " << maxChar << " | " << amount << '\n';
    }
}

char FindFirstNonDuplicate(std::string &&str) {
    if(str.length() == 0)
        return ' ';
    else {
        std::unordered_map<char,int> m;
        for(char i : str) {
            char c = std::tolower(str[i]);
            m[i]++;
        }
        for(int i = 0; i < str.length(); i++) {
            char c = std::tolower(str[i]);
            if(m.count(c) == 1)
                return str[i];
        }
    }
    return ' ';
}

char FindFirstNonDuplicateIter(std::string &&str) {
    if(str.length() == 0)
        return ' ';
    else {
        std::sort(str.begin(), str.end());
        for(int i = 0; i < str.length()-1; i++) {
            if(str[i] != str[i++])
                return str[i];
        }
    }
    return ' ';
}

bool Palindrome(std::string &&str) {
    if(str.length() == 0)
        return true; // Nothing is the same as nothing, so it is declared as true
    std::string revStr = ReverseStringInPlace(std::forward<std::string>(str));
    if(revStr == str)
        return true;
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
    if(str1.length() != str2.length())
        return false;
    else {
        std::unordered_map<int, char> m;
        for(char i : str1) {
            char c = std::tolower(i);
            m[c]++;
        }
        for(int i = 0; i < str2.length(); i++) {
            char c = std::tolower(str2[i]);
            if(m.count(c) == 0)
                return false;
        }
        // return std::equal(m1.begin(), m1.end(), m2.end()); // Check!
    }
    return true;
}

// Given two strings, check if one string is a subsequence of another, in relative order
bool ValidSubSequence(const std::string &str1, const std::string &str2) {
    if(str1 == "" || str2 == "")
        return true;
    else {
        int check = 0;
        for(auto i : str2) {
            if(str1[check] == i)
                check++;
            if(check == str1.length())
                return true;
        }
    }
    return false;
}

std::vector<std::vector<std::string>> GroupAnagrams(std::vector<std::string> &anagrams) {
    std::vector<std::vector<std::string>> groupedAna;
    if(anagrams.size() == 0)
        return groupedAna;
    else {
        for(unsigned int i = 0; i < anagrams.size(); i++) {
            // Find anagrams
                // - Search through characters of each element and compare to one another
            for(unsigned int j = 0; j < anagrams[i].length(); j++) {
                
            }
        }
    }
}

// Reverse the order of words in a string
std::string ReverseWordsInString(std::string &&str) { // Fix!
    if(str.length() == 0)
        return str;
    else {
        std::string currentWord = "";
        std::vector<std::string> words{};
        for(unsigned int i = 0; i < str.length(); i++) {
            if(str[i] != ' ' || i == str.length()-1)
                currentWord += str[i]; 
            else {
                words.push_back(currentWord); 
                currentWord = "";
            }
        }
        str.clear();
        for(unsigned int i = words.size()-1; i > 0; i--) {
            str.append(words[i]);
            str.append(" ");  
        }
    }
    return str;
}

std::string ReverseStringPalin(std::string &&str, int left, int right) {
    while(left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
    return str;
}

// Returns the longest palindromic string found in another string (Excluding string itself) | Check! Wrong!
std::string LongestPalindromicSubString(std::string &&str) {
    if(str.length() == 0)
        return str;
    else {
        // Two pointer technique, reverse string and check for palindromde, keep increasing or reducing and check against previous until all of string has been searched
        int stringLength = 0;
        std::string palinString = "";
        int left = 1, right = str.length()-1; // We set left = 1 as we are ignoring the string itself 
        while(left < right) {
            palinString = ReverseStringPalin(std::forward<std::string>(str), left, right); // Modifies string, change!
            for(unsigned int i = left; i < right; i++) 
                if(str[i] == palinString[i])
                    stringLength++;
            if(stringLength == palinString.length())
                return palinString;
            left++;
            right--;
            stringLength = 0;
        }
    }
    return "";
}

int main() {
    std::cout << "Check Character Exists:\n";
    std::cout << CheckExists('a', "Hello World") << '\n';
    std::cout << CheckExists('o', "Hello World");
    putchar('\n');

    std::cout << "Reverse String:\n";
    std::cout << ReverseStringInPlace("Hello World");
    putchar('\n');

    std::cout << "Remove First From Second:\n";
    std::cout << RemoveFirstFromSecondSlow("ello", "Hello World") << '\n';
    std::cout << RemoveFirstFromSecond("ello", "Hello World");

    putchar('\n');
    std::cout << "Only Digits:\n";
    std::cout << OnlyDigitsMap("123456789") << '\n';
    std::cout << OnlyDigitsMap("1234h6789") << '\n';
    std::cout << OnlyDigits("123456789") << '\n';
    std::cout << OnlyDigits("123h56789");

    std::cout << "\nReverse Order of Words:\n";
    std::cout << ReverseWordsInString("This is a test string");

    std::cout << "\n\nString Rotation:\n";            
    // std::cout << StringRotation("HelloWorld", "lloWorldHe");
    //std::cout << StringRotation("HelloWorld", "ldHelloWor");

    putchar('\n');
    std::cout << "Longest Palindromic Sub-String:\n";
    // std::cout << LongestPalindromicSubString("Banana");

    //std::cout << ReverseWordsInString("Hello World");
    putchar('\n');
    std::cout << "Find First Non-Duplicate:\n";
    std::cout << FindFirstNonDuplicate("Tthhiiss is a Test") << '\n';
    std::cout << FindFirstNonDuplicate("bbbbcccccddddffffggghhhhkuuuTest") << '\n';
    std::cout << FindFirstNonDuplicateIter("Tthhiiss is a Test") << '\n';
    std::cout << FindFirstNonDuplicateIter("bbbbcccccddddffffggghhhhkuuuTest");

    putchar('\n');
    // Permutations("Hello", 0, 4); // Check!
    std::cout << "Vowels And Consonants:\n";
    VowelsConsonants("VowelandConsonantTest");
    putchar('\n');
    VowelsConsonantsAll("aaaauuuuttttiiibbbbmmmmhhhpppp");

    putchar('\n');
    std::cout << CountVowels("AlienPls");
    putchar('\n');

    std::cout << "\nMax Occuring Character:\n";
    MaxOccuringCharacter("Hello World");

    putchar('\n');
    std::cout << "Anagram:\n";
    std::cout << Anagram("Ram", "maR") << '\n';
    std::cout << Anagram("cat", "tac") << '\n';
    std::cout << Anagram("leg", "rib") << '\n';

    std::cout << "Anagram Map:\n";
    std::cout << AnagramMap("Ram", "maR") << '\n';

    return 0;
}