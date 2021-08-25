#ifndef VendingMachine_h
#define VendingMachine_h

class Machine {
private:
    unsigned int stock;
public:
    Machine() {}
    Machine(unsigned int stock);

    void Fill(const unsigned int quantity);
    void Sell(const unsigned int quantity);
    int GetStock() const { return stock; }

    // States
    ~Machine() {};
};

#endif