#ifndef Animal_h
#define Animal_h

#include <iostream>
#include <tuple>

class Animal {
private:
	const std::string m_Name = "";
	short m_Health = 100, m_Damage = 25;
	short hunger = 100;
	short tiredness = 100;
	enum STATE {DEAD = 1, DYING, INJURED, NORMAL, HEALTHY, FRIVING };
	enum MATURITY {BABY = 1, TEEN, ADULT };
	short m_State = 3, m_Maturity = 3;
	char detectValue = 0;
	float age = 1.0f;
	Animal *prey;
	bool isPredator = true; // If false, must be prey
	short detectionRadius; // Calculate radius around animal
public:
	char symbol = 'A';
	enum DIET {CARNIVORE = 1, HERBIVORE, OMNIVORE};
	short diet = CARNIVORE;
	short x_Coord = 0, y_Coord = 0;
	bool isHunting = false;
	Animal(const std::string &name = "Fenrir", const char symbol = 'A', short xCoord = 5, short yCoord = 5)
		:m_Name(name), x_Coord(xCoord), y_Coord(yCoord), symbol(symbol)
	{
	}

	~Animal() = default;

	void PrintStats();
	void CalculateState();
	void GetState(); 
	void AdvanceAge(); // Calculates maturity
	void Logic();
	void TakeDamage(const short damage);
	virtual void Attack();
	std::tuple<short,short>* CheckRadius(std::array<std::array<char, 20>, 20> &m);
	void Movement(std::array<std::array<char, 20>, 20> &m, std::tuple<short, short>& pos);
};

class Fox : public Animal {
private:
public:
	Fox()
		:Animal("Fenrir", 'F')
	{
	}
	void Attack();
};

class Rabbit : public Animal {
private:
	short diet = HERBIVORE;
public:
	Rabbit()
		:Animal("Fenrir", 'R')
	{
	}
};

#endif