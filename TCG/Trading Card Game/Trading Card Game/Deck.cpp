#include "Deck.h"

void Deck::DrawDeck(sf::RenderWindow& window) {
}

void Deck::ShuffleDeck() {
	for (unsigned int i = 0; i < deck->size(); i++) {
		// std::shuffle(deck->begin(), deck->end()); // Do!
	}
}