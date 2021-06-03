#include <iostream>
#include <fstream>
#include <vector>

#include <SFML/Graphics.hpp>

std::fstream fileHandler;
std::fstream fileStorage;

std::vector<std::string> files{};

void ParseFile(const std::string &filePath) {
	fileHandler.open(filePath);
	fileStorage.open("");// Add storage
	if (fileHandler.fail()) {
		std::cerr << "Invalid file path or file is corrupt!\n";
	}
	else {
		std::cout << "Successfully opened file: " << filePath << '\n';
		if (filePath.find_last_of(".jpeg") || filePath.find_last_of("png")) {
			sf::Image img; // Or texture!?
			img.loadFromFile(filePath);
			// Store

		}
		else if (filePath.find_last_of(".txt")) {
			return; // DO!
		}
	}
	if (fileStorage.fail()) { // Must function
		std::cerr << "Failed to open storage file! Either missing or corrupt\n";
		exit(1);
	}
	else { // Write to .txt file
		return;
		// Add file path to .txt file
	}
}

void ViewFiles() { // Add graphics!?
	for (std::string i : files)
		std::cout << i << '\n';
	std::cin.get();
	std::cin.get();
}

void FileHandler() {
	short choice = 0;
	std::cout << "What would you like to do!\n"
		<< "1) View Files  2) Import files\n";
	if (choice == 1)
		ViewFiles();
	else {
		system("cls");
		std::string filePath = "";
		std::cout << "Import a file: ";
		std::cin >> filePath;
		ParseFile(filePath);
	}
}