#include "Dungeon.h"

Dungeon::Dungeon() {

}

void Dungeon::Draw(std::vector<std::vector<char>> &room, Player &player, Chest &chest) {
	system("cls");
	bool newRoom = false;
	short newLine = 0;
	for(unsigned int i = 0; i < room.size(); i++) {
		for(unsigned int j = 0; j < room[i].size(); j++) { // 'j' is not changing
			if (i == player.playerX) std::cout << 'P';
			else if (i == chest.chestX) std::cout << 'C';
			else if (player.playerX == doorX && player.playerY == doorY) Generate();
			else std::cout << room[i][j];
			newLine++;
		}
		if(newLine == roomWidth) {
			std::cout << '\n';
			newLine = 0;
		}
	}
	std::cout << "Health: " << player.GetHealth() << '\n' << "Key: " << player.hasKey;
}

std::vector<std::vector<char>> Dungeon::Generate() {
	short roomPicked;
	// Pick room to draw
	srand(time(0));
	roomPicked = rand() % numOfRooms;
	if (roomPicked == 1) {
		roomWidth = 18;
		roomHeight = 9;
		doorX = 10;
		doorY = 10;
		return Room1;
	}
	return Room1;
}