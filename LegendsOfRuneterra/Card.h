#ifndef Card_h
#define Card_h

#include <iostream>

class Card {
protected:
    enum REGION{SHADOWISLES, DEMACIA, NOXUS, SHURIMA, PILTZAUN, BANDLECITY, TARGON, FREJLORD, IONIA, BILGEWATER};
private:
    std::string cardName = "Default";
    enum TYPE{STANDARD, SPELL, CHAMPION};
    enum SPELLTYPE{SLOW, FAST, BURST};
public:
    int type = 0;
    int spellType = 0;
    int region = 0;
    int cardCost = 1;
    int cardPower = 1;
    int cardToughness = 1;
    Card(const std::string &name, const int cost, const int power, const int toughness) 
        :cardName(name), cardCost(cost), cardPower(power), cardToughness(toughness)
    {
    }

    std::string GetName() const;

    ~Card() 
    {
        std::cout << "Card Destroyed!\n";
    }
};

std::string Card::GetName() const {
    return cardName;
}

// Avoid, going to get messy if so
class Spell : public Card {
private:
    enum type{SLOW, FAST, BURST};
public:

};

#endif