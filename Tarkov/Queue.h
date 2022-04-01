#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <vector>

template<typename T>
struct Queue {
    int front = -1, rear = -1;
    const int MAX_SIZE = 10;
    std::vector<T> items{};
    inline bool isFull() {
        return rear == MAX_SIZE;
    }
    inline bool isEmpty() {
        return rear == 0 && front == -1;
    }
    void Enqueue(T &item) {
        if(isFull())
            return;
        if(rear == MAX_SIZE) { // ?? Change
            front = -1;
            rear = -1;
        }
        else {
            rear++;
            items[rear] = item;
        }
    }
    T Dequeue() {
        if(isEmpty())
            return;
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        T item = items[front];
        front++;
        return item;
    }
};

#endif