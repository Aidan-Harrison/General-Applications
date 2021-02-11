#include <iostream>
#include "Calculator.h"
Calculator calc;

int main() {
	system("cls");
	std::cout << "====Calculator====\n";
	std::cout << "Operations:\n";
	std::cout << "1) Add  2) Subtract  3) Divide  4) Multiply  5) Power  6) Custom  7) History\n";
	std::cin >> calc.userInput;
	if (calc.userInput != 6 && calc.userInput != 7) {
		switch (calc.userInput) {
			case 1: std::cout << "Result: " << calc.Add();	  break;
			case 2: std::cout << "Result: " << calc.Sub();    break;
			case 3: std::cout << "Result: " << calc.Divide(); break;
			case 4: std::cout << "Result: " << calc.Mult();   break;
			case 5: std::cout << "Result: " << calc.Power();  break;
		}
	}
	else if(calc.userInput == 6) calc.Custom();
	else calc.FetchHistory();
	std::cin.get();
	std::cin.get(); 
	main();
	return 0;
}