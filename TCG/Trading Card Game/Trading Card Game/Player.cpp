#include "Player.h"

void Player::DrawCard() {
	switch (hand.size()) {
	case 0: break;
	}
}

void Player::DrawHand(sf::RenderWindow &window) {
	if (hand.size() == 7)
		return;
	else {
		for (int i = 0; i <= hand.size(); i++) {
			hand[i].Draw(window);
		}
	}
}

void Player::Redraw(sf::RenderWindow &window) {
	DrawHand(window);
}