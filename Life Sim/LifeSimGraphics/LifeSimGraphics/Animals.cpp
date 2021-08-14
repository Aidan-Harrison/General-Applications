#include "Animal.h"

void Animal::Generate() {
	int nameIndex = rand() % names.size()-1;
	nameIndex++;
	name = names[nameIndex];
	nameText.setString(name);

	moveSpeed = rand() % 3;
	moveSpeed += 0.5f;
}

void Animal::Roam(const float screenWidth, const float screenHeight) { // Optimise?
	dir = rand() % 3;
	if (dir == LEFT) {
		rect.setPosition(positionX -= moveSpeed, positionY);
		rect.rotate(25.0f);
		detectRad.setPosition(rect.getPosition().x, rect.getPosition().y);
		nameText.setPosition(rect.getPosition().x, rect.getPosition().y - 50.0f);
	}
	if(dir == RIGHT) {
		rect.setPosition(positionX += moveSpeed, positionY);
		rect.rotate(-25.0f);
		detectRad.setPosition(rect.getPosition().x, rect.getPosition().y);
		nameText.setPosition(rect.getPosition().x, rect.getPosition().y - 50.0f);
	}
	if(dir == UP) {
		rect.setPosition(positionX, positionY -= moveSpeed);
		detectRad.setPosition(rect.getPosition().x, rect.getPosition().y);
		nameText.setPosition(rect.getPosition().x, rect.getPosition().y - 50.0f);
	}
	if(dir == DOWN) {
		rect.setPosition(positionX, positionY += moveSpeed);
		detectRad.setPosition(rect.getPosition().x, rect.getPosition().y);
		nameText.setPosition(rect.getPosition().x, rect.getPosition().y - 50.0f);
	}

	// Change
	if (rect.getPosition().x >= screenWidth)
		rect.setPosition(positionX -= 0.5f, positionY);
	else if (rect.getPosition().x <= 0)
		rect.setPosition(positionX += 0.5f, positionY);
	if (rect.getPosition().y >= screenHeight)
		rect.setPosition(positionX, positionY -= 0.5f);
	else if (rect.getPosition().y <= 0)
		rect.setPosition(positionX, positionY += 0.5f);
	fVector.setPosition(rect.getPosition().x, rect.getPosition().y);
}

void Animal::Draw(sf::RenderWindow& window, bool drawText) {
	window.draw(rect);
	window.draw(fVector);
	window.draw(detectRad);
	if(drawText)
		window.draw(nameText);
}