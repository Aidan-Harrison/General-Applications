#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Room.h"

sf::RenderWindow window(sf::VideoMode(800,600), "Procedural Generation");
std::vector<Room> dungeon{};

void Draw() {
	for (int i = 0; i < dungeon.size(); i++) {
		dungeon[i].Draw(window);
	}
}

void Run() {
	while(window.isOpen()) {

		window.clear();
		Draw();
		window.display();
	}
}

void Generate() {
	sf::Vector2i startingPos(400,300);
	Room r(startingPos); // Base room
	r.Initialise(); // Base room only
	dungeon.push_back(r);

	for (int i = 0; i < r.points.size(); i++) {
		Room r(r.points[i]);
		dungeon.push_back(r);
	}

	Run();
}

int main() {
	Generate();

	return 0;
}