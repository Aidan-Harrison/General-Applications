#include <iostream>

#include <SFML/Graphics.hpp>

// Review these namespaces!!
namespace global {
	int screenWidth = 800, screenHeight = 600;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Vending Machine");
	sf::Event event;
	sf::Font font;
}

namespace user {
	int input;
	float cash = 10.00;
	sf::Text cashText;
}

using namespace global;
using namespace user;

struct VendingMachine { // Make singleton?
	sf::RectangleShape rect;
	std::vector<std::vector<sf::RectangleShape>> contents{};
	std::vector<std::vector<std::string>> contentNames{};
	std::vector<std::vector<int>> contentsCount{};
	std::vector<std::vector<int>> contentsID{};
	std::vector<std::vector<float>> contentsCost{};

	// Interface
	sf::RectangleShape panelBack;
	std::vector<sf::RectangleShape> buttons{};

	// Text
	sf::Text title{};
	std::vector<sf::Text> idText{};
	std::vector<sf::Text> buttonIDText{};

	VendingMachine(const unsigned int stock) 
	{
		// Base Graphics
		rect.setSize(sf::Vector2f(screenWidth - 100, screenHeight - 100));
		rect.setFillColor(sf::Color(25,25,25,255));
		rect.setOrigin(rect.getSize().x/2, rect.getSize().y/2);
		rect.setPosition(screenWidth/2, screenHeight/2);
		
		panelBack.setSize(sf::Vector2f(100.0f, rect.getSize().y - 100));
		panelBack.setFillColor(sf::Color::White);
		panelBack.setOrigin(panelBack.getSize().x/2, panelBack.getSize().y/2);
		panelBack.setPosition(screenWidth - 200, screenHeight / 2);

		// Text
		title.setFont(font);
		title.setString("Vending Machine");
		title.setOrigin(title.getLocalBounds().width /2, title.getLocalBounds().height/2);

		for (auto i : idText) {
			i.setFont(font);
		}


		buttons.resize(8);
		for (auto i : buttons) {
			i.setFillColor(sf::Color::Red);
			i.setSize(sf::Vector2f(25.0f,25.0f));
			i.setOrigin(i.getSize().x, i.getSize().y);
			// Do position
			i.setPosition(screenWidth - 200, screenHeight / 2);
			std::cout << i.getPosition().x << "|" << i.getPosition().y << '\n';
		}

		contents.resize(stock);
		for (unsigned int i = 0; i < stock; i++)
			contents[i].resize(stock);
		contentNames.resize(stock);
		for (unsigned int i = 0; i < stock; i++)
			contentNames[i].resize(stock);
		contentsCount.resize(stock);
		for (unsigned int i = 0; i < stock; i++)
			contentsCount[i].resize(stock);
		contentsID.resize(stock);
		for (unsigned int i = 0; i < stock; i++)
			contentsID[i].resize(stock);
		contentsCost.resize(stock);
		for (unsigned int i = 0; i < stock; i++)
			contentsCost[i].resize(stock);
	}

	void Purchase(const int id);
	void Stock(const std::string &str, const int amount); // Adds new items
	void Swap(); // Swap an item for another one

	void Draw(sf::RenderWindow& window);
	~VendingMachine() {}
};

void VendingMachine::Purchase(const int id) {
	for (unsigned int i = 0; i < contentsID.size(); i++) {
		for (unsigned int j = 0; j < contentsID[0].size(); j++) {
			if (id == contentsID[i][j])
				std::cout << "FOUND!\n";
		}
	}
}

void VendingMachine::Stock(const std::string& str, const int amount) {
	for (unsigned int i = 0; i < contentNames.size(); i++) {
		for (unsigned int j = 0; j < contentNames[0].size(); j++) {
			if (str == contentNames[i][j]) {
				contentsCount[i][j] += amount;
				sf::RectangleShape* newItem = new sf::RectangleShape;
				// Push 'newItem'
			}
		}
	}
}

void VendingMachine::Draw(sf::RenderWindow& window) {
	window.draw(rect);
	window.draw(panelBack);
	for (unsigned int i = 0; i < buttons.size(); i++) // Fix!
		window.draw(buttons[i]);
	for (unsigned int i = 0; i < contents.size(); i++) {
		for (unsigned int j = 0; j < contents[0].size(); j++) {
			window.draw(contents[i][j]);
		}
	}
}

void Interface() {
	std::string strInput = "";
	int input = 0;
	VendingMachine vM(10);
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (input) {
				case 0: std::cin >> strInput >> input; vM.Stock(strInput, input); break;
				case 1: std::cin >> input; vM.Purchase(input); break;
				case 2: break;
				case 3: break;
				default: break;
			}

			// Mouse Input
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				std::cout << "Clicked\n";
				for (auto i : vM.buttons) {
					for (unsigned int j = 0; j < vM.buttons[0].getSize().x; j++) {
						if (sf::Mouse::getPosition().x == i.getPosition().x - j || sf::Mouse::getPosition().x == i.getPosition().x + j) {
							std::cout << "Hit Button\n";
						}
						else if (sf::Mouse::getPosition().y == i.getPosition().y - j || sf::Mouse::getPosition().y == i.getPosition().y + j) {
							std::cout << "Hit Button\n";
						}
					}
				}
			}
		}
		window.clear();

		vM.Draw(window);
		window.display();
	}
}

int main() {
	Interface();

	return 0;
}