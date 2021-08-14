#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Queue {
    int MAXSIZE = 10;

    int items[10];
    int rear = 0; // -1?
    int front = 0;

    bool IsFull() {
        if(front == MAXSIZE)
            return true;
        return false;
    }

    bool IsEmpty() {
        if(rear == -1)
            return true;
        return false;
    }

    void Enqueue(int data) {
        if(IsFull())
            std::cerr << "Queue is full!\n";
        else {
            if(rear == -1)
                rear = 0;
            front++;
            rear++; // Ensure rear is one ahead of element
            items[front] = data;
        }
    }

    int Dequeue() { // Fix!
        if(IsEmpty())
            std::cerr << "Queue is empty!\n";
        else {
            int item = items[front];
            front--;
            // Add rear increment!?
            if(rear == MAXSIZE) {
                rear = -1;
                front = 0; 
            } 
            return item;
        }
        return -1;
    }

    int Peek() {
        return items[front];
    }

    int GetSize() {
        return front;
    }

    void Print() {
        for(unsigned int i = 1; i <= front; i++)
            std::cout << items[i] << ", ";
    }
};

void SortQueue(Queue &q) {
   int size = q.GetSize();
   std::vector<int> container{};
   for(int i = 0; i < size; i++)
        container.push_back(q.Dequeue()); // Check!
   std::sort(container.begin(), container.end());
   for(int i = 0; i < container.size(); i++)
        q.Enqueue(container[i]);
}

void ReverseArray(std::vector<int> &arr, Queue &q) {
    int size = q.GetSize();
    for(auto i : arr)
        q.Enqueue(arr[i]);
    q.Print();
    arr.clear();
    for(int i = 0; i < size; i++)
        arr.push_back(q.Dequeue());
}

// Use another Queue to sort an existing Queue
void SortQueueUsingQueue(Queue &q1, Queue &q2) {
   int size = q1.GetSize();
   for(int i = 0; i < size; i++) {
       q2.Enqueue(q1.Dequeue());
       if(q1.Peek() < q2.Peek())
            q1.Enqueue(q2.Peek());
   } 
}

int main() {
    Queue q;
    Queue q2;
    q.Enqueue(5);
    q.Enqueue(15);
    q.Enqueue(24);
    q.Enqueue(7);
    q.Enqueue(91);

    q.Print();

    putchar('\n');

    SortQueue(q);

    q.Print();

    putchar('\n');

    // Fix printing!!!
    std::vector<int> array{16,5,4,2,1};

    putchar('\n');

    for(auto i : array)
        std::cout << i << ", ";

    putchar('\n');
    ReverseArray(array, q2);

    for(auto i : array)
        std::cout << i << ", ";

    return 0;
}