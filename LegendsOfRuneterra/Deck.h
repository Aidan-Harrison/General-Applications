#ifndef Deck_h
#define Deck_h

#include "Card.h"
#include <vector>
#include <array>

class Deck {
private:
    std::string deckName = "";
public:
    int top = 40; // Move from class?
    std::array<Card*, 40> cards{};
    Deck(const std::string &name) 
        :deckName(name)
    {
    }

    Card* Draw();
    void Add(Card *c);
    void PrintDeck() const;
    std::string GetName() const;

    ~Deck() {}
};

Card* Deck::Draw() {
    Card* card = cards[top-1];
    top--;
    return card;
}

void Deck::Add(Card *c) {
    top++;
    cards[top] = c;
}

void Deck::PrintDeck() const {
    for(auto i : cards) {
        std::cout << i->GetName();
    }   
}

std::string Deck::GetName() const {
    return deckName;
}

#endif