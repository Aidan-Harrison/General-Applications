#include <iostream>
#include <vector>
#include <string>

struct node {
    int data;
    node *next;
    node() :data(0), next(nullptr) {}
    node(int d) :data(d), next(nullptr) {}
};

struct sList {
    sList() {}
    ~sList() {}

    node *head;

    // Useful functions
    int GetSize();
    void AddNode(node *n); // Take into accout head node

    void PrintMiddle(node *head, int size);
    void DeleteMiddle(node *head, int size);
    void Increment(node *n);
    node* NthFromEnd(node* head, int n, int total); // Node instead?
    void ReverseList(node *head);
    void SortList(); // DO!
    void RotateList();
    int SumOfLinkedList(node *n1, node *n2);
};

void sList::AddNode(node *n) { // Come back to this! Not correct so far
    node *temp = new node;
    temp = head;
    while(temp != nullptr) {
        temp = temp->next;
    }
}

int sList::GetSize() {
    int size = 0;
    node *temp = new node; // If specifying node to check from, direct initialise
    temp = head;
    while(temp != nullptr) { // Check order!
        size++;
        temp = temp->next;
    }
    delete temp;
    return size;
}

void sList::PrintMiddle(node *head, int size) { // Rounded up
    node *tempNode = head;
    for(unsigned int i = 0; i < size/2; i++)
        tempNode = tempNode->next;
    std::cout << tempNode->data;
    delete tempNode;
}

void sList::DeleteMiddle(node *head, int size) { // Wrong! Temporary node doesn't work | Formula is correct, change to use actual list, not temp iterator
    node *tempNode = head;
    for(unsigned int i = 0; i < size/2-2; i++) // Go back one before mid
        tempNode = tempNode->next;
    tempNode->next = tempNode->next->next; // Check!

    delete tempNode;
}

void sList::Increment(node *n) {
    n->data++;
}

// Returns the nth element from the end of the list
node* sList::NthFromEnd(node *head, int n, int total) {
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

void sList::RotateList() {
    // Refer to array/string rotation
}

// Given two numbers represented by linked lists, add them together and return their sum
int sList::SumOfLinkedList(node *n1, node *n2) {
    std::string firstNum = "";
    std::string secondNum = "";
    while(n1 != nullptr) {
        firstNum.append(std::to_string(n1->data));
        n1 = n1->next;
    }
    while(n2 != nullptr) {
        secondNum.append(std::to_string(n2->data));
        n2 = n2->next;
    }
    return std::stoi(firstNum) + std::stoi(secondNum);
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

// Assuming two lists are of the same size, get the sum of their data
int SumofLists(sList &n, sList &n2) {
    int sum = 0;
    while(n.head != nullptr) {
        sum += n.head->data + n2.head->data;
        n.head = n.head->next;
        n2.head = n2.head->next;
    }
    return sum;
}

// Lists do NOT have to be the same size
int SumofListsIndependent(sList &n1, sList &n2) {
    int sum = 0;
    if(n1.GetSize() > n2.GetSize()) {
        for(int i = 0; i < n2.GetSize(); i++) {
            sum += n1.head->data + n2.head->data;
            n1.head = n1.head->next;
        }
        while(n1.head != nullptr) { // Get remaining
            sum += n1.head->data;
            n1.head->data;
        }
    }
    else {
        for(int i = 0; i < n1.GetSize(); i++) {
            sum += n2.head->data + n1.head->data;
            n2.head = n2.head->next;
        }
        while(n2.head != nullptr) {
            sum += n2.head->data;
            n2.head->data;
        }
    }
    return sum;
}   

int main() {
    sList l;
    sList l2;
    node *head = new node(5);
    node *n1 = new node(16);
    node *n2 = new node(7);
    node *n3 = new node(34);
    node *tail = new node(9);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = tail;

    l.PrintMiddle(head, 5);


    SumofListsIndependent(l, l2);

    return 0;
}