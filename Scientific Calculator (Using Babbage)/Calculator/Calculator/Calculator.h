#ifndef Calculator_h
#define Calculator_h

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <utility>

// Use Babbage

struct InputStack {
	InputStack() {}

	int top = -1;
	std::array<std::string, 20> inputs{};

	bool IsFull();
	bool IsEmpty();
	void Push(const std::string &&data);
	void Pop();

	void Print() const;

	~InputStack() {}
};

class Calculator {
private:
	float m_A, m_B; // Allow for an arbitary amount of values
public:
	InputStack iStack;

	int userInput = 0;
	void FetchHistory();
		// Basic Operations
	float Add();
	float Sub();
	float Divide();
	float Mult();
	float Power();
	float Squareroot();

	void NewAdd();

	float Custom();

	void Print() const;

	std::vector<std::string> hisEquations{}; // Equations here
	std::vector<float> hisAnswers{}; // Answers get added to here
};

#endif