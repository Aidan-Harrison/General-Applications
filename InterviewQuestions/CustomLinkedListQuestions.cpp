#include <iostream>
#include <vector>

struct sList {
    struct node {
        int data;
        node *next;
        node() :data(0), next(nullptr) {}
        node(int d) :data(d), next(nullptr) {}
    };
    sList() {}
    ~sList() {}

    void AddNode(int data);

    void PrintMiddle(node *head, int size);
    void DeleteMiddle(node *head, int size);
    void Increment(node *n);
    node* NthFromEnd(node* head, int n, int total); // Node instead?
    void ReverseList(node *head);
};

void sList::PrintMiddle(node *head, int size) { // Rounded up
    node *tempNode = new node;
    tempNode = head;
    for(int i = 0; i < size/2; i++)
        tempNode = tempNode->next;
    std::cout << tempNode->data;
    delete tempNode;
}

void sList::DeleteMiddle(node *head, int size) {
    node *tempNode = new node;
    tempNode = head;
    for(int i = 0; i < size/2-2; i++) { // Go back one before mid
        tempNode = tempNode->next;
    }
    tempNode->next = tempNode->next->next; // Check!

    delete tempNode;
}

void sList::Increment(node *n) {
    n->data++;
}

// Returns the nth element from the end of the list
sList::node* sList::NthFromEnd(node *head, int n, int total) {
    for(int i = 0; i > total-n; i++) {

    }
}

void sList::ReverseList(node *head) {
    node* current = head;
    node* prev = nullptr, *next = nullptr;
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev; // We need to set the head to the end now that the list is reversed
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

    dList() {}
    ~dList() {}

    void PrintMiddle(node *head, int size); // No point in including?
    void DeleteMiddle(node *head, int size);
    void IncrementElement(int element);
    node* NthFromEnd(node *tail, int n, int total);
    void RemoveDuplicates(node *n);
    void ReverseList(node *head);
};

void dList::PrintMiddle(node *head, int size) {
    node *tempNode = new node;
    tempNode = head;
    for(int i = 0; i <= size/2; i++) {
        tempNode = tempNode->next;
    }
    std::cout << tempNode->data;
    delete tempNode;
}

void dList::IncrementElement(int element) {

}

dList::node* dList::NthFromEnd(node *tail, int n, int total) {
    node *tempNode = new node;
    tempNode = tail;
    for(int i = total; i > n; i--) {
        tempNode = tempNode->prev;
    }
    // Handle deletion!
    return tempNode;
}

void dList::RemoveDuplicates(node *n) { // Check!, fairly certain it is correct
    while(n != nullptr) {
        if(n->data == n->next->data)
            n->next = n->next->next;
        n = n->next;
    }
}

void dList::ReverseList(node *head) {
    node* current = head;
    node* prev = nullptr, *next = nullptr;
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev; // We need to set the head to the end now that the list is reversed
}

int main() {
    sList l;
    sList::node *head = new sList::node(5);
    sList::node *n1 = new sList::node(16);
    sList::node *n2 = new sList::node(7);
    sList::node *n3 = new sList::node(34);
    sList::node *tail = new sList::node(9);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = tail;

    l.PrintMiddle(head, 5);

    return 0;
}