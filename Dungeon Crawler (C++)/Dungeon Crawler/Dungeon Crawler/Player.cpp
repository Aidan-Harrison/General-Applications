#include "Player.h"

Player::Player(const short health, const std::array<std::string, 6> &startInvent)
	:m_Health(health)
{
	assert(m_Health != 0);
	for (int i = 0; i < 6; i++) {
		inventory[i] == startInvent[i];
	}
}

void Player::Input() {
	if(_kbhit()) {
		switch(_getch()) {
			case 'w': dir = UP;    break;
			case 's': dir = DOWN;  break;
			case 'a': dir = LEFT;  break;
			case 'd': dir = RIGHT; break;
		}
	}
}

void Player::Logic() {
	switch (dir) {
		case Player::STOP:			   break;
		case Player::UP:    playerY--; break;
		case Player::DOWN:  playerY++; break;
		case Player::LEFT:  playerX--; break;
		case Player::RIGHT: playerX++; break;
	}
	dir = STOP;
}

void Player::Kill() {
	std::cout << "You have died!\n";
	delete this;
}

void Player::PrintStats() const {
	std::cout << "Health: " << GetHealth();
	std::cout << "\nKey: " << hasKey;
	std::cout << "\nInventory:\n";
	for (unsigned int i = 0; i < 6; i++) {
		std::cout << i << ") " << inventory[i] << '\n';
	}
	std::cout << "\nPos X: " << playerX << " | " << " Pos Y: " << playerY;
}