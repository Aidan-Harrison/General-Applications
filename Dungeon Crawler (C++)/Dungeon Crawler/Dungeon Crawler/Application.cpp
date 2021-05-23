#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Dungeon.h"


void Draw(Player &p, Dungeon& d, Chest &c) {
	bool gameOver = false;
	bool newRoom = false;
	short newLine = 0;

	while (!gameOver) {
		system("cls");
		std::cout << "=====DUNGEON=====\n";
		for (unsigned int i = 0; i < d.width; i++) {
			for (unsigned int j = 0; j < d.height; j++) {
				if (j == p.playerX && i == p.playerY)
					putchar('P');
				else if (j == c.chestX && i == c.chestY)
					putchar('C');
				else {
					switch (d.currentRoom) {
						case 1: std::cout << d.room1[i][j]; break; // Possible flip rooms by doing j - i
						case 2: std::cout << d.room2[i][j]; break;
						case 3: std::cout << d.newRoom[i][j]; break;
					}
				}

				// Collision
				if (p.playerX == d.width)  p.playerX = d.width - 1;
				if (p.playerX == 0)	   p.playerX = 1;
				if (p.playerY == d.height) p.playerY = d.height - 1;
				if (p.playerY == 0)	       p.playerY = 1;

				// Logic
				if (p.playerX == d.doorX && p.playerY == d.doorY) {
					d.Generate(); // Picks the next room layout and adds contents
					c.Spawn(d.width, d.height);
				}
			}
			putchar('\n');
		}

		p.PrintStats();

		std::cout << "\nRoom: " << d.numOfRooms << '\n';

		p.Input();
		p.Logic();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void Generate() {
	Dungeon dungeon{}; // Calls 'Generate()'
	Chest chest{}; // Chest is reused per room;

	// Player setup
	std::array<std::string, 6> inventory1{"Key", "Armor","","","",""};
	Player player{100, inventory1};

	Draw(player, dungeon, chest);
}

int main() {
	Generate();

	return 0;
}