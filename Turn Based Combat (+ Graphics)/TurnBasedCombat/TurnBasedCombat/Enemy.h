#ifndef Enemy_h
#define Enemy_h

#include <iostream>
#include <cassert>

#include <SFML/Graphics.hpp>

class Enemy {
private:
	sf::Text name;
public:
	sf::RectangleShape body;
	std::string m_Name = ""; // Possibly remove?
	short m_Health = 250;
	short m_Damage = 50;
	bool isDead = false;
	Enemy(const std::string &name = "Enemy", const short baseHealth = 250, const short damage = 50)
		:m_Name(name), m_Health(baseHealth), m_Damage(damage)
	{
		assert(m_Health > 25 && m_Damage > 0);
		
		body.setFillColor(sf::Color::Red);
		body.setSize(sf::Vector2f(25.0f,25.0f));
	}
	~Enemy() = default;
	void GetStats() const;
	void TakeDamage(const short damage, sf::RenderWindow &window);

	void Draw(sf::RenderWindow &window);

	void SetPosition(float x, float y);
};

#endif