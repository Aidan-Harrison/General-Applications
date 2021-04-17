#include "Player.h"

Player::Player(short health)
	:m_Health(health)
{
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
}

void Player::Kill() {
	delete this;
}