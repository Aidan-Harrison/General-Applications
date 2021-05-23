#include "Player.h"

void Player::Move(sf::RenderWindow &window) { // Fix movement, movement speed is whack | Delta?
	sf::Event event;
	while (window.pollEvent(event)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			m_Stamina -= 0.5f;
			movementSpeed = 12.0f;
			isSprinting = true;
		}
		else
			isSprinting = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			body.move(0.0f, -movementSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			body.move(0.0f, movementSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			body.move(-movementSpeed, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			body.move(movementSpeed, 0.0f);
	}
	if (!isSprinting) {
		m_Stamina += 0.01f;
		if (m_Stamina >= 100.0f)
			m_Stamina = 100.0f;
	}
}

void Player::DrawUI(sf::RenderWindow &window) {
	window.draw(health);
	window.draw(healthValue);
	window.draw(stamina);
	staminaValue.setString(std::to_string((int)m_Stamina));
	window.draw(staminaValue);
}