#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <thread>

#include "Animal.h"
#include "Plant.h"
#include "map.h"

bool isSimulating = false;
short animalSize = 0;

void Simulate(std::vector<Animal> &animals, std::vector<Plant> &plants);

void Interface(const std::vector<Animal> &animals) {
	std::cout << "Pick an animal to view:\n";
	short inputX = 0, inputY = 0;
	std::cin >> inputX >> inputY;
}

// Solve way to render multiple at once with the ability to scale, else do SFML
void Draw(std::vector<Animal> &animals, std::vector<Plant> &plants) {
	while(isSimulating) {
		system("cls");
		std::cout << "=====LIFE SIM=====\n";
		for (int i = 0; i < mapTest.size(); i++) {
			for (int j = 0; j < mapTest[0].size(); j++) {
				// Animals
				if (animals[0].y_Coord == i && animals[0].x_Coord == j) putchar(animals[0].symbol);
				else if (animals[1].y_Coord == i && animals[1].x_Coord == j) putchar(animals[1].symbol);
				else if (animals[2].y_Coord == i && animals[2].x_Coord == j) putchar(animals[2].symbol);
				else if (animals[3].y_Coord == i && animals[3].x_Coord == j) putchar(animals[3].symbol);
				else if (animals[4].y_Coord == i && animals[4].x_Coord == j) putchar(animals[4].symbol);
				else if (animals[5].y_Coord == i && animals[5].x_Coord == j) putchar(animals[5].symbol);
				else if (animals[6].y_Coord == i && animals[6].x_Coord == j) putchar(animals[6].symbol);
				else if (animals[7].y_Coord == i && animals[7].x_Coord == j) putchar(animals[7].symbol);
				// Plants
				else if (plants[0].y_Coord == i && plants[0].x_Coord == j) putchar(plants[0].symbol);
				else if (plants[1].y_Coord == i && plants[1].x_Coord == j) putchar(plants[1].symbol);
				else if (plants[2].y_Coord == i && plants[2].x_Coord == j) putchar(plants[2].symbol);
				else if (plants[3].y_Coord == i && plants[3].x_Coord == j) putchar(plants[3].symbol);
				else
					std::cout << mapTest[i][j];
			}
			putchar('\n');
			animalSize++;
			if (animalSize == animals.size())
				animalSize = 0;
		}
		std::cout << "PRESS ENTER TO PAUSE\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Allow for input per tick, threading????
		Simulate(animals, plants);
	}
}

void Simulate(std::vector<Animal> &animals, std::vector<Plant> &plants) { // Handles logic
	for (int i = 0; i < animals.size(); i++) {
		animals[i].Logic();
		animals[i].AdvanceAge();
		animals[i].Movement(mapTest, *animals[i].CheckRadius(mapTest));
	}
	for (int i = 0; i < plants.size(); i++) {
		plants[i].Advance();
	}
	Draw(animals, plants);
}

void Setup() {
	std::array<char, 4> plantChars{'T', 'B', 'S', 'b'};
	std::vector<Animal> animals{};
	std::vector<Plant> plants{};
	short amount = 7;
	short index = 0;
	for (int i = 0; i <= amount; i++) {
		index = rand() % 3;
		index++;
		switch (index) {
			case 1: { Animal* a = new Animal(); animals.push_back(*a); break; } // Generic
			case 2: { Fox* f    = new Fox();    animals.push_back(*f); break; }
			case 3: { Rabbit* r = new Rabbit(); animals.push_back(*r); break; }
		}
	}
	for (int i = 0; i <= 4; i++) {
		amount = rand() % 20;
		char character = rand() % plantChars.size();
		Plant* p = new Plant{plantChars[character], amount, amount};
		plants.push_back(*p);
	}

	isSimulating = true;
	Simulate(animals, plants);
}