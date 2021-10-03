#ifndef SubClass_h
#define SubClass_h

class SubClass {
private:
public:
    SubClass() {}
    // 3 sets of options
    enum SETS{POWER = 1, UTILITY, DEFENCE};
    std::string subClassName = "";
    int curSubSet = 0;

    ~SubClass() {}
};

#endif