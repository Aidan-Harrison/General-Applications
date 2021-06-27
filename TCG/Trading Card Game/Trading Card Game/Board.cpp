#include "Board.h"

void Board::DrawBoard(sf::RenderWindow &window) {
	for (unsigned int i = 0; i < grid.size(); i++) {
		for (unsigned int j = 0; j < grid[0].size(); j++) {
			window.draw(grid[i][j]);
		}
	}
}