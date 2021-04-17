#ifndef StudentList_h
#define StudentList_h

#include "Student.h"

// Heap allocate all
namespace Students {
	namespace Y7Students {
		Student* Christie = new Student{ "Christie","", 11, 7 };
	}
	namespace Y8Students {
		Student* Jake = new Student{ "Jake", "Evans",  12, 8 };
	}
	namespace Y9Students {
		Student* Emma = new Student{ "Emma", "",  14, 9 };
	}
	namespace Y10Students {
		Student* James = new Student{ "James","", 15, 10 };
	}
	namespace Y11Students {
		Student* Mandy = new Student{ "Mandy","", 16, 11 };
		Student* Jason = new Student{ "Jason","", 15, 11 };
	}

	// Automate this!? | SHOULD NOT HAVE TO MARK EACH INDIVIDUAL VARIABLE AS A POINTER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// YEAR 7 =======================================
	std::vector<Student> Y7_Students{
		*Y7Students::Christie
	};
	// YEAR 8 =======================================
	std::vector<Student> Y8_Students{
		*Y8Students::Jake
	};
	// YEAR 9 =======================================
	std::vector<Student> Y9_Students{
		*Y9Students::Emma
	};
	// YEAR 10 ======================================
	std::vector<Student> Y10_Students{
		*Y10Students::James
	};
	// YEAR 11 ======================================
	std::vector<Student> Y11_Students{
		*Y11Students::Mandy,
		*Y11Students::Jason
	};
}

#endif StudentList_h