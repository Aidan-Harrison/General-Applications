#include "Chest.h"

void Chest::Spawn(const short x, const short y) {
	chestX = rand() % x;
	chestX = rand() % y;
}