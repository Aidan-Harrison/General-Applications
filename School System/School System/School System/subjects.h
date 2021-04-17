#ifndef subjects_h
#define subjects_h

#include <iostream>
#include <vector>

// Found proper solution
class Subject{ // Heap allocate
private:
	std::string subjectName = "";
	short lessonLength = 30; // Based in minutes
public:
	Subject() = default;
	Subject(const std::string &name, short length)
		:subjectName(name), lessonLength(length)
	{
	}
	~Subject() = default;

	std::string GetName() const { return subjectName; }
	short GetLength() const { return lessonLength; }
};

class AfterSchool : public Subject {
private:
public:
	~AfterSchool() {};
};

#endif