#include <iostream>
#include <unordered_map>

#include <SFML/Graphics.hpp>

// Review these namespaces!!
namespace global {
	int screenWidth = 800, screenHeight = 600;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Vending Machine");
	sf::Event event;
	sf::Font font;
}

namespace user {
	int input; // Remove?
	float cash = 10.00f;
	sf::Text cashText;
}

using namespace global;
using namespace user;

struct VendingMachine { // Make singleton?
	sf::RectangleShape rect;
	std::vector<std::string> contentNames{};
	std::vector<int> contentsCount{};
	std::vector<float> contentsCost{};
	std::unordered_map<int, sf::RectangleShape> contentsMap{};
	std::unordered_map<int, std::tuple<int, sf::RectangleShape, std::string>> contents{};

	// Interface
	sf::RectangleShape panelBack;
	sf::RectangleShape glass;
	std::vector<sf::RectangleShape> buttons{};
	std::vector<sf::Text> ID{};
	std::vector<sf::Text> costs{};

	// Text
	sf::Text title{};

	VendingMachine(const unsigned int stock) 
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load file!\n";
		// Base Graphics
		rect.setSize(sf::Vector2f(screenWidth - 100, screenHeight - 100));
		rect.setFillColor(sf::Color(25,25,25,255));
		rect.setOrigin(rect.getSize().x/2, rect.getSize().y/2);
		rect.setPosition(screenWidth/2, screenHeight/2);
		
		panelBack.setSize(sf::Vector2f(100.0f, rect.getSize().y - 100));
		panelBack.setFillColor(sf::Color::White);
		panelBack.setOrigin(panelBack.getSize().x/2, panelBack.getSize().y/2);
		panelBack.setPosition(screenWidth - 200, screenHeight / 2);

		glass.setSize(sf::Vector2f(rect.getSize().x - 250, rect.getSize().y - 100));
		glass.setOrigin(glass.getSize().x / 2, glass.getSize().y/2);
		glass.setFillColor(sf::Color(128,128,128,255));
		glass.setPosition(rect.getPosition().x - 100, rect.getPosition().y);

		// Text
		title.setFont(font);
		title.setString("Vending Machine");
		title.setOrigin(title.getLocalBounds().width /2, title.getLocalBounds().height/2);

		float xPos = 100.0f;
		float yPos = 150.0f;
		float xOffset = screenWidth/3;
		float yOffset = screenHeight/2;
		int counter = 0;

		for (unsigned int i = 0; i <= 8; i++) {
			sf::Text newText;
			newText.setFont(font);
			//newText.setFillColor(sf::Color::White);
			newText.setString("1");
			newText.setOrigin(newText.getLocalBounds().width/2, newText.getLocalBounds().height/2);
			counter++;
			newText.setPosition(xPos, yPos);
			xPos += 25.0f;
			if (counter == 6) {
				xPos = 0;
				yPos += 25.0f;
			}
		}
		counter = 0;
		for (unsigned int i = 0; i <= 8; i++) {
			sf::Text newText;
			newText.setFont(font);
			//newText.setFillColor(sf::Color::White);
			newText.setString("£0.00");
			newText.setOrigin(newText.getLocalBounds().width/2, newText.getLocalBounds().height/2);
			counter++;
			newText.setPosition(xPos, yPos);
			xPos += 25.0f;
			if (counter == 6) {
				xPos = 0;
				yPos += 25.0f;
			}
		}

		for (unsigned int i = 0; i <= 8; i++) {
			sf::RectangleShape newButton;
			newButton.setFillColor(sf::Color::Red);
			newButton.setSize(sf::Vector2f(25.0f,25.0f));
			newButton.setOrigin(newButton.getSize().x, newButton.getSize().y);
			newButton.setPosition(xOffset, yOffset);
			xOffset += 35.0f;
			if (i == 4) {
				xOffset = screenWidth / 3;
				yOffset += 35.0f;
			}
			contentsMap.insert(std::pair<int, sf::RectangleShape>(i, newButton));
		}

		contentNames.resize(stock);
		contentsCount.resize(stock);
		contentsCost.resize(stock);
	}

	void Purchase();
	void Stock(const std::string &str, const int amount); // Adds new items
	void Swap(); // Swap an item for another one

	void Draw(sf::RenderWindow& window);
	~VendingMachine() {}
};

void VendingMachine::Purchase() {
	int id = 0;
	std::cout << "Purchase\n";
	std::cout << "Enter ID:";
	std::cin >> id;
	std::unordered_map<int, sf::RectangleShape>::iterator result;
	result = contentsMap.find(id);
	if (result != contentsMap.end()) {
		std::cout << "Confirm purchase";
		cash -= contentsCost[0];
		cashText.setString(std::to_string(cash));
		result->second.setFillColor(sf::Color::Blue);
	}
	else { // Add loop
		std::cout << "Not Found!\n";
	}
}

void VendingMachine::Stock(const std::string& str, const int amount) {
	for (unsigned int i = 0; i < contentNames.size(); i++) {
		if (str == contentNames[i]) {
			contentsCount[i] += amount;
		}
	}
}

void VendingMachine::Swap() {
	int id = 0;
	int tempID = 0;
	std::cout << "Enter ID:";
	std::cin >> id;
	tempID = id;
	std::cout << "Enter a different items ID:";
	std::cin >> id;
	while (id == tempID) {
		std::cout << "SAME ID!\nEnter a different items ID:";
		std::cin >> id;
	}
}

void VendingMachine::Draw(sf::RenderWindow& window) {
	window.draw(rect);
	window.draw(panelBack);
	window.draw(glass);
	std::unordered_map<int, sf::RectangleShape>::iterator it;
	for (it = contentsMap.begin(); it != contentsMap.end(); it++) {
		window.draw(it->second);
	}
	// Text
	for (unsigned int i = 0; i < ID.size(); i++)
		window.draw(ID[i]);
	for (unsigned int i = 0; i < costs.size(); i++)
		window.draw(costs[i]);
}

void Interface() {
	std::string strInput = "";
	int input = 0;
	VendingMachine vM(10);
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
				vM.Stock(strInput, input);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				std::cout << "purchase\n";
				vM.Purchase();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
				vM.Swap();
			}

			// Mouse Input
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				for (auto i : vM.buttons) {
					for (unsigned int j = 0; j < vM.buttons[0].getSize().x; j++) {
						if (sf::Mouse::getPosition(window).x == i.getPosition().x - j || sf::Mouse::getPosition(window).x == i.getPosition().x + j) {
							std::cout << "Hit Button\n";
							i.setFillColor(sf::Color::Green);
							break;
						}
						else if (sf::Mouse::getPosition(window).y == i.getPosition().y - j || sf::Mouse::getPosition(window).y == i.getPosition().y + j) {
							std::cout << "Hit Button\n";
							i.setFillColor(sf::Color::Green);
							break;
						}
					}
				}
			}
		}
		window.clear();

		window.draw(cashText);
		vM.Draw(window);
		window.display();
	}
}

int main() {
	cashText.setPosition(sf::Vector2f(50.0f, 50.0f));
	cashText.setString(std::to_string(cash));
	Interface();

	return 0;
}