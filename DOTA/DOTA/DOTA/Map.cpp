#include "Map.h"

void Map::MapSetup() {
	return;
}

void Map::GetTime() {
	if (minutes % 5 == 0)
		if (!isNight)
			isNight = true;
		else
			isNight = false;
	switch (isNight) {
		case false: std::cout << "It is currently DAY\n"; break;
		case true: std::cout << "It is currently NIGHT\n"; break;
	}
}