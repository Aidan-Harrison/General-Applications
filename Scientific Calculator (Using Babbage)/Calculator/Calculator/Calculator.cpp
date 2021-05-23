#include "Calculator.h"

float Calculator::Custom() {
	std::string input;
	std::vector<float> values;
	std::vector<char> operators;
	std::cout << "Enter a string consisting of only numbers and" << "+, -, /, * or x (Spaces allowed):\n";
	std::cin >> input;
	// Check
	for (unsigned int i = 0; i < input.length(); i++) {
		if(input == "=") { operators.push_back('='); }
		else if(input == "+") { operators.push_back('+'); }
		else if(input == "-") { operators.push_back('-'); }
		else if(input == "/") { operators.push_back('/'); }
		else if(input == "*" || input == "x") { operators.push_back('*'); }
		else
			values.push_back(std::stoi(input));
	}
	// Calculate

	return 1;
}
void Calculator::FetchHistory() {
	std::cout << "====History====\n";
	for(unsigned int i = 0; i < hisAnswers.size(); i++)
		std::cout << hisEquations[i] << " = " << hisAnswers[i] << '\n';
}
float Calculator::Add() {
	std::cout << "Enter first number: "; std::cin >> m_A;
	std::cout << "Enter second number: "; std::cin >> m_B;
	std::string equation = std::to_string(static_cast<int>(m_A)) + " + " + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(m_A + m_B);
	return m_A + m_B;
}
float Calculator::Sub() {
	std::cout << "Enter first number: "; std::cin >> m_A;
	std::cout << "Enter second number: "; std::cin >> m_B;
	std::string equation = std::to_string(static_cast<int>(m_A)) + " - " + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(m_A - m_B);
	return m_A - m_B;
}
float Calculator::Divide() {
	std::cout << "Enter first number: "; std::cin >> m_A;
	std::cout << "Enter second number: "; std::cin >> m_B;
	std::string equation = std::to_string(static_cast<int>(m_A)) + " / " + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(m_A / m_B);
	return m_A / m_B;
}
float Calculator::Mult() {
	std::cout << "Enter first number: "; std::cin >> m_A;
	std::cout << "Enter second number: "; std::cin >> m_B;
	std::string equation = std::to_string(static_cast<int>(m_A)) + " * " + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(m_A * m_B);
	return m_A * m_B;
}
float Calculator::Power() {
	std::cout << "Enter a number: "; std::cin >> m_A;
	std::cout << "Enter a power: "; std::cin >> m_B;
	std::string equation = std::to_string(static_cast<int>(userInput)) + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(pow(m_A, m_B));
	return pow(m_A, m_B);
}
float Calculator::Squareroot() {
	std::cout << "Enter a number: "; std::cin >> m_A;
	hisAnswers.push_back(sqrt(m_A));
	return sqrt(m_A);
}

float Calculator::Custom() { // DO PEMDAS
	std::string input = "";
	std::cin >> input;
	for (unsigned int i = 0; i < input.length(); i++) {
		return;
	}
}