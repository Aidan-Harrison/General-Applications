#include "Ally.h"

void Ally::Move(std::array<Enemy, 5> &e, sf::RenderWindow &window, sf::Event &event) {
	sf::Text info;
	std::cout << m_Name << "-\n";
	info.setString("Pick an action\n A) Attack  S) Spell  U) Use Item\n");
	window.draw(info);
	while(window.pollEvent(event)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			Attack(e, window);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			Spell(e);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
			UseItem();
	}
}

void Ally::Attack(std::array<Enemy, 5> &enemies, sf::RenderWindow &window) { // Check size
	int choice = 0;
	std::cout << "Pick a target";
	std::cin >> choice;
	if (choice == 1) {
		enemies[0].TakeDamage(m_Damage, window);
		// Add damage values
		// Add animation system | Interpolate | Change sprites | Use setPos func instead
		body.setPosition(enemies[0].body.getPosition().x, enemies[0].body.getPosition().y);
	}
	else if (choice == 2) {
		enemies[1].TakeDamage(m_Damage, window);
		body.setPosition(enemies[1].body.getPosition().x, enemies[1].body.getPosition().y);
	}
	else if (choice == 3) {
		enemies[2].TakeDamage(m_Damage, window);
		body.setPosition(enemies[2].body.getPosition().x, enemies[2].body.getPosition().y);
	}
	else if (choice == 4) {
		enemies[3].TakeDamage(m_Damage, window);
		body.setPosition(enemies[3].body.getPosition().x, enemies[3].body.getPosition().y);
	}
	else if (choice == 5) {
		enemies[4].TakeDamage(m_Damage, window);
		body.setPosition(enemies[4].body.getPosition().x, enemies[4].body.getPosition().y);
	}
}

void Ally::TakeDamage(const int damage, sf::RenderWindow &window) {
	sf::Text text;
	text.setString(std::to_string(m_Damage));
	m_Health -= damage;
	if (m_Health <= 0) {
		m_Health = 0;
		isDead = true;
	}
	window.draw(text); // Animate!
}

void Ally::Draw(sf::RenderWindow &window) {
	window.draw(body);
}

void Ally::SetPosition(float x, float y) {
	body.setPosition(x,y);
}

void Ally::Spell(std::array<Enemy, 5>& enemies) {
	int choice = 0;
	std::cout << "Pick a spell";
	std::cin >> choice;
	std::tolower(choice);
	switch (choice) {
		case 1: spells[0].Use(); break;
		case 2:	spells[1].Use(); break;
		case 3:	spells[2].Use(); break;
	}
}

void Ally::UseItem() {
	int choice = 0;
	std::cout << "Pick an item";
	std::cin >> choice;
	switch(choice) {
		case 1: inventory[0].Use(); itemStacks[0]--; break;
		case 2: inventory[1].Use(); itemStacks[1]--; break;
		case 3: inventory[2].Use(); itemStacks[2]--; break;
		case 4: inventory[3].Use(); itemStacks[3]--; break;
		case 5: inventory[4].Use(); itemStacks[4]--; break;
	}
	std::cout << "Pick an ally";
	std::cin >> choice;
}

// Support spells
void Heal::Use(std::array<Ally, 2> &allies, std::array<Enemy, 5> &enemies) {
	int choice = 0;
	std::cout << "Pick an ally to heal:\n";
	switch (choice) {
		case 1: allies[0].m_Health += amountToHeal; break;
		case 2: allies[1].m_Health += amountToHeal; break;
	}
}

void Cleanse::Use(std::array<Ally, 2>& allies, std::array<Enemy, 5>& enemies) {
	int choice = 0;
	std::cout << "Pick an ally to cleanse:\n";

}

void Armor::Use(std::array<Ally, 2>& allies, std::array<Enemy, 5>& enemies) {

}

// Damage spells
void Fireball::Use(std::array<Ally, 2>& allies, std::array<Enemy, 5>& enemies) {
	int choice = 0;
	std::cout << "Pick an enemy to attack:\n";
	switch(choice) {
		case 1: enemies[0].m_Health -= damageToDeal; break;
		case 2: enemies[1].m_Health -= damageToDeal; break;
		case 3: enemies[2].m_Health -= damageToDeal; break;
		case 4: enemies[3].m_Health -= damageToDeal; break;
		case 5: enemies[4].m_Health -= damageToDeal; break;
	}
}

void Explosion::Use(std::array<Ally, 2>& allies, std::array<Enemy, 5>& enemies) {
	for (unsigned int i = 0; i < enemies.size(); i++) {
		enemies[i].m_Health -= damageToDeal;
	}
}

void Blizzard::Use(std::array<Ally, 2>& allies, std::array<Enemy, 5>& enemies) {
}
