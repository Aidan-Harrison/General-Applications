#include "Enemy.h"

void Enemy::GetStats() const {
	// Prints stats
	std::cout << m_Name << "-\n";
	std::cout << "Health: " << m_Health << '\n';
	std::cout << "Damage: " << m_Damage << '\n';
	putchar('\n');
}

void Enemy::TakeDamage(const short damage, sf::RenderWindow &window) {
	sf::Text text;
	text.setString(std::to_string(damage));
	m_Health -= damage;
	if (m_Health <= 0) {
		m_Health = 0;
		isDead = true;
	}
	window.draw(text);
}

void Enemy::Draw(sf::RenderWindow &window) {
	window.draw(body);
}

void Enemy::SetPosition(float x, float y) {
	body.setPosition(x,y);
}