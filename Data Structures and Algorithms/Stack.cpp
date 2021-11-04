#include <iostream>
struct stack {
    int items[10]; // Can also use vectors
    int top = -1; // Dictates the size of the stack

    bool IsFull();
    bool IsEmpty();
    void Push(int item);
    int Pop();

    void Print() const;
};

bool stack::IsFull() {
    return (top == 10) ? true : false;
}

bool stack::IsEmpty() {
    return (top == -1) ? true : false;
}

void stack::Push(int item) {
    if(IsFull()) {
        std::cerr << "Stack is full, cannot push!" << std::endl;
        exit(1);
    }
    else {
        top++;
        items[top] = item;
    }
}

int stack::Pop() {
    if(IsEmpty()) {
        std::cerr << "Their is nothing to pop!" << std::endl;
        exit(1);
    }
    else {
        int item = items[top];
        items[top] = 0;
        top--;
        return item;
    }
    return -1;
}

void stack::Print() const {
    for(int i = 0; i <= top; i++)
        std::cout << items[i] << '|';
}

int main() {
    stack s;
    s.Push(3);
    s.Push(1);
    s.Push(5);
    s.Push(6);

    s.Print();

    s.Pop();

    putchar('\n');

    s.Print();


    return 0;
}