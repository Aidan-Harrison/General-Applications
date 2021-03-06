#ifndef Calculator_h
#define Calculator_h

#include <iostream>
#include <string>
#include <vector>
// Use Babbage

struct Calculator {
	float m_A, m_B;
	int userInput = 0;
	float Custom();
	void FetchHistory();
		// Basic Operations
	float Add();
	float Sub();
	float Divide();
	float Mult();
	float Power();
	float Squareroot();
	std::vector<std::string> hisEquations{}; // Equations here
	std::vector<float> hisAnswers{}; // Answers get added to here
};

#endif