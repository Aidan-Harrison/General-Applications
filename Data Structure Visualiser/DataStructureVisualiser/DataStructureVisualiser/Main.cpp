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

void TreeCreation(tNode *parent, int value) { // Re-add size?
	if (value <= parent->data) {
		if (parent->lChild == nullptr) {
			tNode* lChild = new tNode(value, parent->circle.getPosition(), true);
			std::cout << lChild->data << '\n';
			std::cout << parent->circle.getPosition().x << ", " << parent->circle.getPosition().y;
			std::cout << lChild->circle.getPosition().x << ", " << lChild->circle.getPosition().y;
			parent->lChild = lChild;
		}
		else {
			TreeCreation(parent->lChild, parent->lChild->data);
		}
	}
	else {
		if (parent->rChild == nullptr) {
			tNode* rChild = new tNode(value, parent->circle.getPosition(), false);
			std::cout << rChild->data << '\n';
			parent->rChild = rChild;
		}
		else {
			TreeCreation(parent->rChild, parent->rChild->data);
		}
	}
}

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
	else if (choice == 4) { // Tree
		Tree newTree(screenWidth, screenHeight);
		int size = 0;
		tNode* parent = new tNode;
		parent->data = 20;
		parent->data++;
		parent->circle.setPosition(sf::Vector2f((float)screenWidth/2, (float)screenHeight/2)); // Remove?
		newTree.root = parent;
		TreeCreation(newTree.root, 12);
		Draw(newTree); // Change!
	}
	else { // Graph
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