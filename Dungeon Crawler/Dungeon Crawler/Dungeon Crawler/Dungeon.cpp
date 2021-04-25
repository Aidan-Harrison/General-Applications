#include "Dungeon.h"

Dungeon::Dungeon() {
	Generate();
}

void Dungeon::Generate() {
	short genVal = 0;
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
		currentRoom = 2;
	}
}