#ifndef ItemList_h
#define ItemList_h

#include "Items.h"
#include <vector>

// Sort deletion, auto_ptr
namespace ItemList {
	struct WhiteItems {
		Items *Soldiers_Syringe = new Items(1, "Soldiers Syringe");
		Items *Tougher_Times = new Items(2, "Tougher Times");
		Items *Lens_Maker_Glasses = new Items(3, "Lens Maker Glasses");
		Items *Topaz_Brooch = new Items(4, "Topaz Brooch");
		Items *Crowbar = new Items(5, "Crowbar");
		Items *Bustling_Fungus = new Items(6, "Bustling Fungus");
		Items *whiteItemsArray[6]{Soldiers_Syringe, Tougher_Times, Lens_Maker_Glasses, Topaz_Brooch, Crowbar, Bustling_Fungus};
	};

	struct GreenItems {
		Items *ATG_Missle_MK2 = new Items(7, "ATG Missle MK.2");
		Items *Ukele = new Items(8, "Ukele");
		Items *Preadator_Instinct = new Items(9, "Predators Instinct");
		Items *Red_Whip = new Items(10, "Red Whip");
		Items *Infusion = new Items(11, "Infusion");
		Items *Will_O_Wisp = new Items(12, "Will-O-Wisp");
		Items *greenItemsArray[6]{ATG_Missle_MK2, Ukele, Preadator_Instinct, Red_Whip, Infusion, Will_O_Wisp};
	};

	struct RedItems {
		Items *Brilliant_Behemoth = new Items(13, "Brilliant Behemoth");
		Items *Soulbound_Catalyst = new Items(14, "Soulbound Catalyst");
		Items *Aegis = new Items(15, "Aegis");
		Items *Leaf_Clover = new Items(16, "Leaf Clover");
		Items *Rejuvation_Rack = new Items(17, "Rejuvation Rack");
		Items *Resonance_Disc = new Items(18, "Resonance Disc");
		Items *redItemsArray[6]{Brilliant_Behemoth, Soulbound_Catalyst, Aegis, Leaf_Clover, Rejuvation_Rack, Resonance_Disc};
	};

	struct LunarItems {
		Items *Shaped_Glass = new Items(19, "Shaped Glass");
		Items *Beads_of_Fealty = new Items(20, "Beads of Fealty");
		Items *Transcendence = new Items(21, "Transcendence");
		Items *lunarItemsArray[3]{Shaped_Glass, Beads_of_Fealty, Transcendence};
	};

	struct Equipment {
		Items *Sawmerang = new Items(22, "Sawmerang");
		Items *Primordial_Cube = new Items(23, "Primordial Cube");
		Items *Royal_Capacitor = new Items(24, "Royal Capacitor");
		Items *Preon_Accumulator = new Items(25, "Preon Accumulator");
		Items *equipmentArray[4]{Sawmerang, Primordial_Cube, Royal_Capacitor, Preon_Accumulator};
	};
}

#endif