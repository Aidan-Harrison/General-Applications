#include <ctime>

#include "Tree.h"
#include "Interface.h"

int screenWidth = 1024, screenHeight = 720;
bool drawInfo = true;
bool isInterfaceVisible = false;
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Life Simulator");

Interface inter(screenWidth, screenHeight);
void CreateAnimals();

void Clear(std::vector<Animal*> &animals, std::vector<Tree*> &trees) {
	for (auto i : animals)
		delete[] i; // Check!
	for (auto i : trees)
		delete[] i; 
	CreateAnimals();
}

// Provides the stats for the searched animal
void Search(std::vector<Animal*> &animals) {
	std::string name = "";
	std::cout << "Enter name: "; std::cin >> name;
	std::unordered_map<int, Animal> map; // Implement somehow. Fast search instead of linear for loop!
	for (unsigned int i = 0; i < animals.size(); i++) {
		if (name == animals[i]->name) {
			isInterfaceVisible = true;
			inter.Update(screenWidth, screenHeight, *animals[i]);
		}
	}
	std::cout << "Animal not found!\n"; // Add!
}

void Draw(std::vector<Animal*> &animals, std::vector<Tree*> &trees) {
	sf::Event event;
	window.setFramerateLimit(24);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) { // Hide/Show interface
				switch (isInterfaceVisible) {
					case false: isInterfaceVisible = true; break;
					case true: isInterfaceVisible = false; break;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // Search
				Search(animals);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) { // Get names
				for (unsigned int i = 0; i < animals.size(); i++)
					std::cout << i << "| " <<  animals[i]->name << '\n';
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) { // Clear/Generate
				Clear(animals, trees); // Double break!!
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // Spawn new animal at mouse cursor | Stop spawning so many
				sf::Vector2i mousePos = sf::Mouse::getPosition();
				sf::Vector2f mousePosFloat;
				mousePosFloat.x = (float)mousePos.x;
				mousePosFloat.y = (float)mousePos.y;
				Animal* newAnimal = new Animal(100, mousePosFloat);
				animals.push_back(newAnimal);
			}
		}

		window.clear();

		for (unsigned int i = 0; i < animals.size(); i++) {
			animals[i]->Roam(screenWidth, screenHeight, animals);
			if(drawInfo)
				animals[i]->Draw(window, true);
			else
				animals[i]->Draw(window, false);
		}
		for (unsigned int i = 0; i < trees.size(); i++) {
			trees[i]->Advance();
			trees[i]->Draw(window);
		}

		if (isInterfaceVisible)
			inter.Draw(window);

		window.display();
	}
}

void CreateEnvironment(std::vector<Animal*> &animals) {
	std::vector<Tree*> trees{};
	int amount = 0;
	amount = rand() % 5;
	amount++;
	for (unsigned int i = 0; i < animals.size(); i++) {
		Tree* newTree = new Tree(screenWidth, screenHeight);
		trees.push_back(newTree);
	}
	Draw(animals, trees);
}

void CreateAnimals() {
	int amount = 0;
	amount = rand() % 10;
	amount++;
	sf::Vector2f position;
	std::vector<Animal*> animals{};
	for (int i = 0; i <= amount; i++) {
		position.x = rand() % screenWidth;
		position.y = rand() % screenHeight;
		// Pick what animal to generate
		Animal* newAnimal = new Animal(100, position);
		animals.push_back(newAnimal);
	}
	CreateEnvironment(animals);
}

int main() {
	srand(time(0));
	CreateAnimals();


	return 0;
}