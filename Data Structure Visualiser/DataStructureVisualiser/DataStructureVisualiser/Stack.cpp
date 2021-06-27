#include "Stack.h"

bool Stack::IsFull() {
	if (top == values.size())
		return true;
	else
		return false;
}

bool Stack::IsEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

void Stack::Push(const int data) {
	if (IsFull())
		std::cerr << "Stack is full!\n"; // Add graphics
	else {
		values[top++] = data;
		stack[top].setFillColor(sf::Color::White);
		stackText[top].setString(std::to_string(values[top]));
	}
}

void Stack::Pop() {
	if (IsEmpty())
		std::cerr << "Stack is empty!\n"; // Add graphics
	else {
		values[top] = 0;
		stack[top].setFillColor(sf::Color::Black);
		stackText[top].setString(std::to_string(values[top]));
		top--;
	}
}

void Stack::Draw(sf::RenderWindow &window) {
	for (unsigned int i = 0; i < stack.size(); i++) {
		window.draw(stack[i]);
		window.draw(stackText[i]);
	}
}

void Stack::Interface(sf::RenderWindow& window) {
	operationText.setPosition(100.0f,50.0f);
	std::cout << "Pick an operation:\n";
	std::cin >> choice;
	if (choice == 1) {
		operationText.setFont(font);
		operationText.setString("Push");
		window.draw(operationText);
	}
	else if (choice == 2) {
		operationText.setFont(font);
		operationText.setString("Pop");
		window.draw(operationText);
	}

}