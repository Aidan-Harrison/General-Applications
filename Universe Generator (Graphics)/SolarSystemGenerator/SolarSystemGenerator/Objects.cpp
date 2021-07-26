#include "Objects.h"

// ===STAR===
void Star::Generate(float x, float y) { // Get system origin implemented
	int colour = rand() % 5;
	switch (colour) {
		case 0: body.setFillColor(sf::Color::Red); break;
		case 1: body.setFillColor(sf::Color::Yellow); break;
		case 2: body.setFillColor(sf::Color::White); break;
		case 3: body.setFillColor(sf::Color::Cyan); break;
		case 4: body.setFillColor(sf::Color::Magenta); break;
	}
	float radius = rand() % 150;
	radius += 25.0f;
	body.setRadius(radius);

	originPoint.setPosition(x, y);
	body.setPosition(x, y); // Avoid using screen size, swap to custom coord system instead????
	// body.setOrigin(originPoint.getPosition().x, originPoint.getPosition().y);
}

void Star::Draw(sf::RenderWindow& window) {
	window.draw(body);
	// window.draw(originPoint);
}

// ===PLANET===
void Planet::Update() {
	body.rotate(localRotation);
}

void Planet::Generate(float xOffset, float yOffset) { // Fix position setting | Possible remove function argument offset, stick with internal
	float radius = 25.0f; // Rand() | don't think it works with floats to well
	body.setRadius(radius);
	body.setOrigin(body.getRadius() / 2, body.getRadius() / 2);
	int generator = rand() % 6;
	switch (generator) { // Fix color | Not setting
		case 0: color.r = 255;  color.g = 0;   color.b = 15; break;
		case 1: color.r = 0;    color.g = 150; color.b = 75; break;
		case 2: color.r = 100;  color.g = 25;  color.b = 180;break;
		case 3: color.r = 255;  color.g = 0;   color.b = 15; break;
		case 4: color.r = 255;  color.g = 0;   color.b = 15; break;
		case 5: color.r = 255;  color.g = 0;   color.b = 15; break;
	}
	generator = rand() % 2;
	switch (generator) {
		case 0: hasMoons = false; break;
		case 1: hasMoons = true; break;
	}
	distanceToStar = parentStar.body.getPosition().x - body.getPosition().x; // Probably don't want to normalise, do fake value?
	if (distanceToStar < 0)
		distanceToStar = -1;
	else
		distanceToStar = 1;
}

void Planet::Inheritance(Star& star) {
	parentStar = star;
	// Position | Avoid overlap with orbits
	float xOffset = rand() % 600; // Do range instead!
	// body.setOrigin(parentStar.body.getPosition().x, parentStar.body.getPosition().y); // Fix!
	body.setOrigin(parentStar.body.getPosition().x, parentStar.body.getPosition().y); // Fix!
	body.setPosition(sf::Vector2f(parentStar.body.getPosition().x + xOffset, parentStar.body.getPosition().y));
}

void Planet::Draw(sf::RenderWindow& window) {
	window.draw(body);
}

// ===SOLAR SYSTEM===
void SolarSystem::OrbitPaths() { // Fix!
	for (unsigned int i = 0; i < planetOrbits.size(); i++) {
		planetOrbits[i]->setOutlineThickness(5.0f);
		planetOrbits[i]->setOutlineColor(sf::Color::Blue);
		planetOrbits[i]->setFillColor(sf::Color(0, 0, 0, 0));
		planetOrbits[i]->setRadius(stars[0]->body.getPosition().x - planets[i]->body.getPosition().x); // Do some extra math!
		planetOrbits[i]->setOrigin(planetOrbits[i]->getRadius()/2, planetOrbits[i]->getRadius()/2); // Change!
		planetOrbits[i]->setPosition(stars[0]->body.getPosition().x, stars[0]->body.getPosition().y);
		// Do position
	}
}

void SolarSystem::OriginMatch() { // Remove?
	SYSTEM_ORIGIN.setOrigin(stars[0]->body.getPosition().x, stars[0]->body.getPosition().y);
	SYSTEM_ORIGIN.setPosition(stars[0]->body.getPosition().x, stars[0]->body.getPosition().y);
	stars[0]->body.setScale(SYSTEM_ORIGIN.getScale());
	for (unsigned int i = 0; i < planets.size(); i++) {
		planets[i]->body.setScale(SYSTEM_ORIGIN.getScale());
		planetOrbits[i]->setScale(SYSTEM_ORIGIN.getScale());
	}
}

void SolarSystem::Pan(bool xState, bool yState, float x, float y) { // REMOVE!
	if (xState) {
		SYSTEM_ORIGIN.setPosition(SYSTEM_ORIGIN.getPosition().x + x, SYSTEM_ORIGIN.getPosition().y);
		for (int i = 0; i < planets.size(); i++) {
			planets[i]->body.setOrigin(SYSTEM_ORIGIN.getPosition().x + planets[i]->body.getPosition().x, SYSTEM_ORIGIN.getPosition().y); // Take into account each planets initial offset (Orbit)
			planets[i]->body.setPosition(SYSTEM_ORIGIN.getPosition().x + planets[i]->distanceToStar, SYSTEM_ORIGIN.getPosition().y); // Take into account each planets initial offset (Orbit)
		}
	}
	if (!xState) {
		SYSTEM_ORIGIN.setPosition(SYSTEM_ORIGIN.getPosition().x - x, SYSTEM_ORIGIN.getPosition().y + y);
		for (int i = 0; i < planets.size(); i++) {
			planets[i]->body.setOrigin(SYSTEM_ORIGIN.getPosition().x + planets[i]->body.getPosition().x, SYSTEM_ORIGIN.getPosition().y); // Take into account each planets initial offset (Orbit)
			planets[i]->body.setPosition(SYSTEM_ORIGIN.getPosition().x - planets[i]->distanceToStar, SYSTEM_ORIGIN.getPosition().y); // Take into account each planets initial offset (Orbit)
		}
	}
	if (yState) {
		SYSTEM_ORIGIN.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y + y);
		for (int i = 0; i < planets.size(); i++) {
			planets[i]->body.setOrigin(SYSTEM_ORIGIN.getPosition().x + planets[i]->body.getPosition().x, SYSTEM_ORIGIN.getPosition().y);
			planets[i]->body.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y + planets[i]->distanceToStar);
		}
	}
	if (!yState) {
		SYSTEM_ORIGIN.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y - y);
		for (int i = 0; i < planets.size(); i++) {
			planets[i]->body.setOrigin(SYSTEM_ORIGIN.getPosition().x + planets[i]->body.getPosition().x, SYSTEM_ORIGIN.getPosition().y); // Take into account each planets initial offset (Orbit)
			planets[i]->body.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y - planets[i]->distanceToStar); // Take into account each planets initial offset (Orbit)
		}
	}
	stars[0]->body.setOrigin(stars[0]->body.getRadius() / 2, stars[0]->body.getRadius() / 2);
	stars[0]->body.setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y); // Add offset
	stars[0]->originPoint.setPosition(stars[0]->body.getOrigin());
	for (int i = 0; i < planets.size(); i++) {
		planetOrbits[i]->setOrigin(planetOrbits[i]->getRadius() / 2, planetOrbits[i]->getRadius() / 2); // Do initially!
		planetOrbits[i]->setPosition(SYSTEM_ORIGIN.getPosition().x, SYSTEM_ORIGIN.getPosition().y);
	}
}

void SolarSystem::Generator(float posX, float posY) {
	int bodyCount = rand() % 3;
	bodyCount++;
	for (unsigned int i = 0; i < 1; i++) {
		Star* homeStar = new Star;
		homeStar->Generate(posX, posY);
		stars.push_back(homeStar);
	}

	OrbitPaths();
	hasGenerated = true;
}

void SolarSystem::GeneratePlanets() {
	int bodyCount = rand() % 12;
	bodyCount++;
	for (unsigned int i = 0; i < bodyCount; i++) {
		Planet* newPlanet = new Planet;
		newPlanet->Generate(25.0f, 25.0f);
		// Gen moons, if any
			// Run moon func
		planets.push_back(newPlanet);
		sf::CircleShape* orbitPath = new sf::CircleShape;
		planetOrbits.push_back(orbitPath);
	}

	// Calculate planets position relative to star
	// Inheritance
	for (int i = 0; i < planets.size(); i++)
		planets[i]->Inheritance(*stars[0]); // Check!
}

void SolarSystem::Draw(sf::RenderWindow &window) {
	for (unsigned int i = 0; i < stars.size(); i++) { // Seperate star rendering!
		stars[i]->Draw(window);
	}
	/*
	if (!isChunked) {
		for (unsigned int i = 0; i < planets.size(); i++) {
			planets[i]->Update();
			planets[i]->Draw(window);
			window.draw(*planetOrbits[i]); // Check!
		}
	}
	*/
}

// ===GALAXY===
void GChunk::DistributeSystems() { // Prevent overlapping stars!!!!
	int xOffset, yOffset;
	for (unsigned int i = 0; i < systemAmount; i++) {
		SolarSystem* newSolar = new SolarSystem;
		xOffset = rand() % 150000; // Bounds of galaxy
		yOffset = rand() % 150000;
		xOffset += 500;
		yOffset += 500;
		newSolar->SYSTEM_ORIGIN.setPosition(xOffset, yOffset); // Change!
		newSolar->Generator(newSolar->SYSTEM_ORIGIN.getPosition().x, newSolar->SYSTEM_ORIGIN.getPosition().y);
		systems.push_back(newSolar);
	}

	// Calculate overlap | Need to use hash table for searching
	/*
	for (unsigned int i = 0; i < systems.size()-1; i++) {
		if (systems[i]->stars[0]->col.Detect(systems[i + 1]->stars[0]->col))
			delete systems[i + 1]; // Check!
	}
	*/
}

void GChunk::Draw(sf::View &cam, sf::RenderWindow &window) {
	for (unsigned int i = 0; i < systems.size(); i++) { // Get camera view and bounds
		systems[i]->Draw(window);
	}
}