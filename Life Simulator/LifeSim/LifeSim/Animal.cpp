#include "Animal.h"

void Animal::PrintStats() {

}

void Animal::GetState() {

}

void Animal::CalculateState() { // Take into account tiredness and hunger
	if (m_Health <= 0)
		m_State = DEAD;
	else if (m_Health < 15 && m_Health > 0 || hunger <= 10)
		m_State = DYING;
	else if (m_Health < 30 && m_Health > 15 || hunger < 25 && hunger > 10)
		m_State = INJURED;
	else if (m_Health < 45 && m_Health > 30 || hunger > 25 && hunger <= 50)
		m_State = NORMAL;
	else if (m_Health <= 75 && m_Health > 45 || hunger > 50 && hunger <= 80)
		m_State = HEALTHY;
	else if (m_Health > 75 && hunger > 80)
		m_State = FRIVING;
}

void Animal::AdvanceAge() {
	age += 0.1f;
	if (age < 2) {
		m_Maturity = BABY;
		m_Damage = 5;
	}
	else if (age > 2 && age < 18) {
		m_Maturity = TEEN;
		m_Damage = 15;
	}
	else {
		m_Maturity = ADULT;
		m_Damage = 25;
	}
}

void Animal::TakeDamage(const short damage) {
	m_Health -= damage;
	CalculateState();
}

void Animal::Attack() {
	prey->TakeDamage(m_Damage);
}

void Animal::Logic() {
	hunger--;
	tiredness++;
	CalculateState();
}

void Animal::Movement(std::array<std::array<char, 20>, 20> &m, std::tuple<short, short> &pos) {
	if(isHunting) {
		x_Coord = std::get<0>(pos) - 1;
		y_Coord = std::get<1>(pos) - 1;
	}
	short movement = rand() % 5;
	switch (movement) {
		case 0: break; // No movement
		case 1: x_Coord--; break;
		case 2: x_Coord++; break;
		case 3: y_Coord--; break;
		case 4: y_Coord++; break;
	}

	if (x_Coord == 0)
		x_Coord++;
	else if(x_Coord == 19)
		x_Coord--;

	if (y_Coord == 0)
		y_Coord++;
	else if (y_Coord == 19)
		y_Coord--;
}

std::tuple<short,short>* Animal::CheckRadius(std::array<std::array<char, 20>, 20> &m) { // Add detection radius and prey | Fix std::array via ref
	// Detection rad
	for (int i = y_Coord; i < detectionRadius; i++) {
		for (int j = x_Coord; j < detectionRadius; j++) {
			// if(m[i][j] == detectValue && diet == HERBIVORE) // Check!?!?!??!??
				// return; // Chance to eat plant
		}
	}

	if (prey != nullptr) {
		if (x_Coord++ == prey->x_Coord && y_Coord++ == prey->y_Coord) {
			isHunting = true;
			std::tuple<short, short> preyPos(prey->x_Coord, prey->y_Coord);
			return &preyPos;
		}
	}
	else {
		std::tuple<short, short> def(0, 0);
		return &def;
	}
}

// Fox
void Fox::Attack() {

}