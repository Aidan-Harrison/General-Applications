#include <iostream>

#include <SFML/Graphics.hpp>

#include "Songs.h"

int screenWidth = 800, screenHeight = 600;

// Add Queue

void FileParser(sf::Music &m, const std::string &filePath) {
	if(!m.openFromFile("Music/" + filePath)) { // Append "Music/"
		std::cerr << "Failed to open file!\n";
		exit(1); // Add better error handling?, Re-shuffle?
	}
}
void FileParser(sf::Image& i, const std::string& filePath) {
	if (!i.loadFromFile("Covers/" + filePath)) { // Append "Music/"
		std::cerr << "Failed to open file!\n";
		// exit(1); // Add better error handling?, Re-shuffle?
	}
	// Set image
}

void Draw() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Music Player");
	sf::RectangleShape playButton;
	sf::Sprite playSprite;
	sf::RectangleShape loopButton;
	sf::Sprite loopSprite;
	sf::RectangleShape shuffleButton;
	sf::Sprite shuffleSprite;

	sf::RectangleShape playbackBar;
	sf::RectangleShape playbackBackground;

	sf::Image songCover;
	sf::Texture tex;
	sf::Sprite coverSprite;
	sf::SoundBuffer sBuffer;
	sf::Music current;
	std::string songName = "";
	sf::Event event;	
	bool isLooping = false;
	bool isPlaying = true;

	playButton.setSize(sf::Vector2f(50.0f,50.0f));
	playButton.setFillColor(sf::Color::White);
	playButton.setPosition(sf::Vector2f((float)screenWidth / 2, (float)screenHeight - 100.0f));
	playSprite.setPosition(sf::Vector2f(playButton.getPosition().x, playButton.getPosition().y));

	loopButton.setSize(sf::Vector2f(35.0f, 35.0f));
	loopButton.setFillColor(sf::Color::White);
	loopButton.setPosition(sf::Vector2f((float)screenWidth / 3, (float)screenHeight - 100.0f));
	loopSprite.setPosition(sf::Vector2f(loopButton.getPosition().x, loopButton.getPosition().y));

	shuffleButton.setSize(sf::Vector2f(35.0f, 35.0f));
	shuffleButton.setFillColor(sf::Color::White);
	shuffleButton.setPosition(sf::Vector2f((float)screenWidth / 1.5, (float)screenHeight - 100.0f));
	shuffleSprite.setPosition(sf::Vector2f(shuffleButton.getPosition().x, shuffleButton.getPosition().y));

	playbackBar.setFillColor(sf::Color::White);
	playbackBar.setOrigin(playbackBar.getSize().x - playbackBar.getSize().x, playbackBar.getSize().y / 2);

	coverSprite.setPosition(sf::Vector2f(screenWidth / 2, screenHeight / 2));

	// Set Images | Reuse same variable
	FileParser(songCover, "");
	tex.update(songCover);
	playSprite.setTexture(tex);

	FileParser(songCover, "");
	tex.update(songCover);
	playSprite.setTexture(tex);

	FileParser(songCover, "");
	tex.update(songCover);
	playSprite.setTexture(tex);

	current.setVolume(5);
	current.play();

	while (window.isOpen()) {
		while (window.pollEvent(event)) { // Add mouse picking as well
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // Shuffle
				int choice = 0;
				choice = rand() % Songs::songs.size();
				FileParser(current, Songs::songs[choice]);
				current.play();
				FileParser(songCover, Covers::covers[choice]);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) { // Loop
				if (!isLooping) {
					current.setLoop(true);
					isLooping = true;
				}
				else {
					current.setLoop(false);
					isLooping = false;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) { // Play/Pause
				if (isPlaying) {
					current.stop();
					isPlaying = false;
				}
				else {
					current.play();
					isPlaying = true;
				}
			}
		}

		window.clear();

		window.draw(playButton);
		window.draw(loopButton);
		window.draw(shuffleButton);
		// Sprites
		window.draw(coverSprite);
		window.draw(playSprite);
		window.draw(loopSprite);
		window.draw(shuffleSprite);

		window.display();
	}
}

int main() {
	Draw();

	return 0;
}