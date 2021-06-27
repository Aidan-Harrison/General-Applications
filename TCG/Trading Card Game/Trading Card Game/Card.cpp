#include "Card.h"

void Card::Draw(sf::RenderWindow &window) {
	window.draw(body);
	window.draw(damageBack);
	window.draw(healthBack);
	window.draw(manaBack);
	window.draw(artBorder);
	window.draw(infoBack);
	// Information
	window.draw(healthValue);
	window.draw(manaValue);
	window.draw(damageValue);
	window.draw(m_CardName);
	// Misc
	cardTexture.update(cardArt);
	window.draw(m_Art);
}

void Card::SetPos(sf::Vector2i pos) { // Convert to floats
	body.setPosition(pos.x, pos.y);
	damageBack.setPosition(pos.x - 125, pos.y + 175);
	healthBack.setPosition(pos.x + 125, pos.y + 175);
	artBorder.setPosition(pos.x, pos.y - 80);
	manaBack.setPosition(pos.x - 125, pos.y - 160);
	infoBack.setPosition(pos.x, pos.y + 90);

	// Information
	m_CardName.setPosition(pos.x - 125, pos.y - 200);
	manaValue.setPosition(pos.x - 125, pos.y - 175);
	healthValue.setPosition(pos.x + 125, pos.y + 175);
	damageValue.setPosition(pos.x - 125, pos.y + 175);

	// Art
	m_Art.setPosition(pos.x, pos.y - 125);
}