#ifndef Card_h
#define Card_h

#include <iostream>
#include <SFML/Graphics.hpp>

class Card {
private:
	// Base
	sf::RectangleShape body;
	sf::RectangleShape damageBack;
	sf::RectangleShape healthBack;
	sf::RectangleShape infoBack;
	sf::RectangleShape artBorder;
	sf::RectangleShape manaBack;
	sf::Texture cardTexture;
	sf::Image cardArt;
	sf::Sprite m_Art;
	// Values
	sf::Font font;
	sf::Text m_CardName;
	sf::Text cardType;
	sf::Text manaCost;
	sf::Text healthValue;
	sf::Text damageValue;
	sf::Text manaValue;
	sf::Vector2f size{ 250.0f, 350.0f };
	enum CARDTYPE {MYSTICAL = 1, MECHANICAL, DARK, HOLY};
	short m_Type = 0; // ID
	short m_ManaCost = 0;
	short m_Health = 1;
	short m_Damage = 1;
public:
	Card(const short type = 1, const short mana = 1, const short health = 1, const short damage = 1, const std::string &filePath = "Images/shatteredPlains.jpeg",
		const std::string &cardName = "Shattered Plains")
		:m_ManaCost(mana), m_Health(health), m_Damage(damage)
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";
		if (!cardTexture.loadFromFile(filePath))
			std::cerr << "Failed to load image!\n";

		cardArt.loadFromFile(filePath);
		m_Art.setTexture(cardTexture);
		m_Art.setScale(0.1f,0.1f); // Match to art border size

		m_CardName.setFont(font);
		cardType.setFont(font);
		manaCost.setFont(font);
		healthValue.setFont(font);
		manaValue.setFont(font);

		switch(type) {
			case 1: m_Type = MYSTICAL; cardType.setString("Mystical"); break;
			case 2: m_Type = MECHANICAL; cardType.setString("Mechanical"); break;
			case 3: m_Type = DARK; cardType.setString("Dark"); break;
			case 4: m_Type = HOLY; cardType.setString("Holy"); break;
		}

		// Text
		m_CardName.setFont(font);
		cardType.setFont(font);
		manaCost.setFont(font);
		healthValue.setFont(font);
		damageValue.setFont(font);
		manaValue.setFont(font);

		m_CardName.setString(cardName);
		healthValue.setString(std::to_string(health));
		manaValue.setString(std::to_string(mana));
		damageValue.setString(std::to_string(damage));

		body.setSize(size);
		body.setOrigin(125.0f, 175.0f);
		body.setPosition(200.0f, 800.0f);

		// Damage
		damageBack.setSize(sf::Vector2f(35.0f,35.0f));
		damageBack.setOrigin(17.5f, 17.5f);
		damageBack.setPosition(body.getOrigin().x - 125, body.getOrigin().y + 175);
		damageBack.setFillColor(sf::Color::Green);

		// Health
		healthBack.setSize(sf::Vector2f(35.0f,35.0f));
		healthBack.setOrigin(17.5f, 17.5f);
		healthBack.setPosition(body.getOrigin().x + 125, body.getOrigin().y + 175);
		healthBack.setFillColor(sf::Color::Red);

		// Mana
		manaBack.setSize(sf::Vector2f(35.0f, 35.0f));
		manaBack.setOrigin(17.5f, 17.5f);
		manaBack.setPosition(body.getOrigin().x - 125, body.getOrigin().y - 160);
		manaBack.setFillColor(sf::Color::Blue);

		// Art Border
		artBorder.setSize(sf::Vector2f(215.0f, 175.0f));
		artBorder.setOrigin(107.5f, 87.5f);
		artBorder.setPosition(body.getOrigin().x, body.getOrigin().y - 30);
		artBorder.setFillColor(sf::Color::Black);

		// Info
		infoBack.setSize(sf::Vector2f(225.0f, 125.0f));
		infoBack.setOrigin(112.5f, 62.5f);
		infoBack.setPosition(body.getOrigin().x, body.getOrigin().y + 125);
		infoBack.setFillColor(sf::Color::Black);

		// Image
		m_Art.setOrigin(0.5f, 0.5f);
		m_Art.setPosition(sf::Vector2f(body.getOrigin().x, body.getOrigin().y - 30));
	}

	short GetType() const { return m_Type; }
	short GetMana() const { return m_ManaCost; }
	short GetHealth() const { return m_Health; }
	short GetDamage() const { return m_Damage; }

	void Draw(sf::RenderWindow &window);
	void SetPos(sf::Vector2i pos);

	~Card() = default;
};

#endif

