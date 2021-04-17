#include "Student.h"

Student::Student(const std::string& fName, const std::string &sName, short age, short year)
	:m_FirstName(fName), m_SurName(sName), m_Age(age), m_Year(year)
{
	assert(age != 0);
	CheckAge();
}

void Student::SetName() {

}

bool Student::CheckAge() { // Checks whether the age - year is correct.
	if(m_Age == 10 || m_Age == 11) {
		if(m_Year != 7 || m_Year != 8) {
			std::cout << "Invalid!\n" <<
				"Student cannot be in year " << m_Year << " at the age of " << m_Age;
			return false;
		}
		return true;
	}
	else if (m_Age == 12 || m_Age == 13) {
		if (m_Year != 8 || m_Year != 9) {
			std::cout << "Invalid!\n" <<
				"Student cannot be in year " << m_Year << " at the age of " << m_Age;
			return false;
		}
		return true;
	}
	else if (m_Age == 13 || m_Age == 14) {
		if (m_Year != 9 || m_Year != 10) {
			std::cout << "Invalid!\n" <<
				"Student cannot be in year " << m_Year << " at the age of " << m_Age;
			return false;
		}
		return true;
	}
	else if (m_Age == 15 || m_Age == 16) {
		if (m_Year != 10 || m_Year != 11) {
			std::cout << "Invalid!\n" <<
				"Student cannot be in year " << m_Year << " at the age of " << m_Age;
			return false;
		}
		return true;
	}
}