#include "Dungeon.h"

Dungeon::Dungeon() {
	//Generate();
}

void Dungeon::Generate() {
	srand(time(0));
	short genVal = 1;
	previousRoom = genVal;
	genVal = rand() % 4;
	while (genVal == previousRoom) // Prevent previous room from occuring again
		genVal = rand() % 4;
	if (genVal == 1) {
		width = 10;
		height = 10;
		doorX = 7;
		doorY = 6;
		currentRoom = 1;
	}
	else if (genVal == 2) {
		width = 20;
		height = 15;
		doorX = 7;
		doorY = 2;
		currentRoom = 2;
	}
	else if (genVal == 3) {
		width = 25;
		height = 5;
		doorX = 24;
		doorY = 2;
		currentRoom = 3;
	}
	numOfRooms++;
}