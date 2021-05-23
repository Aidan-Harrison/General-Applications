// Password Checker
#include <iostream>
#include <string>
#include <vector>
#include <array>

void CreateAccount();

struct person {
    std::string firstName = "";
    std::string surName = "";
    std::string username = "";
    std::string password = "";
    short m_Age = 1;
    short birthDay = 6, birthMonth = 8, birthYear = 1999;
    std::string occupation = "";
    std::string email = "";
    std::array<std::string, 3> hobbies{" ", " ", " "};
    person() = default;
    // Don't use this!
    person(const std::string &fName, const std::string &sName, short age, short bDay, short bMonth, short bYear) 
        :firstName(fName), surName(sName), m_Age(age), birthDay(bDay), birthMonth(bMonth), birthYear(bYear) 
    {
    }
};

// Username
short length = 0;
// Password
short strength = 1;
bool hasNumber = false;
bool hasSymbol = false;
bool hasUpper = false;
bool correct = false;

// Data
std::vector<std::string> firstNames = {
    "Mary",
    "Tim",
    "Andre",
    "Elon",
    "Sarah",
    "Micheal"
};

std::vector<std::string> surNames = {
    "Harrison",
    "Preston",
    "Hunt",
    "Winters"
};

std::vector<std::string> occupations = {
    "Truck Driver",
    "Software Engineer",
    "Construction Worker",
    "Business Manager",
    "Accountant",
    "Engineer",
    "Unemployed"
};

std::vector<std::string> hobbies = {
    "Painting",
    "Cooking",
    "Gaming",
    "Fishing",
    "Hiking",
    "Dancing"
};

void PrintPerson(person &p, int amount) {
    std::cout << "(" << amount << ")";
    std::cout << "Firstname: " << p.firstName << '\n';
    std::cout << "Surname: " << p.surName << '\n';
    std::cout << "Age: " << p.m_Age << '\n';
    std::cout << "Date of birth: " << p.birthDay << '/' << p.birthMonth << '/' << p.birthYear << '\n';
    std::cout << "Occupation: " << p.occupation << '\n'; 
    std::cout << "Hobbies:\n"; 
    for(int i = 0; i < p.hobbies.size(); i++) {
        if(p.hobbies[i] != " ")
            std::cout << p.hobbies[i] << ", ";
    }
}

void GeneratePerson(int amount) {
    short currentYear = 2021;
    int index = 0;
    for(int i = 0; i < amount; i++) {
        person p;
        index = rand() % firstNames.size();
        p.firstName = firstNames[index];
        index = rand() % surNames.size();
        p.surName = surNames[index];
        index = rand() % 100;
        p.m_Age = index;
        if(p.m_Age > 18) {
            index = rand() % occupations.size();
            p.occupation = occupations[index];
        }
        else if(p.m_Age > 65) {
            p.occupation = "Retired";
        }
        else {
            p.occupation = "Unemployed";
        }
        // Date of birth
        p.birthMonth = rand() % 12;
        if(p.birthMonth == 2) // Do all months
            p.birthDay = rand() % 28;
        else
            p.birthDay = rand() % 31;
        p.birthDay++; // prevents 0
        p.birthMonth++;
        p.birthYear = currentYear -= p.m_Age;
        // Hobbies
        if(p.m_Age > 6) {
            index = rand() % 4;
            for(int i = 0; i < index; i++)
                p.hobbies[i] = hobbies[i];
        }
        // E-Mail
        p.email += p.firstName += p.surName += p.birthYear + "@gmail.com";

        PrintPerson(p, amount);
    }
}

void Login(person &p) {
    std::string credential = "";
    std::cout << "Enter username or email:"; std::cin >> credential;
    if(credential != p.username || credential != p.email)
        std::cout << "You have entered an incorrect username or email:";
    std::cout << "Enter password:"; std::cin >> credential;
}

void CredentialsChecker(person &p) {
    if(p.username.length() < 6) {
        std::cout << "Your username must contain at least 6 characters!\n";
        CreateAccount();
    }
    // Do password | Use map??
    
    // email
    if(!p.email.find("@gmail.com")) // Check!
        std::cout << "Your email is invalid!\n";
}

void CreateAccount() { // Creates person manually
    person customP;
    short value = 0;
    std::cout << "Enter a username and password";
    std::cin >> customP.username >> customP.password;
    std::cout << "Enter an email address";
    std::cin >> customP.email;
    std::cout << "Enter your age (Must be at least 13)";
    std::cin >> value;
    if(value < 13)
        std::cout << "You have entered an invalid age!\nTry again!";

    CredentialsChecker(customP);
}

int main() {
    std::string username;
    std::string pass = "", strengthText = "";
    
    // Password checker | Update! Use Map???
    while(!correct) {
        system("cls");
        std::cout << "Enter a password (Must-Contain a Uppercase letter, Symbol and a Number)" << '\n'; 
        std::cin >> pass;

        for(int i = 0; i < pass.length(); i++) {
            if(!hasNumber) { // Pointless checking characters if a number, symbol or uppercase has already been found
                if(pass[i] == '0' || pass[i] == '1' || pass[i] == '2' || pass[i] == '3' || pass[i] == '4' || pass[i] == '5'
                || pass[i] == '6' || pass[i] == '7' || pass[i] == '8' || pass[i] == '9') {
                    hasNumber = true;
                }
            }
            if(!hasSymbol) {
                if(pass[i] == '@' || pass[i] == '!' || pass[i] == '#' || pass[i] == '~' || pass[i] == '$' || pass[i] == '*'
                || pass[i] == '?' || pass[i] == '&' || pass[i] == '(' || pass[i] == ')') {
                    hasSymbol = true;
                }
            }
            if(!hasUpper) {
                if(pass[i] == 'A' || pass[i] == 'B' || pass[i] == 'C' || pass[i] == 'D' || pass[i] == 'E' || pass[i] == 'F'
                || pass[i] == 'G' || pass[i] == 'H' || pass[i] == 'I' || pass[i] == 'J' || pass[i] == 'K' || pass[i] == 'L'
                || pass[i] == 'M' || pass[i] == 'N' || pass[i] == 'O' || pass[i] == 'P' || pass[i] == 'Q' || pass[i] == 'R'
                || pass[i] == 'S' || pass[i] == 'T' || pass[i] == 'U' || pass[i] == 'V' || pass[i] == 'W' || pass[i] == 'X'
                || pass[i] == 'Y' || pass[i] == 'Z') {
                    hasUpper = true;
                }
            }
        }

        if(!hasNumber) std::cout << "Your password does not contain a number!  Try Again!\n";
        if(!hasSymbol) std::cout << "Your password does not contain a symbol!  Try Again!\n";
        if(!hasUpper)  std::cout << "Your password does not contain a Uppercase letter!  Try Again!\n";
        
        if(strength < 3) strengthText = "Weak";
        else if(strength > 3 && strength < 6) strengthText == "Good";
        else if(strength > 6 && strength < 9) strengthText == "Great";
        else if(strength > 9 && strength < 12) strengthText == "Excellent";

        hasNumber = false;
        hasSymbol = false;
        hasUpper = false;
        std::cout << "Press enter to continue: ";
        std::cin.get();
        std::cin.get();
    }
    // Password strength
    std::cout << "\nYour username is: " << username;
    std::cout << "\nYour password is: " << pass;
    std::cout << "\nPassword strength: " << std::string("/" + strength) << " " << strengthText;

    return 0;
};