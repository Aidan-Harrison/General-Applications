#ifndef german_h
#define german_h

#include <vector>

struct German {
    std::vector<std::string> words = {};
    German() = default;
    ~German() = default;
    void PrintWords() const {
        for(unsigned int i = 0; i < words.size(); i++)
            std::cout << i << " ) " << words[i] << '\n';
    }
};

#endif german_h