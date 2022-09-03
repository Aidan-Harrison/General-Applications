#include <iostream>
#include <vector>

struct stack {
    std::vector<int> items;
    int top = -1, SIZE{};

    int size() const { return top; }

    bool IsFull() const;
    bool IsEmpty() const;
    void Push(const int item);
    void multpush(std::vector<int> && arr);
    int Pop();

    void Print() const;

    stack(int s = 10) 
    { 
        items.resize(s); 
        SIZE = s;
    }
};

bool stack::IsFull()  const{ return (top == SIZE) ? true : false; }
bool stack::IsEmpty() const{ return (top == -1) ? true : false;   }

void stack::Push(const int item) {
    if(IsFull())
        return;
    top++;
    items[top] = item;
}

void stack::multpush(std::vector<int> && arr) {
    for(int i : arr) {
        if(IsFull())
            return;
        items[top] = i;
        top++;
    }
}

int stack::Pop() {
    if(IsEmpty())
        return INT_MIN;
    int item = items[top];
    items[top] = 0;
    top--;
    return item;
}

void stack::Print() const {
    for(int i = 0; i < top; i++)
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

    for(int i = 0; i <= 3; i++)
        s.Pop();
    
    s.Print();
    s.multpush({1,2,3,4,5,6,7});
    s.Print();

    return 0;
}