#include <iostream>

#include "Interface.h"
#include "Objects.h"

#include <SFML/Graphics.hpp>

namespace Parameters {
	int screenWidth = 1920, screenHeight = 1080;
	int MAX_PLANETS = 12; // Per system
	float ZOOM_VALUE = 0.0f; // Set clamps
	float PanX = 0, PanY = 0;
}

using namespace Parameters;// Convert everything to single draw function in solar system struct???

struct Star {
	sf::CircleShape body;
	sf::Text name;
	sf::Color color;

	sf::RectangleShape originPoint;

	Star() 
	{
		originPoint.setSize(sf::Vector2f(25.0f, 25.0f));
		originPoint.setFillColor(sf::Color::Blue);
		originPoint.setOrigin(originPoint.getSize().x, originPoint.getSize().y);
	}
	~Star() {}
	
	void Generate();
	void Draw(sf::RenderWindow &window);
};

void Star::Generate() {
	body.setFillColor(sf::Color::Red);
	body.setRadius(75.0f);
	body.setPosition(sf::Vector2f((float)screenWidth / 2, (float)screenHeight / 2));

	originPoint.setPosition(body.getOrigin().x, body.getOrigin().y);
}

void Star::Draw(sf::RenderWindow& window) {
	window.draw(body);
	window.draw(originPoint);
}

struct SpaceStation { // Add parent planet
	SpaceStation() {}
	~SpaceStation() {}

	sf::Text stationName;
	
	void StationInfo();
	void Draw();
};

struct Planet {
	Star parentStar;
	sf::CircleShape body;

	// Parameters
	enum type {DWARF, EXO, GAS};
	bool hasRings = false;
	bool inhabited = false;
	bool hasAtmosphere = false;
	bool hasMoons = false;
	int radius = 0; // km
	int weight = 0; // Partially tied to radius | kg
	int age = 0;
	sf::Color color;
	std::vector<sf::Text> parameters{};

	sf::Text civOccupation; // Refers to the main occupatation of a civilisation if inhabiated (Mining, trading, space tourism etc.)

	// std::vector<Moon> moons{}; // Check scope, class declarations? | Don't think this is going to work
	std::vector<SpaceStation> spaceStations{}; // Clamp

	Planet() {}
	~Planet() {}

	std::string GetName() const { return parameters[0].getString(); }

	void Update(); // Orbit, set as child of point at star, rotate point, change rotation of point per planet | Rename?
	void PlanetInfo(); // Render
	void Generate(float xOffset, float yOffset);
	void Inheritance(Star &star); // Sets position/orbit relative to star
	void Draw(sf::RenderWindow &window);
};

void Planet::Update() {
	float rotation = 0;
	rotation += 2.0f;
	body.rotate(rotation);
}

void Planet::Generate(float xOffset, float yOffset) { // Fix position setting | Possible remove function argument offset, stick with internal
	float radius = 25.0f; // Rand() | don't think it works with floats to well
	body.setRadius(radius);
	body.setOrigin(body.getRadius() / 2, body.getRadius() / 2);
	int generator = rand() % 6;
	switch (generator) { // Fix color | Not setting
		case 0: color.r = 255; color.g = 0; color.b = 15; break;
		case 1: color.r = 0; color.g = 150; color.b = 75; break;
		case 2: color.r = 100; color.g = 25; color.b = 180; break;
		case 3: color.r = 255; color.g = 0; color.b = 15; break;
		case 4: color.r = 255; color.g = 0; color.b = 15; break;
		case 5: color.r = 255; color.g = 0; color.b = 15; break;
	}
	generator = rand() % 2;
	switch (generator) {
		case 0: hasMoons = false; break;
		case 1: hasMoons = true; break;
	} 
}

void Planet::Inheritance(Star &star) {
	parentStar = star;
	// Position | Avoid overlap with orbits
	float xOffset = rand() % 600; // Do range instead!
	// body.setOrigin(parentStar.body.getPosition().x, parentStar.body.getPosition().y); // Fix!
	body.setOrigin(parentStar.body.getPosition().x, parentStar.body.getPosition().y); // Fix!
	body.setPosition(sf::Vector2f(parentStar.body.getPosition().x + xOffset, parentStar.body.getPosition().y));
}

void Planet::Draw(sf::RenderWindow &window) {
	window.draw(body);
}

struct Moon : public Planet {
	Moon() {}
	~Moon() {}
	sf::Color color;
	Planet* parentPlanet; // Use std::unique_ptr instead??
};

struct SolarSystem {
	sf::Transformable SYSTEM_ORIGIN; // Used for camera movement

	std::vector<sf::CircleShape*> planetOrbits{};

	std::vector<Planet*> planets; // Check!
	std::vector<Star*> stars; // Max 3 (Ternary System)

	void OrbitPaths();
	void OriginMatch();
	void Pan(bool xState, bool yState, float x, float y);

	SolarSystem() {}
	~SolarSystem() {}
};

void SolarSystem::OrbitPaths() {
	for (int i = 0; i < planetOrbits.size(); i++) {
		planetOrbits[i]->setOutlineThickness(5.0f);
		planetOrbits[i]->setOutlineColor(sf::Color::Blue);
		planetOrbits[i]->setFillColor(sf::Color(0,0,0,0));
		planetOrbits[i]->setRadius(planets[i]->body.getPosition().x); // Do some extra math
		planetOrbits[i]->setOrigin(stars[0]->body.getPosition().x, stars[0]->body.getPosition().y); // Do some extra math
		planetOrbits[i]->setPosition(stars[0]->body.getPosition().x, stars[0]->body.getPosition().y);
	}
}

void SolarSystem::OriginMatch() {
	SYSTEM_ORIGIN.setOrigin(stars[0]->body.getPosition().x, stars[0]->body.getPosition().y);
	SYSTEM_ORIGIN.setPosition(stars[0]->body.getPosition().x, stars[0]->body.getPosition().y);
	stars[0]->body.setScale(SYSTEM_ORIGIN.getScale());
	for (int i = 0; i < planets.size(); i++) {
		planets[i]->body.setScale(SYSTEM_ORIGIN.getScale());
		planetOrbits[i]->setScale(SYSTEM_ORIGIN.getScale());
	}
}

void SolarSystem::Pan(bool xState, bool yState, float x, float y) {
	if(xState)
		SYSTEM_ORIGIN.setPosition(SYSTEM_ORIGIN.getPosition().x + x, SYSTEM_ORIGIN.getPosition().y);
	if(!xState)
		SYSTEM_ORIGIN.setPosition(SYSTEM_ORIGIN.getPosition().x - x, SYSTEM_ORIGIN.getPosition().y + y);
	if(yState)
		SYSTEM_ORIGIN.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y + y);
	if(!yState)
		SYSTEM_ORIGIN.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y - y);
	stars[0]->body.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y); // Add offset
	for (int i = 0; i < planets.size(); i++) {
		planets[i]->body.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y); // Take into account each planets initial offset (Orbit)
		planetOrbits[i]->setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y); 
	}
}

void System(SolarSystem &solarSystem);

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

void DeleteSystem() { // Frees memory when buffer overflow (Queue)
}

void System(SolarSystem &solarSystem) { // Add camera controls (Pan, zoom)
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Solar System Generator");
	window.setFramerateLimit(24);
	sf::Event event;
	InformationWindow iW;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			// Keyboard
			// Mouse (Convert to event)
				// If mouse click on object, call window draw and pass in object data
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				// Loop through current solar system and check position
				for (int i = 0; i < solarSystem.planets.size(); i++) {
					// Take into account planet radius
					if (sf::Mouse::getPosition().x == solarSystem.planets[i]->body.getPosition().x || sf::Mouse::getPosition().y == solarSystem.planets[i]->body.getPosition().y) {
						std::cout << solarSystem.planets[i]->GetName();
						iW.visible = true;
					}
				}
			}
			// Pan
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				if (sf::Mouse::getPosition().x < screenWidth / 2)
					PanX -= 0.5f;
					solarSystem.Pan(true, false, PanX, PanY);
				if (sf::Mouse::getPosition().x > screenWidth / 2)
					PanX += 0.5f;
					solarSystem.Pan(false, false, PanX, PanY);
				if (sf::Mouse::getPosition().y < screenHeight / 2)
					PanY -= 0.5f;
					solarSystem.Pan(false, true, PanX, PanY);
				if (sf::Mouse::getPosition().y > screenHeight / 2)
					PanY += 0.5f;
					solarSystem.Pan(false, false, PanX, PanY);
			}
			// Zoom
			if (event.type == sf::Event::MouseWheelMoved) {
				std::cout << event.mouseWheel.delta << '\n';
				if (event.mouseWheel.delta > 0) { // Zoom-in
					ZOOM_VALUE += 0.1f;
					solarSystem.SYSTEM_ORIGIN.setScale(ZOOM_VALUE, ZOOM_VALUE);
					solarSystem.OriginMatch();
				}
				if (event.mouseWheel.delta < 0) {
					ZOOM_VALUE -= 0.1f;
					solarSystem.SYSTEM_ORIGIN.setScale(ZOOM_VALUE, ZOOM_VALUE);
					solarSystem.OriginMatch();
				}
			}
		}
		
		window.clear();

		for (unsigned int i = 0; i < solarSystem.stars.size(); i++) {
			solarSystem.stars[i]->Draw(window);
		}
		for (unsigned int i = 0; i < solarSystem.planets.size(); i++) {
			solarSystem.planets[i]->Update();
			solarSystem.planets[i]->Draw(window);
			window.draw(*solarSystem.planetOrbits[i]); // Check!
		}

		if(iW.visible)
			iW.Draw(window);
	
		window.display();
	}
}

int main() {
	SystemGenerator();

	return 0;
}