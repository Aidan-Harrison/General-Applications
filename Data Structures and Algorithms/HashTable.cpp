#include <iostream>
#include <vector>
#include <utility>

// Hash-table
struct hash {
    std::string key;
    int value;
    inline const std::string first() const { return key; }
    inline const int second() const { return value; }

    hash(const std::string &&_key, const int _val)
        :key(_key), value(_val)
    {
    }
};

std::vector<hash> map{};

bool Find(std::vector<hash> &map, const std::string &&_key) {
    // Linear search through map
    for(hash h : map)
        if(h.first() == _key)
            return true;
}  

void Delete(const std::string &&_key) {
    // Given a key, erase from map
    int counter = 0;
    for(hash h : map) {
        if(h.first() == _key)
            map.erase(map.begin() + counter);
        counter++;
    }
}

void Insert(const std::string &&_key, const int value) {
    hash newHash(_key, value);
    map.push_back(newHash);
}

int main() {
    hash fHash("first", 1);
    hash tHash("test", 5);
    hash oHash("other", 7);
    hash aHash("another", 2);
    hash lHash("last", 9);
    map.push_back(fHash);
    map.push_back(tHash);
    map.push_back(oHash);
    map.push_back(aHash);
    map.push_back(lHash);

    std::cout << Find(map, "test") << '\n';

    return 0;
}
