#ifndef Calculator_h
#define Calculator_h

#include <iostream>
#include <string>
#include <vector>
// Use Babbage

struct Calculator {
	int userInput = 0;
	float Custom();
	void FetchHistory();
	float Add();
	float Sub();
	float Divide();
	float Mult();
	float Square();
	std::vector<std::string> hisEquations{}; // Equations here
	std::vector<float> hisAnswers{}; // Answers get added to here
};

#endif