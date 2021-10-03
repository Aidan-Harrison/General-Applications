#include <iostream>
#include <map>
#include <vector>

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

// Node based
struct trieNode {
    bool terminal = false; // Is end of word
    std::vector<trieNode*> children;
    trieNode() {}
    ~trieNode() {}
};

trieNode* CreateNode() {
    trieNode *newNode = new trieNode;       
    return newNode;
}

bool Insert(trieNode **root, std::string &text) { // Check double pointer
    if(*root == nullptr) // Change root pointer
        *root = CreateNode();
    trieNode *traverseNode = *root;
    for(unsigned int i = 0; i < text.length(); i++) {
        if(traverseNode->children[text[i]] == nullptr) // If it doesn't exist, add it
            traverseNode->children[text[i]] = CreateNode();
        traverseNode = traverseNode->children[text[i]]; // Else keep going
    }
    if(traverseNode->terminal)
        return false;
    else  {
        traverseNode->terminal = true;
        return true;
    }
}

void PrintTrieRec(trieNode *node, std::string &prefix, int length) {
    std::string newPrefix;
    newPrefix.resize(prefix.length());
    if(node->terminal)
        std::cout << "WORD: " << prefix;
}

void PrintTrie(trieNode *root) {
    // Print all children correctly

}

int main() {
    aTrie t;
    t.Insert("cat");

    // Node based
    trieNode newNode;

    return 0;
}