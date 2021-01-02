#ifndef ItemList_h
#define ItemList_h

#include "Items.h"
#include <vector>

// Resolve all control paths
namespace ItemList {
	Items* CreateWhiteItem(int index) { // Use rvalue references?
		if(index == 1) { Items Soldiers_Syringe{ 1, "Soldiers Syringe" }; return &Soldiers_Syringe; }
		else if (index == 2) { Items Tougher_Times{ 2, "Tougher Times" }; return &Tougher_Times; }
		else if (index == 3) { Items Lens_Maker_Glasses{ 3, "Lens Maker Glasses" }; return &Lens_Maker_Glasses; }
		else if (index == 4) { Items Topaz_Brooch{ 4, "Topaz Brooch" }; return &Topaz_Brooch; }
		else if (index == 5) { Items Crowbar{ 5, "Crowbar" }; return &Crowbar; }
		else if (index == 6) { Items Bustling_Fungus{6, "Bustling Fungus"}; return &Bustling_Fungus; }
	}

	Items* CreateGreenItem(int index) {
		if (index == 1) { Items ATG_Mssile_MK2{ 7, "ATG Missle MK.2" }; return &ATG_Mssile_MK2; }
		else if (index == 2) { Items Ukele{ 8, "Ukele" }; return &Ukele; }
		else if (index == 3) { Items Predator_Instinct{ 9, "Predators Instinct" }; return &Predator_Instinct; }
		else if (index == 4) { Items Red_Whip{ 10, "Red Whip" }; return &Red_Whip; }
		else if (index == 5) { Items Infusion{ 11, "Infusion" }; return &Infusion; }
		else if (index == 6) { Items Will_O_Wisp{ 12, "Will-O-Wisp" }; return &Will_O_Wisp; }
	}

	Items* CreateRedItem(int index) {
		if (index == 1) { Items Brilliant_Behemoth{ 13, "Brilliant Behemoth" }; return &Brilliant_Behemoth; }
		else if (index == 2) { Items Soulbound_Catalyst{ 14, "Soulbound Catalyst" }; return &Soulbound_Catalyst; }
		else if (index == 3) { Items Aegis{ 15, "Aegis" }; return &Aegis; }
		else if (index == 4) { Items Leaf_Clover{ 16, "57 Leaf Clover" }; return &Leaf_Clover; }
		else if (index == 5) { Items Rejuvanation_Rack{ 17, "Rejuvanation Rack" }; return &Rejuvanation_Rack; }
		else if (index == 6) { Items Resonance_Disc{ 18, "Resonance Disc" }; &Resonance_Disc; }
	}

	Items* CreateLunarItem(int index) {
		if (index == 1) { Items Shaped_Glass{ 19, "Shaped Glass" }; return &Shaped_Glass; }
		else if (index == 2) { Items Beads_Of_Fealty{ 20, "Beads of Fealty" }; return &Beads_Of_Fealty; }
		else if (index == 3) { Items Transcendence{ 21, "Transcendence" }; return &Transcendence; }
	}

	Items* CreateEquipment(int index) {
		if (index == 1) { Items Sawmerang{ 22, "Sawmerang" }; return &Sawmerang; }
		else if (index == 2) { Items Primordial_Cube{ 23, "Primordial Cube" }; return &Primordial_Cube; }
		else if (index == 3) { Items Royal_Capacitor{ 24, "Royal Capacitor" }; return &Royal_Capacitor; }
		else if (index == 4) { Items Preon_Accumulator{ 25, "Preon Accumulator" }; return &Preon_Accumulator; }
	}
}

#endif