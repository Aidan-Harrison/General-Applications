#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>

// Returns all duplicate characters in string format (Case insensitive)
std::string GetDuplicates(const std::string &&str) {
    if(str.length() == 0)
        return "";
    else {
        std::string dupStr = "";
        std::unordered_map<char, int> m;
        for(char i : str) {
            char c = std::tolower(i);
            m[c]++;
        }
        for(auto it = m.begin(); it != m.end(); it++)
            if(it->second > 1)
                dupStr += it->first;
        return dupStr;
    }
    return "";
}

std::string DeleteDuplicates(std::string &str) { // Manual deletion | Continue
    if(str.length() == 0)
        return "String is invalid: " + str;
    else {
        std::map<char, int> m;
        for(auto i : str)
            m[i]++;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second > 1) {
                for(int i = str.length(); i > 0; i--) {
                    if(str[i] == it->first) {
                        str[i] == ' ';
                        char temp = str[i-1];
                        str[i-1] = str[i];
                        str[str.length()-1] = ' ';
                    }
                }
            }
        }
    }
    return "No duplicates found in " + str;
}

// Rotate a string x amount of times either left or right
std::string RotateString(std::string &str, char dir, int amount) {
    if(dir == 'l') {
        for(int i = 0; i < amount; i++) {
            char starter = str[0];
            for(int j = 0; j < str.length()-1; j++) {
                str[j] = str[j+1];
            }
            str[str.length()-1] = starter;
        }
    }
    else if(dir == 'r') { // CHANGE!!!
        for(int i = 0; i < amount; i++) {
            char starter = str[str.length()-1];
            for(int j = str.length(); j > 1; j--) {
                str[j] = str[j-1];
            }
            str[0] = starter; 
        }    
    }
    return str;
}

// Check if a string is a rotation of another string
bool StringRotation(std::string &&str1, const std::string &&str2) { // Check!
    if(str1.length() == 0 || str2.length() == 0 || str1.length() != str2.length())
        return false;
    else {
        int amount = 1;
        char direction = 'l';
        while(amount < str1.length()) {
            std::string curRotation = RotateString(str1, direction, amount);
            amount++;
            if(amount == str1.length()) { // Might cause issues | Skips a character | Check!
                direction = 'r';
                amount = 1;
            }
            for(unsigned int i = 0; i < curRotation.length(); i++)
                if(curRotation[i] != str2[i])
                    return false;
        }
    }
    return true;
}

// Remove any character from str1 which is found in str2 (Case sensitive)
std::string RemoveFirstFromSecondSlow(const std::string &&str1, std::string &&str2) {
    for(unsigned int i = 0; i < str2.length(); i++) 
        for(unsigned int j = 0; j < str1.length(); j++)
            if(str1[j] == str2[i])
                str2.erase(str2.begin()+i);
    return str2;
}

std::string RemoveFirstFromSecond(const std::string &&str1, std::string &&str2) { // Over-engineered
    if(str1.length() == 0 || str2.length() == 0)
        return "";
    else {
        std::unordered_map<char,int> m;
        for(auto i : str2)
            m[i]++;
        str2.clear();
        for(unsigned int i = 0; i < str1.length(); i++) {
            if(m.count(str1[i]) > 0)
                m.erase(i);
        }
        for(auto it = m.begin(); it != m.end(); it++)
            str2 += it->first;
    }
    return str2; 
}

std::string RemoveFirstFromSecondOther(const std::string &&str1, std::string &&str2) {

}

// Check if the specified char exists in the string
bool CheckExists(const char target, const std::string &&str) { // Pointer char???
    if(str.size() == 0 || target == ' ')
        return false;
    else {
        std::unordered_map<char,int> m;
        for(char i : str)
            m[i]++;
        for(auto it = m.begin(); it != m.end(); it++)
            if(it->first == target)
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
        std::unordered_map<char,int> m;
        char vow[5] = {'a','e','i','o','u'};
        char con[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','w','v','x','y','z'};
        for(char i : str) {
            char c = std::tolower(i);
            m[c]++;
        }
        for(char i : vow)
            if(m.count(i) > 0) // Check!
                std::cout << i << ", ";
        for(char i : con)
            if(m.count(i) > 0)
                std::cout << i << ", ";
    }
}

void VowelsConstonantsOther(const std::string &&str) {
    char vow[5] = {'a', 'e', 'i', 'o', 'u'};
    for(unsigned int i = 0; i < str.length(); i++) {
        for(unsigned int j = 0; j < 5; j++)
            if(str[i] != vow[j])
                std::cout << "Consonant: "<< str[i];
            else
                std::cout << "Vowel: "<< str[i];
    }
}

// We can omit the consonants array
std::vector<char> VowelsConsonantsBetter(const std::string &&str) {
    std::vector<char> vowConst;
    if(str.length() == 0)
        return vowConst;
    else {
        int count = 0;
        char vow[5] = {'a','e','i','o','u'};
        std::unordered_map<char,int> map;
        for(char i : str) {
            char c = std::tolower(i);
            map[c]++;
        }
        for(auto it = map.begin(); it != map.end() && count != 5; it++) {
            if(it->first != vow[count])
                vowConst.push_back(it->first);
            count++;
            if(count == 4)
                count = 0;
        }
    }
    return vowConst;
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
        for(int i = 0; i < str.length(); i++)
            m.insert(std::pair<char, int>(str[i], i)); // Check, int seems wrong??
        for(unsigned int i = 0; i < str.length(); i++) {
            if(m.count(str[i]) == 1)
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
        // Remove whitespace
        for(unsigned int i = 0; i <= str.length(); i++)
            if(str[i] == ' ')
                str.erase(str.begin() + i);
        for(auto i : str)
            std::cout << i;
        putchar('\n');
        for(unsigned int i = 0; i < str.length()-1; i++) {
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
        for(unsigned int i = 0; i < str2.length(); i++) {
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

char FindFirstRecurringNaive(const std::string &&str) {
    if(str.length() == 0)
        return ' ';
    else {
        for(unsigned int i = 0; i < str.length(); i++) {
            for(unsigned int j = i; j < str.length(); j++) {
                if(str[i] == str[j] && j != i)
                    return str[i];
            }
        }
    }
    return ' ';
}

char FindFirstRecurring(const std::string &&str) {
    if(str.length() == 0)
        return ' ';
    else {
        std::unordered_map<char,int> characters;
        for(auto i : str)
            characters[i]++;
        for(unsigned int i = 0; i < str.length(); i++) {
            std::unordered_map<char,int>::iterator it = characters.find(str[i]);
            if(it->second > 1)
                return str[i];
        }
    } 
    return ' ';
}

std::string MatchingCharacters(const std::string &&str) {
    if(str.length() == 0)
        return str;
    else {
        std::string matchingChars = "";
        std::unordered_map<char,int> characters;
        for(auto i : str)
            characters[i]++;
        for(unsigned int i = 0; i < str.length(); i++) {
            std::unordered_map<char,int>::iterator it = characters.find(str[i]);
            if(it->second > 1)
                matchingChars.push_back(str[i]);
        }
        return matchingChars;
    }
    return str;
}

bool isPrefix(std::string word, std::string prefix) {
    int pCounter = 0;
    int prevPos = -1;
    for(int i = 0; i < word.length(); i++) {
        if(pCounter == prefix.length())
            return true;
        if(i == prevPos+1 && word[i] == prefix[i]) {
            std::cout << word[i] << ", ";
            prevPos = i;
            pCounter++;
        }
    }
    return false;
}

// Get words with repeating letters
std::vector<std::string> GetRepeatingBrute(std::vector<std::string> &arr) {
    std::vector<std::string> repeatingStrings{};
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].length() == 1)
            repeatingStrings.push_back(arr[i]);
        std::sort(arr[i].begin(), arr[i].end());
        for(int j = 0; j < arr[i].length(); j++) {
            if(arr[i].at(j) == arr[i].at(j+1))
                repeatingStrings.push_back(arr[i]);
        }
    }
}


std::vector<std::string> GetRepeating(std::vector<std::string> &arr) {
    // Avoid sorting
    // Use map
    std::unordered_map<int, std::string> map;
    std::vector<std::string> repeatingStrings{};
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].length() == 1)
            repeatingStrings.push_back(arr[i]);
        // Don't sort
        // Check with map instead of loop? | Possibly other methods
    }
}

std::string WordFind(const std::string &&sentence, const std::string &&wordToFind = "") {
    bool hasStarted = true;
    std::string word;
    std::vector<std::string> words{};
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] != ' ' && !hasStarted) {
            hasStarted = true;
            word.push_back(sentence[i]);
        }
        else if(sentence[i] != ' ' && hasStarted)
            word.push_back(sentence[i]);
        if(sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?' || i == sentence.length()-1) {
            hasStarted = false;
            words.push_back(word);
            word.clear();
        }
    }
    for(auto i : words)
        if(i == wordToFind)
            return i;
    return "Not Found!";
}

std::vector<std::string> FindSyllables(const std::string &&arr) {
    std::vector<std::string> syllables{};
    std::string curWord = "";
    for(unsigned int i = 0; i < arr.size(); i++) {
        curWord += arr[i];
        if(arr[i] == '-') {
            syllables.push_back(curWord);
            curWord.clear();
        }
    }
    return syllables;
}

// Given a sentence with missing capital letters, capitalise
void Capitalise(std::string &&sentence) {
    for(unsigned int i = 0; i < sentence.length(); i++) {
        if(i == 0 && !std::isupper(sentence[i]))
            sentence[i] = std::toupper(sentence[i]);
        if(sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?' && i != sentence.length()) {
            if(isalnum(sentence[i+1])) {
                sentence.insert(i+1, " ");
                sentence[i+2] = std::toupper(sentence[i+2]); // Check! | originally 1
            }
            else
                sentence[i+2] = std::toupper(sentence[i+2]);
        }
    }
}

std::vector<std::string> CapNames(std::vector<std::string> & names) {
    for(int i = 0; i < names.size(); i++) {
        for(int j = 0; j < names[i].length(); j++) {
            if(std::islower(names[i].at(j)) && j == 0)
                names[i].at(j) = std::toupper(names[i].at(j));
            else if(std::isupper(names[i].at(j)) && j != 0)
                names[i].at(j) = std::tolower(names[i].at(j));
        }
    }
    return names;
}

// Given a sentence, rotate every word n amount | Works! But, look into improving performance
std::vector<std::string> RotationWordFind(const std::string &&sentence) {
    bool hasStarted = true;
    std::string word;
    std::vector<std::string> words{};
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] != ' ' && !hasStarted) {
            hasStarted = true;
            word.push_back(sentence[i]);
        }
        else if(sentence[i] != ' ' && hasStarted)
            word.push_back(sentence[i]);
        if(sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?' || i == sentence.length()-1) {
            hasStarted = false;
            words.push_back(word);
            word.clear();
        }
    }
    return words;
}

std::string RotateWord(std::string &word, const int amount) {
    for(int i = 0; i < amount; i++) {
        char starter = word[0];
        for(int j = 0; j < word.length()-1; j++)
            word[j] = word[j+1];
        word[word.length()-1] = starter;
    }
    return word;
}

std::string WordRotation(std::string &&sentence, const int amount) {
    // Find words
    std::string rotatedSentence;
    std::vector<std::string> words;
    words = RotationWordFind(std::forward<std::string>(sentence));
    for(int i = 0; i < words.size(); i++) {
        // Standard array rotation ran per word
        words[i] = RotateWord(words[i], amount);
        rotatedSentence.append(words[i]);
        if(i != sentence.length()-1)
            rotatedSentence.append(" ");
    }
    return rotatedSentence;
}

// Get Pairs
    // Given a string, find all pair characters
std::vector<std::pair<char,char>> FindPairs(const std::string &&str) {
    // Find duplicates, if pair is available, create and push
    std::vector<std::pair<char,char>> pairs{};
    std::unordered_map<char,int> map;
    for(auto i : str)
        map[i]++;
    for(auto it = map.begin(); it != map.end(); it++) { 
        if(it->second % 2 == 0) {
            std::pair<char,char> newPair{it->first, it->first};
            pairs.push_back(newPair);
        }
    }
    return pairs;
}

// Ceaser Cipher
void Ceaser(std::string s) {
    for(char& c : s) {
        if(c == 'z')
            c = 'a';
        else
            c++;
    }
}

void CeaserBetter(std::string s, int k = 13) {
    for(char& c : s) {
        for(int i = 0; i < k; i++) {
            if(c == 'z')
                c = 'a';
            else
                c++;
        }
    }
}

// Letter Distance
inline const int distance(const int x, const int y) { return x - y; }

int letterDistance(const std::string && str1, const std::string && str2) {
	std::vector<int> results{};
	int result = 0;
	int n = str1.length();
	if(str2.length() < str1.length())
		n = str2.length();
	for(int i = 0; i < n; i++)
		results.push_back(abs(distance(str1[i], str2[i])));
	if(str1.length() != str2.length())
		results.push_back(abs(distance(str1.length(), str2.length())));
	for(int i : results)
				result += i;
	return result;
}

const std::string createPhoneNumber(const int arr [10]){
    std::string phoneNum = "(";
    for(int i = 0; i < 10; i++) {
        if(i == 3)
            phoneNum += ") ";
        else if(i == 6)
            phoneNum += '-';
        phoneNum += std::to_string(arr[i]);
    }
    return phoneNum;
}

std::string bracketString(const std::string & str) {
    std::string result = "";
    std::unordered_map<char,int> m;
    for(char i : str)
        m[std::tolower(i)]++;
    for(char i : str)
        result += m[std::tolower(i)] == 1 ? '(':')';
    return result;
}

std::string getMiddleChar(const std::string && str) {
    std::string middle = "";
    if(str.length() % 2 == 0) {
        middle += str[str.length()/2-1];
        middle += str[str.length()/2];
    }
    else 
        middle += str[str.length()/2];
    return middle;
}

std::string getMiddleCharComp(const std::string && str) {
    if(str.length() % 2 == 0)
        return str.substr(str.length()/2-1,2);
    return str.substr(str.length()/2,1);
}

// Do best version of Ceaser

int main() {
    std::cout << "Get Duplicates:\n";
    std::cout << GetDuplicates("Hello World");

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
    std::cout << LongestPalindromicSubString("Banana");

    //std::cout << ReverseWordsInString("Hello World");
    putchar('\n');
    std::cout << "Find First Non-Duplicate:\n";
    std::cout << FindFirstNonDuplicate("Tthhiiss is a Test") << '\n';
    std::cout << FindFirstNonDuplicate("bbbbcccccddddffffggghhhhkuuuTest") << '\n';
    std::cout << "Find First Non-Duplicate Iter:\n";
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

    int num[10] = {1,2,3,4,5,6,7,8,9,0};
    std::cout << createPhoneNumber(num);

    return 0;
}