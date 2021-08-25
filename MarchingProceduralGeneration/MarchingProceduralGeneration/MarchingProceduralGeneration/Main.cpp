#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <tuple>

#include <SFML/Graphics.hpp>

namespace Global {
	const int screenWidth = 800, screenHeight = 600;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Marching Procedural Generation");
	sf::Event event;
	sf::Font font;
	int x = 0;
	int y = 0;

	// Generation
	sf::Vertex line[2] = {
		sf::Vertex(sf::Vector2f(0.0f, 0.0f)),
		sf::Vertex(sf::Vector2f(0.0f, 0.0f))
	};
	sf::Vector2f marcher(screenWidth -500, 200.0f);
	sf::CircleShape marcherPos;
	sf::CircleShape tilePos;
	sf::Text marcherTitle;
	sf::Text tileSetTitle;
	std::tuple<sf::Text, sf::Text> marcherPosText; // Change for C array?
}

namespace TILESET {
	std::vector<sf::Color> colours{};
	std::vector<sf::RectangleShape> tiles{};
	std::vector<int> tileID{};
}

using namespace Global;

void GenerateColours() {
	srand(time(0));
	int r = 0, g = 0, b = 0;
	const int a = 255;
	for (unsigned int i = 0; i < 10; i++) {
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;
		sf::Color newColor(r,g,b,a);
		// Check if exists
		for (auto j : TILESET::colours) // Fix! Add range??
			if (newColor == j)
				break;
		TILESET::colours.push_back(newColor);
	}
}

void Populate() {
	float yPos = 50.0f;
	int choice = 0;
	for(unsigned int i = 0; i < 8; i++) {
		sf::RectangleShape newTile;
		newTile.setSize(sf::Vector2f(50.0f,50.0f));
		newTile.setOrigin(newTile.getSize().x/2, newTile.getSize().y/2);
		newTile.setPosition(screenWidth - 650, yPos += 60.0f);
		choice = rand() % TILESET::colours.size();
		newTile.setFillColor(TILESET::colours[choice]);
		TILESET::tiles.push_back(newTile);
	}
}

void Draw(std::vector<sf::RectangleShape> &grid) {
	window.clear();
	for (unsigned int i = 0; i < grid.size(); i++) 
		window.draw(grid[i]);
	for (unsigned int i = 0; i < TILESET::tiles.size(); i++)
		window.draw(TILESET::tiles[i]);
	window.draw(std::get<0>(marcherPosText));
	window.draw(std::get<1>(marcherPosText));
	window.draw(marcherPos);
	window.draw(tilePos);
	window.draw(marcherTitle);
	window.draw(tileSetTitle);
	window.draw(line, 2, sf::Lines);
	window.display();
}

void Generate() {
	marcherPos.setFillColor(sf::Color::White);
	marcherPos.setRadius(10.0f);
	marcherPos.setOrigin(marcherPos.getRadius() / 2, marcherPos.getRadius() / 2);
	tilePos.setFillColor(sf::Color::White);
	tilePos.setRadius(10.0f);
	tilePos.setOrigin(tilePos.getRadius() / 2, tilePos.getRadius() / 2);
	int choice = 0;
	std::vector<sf::RectangleShape> grid{};	
	std::cout << "Enter amount: "; 
	std::cin >> x;
	for (unsigned int i = 0; i <= x; i++) {
		if (marcher.x == 600.0f) {
			marcher.x = screenWidth - 500;
			marcher.y += 50.0f;
		}
		marcher.x += 50.0f;
		line[0].position.x = marcher.x;
		line[0].position.y = marcher.y;
		std::get<0>(marcherPosText).setString(std::to_string((int)marcher.x));
		std::get<1>(marcherPosText).setString(std::to_string((int)marcher.y));
		marcherPos.setPosition(marcher.x, marcher.y);
		choice = rand() % TILESET::tiles.size();
		line[1].position.x = TILESET::tiles[choice].getPosition().x;
		line[1].position.y = TILESET::tiles[choice].getPosition().y;
		tilePos.setPosition(line[1].position.x, line[1].position.y);
		grid.push_back(TILESET::tiles[choice]);
		grid[grid.size()-1].setPosition(marcher.x, marcher.y);
		// std::cout << grid[grid.size() - 1].getPosition().x << "|" << grid[grid.size() - 1].getPosition().y << '\n';
		// Call draw function
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		Draw(grid);
	}

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				marcher.y = 200.0f;
				Generate();
			}
		}
	}
}

int main() {
	if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
		std::cerr << "Faile to load font!\n";
	std::get<0>(marcherPosText).setFont(font);
	std::get<0>(marcherPosText).setPosition(screenWidth - 425, 80.0f);
	std::get<1>(marcherPosText).setFont(font);
	std::get<1>(marcherPosText).setPosition(screenWidth - 325, 80.0f);
	tileSetTitle.setFont(font);
	tileSetTitle.setString("Tileset");
	tileSetTitle.setOrigin(tileSetTitle.getLocalBounds().width/2, tileSetTitle.getLocalBounds().height/2);
	tileSetTitle.setPosition(screenWidth - 650, 45.0f);
	marcherTitle.setFont(font);
	marcherTitle.setString("Marcher: ");
	marcherTitle.setPosition(screenWidth - 425, 45.0f);

	GenerateColours();
	Populate();
	Generate();

	return 0;
}