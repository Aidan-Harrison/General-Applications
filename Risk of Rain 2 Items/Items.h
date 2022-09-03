#ifndef Items_h
#define Items_h

#include <iostream>
#include <vector>
#include <fstream>

class Items {
private:
    int m_ItemIndex;
public:
    enum RARITY{WHITE, GREEN, UNIQUE, LUNAR, EQUIPMENT};
    int m_RandomItem = 0, m_ItemType = WHITE;
    std::string m_ItemName = "";
    //Stats
    Items()
        :m_ItemIndex(-1), m_ItemName("DEFAULT ITEM"), m_ItemType(WHITE)
    {
    }
    Items(const int itemIndex, const int itemType, const std::string && itemName)
        :m_ItemIndex(itemIndex), m_ItemType(itemType), m_ItemName(itemName)
    {
    }
    ~Items() {};
};

#endif