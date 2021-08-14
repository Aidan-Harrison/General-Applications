#include <iostream>
#include <map>

// Lowercase only

class aTrie {
private:
    struct arrayNode {
        char c;
        arrayNode* children[26];
        bool isWord;
        arrayNode(const char ch) :c(ch), isWord(false) {}

        ~arrayNode() {}
    };
public:
    arrayNode* root;
    aTrie() 
    {
        root = new arrayNode('0');
    }

    arrayNode* GetNode(const std::string &word) { // Returns last node in word
        arrayNode* tempNode = root;
        for(unsigned int i = 0; i < word.length(); i++) {
            char c = word[i];
            if(tempNode->children[c - 'a'] == nullptr)
                return nullptr;
            tempNode = tempNode->children[c - 'a'];
        }
        return tempNode;
    }

    void Insert(const std::string &word) {
        arrayNode* tempNode = root;
        for(unsigned int i = 0; i < word.length(); i++) {
            char c = word[i];
            if(tempNode->children[c - 'a'] == nullptr)
                tempNode->children[c - 'a'] = new arrayNode(c);
            tempNode = tempNode->children[c - 'a'];
        }
        tempNode->isWord = true;
    }

    bool Search(const std::string &word) {
        arrayNode* tempNode = GetNode(word);
        return tempNode != nullptr && tempNode->isWord; // Check!
    }

    bool StartsWith(const std::string &prefix) {
        return GetNode(prefix) != nullptr;
    }

    void Print() { // DEPTH FIRST!!
        // Depth first search, go down each branch and print result
        arrayNode* tempNode = root;
        for(unsigned int i = 0; i < 26; i++) {
            if(tempNode->children[i] != nullptr) {
                tempNode = tempNode->children[i];
                std::cout << tempNode->c;
            }
        }
    }

    ~aTrie() {}
};

int main() {
    aTrie t;
    t.Insert("cat");

    return 0;
}