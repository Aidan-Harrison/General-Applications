#include <iostream>

int size = 0;

struct stack {
    int items[10];
    int top = -1; // Change to head?
};

void CreateEmptyStack(stack* s) {
    s->top = -1;
}

bool IsFull(stack *s) {
    if(s->top == 10 - 1)
        return true;
    else
        return false;
}

bool IsEmpty(stack *s) {
    if(s->top == -1)
        return true;
    else
        return false;
}

void Push(stack *s, int item) {
    if(IsFull(s)) {
        std::cerr << "Stack is full, cannot push!\n";
        exit(1);
    }
    else {
        s->top++;
        s->items[s->top] = item;
    }
    size++;
}

void Pop(stack *s) {
    if(IsEmpty(s)) {
        std::cerr << "Their is nothing to pop!\n";
        exit(1);
    }
    else {
        s->items[s->top] = 0;
        s->top--;
    }
    size--;
}

void PrintStack(stack *s) {
    for(int i = 0; i < size; i++)
        std::cout << s->items[i] << ", ";
}

int main() {
    stack s;
    Push(s, 3);
    Push(s, 1);
    Push(s, 5);
    Push(s, 6);
    PrintStack(s);

    return 0;
}