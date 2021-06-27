#ifndef ItemList_h
#define ItemList_h

#include "Items.h"
#include <vector>

namespace ItemList {
	Items *EmptyItem;
	Items* CreateWhiteItem(int index) {
		if (index == 0) { Items* Soldiers_Syringe = new Items{1, "White", "Soldiers Syringe" };		    return Soldiers_Syringe; }
		else if(index == 1) { Items *Tougher_Times = new Items{2, "White", "Tougher Times"};			return Tougher_Times; }
		else if (index == 2) { Items* Lens_Maker_Glasses = new Items{3, "White", "Lens Maker Glasses" };return Lens_Maker_Glasses; }
		else if(index == 3) { Items *Topaz_Brooch = new Items{ 4, "White", "Topaz Brooch" };			return Topaz_Brooch; }
		else if(index == 4) { Items *Crowbar = new Items{ 5, "White", "Crowbar" };						return Crowbar; }
		else if(index == 5) { Items *Bustling_Fungus = new Items{ 6, "White", "Bustling Fungus"};		return Bustling_Fungus; }
		return EmptyItem;
	}
	Items* CreateGreenItem(int index) {
		if(index == 0)		{ Items *ATG_Mssile_MK2 = new Items{ 7, "Green", "ATG Missle MK.2" };	   return ATG_Mssile_MK2; }
		else if(index == 1) { Items *Ukele = new Items{ 8, "Green", "Ukele" };					       return Ukele; }
		else if(index == 2) { Items *Predator_Instinct = new Items{ 9, "Green", "Predators Instinct" };return Predator_Instinct; }
		else if(index == 3) { Items *Red_Whip = new Items{ 10,"Green", "Red Whip" };				   return Red_Whip; }
		else if(index == 4) { Items *Infusion = new Items{ 11,"Green", "Infusion" };				   return Infusion; }
		else if(index == 5) { Items *Will_O_Wisp = new Items{ 12,"Green", "Will-O-Wisp" };			   return Will_O_Wisp; }
		return EmptyItem;
	}
	Items* CreateRedItem(int index) {
		if(index == 0)		{ Items *Brilliant_Behemoth = new Items { 13, "Red", "Brilliant Behemoth" };return Brilliant_Behemoth; }
		else if(index == 1) { Items *Soulbound_Catalyst = new Items{ 14, "Red", "Soulbound Catalyst" }; return Soulbound_Catalyst; }
		else if(index == 2) { Items *Aegis = new Items{ 15, "Red", "Aegis" };					        return Aegis; }
		else if(index == 3) { Items *Leaf_Clover = new Items{ 16, "Red", "57 Leaf Clover" };		    return Leaf_Clover; }
		else if(index == 4) { Items *Rejuvanation_Rack = new Items{ 17, "Red", "Rejuvanation Rack" };   return Rejuvanation_Rack; }
		else if(index == 5) { Items *Resonance_Disc = new Items{ 18, "Red", "Resonance Disc" };		    return Resonance_Disc; }
		return EmptyItem;
	}
	Items* CreateLunarItem(int index) {
		if(index == 0)		{ Items *Shaped_Glass = new Items{ 19, "Lunar", "Shaped Glass" };	   return Shaped_Glass; }
		else if(index == 1) { Items *Beads_Of_Fealty = new Items{ 20, "Lunar", "Beads of Fealty" };return Beads_Of_Fealty; }
		else if(index == 2) { Items *Transcendence = new Items{ 21, "Lunar", "Transcendence" };	   return Transcendence; }
		return EmptyItem;
	}
	Items* CreateEquipment(int index) {
		if(index == 0)		{ Items *Sawmerang = new Items{ 22, "Equipment", "Sawmerang" };				   return Sawmerang; }
		else if(index == 1) { Items *Primordial_Cube = new Items{ 23, "Equipment", "Primordial Cube" };	   return Primordial_Cube; }
		else if(index == 2) { Items *Royal_Capacitor = new Items{ 24, "Equipment", "Royal Capacitor" };    return Royal_Capacitor; }
		else if(index == 3) { Items *Preon_Accumulator = new Items{ 25, "Equipment", "Preon Accumulator" };return Preon_Accumulator; }
		return EmptyItem;
	}

	Items* CreateScrap(std::string itemType) { // ID should always be last, Add automatic system
		if (itemType == "white")      { Items *WhiteScrap = new Items { 26, "WhiteScrap", "White Scrap" };return WhiteScrap; }
		else if (itemType == "green") { Items *GreenScrap = new Items{ 27, "WhiteScrap", "Green Scrap" }; return GreenScrap; }
		else if (itemType == "red")   { Items *RedScrap = new Items{ 28, "WhiteScrap", "Red Scrap" };	  return RedScrap; }
	}
}

#endif