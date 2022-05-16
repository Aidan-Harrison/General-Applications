#include <iostream>
// Singly Linked-List:
struct sLinkedList {
    struct node {
        int data;
        node *next;
        node() :data(0), next(nullptr) {}
        node(const int val) :data(val), next(nullptr) {}
    };
    node * tail = nullptr;
    node * head = nullptr;
};

void push_front(sLinkedList & l, sLinkedList::node * node) {
    l.head->next = node;
    l.head = nullptr;
}

void push_back(sLinkedList & l, sLinkedList::node * node) {
    l.tail->next = node;
    l.tail = node;
}

sLinkedList::node * pop_front(sLinkedList & l) {
    sLinkedList::node * result = l.head;
    l.tail = nullptr;
    return result;
}

sLinkedList::node * pop_back(sLinkedList & l) {
    sLinkedList::node * result = l.tail;
    l.tail = nullptr;
    return result;
}

sLinkedList::node * AddNode(sLinkedList::node * curNode, const int val) {
    sLinkedList::node * newNode = new sLinkedList::node(val);
    newNode->next = curNode->next;
    curNode->next = newNode;
    return newNode;
}

void Delete(sLinkedList::node * n) { // Deletes next node
    n->next = n->next->next;
    // Possibly add 'delete'
}

void Delete(sLinkedList::node * n, const int val) {
    // Search for node with value
    // Delete
    sLinkedList::node * searchNode = n;
    while(searchNode != nullptr) {
        if(searchNode->data == val)
            searchNode->next = searchNode->next->next;
        else
            searchNode = searchNode->next;
    }
    delete searchNode;
}

void DeleteOther(node * head, const int n) { // Deletes nth node from start
    node *tempNode = head;
    int counter = 0;
    while(tempNode != nullptr) {
        if(counter == n)
            tempNode->next = tempNode->next->next;
        tempNode = tempNode->next;
        counter++;
    }
    delete tempNode;
}

void PrintList(node * n) {
    while(n != nullptr) {
        if(n->next != nullptr)
            std::cout << n->data << " -> ";
        else
            std::cout << n->data;
        n = n->next;
    }
}

// Doubly Linked-List:
struct dNode {
    int data;
    dNode *prev;
    dNode *next;
    dNode() :data(0), prev(nullptr), next(nullptr) {}
    dNode(int d) :data(d), prev(nullptr), next(nullptr) {}
};

dNode* Add(dNode *curNode, int val) {
    dNode * newNode = new dNode(val);
    newNode->prev = curNode;
    newNode->next = curNode->next;
    curNode->next = newNode;
    return newNode;
}

void Delete(dNode * n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;    
}

void PrintDList(dNode *n) {
    dNode *tempNode = n;
    while(tempNode != nullptr) {
        if(tempNode->prev == nullptr)
            std::cout << 'X';
        std::cout << " <- " << tempNode->data << " -> ";
        if(tempNode->next == nullptr)
            std::cout << 'X';
        tempNode = tempNode->next;
    }
    delete tempNode;
}

void ReverseList(node * head) {
    node * next = nullptr;
    node * prev = nullptr;
    while(head != nullptr) {
        next = head->next;
        head->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    // Singly Linked-List: ================================================= 
    node *head = nullptr;
    node *one = nullptr;
    node *two = nullptr;
    node *tail = nullptr;

    // Assign memory for pointers and set data using constructor
    head->data  = 7;
    one->data   = 2;
    two->data   = 3;
    tail->data  = 5;

    // Set pointers locations
    head->next = one;
    one->next = two;
    two->next = tail;

    PrintList(head);
    node *insertNode = Add(one, 7); // Adds a new node between one and two with the value 7
    putchar('\n');
    PrintList(head);
    Delete(one); // Sets one's next pointer to the next value of two, thus removing two from list 
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

    PrintDList(dHead);

    return 0;
}