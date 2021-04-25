#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Dungeon.h"

Player player{100};

void Draw(Dungeon& d, Player& p) {
	bool gameOver = false;
	bool newRoom = false;
	short newLine = 0;

	while (!gameOver) {
		system("cls");
		for (unsigned int i = 0; i < d.width; i++) {
			for (unsigned int j = 0; j < d.height; j++) {
				if (j == player.playerX && i == player.playerY)
					putchar('P');
				else if (j == d.chest.chestX && i == d.chest.chestY)
					putchar('C');
				else {
					switch (d.currentRoom) {
						case 1: std::cout << d.room1[i][j]; break;
						case 2: std::cout << d.room2[i][j]; break;
					}
				}

				// Collision | Fix positive X and Y
				if (player.playerX == d.width) player.playerX = 9;
				if (player.playerX == 0)	   player.playerX = 1;
				if (player.playerY == d.height)player.playerY = 9;
				if (player.playerY == 0)	   player.playerY = 1;

				// Logic | Load next room | Fix!
				if (player.playerX == d.doorX && player.playerY == d.doorY) {
					d.Generate(); // Picks the next room layout and adds contents
				}
			}
			putchar('\n');
		}

		std::cout << "Health: " << player.GetHealth()
				  << "\nKey: " << player.hasKey
				  << "Position: " << "X: " << player.playerX << " Y: " << player.playerY;
		player.Input();
		player.Logic();
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void Generate() {
	Dungeon dungeon{}; // Calls 'Generate()'
	Draw(dungeon, player);
}

int main() {
	Generate();

	return 0;
}