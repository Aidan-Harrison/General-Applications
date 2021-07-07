#ifndef Interface_h
#define Interface_h

#include <SFML/Graphics.hpp>

struct Highlighter { // Rounded corner square around planet
	sf::Texture tex;
	sf::Sprite spr;
};

class InformationWindow { // Displays information of the currently selected object | Singleton
private:
	// InformationWindow() {} // Check!
public:
	InformationWindow(); // Change to be singleton
	~InformationWindow() {}

	bool visible = false;

	sf::RectangleShape background;
	std::vector<sf::Text> data{};

	void Update(std::vector<sf::Text>& data); // Updates data
	void Draw(sf::RenderWindow &window);
};

InformationWindow::InformationWindow() {
	background.setFillColor(sf::Color::White);
	background.setSize(sf::Vector2f(1900.0f, 300.0f)); // Change to take screen size
	background.setPosition(100.0f, 540.0f);
}

// Move to .cpp eventually
void InformationWindow::Update(std::vector<sf::Text> &objData) {
	for (int i = 0; i < objData.size(); i++) {
		data[i] = objData[i];
	}
}

void InformationWindow::Draw(sf::RenderWindow &window) {
	window.draw(background);
	for (int i = 0; i < data.size(); i++) {
		window.draw(data[i]);
	}
}

#endif
