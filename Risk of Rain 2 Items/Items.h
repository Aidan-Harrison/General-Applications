#ifndef Items_h
#define Items_h

#include <iostream>
#include <vector>
#include <fstream>

class Items {
private:
    int m_ItemIndex; // Unique only | Possibly not needed
public:
    int m_RandomItem = 0; std::string m_ItemName = "";
    //Stats
    
    Items() = default;
    Items(short itemIndex, std::string itemName) {
        m_ItemIndex = itemIndex;
        m_ItemName = itemName;
    }
   ~Items() = default;
};

#endif