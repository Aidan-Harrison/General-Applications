#ifndef VendingMachine_h
#define VendingMachine_h

class Machine {
private:
    unsigned short stock;
public:
    Machine(unsigned short stock);
    ~Machine();
    void Fill(const unsigned int quantity);
    void Sell(const unsigned int quantity);
    short GetStock() const { return stock; }

    // States | Possibly move to its own class
};

#endif