#ifndef TeacherList_h
#define TeacherList_h

#include "Staff.h"

namespace StaffList {
	// Principal
	Principal principal{"Steve", "Law", "Principal"};
	// ENGLISH
	Teacher* janet  = new Teacher{"Janet", "Taylor", "English Teacher", false}; // Possibly change job for something index based
	// SCIENCE
	Teacher* Hannah = new Teacher{"Hannah","Horton", "Science Teacher", false};
	Teacher* Lex    = new Teacher{"Lex",   "Fridman","Science Teacher", true};
	// MATHEMATICS
	Teacher* Tariq  = new Teacher{"Tariq", "Qasim",  "Maths Teacher",   false};
	std::vector<Staff> englishTeachers {
		*janet
	};
	std::vector<Staff> scienceTeachers {
		*Hannah,
		*Lex
	};
	std::vector<Staff> mathsTeachers {
		*Tariq
	};
}


#endif