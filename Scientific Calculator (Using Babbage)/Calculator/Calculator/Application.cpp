#include "Calculator.h"
Calculator calc;

void Interface() {
	system("cls");
	std::cout << "====Calculator====\n";
	std::cout << "Operations:\n";
	std::cout << "1) Add  2) Subtract  3) Divide  4) Multiply  \n5) Power  6) Custom  7) History  8) PrintStack\n";
	std::cin >> calc.userInput;
	if (calc.userInput != 6 && calc.userInput != 7) { // Remove, error should not exist in first place
		switch (calc.userInput) {
			case 1: std::cout << "Result: " << calc.Add();	  break;
			case 2: std::cout << "Result: " << calc.Sub();    break;
			case 3: std::cout << "Result: " << calc.Divide(); break;
			case 4: std::cout << "Result: " << calc.Mult();   break;
			case 5: std::cout << "Result: " << calc.Power();  break;
			case 8: calc.Print(); break;
			case 9: calc.NewAdd(); break;
		}
	}
	else if(calc.userInput == 6) calc.Custom();
	else calc.FetchHistory();

	std::cin.get();
	std::cin.get();

	Interface();
}

int main() {
	Interface();

	return 0;
}