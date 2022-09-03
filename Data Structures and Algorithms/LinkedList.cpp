#include <iostream>

// Singly-Linked List
struct node {
    int data;
    node * next;
    node() :data(0), next(nullptr) {}
    node(const int val) :data(val), next(nullptr) {}
};

void AddNode(node * cur, const int val) {
    node * newNode;
    newNode->data = val;
    newNode->next = cur->next;
    cur->next = newNode;
}

void Delete(node * head, const int val) {
    // Search for node with value
    // Delete
    node * searchNode = head;
    while(searchNode != nullptr) {
        if(searchNode->data == val)
            searchNode->next = searchNode->next->next;
        else
            searchNode = searchNode->next;
    }
}

void DeleteNth(node * head, const int n) { // Deletes nth node from start
    node * tempNode = head;
    int counter = 0;
    while(tempNode != nullptr) {
        if(counter == n)
            tempNode->next = tempNode->next->next;
        tempNode = tempNode->next;
        counter++;
    }
}

// Doubly Linked-List:
struct dNode {
    int data;
    dNode * prev;
    dNode * next;
    dNode() :data(0), prev(nullptr), next(nullptr) {}
    dNode(int d) :data(d), prev(nullptr), next(nullptr) {}
};

void Add(dNode * cur, int val) {
    dNode * newNode = new dNode(val);
    newNode->prev = cur;
    newNode->next = cur->next;
    cur->next = newNode;
}

void Delete(dNode * n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;    
}

void ReverseList(node * head) {
    node * next = nullptr;
    node * prev = nullptr;
    node * current = nullptr;
    while(head != nullptr) {
        next = head->next;
        head->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Print functions
void PrintList(node * n) {
    while(n != nullptr) {
        if(n->next != nullptr)
            std::cout << n->data << " -> ";
        else
            std::cout << n->data;
        n = n->next;
    }
}

void PrintList(dNode *n) {
    dNode * tempNode = n;
    while(tempNode != nullptr) {
        if(tempNode->prev == nullptr)
            std::cout << 'X';
        std::cout << " <- " << tempNode->data << " -> ";
        if(tempNode->next == nullptr)
            std::cout << 'X';
        tempNode = tempNode->next;
    }
}
int main() {
    // Singly Linked-List: ================================================= 
    node * head = nullptr;
    node * one  = nullptr;
    node * two  = nullptr;
    node * tail = nullptr;

    // Assign memory for pointers and set data using constructor
    head->data  = 7;
    one->data   = 2;
    two->data   = 3;
    tail->data  = 5;

    // Set pointers locations
    head->next = one;
    one->next  = two;
    two->next  = tail;

    PrintList(head);
    putchar('\n');
    PrintList(head);
    putchar('\n');
    PrintList(head);

    // Doubly Linked-List: ================================================= 
    dNode * dHead = nullptr;
    dNode * dOne  = nullptr;
    dNode * dTwo  = nullptr;
    dNode * dTail = nullptr;

    dHead->data = 19;
    dOne->data  = 5;
    dTwo->data  = 8;
    dTail->data = 24;

    dOne->prev  = dHead;
    dTwo->prev  = dOne;
    dTail->prev = dTwo;
        
    dHead->next = dOne;
    dOne->next  = dTwo;
    dTwo->next  = dTail;

    PrintList(dHead);
    Add(dOne, 7); // Adds a new node between one and two with the value 7
    Delete(dTwo);
    PrintList(dHead);

    return 0;
}

// Re-write
class LinkedList {
private:
    int size{};
public:
    struct node {
        int data;
        node * next;
        node * prev;
    };
    node * head = nullptr;
    node * tail = nullptr;

    int size() const {return size;}

    void insert(node * n, node * cur) {
        cur->next = n->next;
        n->next = cur;
        cur->prev = n;
    }

    void insert(const int pos, const int val) {
        int counter{};
        node * tNode = head;
        while(tNode != nullptr) {
            if(counter == pos) {   
                node * newNode;
                newNode->next = head->next;
                newNode->prev = head;
                head->next = newNode;
            }
            counter++;
        }
    }

    void push(node * n) {
        size++;
        if(head == nullptr) {
            head = n;
            return;
        }
        if(tail == nullptr) {
            tail = n;
            head->next = tail;
            return;
        }
        tail = n;
    }

    node * pop() { // Check prev next pointer
        node * retNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        return retNode;
    }

    void print() const {
        node * tNode = head;
        while(tNode != nullptr) {
            if(tNode->next != nullptr)
                std::cout << tNode->data << "->";
            tNode = tNode->next;
        }
    }

    LinkedList() {}
};