#include <iostream>
#include <thread>
#include <chrono>
#include <tuple>
#include <vector>

#include <SFML/Graphics.hpp>

int screenWidth = 800, screenHeight = 600;

struct timer {
	sf::Font font;
	struct time {
		std::tuple<int, int, int> lap;
		sf::Font f;
		int hour = 0, minutes = 0, seconds = 0;
		int state = 0;
		sf::Text hourText;
		sf::Text minuteText;
		sf::Text secondsText;

		std::tuple<sf::Text, sf::Text, sf::Text> seperators{};

		time() 
		{
			if(!f.loadFromFile("Fonts/InputSansNarrow-Light.ttf")) {
				std::cerr << "Failed to load 'time' font!\n";
				exit(1);
			}

			hourText.setFont(f);
			minuteText.setFont(f);
			secondsText.setFont(f);

			hourText.setString(std::to_string(hour));
			minuteText.setString(std::to_string(minutes));
			secondsText.setString(std::to_string(seconds));

			hourText.setCharacterSize(150.0f);
			minuteText.setCharacterSize(150.0f);
			secondsText.setCharacterSize(150.0f);

			hourText.setPosition((float)screenWidth/4, (float)screenHeight/2);
			minuteText.setPosition((float)screenWidth/2, (float)screenHeight/2);
			secondsText.setPosition((float)screenWidth/1.5, (float)screenHeight/2);

			// Seperators | Iterator?? | Do loop of some sort?
			std::get<0>(seperators).setFont(f);
			std::get<1>(seperators).setFont(f);
			std::get<2>(seperators).setFont(f);

			std::get<0>(seperators).setCharacterSize(150.0f);
			std::get<1>(seperators).setCharacterSize(150.0f);
			std::get<2>(seperators).setCharacterSize(150.0f);

			std::get<0>(seperators).setString(":");
			std::get<1>(seperators).setString(":");
			std::get<2>(seperators).setString(":");

			std::get<0>(seperators).setPosition((float)screenWidth / 3, (float)screenHeight / 2);
			std::get<1>(seperators).setPosition((float)screenWidth / 1.75, (float)screenHeight / 2);
			std::get<2>(seperators).setPosition((float)screenWidth / 1.25, (float)screenHeight / 2);
		}
		~time() {}
		// Fix! Text is not changing!
		void Update() {
			while (1) {
				std::this_thread::sleep_for(std::chrono::seconds(1)); // Change to something else, apparently threading and chrono isn't the best
				// May cause issues if running multiple timers becomes a thing, would have to use atomics++ | Might want to use atomics regardless
				seconds++;
				std::cout << seconds << '\n';
				secondsText.setString(std::to_string(seconds));
				if (seconds == 60) {
					seconds = 0;
					secondsText.setString("0"); // Cheaper to just directly set it instead of converting
					minutes++;
					minuteText.setString(std::to_string(minutes));
				}
				if (minutes == 60) {
					minutes = 0;
					minuteText.setString("0");
					hour++;
					hourText.setString(std::to_string(hour));
				}
			}
		}

		std::tuple<int,int,int> GetLap() {
			std::get<0>(lap) = hour;
			std::get<1>(lap) = minutes;
			std::get<2>(lap) = seconds;
			return lap;
		}

		void Draw(sf::RenderWindow& window) {
			window.draw(hourText);
			window.draw(minuteText);
			window.draw(secondsText);

			window.draw(std::get<0>(seperators));
			window.draw(std::get<1>(seperators));
			window.draw(std::get<2>(seperators));
		}
	};

	std::tuple<sf::Text, sf::Text, sf::Text> units{};

	std::vector<std::tuple<int,int,int>> laps{};
	//std::vector<std::tuple<sf::Text,sf::Text,sf::Text>> lapsText{};
	
	// Buttons
	sf::RectangleShape startButton;
	sf::Text startText;
	sf::RectangleShape stopButton;
	sf::Text stopText;

	timer() 
	{
		if(!font.loadFromFile("Fonts/InputSansNarrow-Light.ttf")) {
			std::cerr << "Failed to load font!\n";
			exit(1);
		}
		
		std::get<0>(units).setFont(font);
		std::get<1>(units).setFont(font);
		std::get<2>(units).setFont(font);

		std::get<0>(units).setString("Hours");
		std::get<1>(units).setString("Minutes");
		std::get<2>(units).setString("Seconds");

		// Check position
		//std::get<0>(units).setPosition(std::get<0>(lapsText[0]).getPosition().x, std::get<0>(lapsText[0]).getPosition().y - 25.0f);
		//std::get<1>(units).setPosition(std::get<0>(lapsText[1]).getPosition().x, std::get<0>(lapsText[1]).getPosition().y - 25.0f);
		//std::get<2>(units).setPosition(std::get<0>(lapsText[2]).getPosition().x, std::get<0>(lapsText[2]).getPosition().y - 25.0f);
		
		startButton.setFillColor(sf::Color::Green);
		startButton.setSize(sf::Vector2f(100.0f, 100.0f));
		startButton.setPosition((float)screenWidth / 3, (float)screenHeight - 100.0f);
		startButton.setOrigin(startButton.getSize().x/2, startButton.getSize().y/2);

		stopButton.setFillColor(sf::Color::Red);
		stopButton.setSize(sf::Vector2f(100.0f, 100.0f));
		stopButton.setPosition((float)screenWidth / 1.5, (float)screenHeight - 100.0f);
		stopButton.setOrigin(stopButton.getSize().x/2, stopButton.getSize().y/2);

		startText.setFont(font);
		startText.setString("START");
		startText.setOrigin(startText.getLocalBounds().width/2, startText.getLocalBounds().height/2);
		startText.setPosition(startButton.getPosition().x, startButton.getPosition().y);

		stopText.setFont(font);
		stopText.setString("STOP");
		stopText.setOrigin(stopText.getLocalBounds().width/2, stopText.getLocalBounds().height/2);
		stopText.setPosition(stopButton.getPosition().x, stopButton.getPosition().y);
	}
	~timer() {}

	bool displayLaps = true;
	bool stopped = true;
	time t; // Check!

	// State machine | Possibly remove
	enum {COUNTING, STOPPED, LAP};

	void Count();
	void Draw(sf::RenderWindow& window);

	void Lap();
};

void timer::Draw(sf::RenderWindow &window) {
	window.draw(startButton);
	window.draw(stopButton);
	window.draw(startText);
	window.draw(stopText);

	/*
	if(displayLaps) {
		window.draw(std::get<0>(lapsText[0]));
		window.draw(std::get<1>(lapsText[1]));
		window.draw(std::get<2>(lapsText[2]));
	}
	*/

	t.Draw(window);
}

void timer::Lap() {
	std::tuple<int, int, int> current = t.GetLap();
	laps.push_back(current);
}

void Interface() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Graphical Timer/Clock");
	sf::Event event;
	window.setFramerateLimit(15); 
	timer t;

	while(window.isOpen()) {
		while (window.pollEvent(event)) {
			// Keyboard inputs
			if (event.type == sf::Event::KeyPressed) { // Start/Stop  
				if (event.key.code == sf::Keyboard::S) {
					switch (t.stopped) {
						case true: t.stopped = false; break;
						case false: t.stopped = true; break;
					}
				}
			}
			if (event.type == sf::Event::KeyPressed) { // Show/Hide (Change modes?)
				if (event.key.code == sf::Keyboard::D) {
					switch (t.displayLaps) {
						case false: t.displayLaps = true; break;
						case true: t.displayLaps = false; break;
					}
				}
			}
			// Mouse inputs | Change to event!
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				for(int i = 0; i < t.startButton.getSize().x; i++)
					if (sf::Mouse::getPosition().x == t.startButton.getPosition().x + 25.0f || sf::Mouse::getPosition().y == t.startButton.getPosition().y - 25.0f) {
						t.stopped = false;
						putchar('s');
					}
					if (sf::Mouse::getPosition().x == t.stopButton.getPosition().x + 25.0f || sf::Mouse::getPosition().y == t.stopButton.getPosition().y - 25.0f) {
						t.stopped = true;
						putchar('t');
					}
			}
		}
		window.clear();

		if(!t.stopped)
			t.t.Update();
		t.Draw(window);
		
		window.display();
	}
}

int main() {
	Interface();

	return 0;
}