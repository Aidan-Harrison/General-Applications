#ifndef Items_h
#define Items_h

#include <iostream>
#include <vector>
#include <fstream>

class Items {
private:
    static int m_ItemIndex; // Unique only | Possibly not needed
public:
    Items *scrap; // Test
    int m_RandomItem = 0;
    Items() = default;
   ~Items() = default;
    // Items | Do it via file streaming | Allow users to add or remove items?
    std::string whiteItems[6]{"Soldiers Syringe", "Tougher Times", "Lens Maker Glasses", "Topaz Brooch", "Crowbar", "Bustling Fungus"};
    std::string greenItems[6]{"ATG Missle MK.2", "Ukele", "Preadtors Instinct", "Red Whip", "Infusion", "Will-O-Wisp"};
    std::string redItems[6]{"Brilliant Behemoth", "Soulbound Catalyst", "Aegis", "57 Leaf Clover", "Rejuvation Rack", "Resonance Disc"};
    std::string lunarItems[3]{"Shaped Glass", "Beads of Fealty", "Transcendence"};
    std::string equipment[4]{"Sawmerang", "Primordial Cube", "Royal Capacitor", "Preon Accumulator"};
};

#endif