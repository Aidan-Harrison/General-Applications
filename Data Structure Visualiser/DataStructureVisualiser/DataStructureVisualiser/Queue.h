#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <array>

#include <SFML/Graphics.hpp>

class Queue {
private:
	sf::Font font;
	float xOffset = 30.0f;

	int choice = 0;
	sf::Text operationText;
public:
	std::array<int, 10> values;
	std::array<sf::RectangleShape, 10> queue;
	std::array<sf::Text, 10> queueText;
	int front = 0;
	int rear = -1;

	bool IsFull();
	bool IsEmpty();
	void Enqueue(const int data);
	void Dequque();

	void Draw(sf::RenderWindow &window);
	void Interface(sf::RenderWindow& window);

	Queue(const std::vector<int> &items) 
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";
		for (unsigned int i = 0; i < items.size(); i++) {
			values[i] = items[i];
		}

		for (unsigned int i = 0; i < queue.size(); i++) {
			queue[i].setFillColor(sf::Color::White);
			queue[i].setSize(sf::Vector2f(25.0f, 100.0f));
			queue[i].setOrigin(queue[i].getSize().x / 2, queue[i].getSize().y / 2);
			queue[i].setPosition(xOffset, 300.0f);
			xOffset += 30.0f;
		}
		xOffset = 30.0f;
		for (unsigned int i = 0; i < queueText.size(); i++) {
			queueText[i].setFont(font);
			queueText[i].setString(std::to_string(values[i]));
			queueText[i].setOrigin(queueText[i].getLocalBounds().width / 2, queueText[i].getLocalBounds().height / 2);
			queueText[i].setPosition(xOffset, 300.0f);
			xOffset += 30.0f;
		}
	}
	~Queue() {}
};

#endif Queue_h