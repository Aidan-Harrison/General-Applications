#include "Hero.h"
#include "Map.h"

#include <iostream>
#include <vector>
#include <ctime>

void Shop();
void Roshan(std::vector<Hero> &team, Map &m);

Map map;

void Setup() {
	int memberToAdd = 0;
	std::vector<Hero> team; // Possibly make global
}

int main() {
	Hero brewmaster{"Brewmaster", 500, 200, 50, 275, 400};
	std::cout << brewmaster.GetName();
	brewmaster.PrintStats();
	brewmaster.PrintInventory();

	Setup();
	return 0;
}