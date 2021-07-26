#include "Calculator.h"

bool InputStack::IsFull() {
	if (top == 20)
		return true;
	return false;
}

bool InputStack::IsEmpty() {
	if (top == -1)
		return true;
	return false;
}

void InputStack::Push(const std::string &&data) {
	if (IsFull())
		std::cerr << "Stack is full!\n";
	else {
		top++;
		inputs[top] = data;
	}
}

void InputStack::Pop() {
	if (IsEmpty())
		std::cerr << "Stack is empty!\n";
	else {
		inputs[top] = ""; // Check!
		top--;
	}
}

void InputStack::Print() const {
	for (auto i : inputs)
		std::cout << i << " | ";
}

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
	// Use stack to read x amount of numbers
	// Check for terminate symbol
	// Calculate
	std::cout << "Enter first number: "; std::cin >> m_A;
	iStack.Push(std::forward<std::string>(std::to_string(m_A))); // Floor? Retain some decimals
	std::cout << "Enter second number: "; std::cin >> m_B;
	iStack.Push(std::forward<std::string>(std::to_string(m_B)));
	std::string equation = std::to_string(static_cast<int>(m_A)) + " + " + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(m_A + m_B);
	return m_A + m_B;
}

float Calculator::Sub() {
	std::cout << "Enter first number: "; std::cin >> m_A;
	iStack.Push(std::forward<std::string>(std::to_string(m_A)));
	std::cout << "Enter second number: "; std::cin >> m_B;
	iStack.Push(std::forward<std::string>(std::to_string(m_B)));
	std::string equation = std::to_string(static_cast<int>(m_A)) + " - " + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(m_A - m_B);
	return m_A - m_B;
}

float Calculator::Divide() {
	std::cout << "Enter first number: "; std::cin >> m_A;
	iStack.Push(std::forward<std::string>(std::to_string(m_A)));
	std::cout << "Enter second number: "; std::cin >> m_B;
	iStack.Push(std::forward<std::string>(std::to_string(m_B)));
	std::string equation = std::to_string(static_cast<int>(m_A)) + " / " + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(m_A / m_B);
	return m_A / m_B;
}

float Calculator::Mult() {
	std::cout << "Enter first number: "; std::cin >> m_A;
	iStack.Push(std::forward<std::string>(std::to_string(m_A)));
	std::cout << "Enter second number: "; std::cin >> m_B;
	iStack.Push(std::forward<std::string>(std::to_string(m_B)));
	std::string equation = std::to_string(static_cast<int>(m_A)) + " * " + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(m_A * m_B);
	return m_A * m_B;
}

float Calculator::Power() {
	std::cout << "Enter a number: "; std::cin >> m_A;
	iStack.Push(std::forward<std::string>(std::to_string(m_A)));
	std::cout << "Enter a power: "; std::cin >> m_B;
	iStack.Push(std::forward<std::string>(std::to_string(m_B)));
	std::string equation = std::to_string(static_cast<int>(m_A)) + "^" + std::to_string(static_cast<int>(m_B));
	hisEquations.push_back(equation);
	hisAnswers.push_back(pow(m_A, m_B));
	return pow(m_A, m_B);
}

float Calculator::Squareroot() {
	std::cout << "Enter a number: "; std::cin >> m_A;
	iStack.Push(std::forward<std::string>(std::to_string(m_A)));
	hisAnswers.push_back(sqrt(m_A));
	return sqrt(m_A);
}

void Calculator::Print() const {
	iStack.Print();
}

void Calculator::NewAdd() { // Recursive function, backtrack? | Map, have to search for brackets first
	// Create a new stack???
	InputStack newStack;
	std::string current;
	float sum = 0.0f;
	std::cout << "Enter equation\t";
	std::vector<int> values;
	std::vector<char> symbols;
	while (1) {
		std::cin >> current;
		if (current == "?") // Terminate symbol
			break;
		newStack.Push(std::forward<std::string>(current));
		current.clear();
	}
	int itemCount = 0;
	for (int i = 0; i < newStack.inputs.size()-1; i++) {
		if (newStack.inputs[i] == "(") {// Calculate brackets block | Improve efficiency, nested for loop is slow!
			// mark first non-bracket item
			// Check for more brackets '('!
			for (int j = i+1; j < newStack.inputs.size(); j++) { // Brackets, only, can possibly remove
				itemCount++;
				if (newStack.inputs[j] == ")") {
					// Calculate block
					
				}
			}
		}
	}

	// Two pointer technique instead!
	int left = 0;
	int right = 0;
	int lBracketCount = 0;
	int rBracketCount = 0;
	while (1) {
		if (newStack.inputs[left] != "(") {
			left++;
			right++;
		}
		else {
			// Search for bracket
			right++;
			// Find_last_of
			if (newStack.inputs[right] == "(") {
				left = right;
			}
		}
	}

	std::cout << sum;
}