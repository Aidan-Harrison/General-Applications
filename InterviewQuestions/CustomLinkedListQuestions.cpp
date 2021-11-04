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

    // Standard functions
    int GetSize();
    void AddNode(node *n); // Take into accout head node
    void Print(node *n) const;
    void Clear(node *n);

    void PrintMiddle(node *head);
    void PrintMiddle(node *head, int size);
    void PrintMiddleOther(node *head);

    void DeleteMiddle(node *head, int size);
    void DeleteMiddleOther(node *head);

    void Increment(node *n);
    node* NthFromEnd(node* head, int n, int total); // Node instead?

    void ReverseList(node *n);
    node* ReverseListBetter(node *n);

    void SortList(); // DO! | Merge Sort
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

void sList::Print(node *n) const {
    node *tempNode = n;
    while (tempNode != nullptr) {
        std::cout << tempNode->data << " -> ";
        tempNode = tempNode->next;
    }
    delete tempNode;
}

void sList::PrintMiddle(node *head) {
    int size = 0;
    node *traverseNode = head;
    while(traverseNode != nullptr) {
        traverseNode = traverseNode->next;
        size++;
    }
    traverseNode = head;
    for(unsigned int i = 0; i < size/2; i++) {
        traverseNode = traverseNode->next;
    }
    std::cout << traverseNode->data;
}

void sList::PrintMiddle(node *head, int size) { // Rounded up
    node *tempNode = head;
    for(unsigned int i = 0; i < size/2; i++)
        tempNode = tempNode->next;
    std::cout << tempNode->data;
    // delete tempNode;
}

void sList::PrintMiddleOther(node *head) {
    node *firstNode = head;
    node *secondNode = head;
    while(secondNode != nullptr) {
        secondNode = secondNode->next->next; // Increment second node by two
        firstNode = firstNode->next;
    }
    std::cout << firstNode->data << '\n';
}

// Re-Do this!
void sList::DeleteMiddle(node *head, int size) { // Wrong! Temporary node doesn't work | Formula is also wrong, change to use actual list, not temp iterator
    node *newNode = head;
    int mid = size/2;
    while(mid > 1) {
        head=head->next;
        mid--;
    }
    head->next = head->next->next;
}

void sList::DeleteMiddleOther(node *head) {
    node *fastNode = head;
    node *slowNode = head;
    while(fastNode != nullptr) {
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    } 
    head = slowNode;
    head->next = head->next->next;
}

void sList::Increment(node *n) {
    n->data++;
}

// Returns the nth element from the end of the list | Change?
node* sList::NthFromEnd(node *head, int n, int total) {
    for(int i = 0; i > total-n; i++) {
    }
    return nullptr;
}

void sList::Clear(node *n) {
    while(n != nullptr) {
        n->data = 0;
        n = n->next;
    }
}

void sList::ReverseList(node *n) {
    if(n->next == nullptr)
        return;
    node *root = n;
    std::vector<int> temp{};
    while(n != nullptr) {
        temp.push_back(n->data);
        n = n->next;
    }
    n = root;
    Clear(n);
    for(unsigned int i = 0; i < temp.size(); i++) {
        node *newNode = new node(i);
        n->next = newNode;
        n = n->next;
    }
}

node* sList::ReverseListBetter(node *n) {
    node *cur = n;
    node *follow = n;
    node *prev = nullptr;
    while(cur != nullptr) {
        follow = follow->next;
        cur->next = prev;
        prev = cur;
        cur = follow;
    }
    // Prev = head
    return prev;
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

struct dNode {
    int data;
    dNode *prev;
    dNode *next;
    dNode() :data(0), prev(nullptr), next(nullptr) {}
    dNode(int d) :data(d), prev(nullptr), next(nullptr) {}
};

// Doubly Linked-List
class dList {
private:
public:
    dList() {}

    void Print(dNode *n) const;

    void PrintMiddle(dNode *head, int size); // No point in including?
    void DeleteMiddle(dNode *head, int size);
    void IncrementElement(dNode *head, const int element);
    dNode* NthFromEnd(dNode *tail, int n, int total);
    void RemoveDuplicates(dNode *n);
    void ReverseList(dNode *tail);

    ~dList() {}
};

void dList::Print(dNode *n) const {
    while(n != nullptr) {
        if(n->prev == nullptr)
            std::cout << "x";
        std::cout << " <- " << n->data << " -> ";
        if(n->next == nullptr)
            std::cout << "x";
        n = n->next;
    }
}

void dList::PrintMiddle(dNode *head, int size) {
    dNode *tempNode = new dNode;
    tempNode = head;
    for(int i = 0; i <= size/2; i++) {
        tempNode = tempNode->next;
    }
    std::cout << tempNode->data;
    delete tempNode;
}

void dList::DeleteMiddle(dNode *head, int size) {
    dNode *tempNode = head;
    int mid = size / 2;
    while(mid > 1) { // Cleaner then a for loop
        head = head->next;
        mid--;
    }
    head->next = head->next->next;
}

// Given the head node and the element of another node, increment the node which holds the matching element
void dList::IncrementElement(dNode *head, const int element) {
    dNode *tempNode = head;
    while(tempNode != nullptr) {
        if(tempNode->next->data == element) {
            tempNode->next->data += 1;
            tempNode = nullptr;
        }
        else
            tempNode = tempNode->next;
    }
    delete tempNode;
}

dNode* dList::NthFromEnd(dNode *tail, int n, int total) {
    dNode *tempNode = new dNode;
    tempNode = tail;
    for(int i = total; i > n; i--) {
        tempNode = tempNode->prev;
    }
    // Handle deletion!? Scope deletes??
    return tempNode;
}

void dList::RemoveDuplicates(dNode *n) { // Check!, fairly certain it is correct
    while(n != nullptr) {
        if(n->data == n->next->data)
            n->next = n->next->next;
        n = n->next;
    }
}

void dList::ReverseList(dNode *tail) {
    while(tail != nullptr) {
        tail->next = tail->prev;
        tail = tail->prev;
    }
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

std::vector<int> GetDuplicates(node *head) {
    std::vector<int> duplicates{};
    node* traverseNode = head;
    while(traverseNode != nullptr) {
        int cur = traverseNode->data;
        if(traverseNode->next->data == cur)
            duplicates.push_back(cur);
        traverseNode = traverseNode->next;
    }
    
}

// List cannot be sorted
void DeleteDuplicates(node *head) {
    // Find all duplicates in list
    // shift next pointers until only pointing to single element
    //  - or shift so all elements are removed (easier)

}

int main() {
    // Singly-Linked List
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

    l.Print(head);
    putchar('\n');
    std::cout << "Print Middle:\n";
    l.PrintMiddle(head);
    std::cout << "\nPrint Middle 2:\n";
    l.PrintMiddle(head, 5);
    std::cout << "\nPrint Middle (other):\n";
    // l.PrintMiddleOther(head); // Fix!
    std::cout << "\nDelete Middle:\n";
    l.DeleteMiddle(head, 5);
    std::cout << "\nReverse:\n";
    //l.ReverseList(head);
    l.Print(head);
    std::cout << "\nReverse Better:\n";
    head = l.ReverseListBetter(head);
    l.Print(head);

    // SumofListsIndependent(l, l2);

    std::cout << "\nFind Duplicates:\n";

    std::cout << "\nRemove Duplicates:\n";


    // Doubly-Linked List
    std::cout << "\nDouble:\n";
    dList dL;
    dNode *dHead = new dNode(5);
    dNode *dN1 = new dNode(16);
    dNode *dN2 = new dNode(7);
    dNode *dN3 = new dNode(34);
    dNode *dTail = new dNode(9);

    dHead->next = dN1;

    dN1->prev = dHead;
    dN1->next = dN2;

    dN2->prev = dN1;
    dN2->next = dN3;

    dN3->prev = dN2;
    dN3->next = dTail;

    dTail->prev = dN3;

    dL.Print(dHead);
    dL.IncrementElement(dHead, 34);
    putchar('\n');
    dL.Print(dHead);
    dL.DeleteMiddle(dHead, 5);
    putchar('\n');
    dL.Print(dHead);

    return 0;
}