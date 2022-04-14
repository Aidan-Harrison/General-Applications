#include <iostream>
#include <queue>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>

#include "Songs.h"

// Add queue
// Add window closing via 'X'
// Manually calculate time remaining + current time
// Set background colour to most commom colour in image. Do pixel search??

void FileParser(sf::Music& m, sf::Sprite& c, sf::Texture &t, const std::string& filePath, const char type);

namespace Parameters {
	int screenWidth = 800, screenHeight = 600;
	int minutes = 0;
	float positionOffset = 160.0f;
	std::queue<std::string> q; // Check!
	std::fstream fileHandler;
	sf::Text currentTrack;
}

using namespace Parameters;

// Add Queue | Can't shuffle same song until queue is empty
void Shuffle(sf::Music &current, sf::Sprite &cover, sf::Texture &t) {
	minutes = 0;
	int choice = 0;
	choice = rand() % Songs::songs.size();
	if(q.size() > 0)
		if (q.front() == Songs::songs[choice])
			Shuffle(current, cover, t);
	FileParser(current, cover, t, Songs::songs[choice], 'm');
	current.play();
	FileParser(current, cover, t, Covers::covers[choice], 'c');
	cover.setTexture(t);

	std::string trackName = Songs::songs[choice];
	trackName.erase(trackName.find(".ogg")); // Check!
	currentTrack.setString(trackName);
	currentTrack.setOrigin(currentTrack.getLocalBounds().width / 2, currentTrack.getLocalBounds().height / 2);
	q.push(trackName); // Compare strings instead of music objects
}

void FileHandle() {
	int totalSongs = 0;
	std::string line;
	fileHandler.open("SongList/SongList.txt");
	if (fileHandler.fail()) {
		std::cerr << "Failed to open music file!\n";
		// exit(1); // Must open, else can't play
	}
	else {
		std::cout << "Successfully opened music file!\n";
		std::cout << "Total songs found:\n";
		while (std::getline(fileHandler, line)) {
			totalSongs++;
			Songs::songs.push_back(line);
		}
		std::cout << "Songs: " << totalSongs << '\n';
		// Manually get covers, have it so cover's won't cause errors | Re-write system
	}
}

void FileParser(sf::Music& m, sf::Sprite& c, sf::Texture &t, const std::string& filePath, const char type) {
	if (type == 'c') {
		if (!t.loadFromFile("Covers/" + filePath)) {
			std::cerr << "Failed to open file!\n";
		}
	}
	else if (type == 'i') {
		if (!t.loadFromFile("Icons/" + filePath)) {
			std::cerr << "Failed to open file!\n";
		}
	}
	else if (type == 'm') {
		if (!m.openFromFile("Music/" + filePath)) {
			std::cerr << "Failed to open file!\n";
			Shuffle(m, c, t);
		}
	}
}

void Setup() {}

void Draw() { // Split function!
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Music Player");
	window.setFramerateLimit(10);

	sf::Texture playTex;
	sf::Sprite playSprite;
	sf::Texture loopTex;
	sf::Sprite loopSprite;
	sf::Sprite shuffleSprite;
	sf::Texture shuffleTex;
	sf::Text stateText;

	sf::Time currentTime;
	sf::Time trackLength;
	sf::Text currentTimeText;
	sf::Text trackLengthText;

	sf::RectangleShape playbackBar;
	sf::RectangleShape playbackBackground;

	sf::Texture coverTex;
	sf::Image songCover;
	sf::Sprite coverSprite;
	sf::SoundBuffer sBuffer;
	sf::Music current;
	std::string songName = "";
	sf::Event event;	

	sf::Font font;

	enum STATES {STOPPED, LOOPING, SHUFFLING, PLAYING};

	bool isLooping = false;
	bool isPlaying = true;

	// Track Stats
	if(!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
		std::cerr << "Failed to load font!\n";
	currentTrack.setFont(font);
	currentTrack.setPosition(sf::Vector2f(screenWidth / 2, screenHeight - 550.0f));

	trackLengthText.setFont(font);
	trackLengthText.setOrigin(trackLengthText.getLocalBounds().width / 2, trackLengthText.getLocalBounds().height / 2);
	trackLengthText.setPosition(sf::Vector2f((float)screenWidth / 1.4, (float)screenHeight - positionOffset));

	currentTimeText.setFont(font);
	currentTimeText.setOrigin(currentTimeText.getLocalBounds().width / 2, currentTimeText.getLocalBounds().height / 2);
	currentTimeText.setPosition(sf::Vector2f((float)screenWidth / 3, (float)screenHeight - positionOffset));

	playSprite.setPosition(sf::Vector2f((float)screenWidth / 2, (float)screenHeight - 100.0f));
	loopSprite.setPosition(sf::Vector2f((float)screenWidth / 3, (float)screenHeight - 100.0f));
	shuffleSprite.setPosition(sf::Vector2f((float)screenWidth / 1.5, (float)screenHeight - 100.0f));
	
	playbackBar.setFillColor(sf::Color::White);
	playbackBar.setOrigin(playbackBar.getSize().x / 2, playbackBar.getSize().y / 2); // Replace with minus or inverse mult?, division is slower
	playbackBar.setPosition((float)screenWidth / 2, (float)screenHeight - 150.0f);

	playbackBackground.setFillColor(sf::Color::Yellow);
	playbackBackground.setSize(sf::Vector2f(400.0f, 15.0f));
	playbackBackground.setOrigin(0.0f, playbackBackground.getSize().y /2);
	playbackBackground.setPosition(200.0f, (float)screenHeight - 250.0f); // ????????????

	sf::Vector2f imgSize = coverSprite.getScale();
	sf::RectangleShape rect;
	coverSprite.setScale(imgSize.x / 2, imgSize.y / 2); // Force correct scaling per cover | Get res/size | Use localbounds()? | Subrect
	coverSprite.setScale(0.25f, 0.25f); // Force correct scaling per cover | Get res/size | Use localbounds()? 
	coverSprite.setOrigin((float)screenWidth / 2, (float)screenHeight/ 2);
	coverSprite.setPosition(sf::Vector2f((float)screenWidth / 2, (float)screenHeight - 450.0f));

	// Set Images | Reuses same variable | TODO: Get images for each icon
	FileParser(current, coverSprite, playTex, "PlayPause.png", 'i');
	playSprite.setTexture(playTex);
	playSprite.setScale(0.1f, 0.1f);

	FileParser(current, coverSprite, loopTex, "ShuffleIcon.png", 'i'); // Change
	coverTex.update(songCover);
	loopSprite.setTexture(loopTex);
	loopSprite.setScale(0.05f, 0.05f);

	FileParser(current, coverSprite, shuffleTex, "ShuffleIcon.png", 'i');
	coverTex.update(songCover);
	shuffleSprite.setTexture(shuffleTex);
	shuffleSprite.setScale(0.05f, 0.05f); // Make White in GIMP!!

	current.setVolume(5);
	current.play();

	while (window.isOpen()) {
		while (window.pollEvent(event)) { // Add mouse picking as well
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // Shuffle
				Shuffle(current, coverSprite, coverTex);
				trackLength = current.getDuration();
				int length = std::floor(trackLength.asSeconds()) / 60; // Minutes
				trackLengthText.setString(std::to_string(length));
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
					current.pause();
					isPlaying = false;
				}
				else {
					current.play();
					isPlaying = true;
				}
			}

			// Mouse Input | Fix, positions are off!
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				// Check range | Prevent double input
				for (int i = 0; i <= 25; i++) {
					if (sf::Mouse::getPosition(window).x == playSprite.getPosition().x - i || sf::Mouse::getPosition(window).x == playSprite.getPosition().x + i) {
						std::cout << "CLICK!\n";
						if (isPlaying) {
							current.pause();
							isPlaying = false;
						}
						else {
							current.play();
							isPlaying = true;
						}
					}
					if (sf::Mouse::getPosition(window).y == playSprite.getPosition().y - i || sf::Mouse::getPosition(window).y == playSprite.getPosition().y + i) {
						std::cout << "CLICK!\n";
						if (isPlaying) {
							current.pause();
							isPlaying = false;
						}
						else {
							current.play();
							isPlaying = true;
						}
					}
					if (sf::Mouse::getPosition(window).x == loopSprite.getPosition().x - i || sf::Mouse::getPosition(window).y == loopSprite.getPosition().x + i) {
						std::cout << "LOOPCLICK!\n";
						if (!isLooping) {
							current.setLoop(true);
							isLooping = true;
						}
						else {
							current.setLoop(false);
							isLooping = false;
						}
					}
					if (sf::Mouse::getPosition(window).x == loopSprite.getPosition().y - i || sf::Mouse::getPosition(window).y == loopSprite.getPosition().y + i) {
						std::cout << "LOOPCLICK!\n";
						if (!isLooping) {
							current.setLoop(true);
							isLooping = true;
						}
						else {
							current.setLoop(false);
							isLooping = false;
						}
					}
				}
			}
		}

		// Shuffle will be different, once track ends, then run function
		currentTime = current.getPlayingOffset();
		playbackBar.setSize(sf::Vector2f(currentTime.asSeconds(), 10.0f));
		currentTimeText.setString(std::to_string(minutes) + ':' + std::to_string((int)currentTime.asSeconds())); // Optimise!!!
		if (currentTime.asSeconds() == 60) // Change when minute is added
			minutes++;
		if (currentTime == trackLength)
			std::cout << "END!\n";

		window.clear();

		window.draw(currentTrack);
		window.draw(trackLengthText);
		window.draw(currentTimeText);
		// Sprites
		window.draw(coverSprite);
		window.draw(playSprite);
		window.draw(loopSprite);
		window.draw(shuffleSprite);
		// Playback
		// window.draw(playbackBackground);
		window.draw(playbackBar);

		window.display();
	}
}

int main() {
	Draw();

	return 0;
}
