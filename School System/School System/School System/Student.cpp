#include "Student.h"

Student::Student(const std::string& fName, const std::string &sName, short age, short year)
	:m_FirstName(fName), m_SurName(sName), m_Age(age), m_Year(year)
{
	assert(age != 0);
	CheckAge();
}

void Student::SetName() {
	std::cin >> m_FirstName >> m_SurName;
}

bool Student::CheckAge() { // Checks whether the age - year is correct.
	if(m_Age == 10 || m_Age == 11) {
		if(m_Year != 7 || m_Year != 8) {
			std::cout << "Invalid!\n" 
					  << "Student cannot be in year " << m_Year << " at the age of " << m_Age;
			return false;
		}
		return true;
	}
	else if (m_Age == 12 || m_Age == 13) {
		if (m_Year != 8 || m_Year != 9) {
			std::cout << "Invalid!\n" 
					  << "Student cannot be in year " << m_Year << " at the age of " << m_Age;
			return false;
		}
		return true;
	}
	else if (m_Age == 13 || m_Age == 14) {
		if (m_Year != 9 || m_Year != 10) {
			std::cout << "Invalid!\n" 
					  << "Student cannot be in year " << m_Year << " at the age of " << m_Age;
			return false;
		}
		return true;
	}
	else if (m_Age == 15 || m_Age == 16) {
		if (m_Year != 10 || m_Year != 11) {
			std::cout << "Invalid!\n" 
					  << "Student cannot be in year " << m_Year << " at the age of " << m_Age;
			return false;
		}
		return true;
	}
}

void Student::GetCiriculum() {
	for (unsigned int i = 0; i < 5; i++) {
		for (unsigned int j = 0; j < 5; j++) {
			std::cout << cirriculum[0][j].GetName() << '\n';
		}
	}
}

Subject PrintSubjects() { // Check return | Address or Ref return???? | Get Switch working
	short choice = 0, length = 0;
	std::cout << "1) English\n"
			  << "2) Science\n"
			  << "3) Mathematics\n"
			  << "4) Art\n"
			  << "5) Drama\n"
			  << "6) Break/Nothing\n";
	while (1) {
		std::cin >> choice;
		while (choice > 6) {
			std::cout << "Invalid choice!\n";
			std::cin >> choice;
		}
		std::cout << "Set Length (Minutes) | Cannot be less then 30: "; std::cin >> length;
		while (length < 30) {
			std::cout << "Lesson cannot be shorter then 30 minutes!\n";
			std::cin >> length;
		}
		switch (choice) {
			case 1: {Subject english("English", length);		 return english;}
			case 2: {Subject science("Science", length);	     return science;}
			case 3: {Subject mathematics("Mathematics", length); return mathematics;}
			case 4: {Subject art("Art", length);                 return art;}
			case 5: {Subject drama("Drama", length);			 return drama;}
			case 6: {Subject Break("Break", length);			 return Break; }
		}
	}
}

void Student::SetCiriculum() {
	while (monday.size() <= 3) {
		system("cls");
		std::cout << "Monday:\n";
		std::cout << "Amount of lessons (Max 3): " << monday.size() << '\n';
		monday.push_back(PrintSubjects());
	}

	while (tuesday.size() <= 3) {
		system("cls");
		std::cout << "Tuesday:\n";
		std::cout << "Amount of lessons (Max 3): " << tuesday.size() << '\n';
		tuesday.push_back(PrintSubjects());
	}

	while (wednesday.size() <= 3) {
		system("cls");
		std::cout << "Wednesday:\n";
		std::cout << "Amount of lessons (Max 3): " << wednesday.size() << '\n';
		wednesday.push_back(PrintSubjects());
	}

	while (thursday.size() <= 3) {
		system("cls");
		std::cout << "Thursday:\n";
		std::cout << "Amount of lessons (Max 3): " << thursday.size() << '\n';
		thursday.push_back(PrintSubjects());
	}

	while (friday.size() <= 3) {
		system("cls");
		std::cout << "Friday:\n";
		std::cout << "Amount of lessons (Max 3): " << friday.size() << '\n';
		friday.push_back(PrintSubjects());
	}
}