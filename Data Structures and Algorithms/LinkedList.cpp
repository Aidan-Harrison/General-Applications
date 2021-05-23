#include <iostream>
// Singly Linked-List:
struct node {
    int data;
    node *next;
    node(int val) :data(val), next(nullptr) {}
};

node* Add(node *prevNode, int val, node *nextNode) {
    node *newNode;
    newNode = new node(val);
    prevNode->next = newNode;
    newNode->next = nextNode;
    return newNode;
}

void Delete(node *prevNode, node *delNode) { // Due to being singly linked, must provide prev and current node
    prevNode->next = delNode->next;
    // Possibly add 'delete'
}

void PrintList(node *n) {
    while(n != nullptr) {
        std::cout << n->data << ' ';
        n = n->next;
    }
}

// Doubly Linked-List:
struct dNode {
    int data;
    dNode *prev;
    dNode *next;
    dNode(int d) :data(d), prev(nullptr), next(nullptr) {}
};

dNode* Add(dNode *prevNode, int val, dNode *nextNode) {
    dNode *newNode;
    newNode = new dNode(val);
    prevNode->next = newNode;
    nextNode->prev = newNode;
    return newNode;
}

void Delete(dNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;    
}

int main() {
    // Singly Linked-List: ================================================= 
    node *head = nullptr;
    node *one = nullptr;
    node *two = nullptr;
    node *tail = nullptr;

    // Assign memory for pointers and set data using constructor
    head = new node(1);
    one = new node(2);
    two = new node(3);
    tail = new node(5);

    // Set pointers locations
    head->next = one;
    one->next = two;
    two->next = tail;
    tail->next = nullptr;

    PrintList(head);
    node *insertNode = Add(one, 7, two); // Adds a new node between one and two with the value 7
    putchar('\n');
    PrintList(head);
    Delete(one, two); // Sets one's next pointer to the next value of two, thus removing two from list 
    putchar('\n');
    PrintList(head);

    // Doubly Linked-List: ================================================= 
    dNode *dHead = nullptr;
    dNode *dOne = nullptr;
    dNode *dTwo = nullptr;
    dNode *dTail = nullptr;

    dHead = new dNode(19); // Constructor defaults prev and next to 'nullptr'
    dOne = new dNode(5);
    dTwo = new dNode(8);
    dTail = new dNode(24);

    dOne->prev = dHead;
    dTwo->prev = dOne;
    dTail->prev = dTwo;
        
    dHead->next = dOne;
    dOne->next = dTwo;
    dTwo->next = dTail;
   
    return 0;
}