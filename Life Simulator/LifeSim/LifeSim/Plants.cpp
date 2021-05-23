#include "Plant.h"

void Plant::Advance() {
	age++;
	if (age > 15)
		rotten = true;
}