#include <iostream>
struct stack {
    int items[10];
    int top = -1; // Dictates the size of the stack
};

void CreateEmptyStack(stack* s) {
    s->top = -1;
}

bool IsFull(stack *s) {
    if(s->top == 10)
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
        std::cerr << "Stack is full, cannot push!" << std::endl;
        exit(1);
    }
    else {
        s->top++;
        s->items[s->top] = item;
    }
}

void Pop(stack *s) {
    if(IsEmpty(s)) {
        std::cerr << "Their is nothing to pop!" << std::endl;
        exit(1);
    }
    else {
        s->items[s->top] = 0;
        s->top--;
    }
}

void PrintStack(stack *s) {
    for(int i = 0; i < s->top; i++)
        std::cout << s->items[i] << ", ";
}

int main() {
    stack s;
    Push(&s, 3);
    Push(&s, 1);
    Push(&s, 5);
    Push(&s, 6);
    PrintStack(&s);
    Pop(&s);
    putchar('\n');
    PrintStack(&s);

    return 0;
}