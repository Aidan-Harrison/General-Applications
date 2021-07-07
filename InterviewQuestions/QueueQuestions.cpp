#include <iostream>
#include <vector>
#include <algorithm>

struct Queue {
    int MAXSIZE = 10;

    int items[10];
    int front = -1;
    int rear = 0;

    bool IsFull() {
        if(rear == MAXSIZE)
            return true;
        return false;
    }
    bool IsEmpty() {
        if(front == -1)
            return true;
        return false;
    }
    void Enqueue(int data) { // Check, push front when full??
        if(IsFull())
            std::cerr << "Queue is full!\n";
        else {
            if(front == -1)
                front = 0;
            items[rear++] = data;
        }
    }
    int Dequeue() { // Fix!
        if(IsEmpty())
            std::cerr << "Queue is empty!\n";
        else {
            front++;
            if(front == MAXSIZE) {
                rear = 0; // Check!
                front = -1;   // Check!
            }
            return items[rear];
        }
        return -1;
    }

    int Peek() {
        return items[rear];
    }

    int GetSize() {
        return rear;
    }

    void Print() {
        for(int i = 0; i < rear; i++)
            std::cout << items[rear];
    }
};

void SortQueue(Queue &q) {
   int size = q.GetSize();
   std::vector<int> container{};
   for(int i = 0; i < size; i++) {
        container.push_back(q.Dequeue()); // Check!
   }
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

    SortQueue(q);

    // Fix printing!!!
    std::vector<int> array{16,5,4,2,1};

    for(auto i : array)
        std::cout << i << ", ";
    ReverseArray(array, q2);
    for(int i = 0; i < array.size(); i++)
        std::cout << array[i] << ", ";


    q.Print();

    return 0;
}