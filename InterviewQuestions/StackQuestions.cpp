#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// Convert to templated struct, figure out pass by reference!
template<typename T>
struct stack {
    T items[10];
    int top = 0;

    int MAXSIZE = 10;

    stack() {}
    stack(stack<int> *newStack) 
    {
        while(GetSize() != newStack->GetSize())
            Push(newStack->Pop());
    }

    bool IsFull() {
        if(top == MAXSIZE)
            return true;
        return false;
    }

    bool IsEmpty() {
        if(top == 0) // Check!
            return true;
        return false;
    }

    void Push(T data) {
        if(IsFull())
            std::cerr << "Stack is full!\n";
        else {
            top++;
            items[top] = data;
        }
    }

    T Pop() {
        if(IsEmpty())
            std::cerr << "Stack is empty!\n";
        else {
            T item = items[top];
            items[top] = -1; // NULL instead?
            top--;
            return item;
        }
        return -1;
    }

    int Peek() { return items[top];}
    int GetSize() { return top;}

    void Print() const {
        for(unsigned int i = 1; i <= top; i++)
            std::cout << items[i] << ", ";
    }
    
    ~stack() {}
};

// Problems
void SortStack(stack<int> &s) {
    int size = s.GetSize();
    std::vector<int> container{};
    for(unsigned int i = 0; i < size; i++)
        container.push_back(s.Pop());

    std::sort(container.begin(), container.end());

    for(unsigned int i = 0; i < container.size(); i++)
        s.Push(container[i]);
}

void SortStack2(stack<int> &s) { // Approach 2 | Avoid using std::sort or another container, compare instead
    int current = 0;
}

void ReverseArrayUsingStack(std::vector<int> &arr, stack<int> &s) { 
    s.MAXSIZE = arr.size();
    for(auto i : arr)
       s.Push(i);
    arr.clear();
    for(int i = 0; i < s.MAXSIZE; i++)
        arr.push_back(s.Pop());
}

// Given two stacks, create a Queue | Check entire section! Seems just like a stack made of two stacks instead of a Queue
template<typename T>
struct QueueStack {
    QueueStack() {}
    stack<int> *s1 = new stack<int>; // s1 top handles front | Check!
    stack<int> *s2 = new stack<int>; // s2 top handles rear

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
    ~QueueStack() {}
};

std::string ReverseString(std::string &str, stack<char> &s) {
    for(auto i : str) 
        s.Push(i);
    str.clear();
    for(int i = 0; i < s.GetSize(); i++)
        str.append(std::to_string(s.Pop())); // to lower may be cheaper??
    return str;
}

void SortStackUsingOtherStack(stack<int> &s1, stack<int> &s2) { // Fix!
    for(int i = 0; i < s1.GetSize(); i++) {
        s2.Push(s1.Pop());
        if(s1.Peek() > s2.Peek())
            s1.Push(s2.Pop());
    } 
    for(int i = 0; i < s2.GetSize(); i++) // Push remaining
        s1.Push(s2.Pop());
}

// Reverse a stack without using another data structure
void ReverseStackContained(stack<int> &s) {
    int left = 0;
    int right = s.GetSize();
    while(left < right) {
        int temp = s.Pop();
        s.Push(temp);
        left++;
        right--;
    }
}

// Sort a stack via recursion | Barely recursive, doesn't use recursion well, just so happens to use it | RE-DO
void SortRecursion(stack<int> &s, std::vector<int> &container, int index = 0) {
    if(s.GetSize() == 0)
        return;
    if(index == s.GetSize()) {// Done sorting
        for(unsigned int i = 0; i < container.size(); i++)
            s.Push(container[i]);
    }
    else {
        container.push_back(s.Pop());
        SortRecursion(s, container, index++);
    }
}

// Returns a new stack which contains the sum of two stacks (Matching Sizes)
stack<int>* AddStacks(stack<int> &s1, stack<int> &s2) {
    stack<int> *newStack = new stack<int>;
    if(s1.GetSize() != s2.GetSize() || s1.IsEmpty() || s2.IsEmpty())
        return newStack;
    else {
        while(!s1.IsEmpty()) 
            newStack->Push(s1.Pop() + s2.Pop());
    }
    newStack->Print();
    return newStack;
}

// Returns a new stack which contains the sum of two stacks (Size doesn't have to match, remaining elements will be pushed onto the end)
stack<int>* AddStacksIndependent(stack<int> &s1, stack<int> &s2) {
    stack<int> *newStack = new stack<int>;
    if(s1.GetSize() > s2.GetSize()) {
        int size = s2.GetSize();
        for(unsigned int i = 0; i < size; i++)
            newStack->Push(s1.Pop() + s2.Pop());
        while(!s1.IsEmpty())
            newStack->Push(s1.Pop());
    }
    else {
        int size = s1.GetSize();
        for(unsigned int i = 0; i < size; i++)
            newStack->Push(s1.Pop() + s2.Pop());
        while(!s2.IsEmpty())
            newStack->Push(s2.Pop());
    }
    newStack->Print();
    return newStack;
}

// Add two stacks total value and return
int AddStacksGlobal(stack<int> &s1, stack<int> &s2) {
    if(s1.GetSize() != s2.GetSize() || s1.IsEmpty() || s2.IsEmpty())
        return 0;
    else {
        int sum = 0;
        while (!s1.IsEmpty() && !s2.IsEmpty())
            sum += s1.Pop() + s2.Pop();
        return sum;   
    }
    return 0;
}

// Same as previous except sizes do not have to match
int AddStacksSeperate(stack<int> &s1, stack<int> &s2) { // Assumes stack sizes won't be equal
    if(s1.IsEmpty() || s2.IsEmpty())
        return -1;
    else {
        int sum = 0;
        if(s1.GetSize() > s2.GetSize()) {
            int size = s2.GetSize();
            for(unsigned int i = 0; i < size; i++)
                sum += s2.Pop() + s1.Pop();
            while(!s1.IsEmpty())
                sum += s1.Pop();
        }
        else {
            int size = s1.GetSize();
            for(unsigned int i = 0; i < size; i++)
                sum += s1.Pop() + s2.Pop();
            while(!s2.IsEmpty())
                sum += s2.Pop();
        }
        return sum; 
    }
    return -1;
}

// Converts the stacks into long numbers and adds them together
long long CombinedSum(stack<int> &s1, stack<int> &s2) {
    std::string firstNum = "";
    std::string secondNum = "";
    while (!s1.IsEmpty()) firstNum.append(std::to_string(s1.Pop()));
    while (!s2.IsEmpty()) secondNum.append(std::to_string(s2.Pop()));
    std::reverse(firstNum.begin(), firstNum.end());
    std::reverse(secondNum.begin(), secondNum.end());
    std::cout << firstNum << " | " << secondNum << '\n';
    return std::stoll(firstNum) + std::stoll(secondNum);
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
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    s1.Push(6);
    s1.Push(12);
    s1.Push(4);
    s1.Push(90);
    s1.Push(1);
    s1.Push(34);
    s1.Push(5);
    s1.Push(9);

    s1.Print();
    putchar('\n');

    s2.Push(5);
    s2.Push(7);
    s2.Push(2);
    s2.Push(10);
    s2.Push(17);

    s2.Print();

    s3.Push(6);
    s3.Push(12);
    s3.Push(14);
    s3.Push(2);
    s3.Push(1);

    SortStack(s1);

    putchar('\n');

    s1.Print();

    std::cout << "\n\nStack Adding:\n"; // Comment out any function not being used, else result will be affected
    // std::cout << "Add Stacks: "; AddStacks(s2,s3);
    std::cout << "Add Stacks Independent: "; AddStacksIndependent(s2,s3);
    // std::cout << "\nAdd Stacks Global: " << AddStacksGlobal(s2,s3);
    // std::cout << "\nAdd Stacks Seperate: " << AddStacksSeperate(s1, s2);
    // std::cout << "\nCombined Sum: " << CombinedSum(s1, s2);


    return 0;
}