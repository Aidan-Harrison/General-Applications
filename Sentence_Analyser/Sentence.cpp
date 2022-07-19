/*
    - Sentence Analyser
    - Aidan Harrison
    - 2022
    - C++20
    Takes a string and returns the following:
        - Each word individually
        - A list of all characters used 
        - All punctucation used
            - And subsequently not used -- DO
        - Whitespace count 
        - Word count 
        - Character count 
        - Punctuation count -- Partial
        - Uppercase and Lowercase count 
        - Verb, noun and adjective count -- Add rest of data
            - Also stores and returns each in their own container | Rephrase
        - Longest word 
        - Average word length
        - Most and least used word 
        - Most and least used letter 
        - Mistakes:
            - Missing capital letters
            - Missing spaces (This will be hard)
            - Spelling errors (Partial) (Also hard)
            - Missing punctuation (Another hard one)
            - Intended comma placement | Based off sentence and word length (Yet another hard one)
*/

#define firstElement std::get<0>
#define secondElement std::get<1>
#define thirdElement std::get<2>

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

std::fstream fileHandler;
enum LEVELS{LOW=1,MID,HIGH};

namespace _data {
    int wordCount{}, characterCount{};
    int whitespaceCount{}, mistakeCount{};
    std::map<std::string,int> words{}; // Word and count
    std::map<std::string,bool> verbs{};
    std::map<std::string,bool> nouns{};
    std::map<std::string,bool> adjectives{};
    std::map<char,bool> characters{};
    std::map<char,bool> punctuation{};
    int verbCount{}, nounCount{}, adjectCount{};
    int vowelCount{}, constenantCount{};
    int punctuationCount{};
    int uppercaseCount{}, lowercaseCount{};
    int averageWordLength{};
    std::map<char,int> characterUsage{};
    std::tuple<std::string,int,int> longestWord = {"",INT_MIN,0}; // Word, length, location
}

bool Load() {
    using namespace _data;
    fileHandler.open("verbs.txt");
    if(fileHandler.fail())
        std::cerr << "Failed to load 'verbs.txt'\n";
    else
        std::cout << "'verbs.txt' loaded successfully\n";
    // Store verbs
    std::string line = "";
    while(!fileHandler.eof()) {
        fileHandler >> line;
        verbs[line] = true;
    }
    return true;
}

bool vowelCheck(const char c) {
    switch(c) {
        case 'a': return true;
        case 'e': return true;
        case 'i': return true;
        case 'o': return true;
        case 'u': return true;
    }
    return false;
}

void Analyse(const std::string && sentence) {
    _data::characterCount = sentence.length();
    std::string curWord = "";
    int k = 0;
    while(sentence[k] != ' ') { // Get first word
        if(sentence[k] == '.' || sentence[k] == '?' || sentence[k] == '!') {
            _data::punctuationCount++;
            _data::punctuation[sentence[k]] = true;
            // Check for proper usage
            if(k+1 < sentence.length()-1 && sentence[k+1] != ' ') {
                _data::mistakeCount++;
                int l = k+2;
                while(sentence[l] == ' ') {
                    _data::mistakeCount++;
                    l++;
                }
                k = l;
            } 
            else if(k+2 < sentence.length()-1 && !isupper(sentence[k+2]))
                _data::mistakeCount++;
            break;
        }
        else if(k == sentence.length()-1)
            break;
        if(vowelCheck(sentence[k]))
            _data::vowelCount++;
        else 
            _data::constenantCount++;
        curWord += sentence[k];
        _data::characters[sentence[k]] = true;
        _data::characterUsage[sentence[k]]++;
        if(isupper(sentence[k]))
            _data::uppercaseCount++;
        else
            _data::lowercaseCount++;
        k++;
    }
    _data::words[curWord]++;
    curWord.clear();
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ') {
            _data::whitespaceCount++;
            int j = i+1; // Check overflow!?
            while(sentence[j] != ' ') {
                if(sentence[j] == '.' || sentence[j] == '?' || sentence[j] == '!') {
                    _data::punctuationCount++;
                    _data::punctuation[sentence[j]] = true;
                    if(j+1 < sentence.length()-1 && sentence[j+1] != ' ') {
                        _data::mistakeCount++;
                        int l = j+2;
                        while(sentence[l] == ' ') {
                            _data::mistakeCount++;
                            l++;
                        }
                        j = l;
                    }  
                    else if(j+2 < sentence.length()-1 && !isupper(sentence[j+2]))
                        _data::mistakeCount++;
                    break;
                }
                else if(j == sentence.length()-1) {
                    i=j-1;
                    break;
                }
                if(vowelCheck(sentence[j]))
                    _data::vowelCount++;
                else 
                    _data::constenantCount++;
                curWord += sentence[j];
                _data::characters[sentence[j]] = true;
                _data::characterUsage[sentence[j]]++;
                if(isupper(sentence[j]))
                    _data::uppercaseCount++;
                else
                    _data::lowercaseCount++;
                j++;
            }
            i=j-1;
            _data::words[curWord]++;
            curWord.clear();
        } 
    }
    _data::wordCount = _data::words.size();
    int sum = 0, counter = 0;
    for(auto it = _data::words.begin(); it != _data::words.end(); it++) { // Search through verbs, nouns and adjectives
        sum += it->first.length();
        int original = secondElement(_data::longestWord);
        secondElement(_data::longestWord) = std::max(secondElement(_data::longestWord), (int)it->first.length());
        // Average word length
        if(original != secondElement(_data::longestWord)) { // Has changed
            firstElement(_data::longestWord) = it->first;
            thirdElement(_data::longestWord) = counter; 
        }
        if(_data::verbs[it->first]) {
            _data::verbCount++;
        } else if(_data::nouns[it->first]) {
            _data::nounCount++;
        } else if(_data::adjectives[it->first]) {
            _data::adjectCount++;
        }
        counter++;
    }
    _data::averageWordLength = sum / _data::words.size();
}

void Display(int level = HIGH) {
    using namespace _data;
    printf("Character Count: %d\n", characterCount);
    printf("Whitespace: %d\n", whitespaceCount);
    printf("Word Count: %d\n", wordCount);
    if(level > LOW) {
        printf("Uppercase Count: %d\n", uppercaseCount);
        printf("Lowercase Count: %d\n", lowercaseCount);
    }
    printf("Punctuation Count: %d\n", punctuationCount);
    if(level > LOW) {
        printf("Vowel Count: %d\n", vowelCount);
        printf("Constenant Count: %d\n", constenantCount);
    }
    printf("Mitsake Count: %d\n", mistakeCount);
    printf("Verb Count: %d\n", verbCount);
    printf("Noun Count: %d\n", nounCount);
    printf("Adjective Count: %d\n", adjectCount);
    for(auto word = words.begin(); word != words.end(); word++)
        std::cout << word->first << ' ';
    if(level > MID) {
        printf("\nWord usage:\n");
        for(auto word = words.begin(); word != words.end(); word++)
            std::cout << '\t' << word->first << " | " << word->second << '\n';
    }
    printf("\n%s\n", "Characters: ");
    for(auto it = characters.begin(); it != characters.end(); it++)
        std::cout << it->first << ", ";
    if(level > MID) {
        printf("\nCharacter usage:\n");
        for(auto it = characterUsage.begin(); it != characterUsage.end(); it++)
            std::cout << '\t' << it->first << " | " << it->second << '\n';
    }
    printf("\n%s\n", "Punctuation: ");
    for(auto it = punctuation.begin(); it != punctuation.end(); it++)
        std::cout << it->first << ' ';
    printf("\nLongest Word: %d | %s\n", secondElement(_data::longestWord), firstElement(_data::longestWord).c_str());
    printf("Average Word Length: %d\n", _data::averageWordLength);
}

int main() {
    Load();
    Analyse("This is a test! Sentence. Here is the rest");
    Display(); // Defaults to HIGH (Most information)

    return 0;
}