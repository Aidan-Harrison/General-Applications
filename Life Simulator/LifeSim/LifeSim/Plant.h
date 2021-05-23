#ifndef Plant_h
#define Plant_h

class Plant {
private:
	short age = 0;
	bool rotten = false;
public:
	short x_Coord = 0, y_Coord = 0;
	char symbol = 'T'; // Optimise? * or &
	Plant(char sym, const short x, const short y) 
		:symbol(sym), x_Coord(x), y_Coord(y)
	{
	}
	void Advance();

	~Plant() = default;
};

#endif