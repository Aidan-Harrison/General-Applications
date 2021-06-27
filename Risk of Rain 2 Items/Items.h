#ifndef Items_h
#define Items_h

#include <iostream>
#include <vector>
#include <fstream>

class Items {
private:
    int m_ItemIndex;
public:
    int m_RandomItem = 0; 
    std::string m_ItemName = "", m_ItemType = "";
    //Stats
    Items(short itemIndex, std::string itemType, std::string itemName)
        :m_ItemIndex(itemIndex), m_ItemType(itemType), m_ItemName(itemName)
    {
    }
    ~Items() {};
};

#endif