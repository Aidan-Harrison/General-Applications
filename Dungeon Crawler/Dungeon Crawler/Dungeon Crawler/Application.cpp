#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Dungeon.h"

Player player;
Chest chest; // Randomize items?
Dungeon dungeon;

int main() {
	bool gameOver = false;
	std::vector<std::vector<char>> room{{}};
	room = dungeon.Generate();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	while(!gameOver) {
		dungeon.Draw(room, player, chest);
		player.Input();
		player.Logic();
	}

	return 0;
}