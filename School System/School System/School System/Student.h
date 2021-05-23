#ifndef Student_h
#define Student_h

#include <iostream>
#include <vector>
#include <cassert>
#include "subjects.h"

class Student { // Heap allocate students
private:
	std::string m_FirstName = "", m_SurName = "";
	int m_Age = 11, m_Year = 7; // Year == Grade
public:
	std::vector<Subject> monday{};
	std::vector<Subject> tuesday{};
	std::vector<Subject> wednesday{};
	std::vector<Subject> thursday{};
	std::vector<Subject> friday{};
	std::vector<std::vector<Subject>> cirriculum{monday, tuesday, wednesday, thursday, friday};

	Student(const std::string& fName, const std::string& sName, short age, short year);
	~Student() = default;
	std::string GetName() const { return m_FirstName + ' ' + m_SurName; }
	std::string GetSurname() const { return m_SurName; }
	int GetAge() const { return m_Age; }
	int GetYear() const { return m_Year; }

	bool CheckAge();
	void SetName();

	void ChangeDetails();

	void GetCiriculum();
	void SetCiriculum();
};

#endif