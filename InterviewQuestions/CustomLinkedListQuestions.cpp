#include <iostream>
#include <vector>

struct sList {
    struct node {
        int data;
        node *next;
        node() :data(0), next(nullptr) {}
        node(int d) :data(d), next(nullptr) {}
    };
    std::vector<node> items{};
    sList(std::vector<node> &nodes)
        :items(nodes) // Check! 
    {
    }
    ~sList() {}
    void PrintMiddle();
};

void sList::PrintMiddle() {
    std::cout << items[items.size() / 2].data;
}

// Doubly Linked-List
class dList {
private:
public:
    struct node {
        int data;
        node *prev;
        node *next;
        node() :data(0), prev(nullptr), next(nullptr) {}
        node(int d) :data(d), prev(nullptr), next(nullptr) {}
    };
    std::vector<node> items{}; // Remove!!!!!!
    dList(std::vector<node> &nodes)
        :items(nodes) // Check! 
    {
    }
    ~dList() {}
    void DeleteMiddle();
    void IncrementElement(int element);
};

void dList::DeleteMiddle() { // Re-do after vector removal
    int mid = items.size()/2;
    items[mid].prev = items[mid].next;
}

void dList::IncrementElement(int element) {
    items[element].data++;
}

int main() {


    return 0;
}