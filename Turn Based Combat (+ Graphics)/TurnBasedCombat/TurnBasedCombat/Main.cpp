#include <iostream>
#include <tuple>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Team.h"

// Turn system
short turn = 0;
bool allyTurn = false;

short screenWidth = 800, screenHeight = 600;
sf::Font font; // Do!
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Turn-Based Combat Tool");

sf::Event event;

// File handling
void ParseFile(const std::string& filePath); // Remove?, might want to keep in
void FileHandler();

void Interface() { // Engine/Tool interface | Edit game
	sf::RectangleShape background;
	sf::Text header;
	std::array<sf::RectangleShape, 3> buttonTest;

	background.setFillColor(sf::Color::Black);
	background.setSize(sf::Vector2f((float)screenWidth / 3, (float)screenHeight));
}

void Draw(AllyTeam &aT, EnemyTeam &eT, sf::RenderWindow &window) {
	sf::Text turnCount;
	sf::RectangleShape background;
	background.setSize(sf::Vector2f((float)screenWidth, (float)screenHeight));
	background.setFillColor(sf::Color::Blue);
	background.setOrigin(background.getSize().x / 2, background.getSize().y);
	background.setPosition((float)screenWidth / 2, (float)screenHeight); // Check with origin!
	// UI/HUD
	// turnCount.setFont(font);
	while (window.isOpen()) {

		window.draw(background);

		// Allies and Enemies
		for (unsigned int i = 0; i < aT.aTeam.size(); i++) { aT.aTeam[i].Draw(window); }
		for (unsigned int i = 0; i < eT.eTeam.size(); i++) { eT.eTeam[i].Draw(window); }

		aT.DisplayInventory(window);
		window.display();
		window.clear();
	}
}

void Fight(AllyTeam &aT, EnemyTeam &eT, sf::RenderWindow &window) {
	while (!aT.teamWiped) {
		system("cls");
		std::cout << "Turn: " << turn << '\n';
		std::cout << "It is " << allyTurn << "turn\n"; // DO!
		aT.GetTeam();
		if (allyTurn) {
			putchar('\n');
			for (unsigned int i = 0; i < eT.eTeam.size(); i++) {
				eT.eTeam[i].GetStats();
			}
			std::cout << "=====================================\n";
			for (unsigned int i = 0; i < aT.aTeam.size(); i++) {
				aT.aTeam[i].Move(eT.eTeam, window, event);
			}
			std::cin.get();
			std::cin.get();
		}
		else { // Enemies turn | Loops through enemies, attacks random ally
			for (unsigned int i = 0; i < eT.eTeam.size(); i++) {
				short choice = 0; // Change?
				choice = rand() % aT.aTeam.size();
				aT.aTeam[choice].TakeDamage(eT.eTeam[i].m_Damage, window);
			}
		}
		turn++;
		if (turn % 2 == 0)
			allyTurn = true;
		else
			allyTurn = false;
	}
}

void GraphicsSetup(AllyTeam &aT, EnemyTeam &eT) {
	/*
	if (!font.loadFromFile("")) { // Do!
		std::cerr << "Failed to load font\n";
		exit(1);
	}
	*/
	// Setup positions of allies and enemies
	float offset = 0;
	for (unsigned int i = 0; i < aT.aTeam.size(); i++) {
		aT.aTeam[i].SetPosition((float)screenWidth + 25, 15.0f + offset);
		offset += 30;
	}
	offset = 0;
	for (unsigned int i = 0; i < eT.eTeam.size(); i++) {
		eT.eTeam[i].SetPosition((float)screenWidth - 25, 15.0f + offset);
		offset += 30;
	}

	Fight(aT, eT, window); // Run
}

void LogicSetup() {
	short amount = 0;
	amount = rand() % 5;
	amount++;
	std::vector<Enemy> enemies{};
	for (int i = 0; i < amount; i++) {
		Enemy e1;
		enemies.push_back(e1);
	}
	EnemyTeam eT(amount, enemies);

	std::string name = "";
	std::cout << "Pick a team OR create your own!\n 1) Create  2) Choose";
	std::cin >> amount;
	if (amount == 1) {
		// Skill sets | Move to seperate file! Namespace
			// -- Damage
		Fireball f(true, 25, 1);
		Explosion e(true, 125, 0);
		Blizzard b(true, 100, 2);
		std::tuple<Fireball, Explosion, Blizzard> damageBuild(f, e, b);
			// -- Support
		Heal h(false, 25, 0);
		Armor a(false, 75, 0);
		Cleanse c(false, 100, 0);
		std::tuple<Heal, Armor, Cleanse> supportBuild(h, a, c);

		std::vector<Ally> allies{};
		for (unsigned int i = 1; i <= 3; i++) {
			std::cout << "Enter the name of your ";
			switch(i) {
				case 1: std::cout << "First party member: "; break;
				case 2: std::cout << "Second party member: "; break;
				case 3: std::cout << "Third party member: "; break;
			}
			std::cin >> name;
			Ally a1(name, 250, 250);
			allies.push_back(a1);
		}
		AllyTeam aT("Ally Team", allies);
		GraphicsSetup(aT, eT);
	}
	else {
		return;
	}
}

int main() {
	std::thread drawThread(Draw); // Have to use namepsaces instead or study method to use paramteres in thread call

	short choice = 0;
	std::cin >> choice;
	switch (choice) {
		case 1: LogicSetup(); break;
		case 2: FileHandler(); break;
	}

	drawThread.join();
	return 0;
}