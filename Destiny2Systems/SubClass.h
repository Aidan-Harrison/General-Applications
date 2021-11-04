#ifndef SubClass_h
#define SubClass_h

class SubClass {
private:
public:
    SubClass() {}
    // 3 sets of options
    enum SETS{POWER = 1, UTILITY, DEFENCE};
    std::string subClassName = "";
    std::string subClassDescription = "";
    int curSubSet = 0;

    ~SubClass() {}
};

// Get assignment working

class Solar : public SubClass {
private:
public:
    Solar() 
    {
        subClassName = "Solar";
        subClassDescription = "Solar description";
    }
    ~Solar() {}
};

class Void : public SubClass {
private:
public:
    Void() 
    {
        subClassName = "Solar";
        subClassDescription = "Solar description";
    }
    ~Void() {}
};

class Arc : public SubClass {
private:
public:
    Arc() 
    {
        subClassName = "Solar";
        subClassDescription = "Solar description";
    }
    ~Arc() {}
};

#endif