#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <array>

#include <SFML/Graphics.hpp>

class Stack {
private:
	sf::Font font;
	float yOffset = 0.0f;

	int choice = 0; // Used exclusively for Interface()
	sf::Text operationText;
public:

	std::array<int, 10> values;
	std::array<sf::RectangleShape, 10> stack;
	std::array<sf::Text, 10> stackText;
	int top = -1;

	bool IsFull();
	bool IsEmpty();
	void Push(const int data);
	void Pop();

	void Draw(sf::RenderWindow &window);
	void Interface(sf::RenderWindow &window);

	void Delete();

	Stack(const std::vector<int> &data)
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";
		for (int i = 0; i < data.size(); i++) {
			values[i] = data[i];
			top++;
		}

		for (int i = 0; i < stack.size(); i++) {
			stack[i].setSize(sf::Vector2f(100.0f, 25.0f));
			stack[i].setOrigin(stack[i].getSize().x, stack[i].getSize().y);
			stack[i].setPosition(400.0f, yOffset);
			yOffset += 30.0f;
		}
		yOffset = 0.0f;
		for (int i = 0; i < stackText.size(); i++) {
			stackText[i].setFont(font);
			// stackText[i].setFillColor(sf::Color::Black);
			stackText[i].setString(std::to_string(values[i]));
			stackText[i].setOrigin(stackText[i].getLocalBounds().width / 2, stackText[i].getLocalBounds().height / 2);
			stackText[i].setPosition(400.0f, yOffset);
			yOffset += 30.0f;
		}
	}
	~Stack() {}
};

#endif