#include "Calculator.h"

float Calculator::Custom() {
	std::string input;
	std::vector<float> values;
	std::vector<char> operators;
	std::cout << "Enter a string consisting of only numbers and" << "+, -, /, * or x:\n";
	std::cin >> input;
	// Check
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input == "=") { operators.push_back('='); }
		else if (input == "+") { operators.push_back('+'); }
		else if (input == "-") { operators.push_back('-'); }
		else if (input == "/") { operators.push_back('/'); }
		else if (input == "*" || input == "x") { operators.push_back('*'); }
		else
			values.push_back(std::stoi(input));
	}
	// Calculate

	return 1;
}

void Calculator::FetchHistory() {
	std::cout << "====History====\n";
	for (unsigned int i = 0; i < hisAnswers.size(); i++)
		std::cout << hisEquations[i] << " = " << hisAnswers[i] << '\n';
}

float Calculator::Add() {
	float a, b; // Possibly abstract input system
	std::cout << "Enter first number: "; std::cin >> userInput;
	a = userInput;
	std::cout << "Enter second number: "; std::cin >> userInput;
	b = userInput;
	std::string equation = std::to_string(static_cast<int>(a)) + " + " + std::to_string(static_cast<int>(b));
	hisEquations.push_back(equation);
	hisAnswers.push_back(a + b);
	return a + b; 
}
float Calculator::Sub() {
	float a, b;
	std::cout << "Enter first number: "; std::cin >> userInput;
	a = userInput;
	std::cout << "Enter second number: "; std::cin >> userInput;
	b = userInput;
	std::string equation = std::to_string(static_cast<int>(a)) + " - " + std::to_string(static_cast<int>(b));
	hisEquations.push_back(equation);
	hisAnswers.push_back(a - b);
	return a - b; 
}
float Calculator::Divide() {
	float a, b;
	std::cout << "Enter first number: "; std::cin >> userInput;
	a = userInput;
	std::cout << "Enter second number: "; std::cin >> userInput;
	b = userInput;
	std::string equation = std::to_string(static_cast<int>(a)) + " / " + std::to_string(static_cast<int>(b));
	hisEquations.push_back(equation);
	hisAnswers.push_back(a / b);
	return a / b; 
}
float Calculator::Mult() {
	float a, b;
	std::cout << "Enter first number: "; std::cin >> userInput;
	a = userInput;
	std::cout << "Enter second number: "; std::cin >> userInput;
	b = userInput;
	std::string equation = std::to_string(static_cast<int>(a)) + " * " + std::to_string(static_cast<int>(b));
	hisEquations.push_back(equation);
	hisAnswers.push_back(a * b);
	return a * b; 
}

float Calculator::Square() {
	std::cin >> userInput;
	std::string equation = std::to_string(static_cast<int>(userInput)) + "2\n"; // Add wide char to support unicode and thus square symbol?
	hisEquations.push_back(equation);
	hisAnswers.push_back(userInput * userInput);
	return userInput * userInput;
}