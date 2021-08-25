#include "Queue.h"

bool Queue::IsFull() {
	if (rear == values.size())
		return true;
	return false;
}

bool Queue::IsEmpty() {
	if (rear == front) // Check!
		return true;
	return false;
}

void Queue::Enqueue(const int data) {
	if (IsFull())
		std::cerr << "Queue is full!\n";
	else {
		values[rear++] = data;
	}
}

void Queue::Dequque() {
	if (IsEmpty())
		std::cerr << "Queue is empty!\n";
	else {
		return;
	}
}

void Queue::Draw(sf::RenderWindow& window) {
	for (unsigned int i = 0; i < queue.size(); i++) {
		window.draw(queue[i]);
		window.draw(queueText[i]);
	}
}