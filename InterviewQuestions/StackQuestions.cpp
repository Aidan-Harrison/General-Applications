#include <iostream>
#include <algorithm>
#include <vector>

// Convert to templated struct, figure out pass by reference!
struct stack {
    int items[10];
    std::string TempItems[10];
    int top = 0;

    int MAXSIZE = 10; // Use when needed, intergrate into existing functions | ADD TO ARRAY

    stack() {}
    ~stack() {}

    bool IsFull() {
        if(top == MAXSIZE)
            return true;
        return false;
    }

    bool IsEmpty() {
        if(top == -1) // Check!
            return true;
        return false;
    }

    void Push(int data) {
        if(IsFull())
            std::cerr << "Stack is full!\n";
        else {
            items[top++] = data;
        }
    }

    void TempPush(char data) {
        if(IsFull())
            std::cerr << "Stack is full!\n";
        else {
            TempItems[top++] = data;
        }
    }

    std::string TempPop() {
        if(IsEmpty())
            std::cerr << "Stack is empty!\n";
        else {
            std::string item = TempItems[top];
            TempItems[top] = -1; // NULL instead?
            top--;
            return item;
        }
        return " ";
    }

    int Pop() {
        if(IsEmpty())
            std::cerr << "Stack is empty!\n";
        else {
            int item = items[top];
            items[top] = -1; // NULL instead?
            top--;
            return item;
        }
        return -1;
    }

    int Peek() {
        return items[top];
    }

    int GetSize() {
        return top;
    }

    void Print() const {
        for(int i = 0; i < top; i++) // Check!
            std::cout << items[i] << ", ";
    }
};

// Problems
void SortStack(stack &s) {
    int size = s.GetSize();
    std::vector<int> container{};
    for (int i = 0; i <= size; i++)
        container.push_back(s.Pop());

    std::sort(container.begin(), container.end());
    
    for(int i = 0; i < container.size(); i++)
        s.Push(container[i]);
}

void ReverseArrayUsingStack(std::vector<int> &arr, stack &s) { 
    s.MAXSIZE = arr.size();
    for(auto i : arr)
       s.Push(i);
    arr.clear(); // Check!
    for(int i = 0; i < s.MAXSIZE; i++)
        arr.push_back(s.Pop());
}

// Given two stacks, create a Queue | Check entire section! Seems correct
struct QueueStack {
    stack *s1; // s1 top handles front
    stack *s2; // s2 top handles rear

    const int MAXSIZE = 10;

    bool IsFull() {
        if(s2->GetSize() == MAXSIZE)
            return true;
        return false;
    }

    bool IsEmpty() {
        if(s1->IsEmpty())
            return true;
        return false;
    }

    void Enqueue(int data) {
        if(IsFull())
            std::cerr << "Queue is full!\n";
        else {
            s2->Push(data);
        }
    }

    int Dequeue() {
        if(IsEmpty())
            std::cerr << "Queue is empty!\n";
        else {
            if(IsFull()) {
                s1->top++; // Increment front
            }
        }
        if(s1->GetSize() == MAXSIZE) // Check for reset
            s1->top = 0;
        return s2->Pop(); // Return dequeued value
    }
};

std::string ReverseString(std::string &str, stack &s) {
    for(auto i : str) 
        s.TempPush(i);
    str.clear();
    for(int i = 0; i < s.GetSize(); i++)
        str.append(s.TempPop());
    return str;
}

void SortStackUsingOtherStack(stack &s1, stack &s2) { // Fix!
    for(int i = 0; i < s1.GetSize(); i++) {
        s2.Push(s1.Pop());
        if(s1.Peek() > s2.Peek())
            s1.Push(s2.Pop());
    } 
    for(int i = 0; i < s2.GetSize(); i++) // Push remaining
        s1.Push(s2.Pop());
}

// Reverse a stack without using another data structure
void ReverseStackContained(stack &s) {
    int temp = s.Pop();
    std::cout << temp;
}

// Sort a stack via recursion | Barely recursive, doesn't use recursion well, just so happens to use it
void SortRecursion(stack &s, std::vector<int> &container, int index = 0) { // Check!
    int amount = index;
    if(index == 0) // Done sorting
        return;
    else {
        container.push_back(s.Pop());
        if(s.Peek() > container[amount]);
            s.Push(container[index]);
        SortRecursion(s, container, amount++);
    }
}

// Returns a new stack which contains the sum of two stacks
stack* AddStacks(stack &s1, stack &s2) {
    stack *newStack = new stack;
    if(s1.GetSize() != s2.GetSize() || s1.IsEmpty() || s2.IsEmpty())
        return newStack;
    else {
        for(int i = 0; i < s1.GetSize(); i++) {
            int sum = s1.Pop() + s2.Pop();
            newStack->Push(sum);
        }   
    }
    return newStack;
}

// Allows a stack to be cycled | CONTINUE, top always set to 0, change!?
void CycleStack(stack &s1, int data) {
    if(s1.IsFull()) { // Cycle instead
        s1.top = 0; // We cycle top but don't pop anything, simply overwrite
        s1.items[s1.top] = data;
    }
}

// Two stacks in array | Do!
struct TwoStackArr {
    std::vector<int> arr{};
    int s1Top = 0;
    int s2Top = 0; // Increases n + i

    TwoStackArr() {}
    ~TwoStackArr() {}
};

int main() {
    stack s1;
    stack s2;
    s1.Push(6);
    s1.Push(12);
    s1.Push(4);
    s1.Push(90);
    s1.Push(1);

    s1.Print(); // Not printing last?

    SortStack(s1);

    putchar('\n');

    s1.Print();

    return 0;
}