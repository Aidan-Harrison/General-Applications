#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Graph.h"
#include "Tree.h"

#include "Interface.h"

const int screenWidth = 800, screenHeight = 600;
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "DSA Visualiser");
Interface interface(screenWidth, screenHeight);

void StructureCreation();

template<typename T>
void Draw(T &structure) {
	window.setFramerateLimit(24);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { // Reset
				StructureCreation(); // Kill this function
			}
		}

		window.clear();
		structure.Draw(window);
		interface.Draw(window);
		//structure.Interface(window);

		window.display();
	}
}

// Run necessarcy code, swap between classes, delete class object when not drawing
void StructureCreation() {
	system("cls");
	sf::Font font; // Only load once, move this somewhere else
	if (!font.loadFromFile("Fonts/Roboto-Bold.ttf")) {
		std::cerr << "Failed to load font!\n Aborting...";
		exit(1);
	}
	int choice = 0;
	std::cout << "Pick a structure:\n 1) Stack    2) Queue    3) List    4) Binary Tree    5) Graph\n";
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
	else if (choice == 4) {
		// std::cout << "Tree size:\t";
		Tree newTree(screenWidth, screenHeight);
		tNode* parent = new tNode;
		parent->circle.setPosition(sf::Vector2f((float)screenWidth/2, (float)screenHeight/2));
		newTree.root = parent;
		tNode* lChild = new tNode(0, parent->circle.getPosition(), true);
		tNode* rChild = new tNode(0, parent->circle.getPosition(), false);
		newTree.root->lChild = lChild;
		newTree.root->rChild = rChild;
		Draw(newTree);
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