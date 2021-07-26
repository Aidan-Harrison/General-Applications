#ifndef Objects_h
#define Objects_h

#include <iostream> // Used for logging/debugging
#include <map>

// Use stack for searching!
// Tree/Graph!!!
// Space is of most importance, short instead of int

#include "Global.h"
// #include "Collision.h"


using namespace Parameters;

struct Star {
	sf::CircleShape body;
	sf::Text name;
	sf::Color color;

	sf::RectangleShape originPoint;
	// Collider col;

	Star()
	{
		originPoint.setSize(sf::Vector2f(25.0f, 25.0f));
		originPoint.setFillColor(sf::Color::Blue);
		originPoint.setOrigin(originPoint.getSize().x, originPoint.getSize().y);
	}
	~Star() {}

	void Generate(float x, float y);
	void Draw(sf::RenderWindow& window);
};

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
	short distanceToStar = 0; // Used for orbit
	float localRotation = 0.0f;

	enum type { DWARF, EXO, GAS };
	bool hasRings = false;
	bool inhabited = false;
	bool hasAtmosphere = false;
	bool hasMoons = false;
	short radius = 0; // km
	short weight = 0; // Partially tied to radius | kg
	short age = 0;
	sf::Color color;
	std::vector<sf::Text> parameters{};

	sf::Text civOccupation; // Refers to the main occupatation of a civilisation if inhabiated (Mining, trading, space tourism etc.)

	// std::vector<Moon> moons{}; // Check scope, class declarations? | Don't think this is going to work
	std::vector<SpaceStation> spaceStations{}; // Clamp

	Planet()
	{
		localRotation = rand() % 2; // Check with float | Calculate distance to star
		localRotation += 0.25f;
	}
	~Planet() {}

	std::string GetName() const { return parameters[0].getString(); }

	void Update(); // Orbit, set as child of point at star, rotate point, change rotation of point per planet | Rename?
	void PlanetInfo(); // Render
	void Generate(float xOffset, float yOffset);
	void Inheritance(Star& star); // Sets position/orbit relative to star
	void Draw(sf::RenderWindow& window);
};

struct Moon : public Planet {
	Moon() {}
	~Moon() {}
	sf::Color color;
	Planet* parentPlanet; // Use std::unique_ptr instead??
};

struct SolarSystem {
	sf::Transformable SYSTEM_ORIGIN; // May still be useful after camera refactor
	sf::RectangleShape bounds; // Used for culling | Match with camera viewport and zoom | (MUST BE IN VIEWPORT AND CLOSE ENOUGH)

	std::vector<sf::CircleShape*> planetOrbits{};

	std::vector<Planet*> planets; // Check!
	std::vector<Star*> stars; // Max 3 (Ternary System)

	bool isChunked = false;
	bool hasGenerated = false;
	bool hasGenPlanets = false;

	void OrbitPaths();
	void OriginMatch();
	void Pan(bool xState, bool yState, float x, float y);

	void Generator(float posX, float posY);
	void GeneratePlanets();

	void Draw(sf::RenderWindow &window);

	SolarSystem() {}
	~SolarSystem() {}
};

struct GChunk {
	GChunk() {}
	~GChunk() {}

	std::vector<SolarSystem*> systems{};

	short systemAmount = 20000; // 20k prev | Int?

	void DistributeSystems(); // Generates solar systems in a random pattern
	void Draw(sf::View &cam, sf::RenderWindow &window);

	// std::vector<SolarSystem*> sSystems{}; // Rename?
};

#endif
