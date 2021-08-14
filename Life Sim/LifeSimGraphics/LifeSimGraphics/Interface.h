#ifndef Interface_h
#define Interface_h

#include "Animal.h"

struct Interface { // Make singleton
private:
	sf::Font font;
public:
	float yOffset = 35.0f;
	sf::RectangleShape rect;
	std::vector<sf::Text> stats{};

	Interface(const int sWidth, const int sHeight) 
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font for INTERFACE\n";

		rect.setSize(sf::Vector2f((float)sWidth / 3, (float)sHeight));
		rect.setOrigin(0.0f, 0.0f);
		rect.setPosition(0.0f, 0.0f);
		rect.setFillColor(sf::Color(105, 105, 105, 255));

		stats.resize(3);
		for (auto i : stats)
			i.setFont(font);
	}

	void Update(int sWidth, int sHeight, Animal &a);
	void Draw(sf::RenderWindow &window);

	~Interface() {}
};

#endif
