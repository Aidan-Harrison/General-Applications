#ifndef Board_h
#define Board_h

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

struct Board {
	std::vector<std::vector<sf::RectangleShape>> grid;

	sf::RectangleShape boardSpace;

	float xOffset = 0.0f, yOffset = 0.0f;

	Board() 
	{
		// It is faster to create one piece and push it back x amount of times
		// then it is setup each piece individually // DO!
		boardSpace.setSize(sf::Vector2f(50.0f, 50.0f));
		boardSpace.setOrigin(boardSpace.getSize().x / 2, boardSpace.getSize().y / 2);
		boardSpace.setFillColor(sf::Color::White);

		/*
		for (unsigned int i = 0; i < grid.size(); i++) {
			std::vector<sf::RectangleShape> boardCol;
			for (unsigned int j = 0; j < grid.size(); j++) {
				boardCol.push_back(boardSpace);
				grid.push_back(boardCol);
			}
		}
		*/

		for (unsigned int i = 0; i < grid.size(); i++) {
			for (unsigned int j = 0; j < grid[i].size(); j++) {
				grid[i][j].setSize(sf::Vector2f(5.0f, 5.0f));
				grid[i][j].setOrigin(grid[i][j].getSize().x / 2, grid[i][j].getSize().y / 2);
				grid[i][j].setFillColor(sf::Color::White);

				grid[i][j].setPosition(xOffset, yOffset);
				xOffset += grid[i][j].getSize().x + 15.0f;
			}
			yOffset += grid[i][0].getSize().y + 15.0f;
		}
	}

	void DrawBoard(sf::RenderWindow& window);

	~Board() {}
};

#endif
