#ifndef Songs_h
#define Songs_h

#include <vector>

#include <SFML/Audio.hpp>

namespace Songs {
	std::vector<std::string> songs{ "Tekken 3 Character Select Theme.ogg", "Street Fighter III 3rd Strike - Let's Get It On.ogg", "Marvel vs. Capcom 2 OST - Clock Tower Stage.ogg", "Ridge Racer Type 4 - One More Win.ogg" };
}

namespace Covers {
	std::vector<std::string> covers{"Tekken3Logo.jpg", "StreetFighter3Cover.png", "MarvelVsCapcom2.jpg", "RidgeRacerType4.jpg"};
}

#endif