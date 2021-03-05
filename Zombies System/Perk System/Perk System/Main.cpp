#include "Player.h"
#include <ctime>

Player player;
void Interface();

void RollPerk() {
	system("cls");
	short input = 0;
	std::cout << "Current Points: " << player.points << '\n';
	std::cout << "Pick a perk:\n" <<
				 "1) Quick-Revive(500)  2) Juggernaut(2500)  3) Speed-Cola(3000)  4) Double-Tap(2000)  5) Mule-Kick(4000)  6) Widows-Wine(3500)  7) Stamina-Up(2500)";
	std::cin >> input;
	if(input == 1 && player.points >= 500)		 player.AddPerk(1);
	else if(input == 2 && player.points >= 2500) player.AddPerk(2);
	else if(input == 3 && player.points >= 2000) player.AddPerk(3);
	else if(input == 4 && player.points >= 3000) player.AddPerk(4);
	else if(input == 5 && player.points >= 4000) player.AddPerk(5);
	else if(input == 6 && player.points >= 3500) player.AddPerk(6);
	else if(input == 7 && player.points >= 2500) player.AddPerk(6);
	else std::cout << "You do not have enough points for "; // Add perk name
	for(unsigned int i = 0; i < player.perkInventory.size(); i++) {
		if(player.perkInventory[i].perkName == "Quick Revive")	  player.canSelfRevive = true;
		else if(player.perkInventory[i].perkName == "Juggernaut") player.m_Health * 2;
		else if(player.perkInventory[i].perkName == "Double-Tap") player.m_Damage * 2;
		else if(player.perkInventory[i].perkName == "Speed-Cola") player.m_ReloadSpeed * 2;
		else if(player.perkInventory[i].perkName == "Mule-Kick")  player.maxWeapons = 3;
		else if(player.perkInventory[i].perkName == "Stamina-Up") player.m_Stamina * 2;
	}
	std::cin.get();
	Interface();
}

void MysteryBox() {
	if(player.points >= 950 && player.weaponInventory.size() != player.maxWeapons) {
		player.points -= 950;
		srand(time(0));
		int weapon = 0;
		weapon = rand() % 5;
		player.AddWeapon(weapon);
	}
	else std::cout << "You don't have enough points or you are already at max weapons!";
	std::cin.get();
	std::cin.get();
	Interface();
}

void PackAPunch() {
	if(player.weaponInventory.size() == 0) {
		std::cout << "You have no weapons to Pack-A-Punch!\n";
		std::cin.get();
		std::cin.get();
		Interface();
	}
	else {
		Weapon newWeapon;
		std::string wepChoice = " ";
		std::cout << "What weapon would you like to Pack-A-Punch:\n"; std::cin >> wepChoice;
		for(unsigned int i = 0; i < player.weaponInventory.size(); i++) {
			if(wepChoice == player.weaponInventory[i].wepName) {
				newWeapon.wepName = "Pack-A-Punched " + player.weaponInventory[i].wepName;
				newWeapon.m_Damage = player.weaponInventory[i].m_Damage * 2;
				newWeapon.m_Ammo = player.weaponInventory[i].m_Ammo * 2;
				player.weaponInventory[i].DeleteWeapon(&player.weaponInventory[i]);
			}
		}
		player.weaponInventory.push_back(newWeapon);
	}
	Interface();
}

void GobbleGum() {
	srand(time(0));
	int gum = 0;
	gum = rand() % 3;
	player.AddGum(gum);
	for(unsigned int i = 0; i < player.gumInventory.size(); i++) {
		if (player.gumInventory[i].m_Name == "Perk-A-Holic")       player.m_MaxPerkCount = 7;
		else if (player.gumInventory[i].m_Name == "Fast-Hands")    player.m_ReloadSpeed = 20;
		else if (player.gumInventory[i].m_Name == "Avoid-Zombies") player.isInvisible = true;
	}
	Interface();
}

void Interface() {
	system("cls");
	short input = 0;
	std::cout << "Zombie's System:\n" <<
				 "Pick an option | 1) Perk  2) Mystery Box  3) Pack-A-Punch  4) Gobble-Gum  5) Print Stats"; 
	std::cin >> input;
	switch(input) {
		case 1: RollPerk();			 break;
		case 2: MysteryBox();		 break;
		case 3: PackAPunch();		 break;
		case 4: GobbleGum();	     break;
		case 5: player.PrintStats(); break;
	}
}

int main() {
	std::cout << "How many points would you like to start with? (Defaults to 500) "; std::cin >> player.points;
	Interface();
	return 0;
}