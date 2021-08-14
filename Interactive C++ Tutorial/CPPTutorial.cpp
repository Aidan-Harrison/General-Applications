#include <iostream>
#include <sstream>

int input;

// Add page turning

void FunctionTut() {

}

void FlowTut() {
    system("cls");
    std::cout << "While we have reduced the amount of work we have to do to change the output, it still seems tedious to have to write out a print statement 8 times to get 8 prints.\n"
              << "If only their was a way to automate the process, so we could print as many x's as we wanted by changing a single value. There is!\n"
              << "Flow control comes to save the day. Flow control refers to the following statements\n\t"
              << "'if'/'if else'\n\t 'for' and 'for-each' loops\n\t 'while' loops \n\t 'switch' statements\n\t 'goto' statements\n";
    std::cout << "It seems like a lot but they are all simple in thier own regards. We shall start with 'for' loops to addresss our previous issue.";
    std::cin.get();
    std::cin.get();
    system("cls");
}

void VariableTut() {
    system("cls");
    std::cout << "Variables can thought of as containers in which we store 'stuff' to manage and use at a later date. Take the following snippet of code for example:\n"
              << "std::cout << 5 << std::endl;\n" << "This prints the number 5 out to the console, great, but now take this example:\n";
    for(unsigned int i = 0; i <= 8; i++)
        std::cout << "std::cout << 5 << std::endl;\n";
    std::cout << "It seems harmless enough, printing the number 5 out 8 times. However. What if we wanted to change the value? We would have to go and change all 8 lines to a different\n" 
              << "number. This is tedious, we can do better. Enter variables, variables can resolve our issue by storing our data (in this case '5') and allowing us to call the variable instead.\n" 
              << "Creating a variable goes as follows:\n\t data type -> variable name -> data.\n Note that the 'data' part is not required but is encouraged to be initialised with something.";
    std::cout << "PRESS ENTER TO CONTINUE!";
    std::cin.get();
    std::cin.get();
    system("cls");
    std::cout << "Let's create a variable:\n\t" << "int x = 5;\n" << "Here we have created a integer (Whole number), with the name 'x' and initialised it with a value of '5'.";
    std::cout << "So let's apply this to our previous example:\n";
    for(unsigned int i = 0; i <= 8; i++)
        std::cout << "std::cout << x << std::endl;\n";
    std::cout << "We get the same result! This time however if we want to change the value, we need only change 'x' instead of all 8 lines. Drastically reducing the amount of work we have to do!\n";
    std::cin.get();
    std::cin.get();
    FlowTut();
}

void HomeTut() {
    std::cout << "Welcome to an interactive C++ tutorial!\n This tutorial aims to teach the basic concepts and import libraries of C++ in a simple, quick manner with interactive steps.";
    std::cout << "Press enter to continue to skip to a chapter:\n\t";
    std::cout << "ENTER) Continue\t 1) Variables\t 2) Flow Control\t 3) Functions\t";
    std::cin >> input;
    switch (input) {
        case 1: VariableTut(); break;
        case 2: FlowTut(); break;
        case 3: FunctionTut(); break;
        default: VariableTut(); break;
    }
}

int main() {
    HomeTut();

    return 0; 
}