#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Graph.h"

#include <SFML/Graphics.hpp>

template<typename T>
void Draw(T &structure) {
	sf::RenderWindow window(sf::VideoMode(800, 600), "DSA Visualiser");
	window.setFramerateLimit(24);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
		}

		window.clear();
		structure.Draw(window);
		structure.Interface(window);

		window.display();
	}
}

// Run necessarcy code, swap between classes, delete class object when not drawing
void StructureCreation() {
	sf::Font font; // Only load once, move this somewhere else
	if (!font.loadFromFile("Fonts/Roboto-Bold.ttf")) {
		std::cerr << "Failed to load font!\n Aborting...";
		exit(1);
	}
	int choice = 0;
	std::cout << "Pick a structure:\n 1) Stack    2) Queue    3) List    4) Graph/Tree\n";
	std::cin >> choice;
	if (choice == 1) { // Stack
		std::vector<int> data{1,2,3,4,5,6,7};
		Stack s(data);
		Draw(s);
	}
	else if (choice == 2) { // Queue
		std::vector<int> data{1,2,3,4,5,6,7};
		Queue q(data);
		Draw(q);
	}
	else if (choice == 3) { // List
		List l;
		Draw(l);
	}
	else { // Graph/Tree?
		std::vector<int> data{1,2,3,4,5,6,7};
		Graph g(data);
		Draw(g);
	}
}

void Setup() { // Remove!?
	StructureCreation();
}

int main() {
	Setup();

	return 0;
}