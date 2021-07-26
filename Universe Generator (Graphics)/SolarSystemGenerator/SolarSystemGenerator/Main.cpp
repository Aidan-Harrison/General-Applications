#include <iostream>

#include "Interface.h"
#include "Objects.h"

#include <SFML/Graphics.hpp>

sf::Event event;
sf::View camera;
GChunk g;
InformationWindow iW;

using namespace Parameters;// Convert everything to single draw function in solar system struct???
void System(sf::RenderWindow &window, SolarSystem &solarSystem);
void Universe(sf::RenderWindow &window, GChunk &galaxy);

/*
void SystemGenerator() { // If doing galaxy, call this recursively based on camera zoom!
	SolarSystem *newSolar = new SolarSystem;
	int bodyCount = 0;
	bodyCount = rand() % 3;
	bodyCount++;
	for (int i = 0; i < 1; i++) {
		Star *homeStar = new Star;
		homeStar->Generate();
		newSolar->stars.push_back(homeStar);
	}
	bodyCount = rand() % 12;
	bodyCount++;
	for (int i = 0; i < bodyCount; i++) {
		Planet *newPlanet = new Planet;
		newPlanet->Generate(25.0f, 25.0f);
		// Gen moons, if any
			// Run moon func
		newSolar->planets.push_back(newPlanet);
		sf::CircleShape* orbitPath = new sf::CircleShape;
		newSolar->planetOrbits.push_back(orbitPath);
	}
	
	// Calculate planets position relative to star
	// Inheritance
	for (int i = 0; i < newSolar->planets.size(); i++)
		newSolar->planets[i]->Inheritance(*newSolar->stars[0]); // Check!

	newSolar->OrbitPaths();

	System(*newSolar); // Check!
}
*/

void DeleteSystem() { // Frees memory when buffer overflow (Queue)
}

void System(sf::RenderWindow &window, SolarSystem &solarSystem) { // Fix panning!
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			// Keyboard
			// Mouse (Convert to event)
				// If mouse click on object, call window draw and pass in object data
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				// Loop through current solar system and check position
				for (int i = 0; i < solarSystem.planets.size(); i++) {
					// Take into account planet radius
					/*
					for (int j = 0; j < solarSystem.planets[i]->body.getRadius(); i++) {
						if (sf::Mouse::getPosition().x == solarSystem.planets[i]->body.getPosition().x - j || sf::Mouse::getPosition().y == solarSystem.planets[i]->body.getPosition().y - j) {
							std::cout << solarSystem.planets[i]->GetName();
							iW.visible = true;
						}
						if (sf::Mouse::getPosition().x == solarSystem.planets[i]->body.getPosition().x + j || sf::Mouse::getPosition().y == solarSystem.planets[i]->body.getPosition().y + j) {
							std::cout << solarSystem.planets[i]->GetName();
							iW.visible = true;
						}
					}
					*/
				}
			}
			// Pan
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) { // Change! Drag + pan and edge move
				if (sf::Mouse::getPosition().x < screenWidth / 2) {
					camera.move(-5.0f, 0.0f);
				}
				if (sf::Mouse::getPosition().x > screenWidth / 2) {
					camera.move(5.0f, 0.0f);
				}
				if (sf::Mouse::getPosition().y < screenHeight / 2) {
					camera.move(0.0f, 5.0f);
				}
				if (sf::Mouse::getPosition().y > screenHeight / 2) {
					camera.move(0.0f, -5.0f);
				}
			}
			// Zoom
			if (event.type == sf::Event::MouseWheelMoved) {
				if (event.mouseWheel.delta > 0) { // Zoom-in
					ZOOM_VALUE += 0.1f;
					camera.zoom(0.9f);
				}
				if (event.mouseWheel.delta < 0) {
					ZOOM_VALUE -= 0.1f;
					camera.zoom(1.1f);
				}
				if (ZOOM_VALUE < -4.0f) {
					std::cout << "CHUNK!\n";
					solarSystem.isChunked = true;
					// Compress and chunk system (Stop rendering contents and running calculations)
					// Load other systems (Simplified)
					// Load galaxy if zoom is far enough (Fade in)
					// Cull systems based on camera frustrum
					// Repeat for galaxies
				}
				else {
					solarSystem.isChunked = false;
				}
				std::cout << ZOOM_VALUE << '\n';
				if (ZOOM_VALUE == 0) 
					ZOOM_VALUE = 0;
			}
		}
		
		window.clear();

		window.setView(camera);
		// window.draw(speed);
		camera.setViewport(sf::FloatRect(0.0f,0.0f,1.0f,1.0f));
		if(iW.visible)
			iW.Draw(window);

		window.display();
	}
}

void Universe(sf::RenderWindow &window, GChunk &galaxy) { // Change to vector of galaxies
	galaxy.DistributeSystems();
	// Check if galaxy/s in view, if so draw

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			// Keyboard
			// Mouse (Convert to event)
				// If mouse click on object, call window draw and pass in object data
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) { // Change! Drag + pan and edge move
				if (sf::Mouse::getPosition().x < screenWidth / 2) { camera.move(10.0f + SPEED_VALUE, 0.0f); }
				if (sf::Mouse::getPosition().x > screenWidth / 2) { camera.move(-10.0f - SPEED_VALUE, 0.0f); }
				if (sf::Mouse::getPosition().y < screenHeight / 2) { camera.move(0.0f, -10.0f - SPEED_VALUE); }
				if (sf::Mouse::getPosition().y > screenHeight / 2) { camera.move(0.0f, 10.0f + SPEED_VALUE); }
			}
			// Zoom
			if (event.type == sf::Event::MouseWheelMoved) {
				if (event.mouseWheel.delta > 0) { // Zoom-in
					ZOOM_VALUE += 0.1f;
					SPEED_VALUE += 2.5f;
					camera.zoom(0.9f);
				}
				if (event.mouseWheel.delta < 0) {
					ZOOM_VALUE -= 0.1f;
					SPEED_VALUE -= 2.5f;
					camera.zoom(1.1f);
				}
				// Refactor for galaxies
				if (ZOOM_VALUE < -2.0f) {
					std::cout << "CHUNK!\n";
					for (int i = 0; i < galaxy.systems.size(); i++) {
						galaxy.systems[i]->isChunked = true;
					}
					//	solarSystem.isChunked = true;
					// Compress and chunk system (Stop rendering contents and running calculations)
					// Load other systems (Simplified)
					// Load galaxy if zoom is far enough (Fade in)
					// Cull systems based on camera frustrum
					// Repeat for galaxies
				}
				else {
					for (int i = 0; i < galaxy.systems.size(); i++) {
						galaxy.systems[i]->isChunked = false;
					}
				}
				
				std::cout << ZOOM_VALUE << '\n';
				if (ZOOM_VALUE == 0)
					ZOOM_VALUE = 0;
			}
		}

		window.clear();

		galaxy.Draw(camera, window);

		window.setView(camera);
		camera.setViewport(sf::FloatRect(0.0f,0.0f,1.0f,1.0f)); // Before?

		window.display();
	}

}

int main() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Solar System Generator");
	window.setFramerateLimit(24);

	// SystemGenerator();
	Universe(window, g);

	//if (!f.loadFromFile(""))
		//std::cerr << "Failed to load font!\n";
	//speed.setPosition(screenWidth/2, 50.0f);

	return 0;
}