#include "Room.h"

void Room::CreateRoom(sf::Vector2i &pointPos) {
	float randX = 50, randY = 50;
	// randX = rand() % 10;
	// randY = rand() % 10;
	m_Room.setSize(sf::Vector2f(randX, randY));

	// Position:
	m_Room.setOrigin(pointPos.x, pointPos.y);
	m_Room.setPosition(pointPos.x, pointPos.y);

	// Points:
	left_Pos.x = m_Room.getPosition().x -m_Room.getSize().x;
	left_Pos.y = m_Room.getPosition().y;

	right_Pos.x = m_Room.getPosition().x + m_Room.getSize().x;
	right_Pos.y = 0;

	top_Pos.x = m_Room.getPosition().x;
	top_Pos.y = m_Room.getPosition().y - m_Room.getSize().y / 2;

	bottom_Pos.x = m_Room.getPosition().x;
	bottom_Pos.y = m_Room.getPosition().y + m_Room.getSize().y / 2;

	// POINT VISUALS
	leftDEBUG.setSize(sf::Vector2f(5,5));
	leftDEBUG.setOrigin(pointPos.x, pointPos.y);
	leftDEBUG.setFillColor(sf::Color::Red);
	leftDEBUG.setPosition(left_Pos.x, left_Pos.y);

	rightDEBUG.setSize(sf::Vector2f(5,5));
	rightDEBUG.setOrigin(pointPos.x, pointPos.y);
	rightDEBUG.setFillColor(sf::Color::Red);
	rightDEBUG.setPosition(right_Pos.x, right_Pos.y);

	topDEBUG.setSize(sf::Vector2f(5,5));
	topDEBUG.setOrigin(pointPos.x, pointPos.y);
	topDEBUG.setFillColor(sf::Color::Red);
	topDEBUG.setPosition(top_Pos.x, top_Pos.y);

	bottomDEBUG.setSize(sf::Vector2f(5,5));
	bottomDEBUG.setOrigin(pointPos.x, pointPos.y);
	bottomDEBUG.setFillColor(sf::Color::Red);
	bottomDEBUG.setPosition(bottom_Pos.x, bottom_Pos.y);
}

void Room::Draw(sf::RenderWindow &window) {
	window.draw(m_Room);
	window.draw(leftDEBUG);
	window.draw(rightDEBUG);
	window.draw(topDEBUG);
	window.draw(bottomDEBUG);
}

void Room::Initialise() {
	m_Room.setOrigin(m_Room.getSize().x / 2, m_Room.getSize().y / 2);
	m_Room.setPosition(sf::Vector2f(400,300));
}