#ifndef Student_h
#define Student_h

#include <iostream>
#include <vector>
#include <cassert>
#include "subjects.h"

class Student { // Heap allocate students
private:
	std::string m_FirstName = "", m_SurName = "";
	std::string m_FullName = m_FirstName + m_SurName; // Check! r-value
	int m_Age = 11, m_Year = 7; // Year == Grade
public:
	std::vector<Subject> cirriculum{};
	Student(const std::string& fName, const std::string& sName, short age, short year);
	~Student() = default;
	std::string GetName() const { return m_FullName; }
	int GetAge() const { return m_Age; }
	int GetYear() const { return m_Year; }

	bool CheckAge();
	void SetName();
};

#endif