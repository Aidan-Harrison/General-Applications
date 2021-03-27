#ifndef french_h
#define french_h

#include <vector>
#include <map>

struct French {
    std::vector<std::string> words = {"Bonjour", "salut", "merci"};
    std::map<int, std::string> wordsMap = {};
    French() { // Still try to incorporate map
    ~French() = default;
        for(unsigned int i = 0; i < words.size(); i++)
            return; // Add to map using insert function
    }
    void PrintWords() const {
        for(unsigned int i = 0; i < words.size(); i++) 
            std::cout << i << " ) " << words[i] << '\n';
    }
};

#endif