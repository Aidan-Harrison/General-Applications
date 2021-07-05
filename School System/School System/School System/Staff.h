#ifndef Staff_h
#define Staff_h

#include "subjects.h"
#include <vector>

class Staff {
private:
	std::string forename, surname;
	std::string m_Job = "";
public:
	Staff(const std::string &fName, const std::string &sName, const std::string &job)
		:forename(fName), surname(sName), m_Job(job)
	{
	}
	~Staff() {};

	virtual std::string GetJob() const { return m_Job; }
	std::string GetName() const { return forename + ' ' + surname; }

	// Add friend functions??
};

class Principal : public Staff { // Singeleton! DO
private:
public:
	Principal(const std::string &fName, const std::string &sName, const std::string &job)
		:Staff(fName, sName, job)
	{
	}
	~Principal() {};
};

class Teacher : public Staff {
private:
	bool isSubstitue = false;
	Subject m_Subject{"English", 60}; // Pointer? | Doesn't work with constructor
	std::vector<Subject> ciriculum{}; // ?
public:
	Teacher(const std::string &fName, const std::string &sName, const std::string &job, bool isSub = false)
		:Staff(fName, sName, job), isSubstitue(isSub)
	{
	};
	~Teacher() {};
	std::string GetJob() const { return m_Subject.GetName(); }
	void GetCiriculum();
};

#endif