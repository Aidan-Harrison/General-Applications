#ifndef StudentList_h
#define StudentList_h

#include <algorithm>
#include "Student.h"

// Heap allocate all
namespace Students {
	namespace Y7Students {
		Student* Christie = new Student { "Christie","Crystal",   11, 7 };
		Student* Jin      = new Student { "Jin",     "Kazama",    11, 7 };
		Student* Lars     = new Student { "Lars",    "Mishima",   11, 7 };
		Student* Marshall = new Student { "Marshall","Law",       11, 7 };
		Student* Bruce    = new Student { "Bruce",   "Eddison",   11, 7 };
	}
	namespace Y8Students {
		Student* Jake     = new Student { "Jake",    "Evans",     12, 8 };
		Student* Johnny   = new Student { "Johnny",  "Bravo",     12, 8 };
		Student* Serene   = new Student { "Serene",  "Kahn",      12, 8 };
		Student* Eddie    = new Student { "Eddie",   "Brock",     12, 8 };
		Student* Peter    = new Student { "Peter",   "Parker",    12, 8 };
		Student* Miles    = new Student { "Miles",   "Morales",   12, 8 };
		Student* Billy    = new Student { "Billy",   "Mandy",     12, 8 };
		Student* Nikola   = new Student { "Nikola",  "Tesla",     12, 8 };
	}
	namespace Y9Students {
		Student* Emma     = new Student { "Emma",    "Axel",      14, 9 };
		Student* Amy      = new Student { "Amy",     "Allans",    14, 9 };
		Student* John     = new Student { "John",    "Sadley",    14, 9 };
		Student* Calum    = new Student { "Calum",   "Hickman",   14, 9 };
		Student* Seto     = new Student { "Seto",    "Kaiba",     14, 9 };
		Student* Yami     = new Student { "Yami",    "Yugi",      14, 9 };
		Student* Thomas   = new Student { "Thomas",  "Jerry",     14, 9 };
		Student* Patrick  = new Student { "Patrick", "Eugene",    14, 9 };
	}
	namespace Y10Students {
		Student* James    = new Student { "James",   "Black",     15, 10 };
		Student* Ali      = new Student { "Ali",     "Larsen",    15, 10 };
		Student* Josh     = new Student { "Josh",    "Mcgregor",  15, 10 };
		Student* Megan    = new Student { "Megan",   "Morigan",   15, 10 };
		Student* Veronica = new Student { "Veronica","Wednesday", 15, 10 };
		Student* Lisa     = new Student { "Lisa",    "Lee",       15, 10 };
		Student* Janet    = new Student { "Janet",   "Nobody",    15, 10 };
		Student* Raymond  = new Student { "Raymond", "Rayman",    15, 10 };
		Student* Richard  = new Student { "Richard", "Armstrong", 15, 10 };
		Student* Bradley  = new Student { "Bradley", "Cooper",    15, 10 };
	}
	namespace Y11Students {
		Student* Mandy    = new Student { "Mandy",   "Apples",    16, 11 };
		Student* Jason    = new Student { "Jason",   "Armstrong", 15, 11 };
		Student* Steven   = new Student { "Steven",  "Segal",     15, 11 };
		Student* Micheal  = new Student { "Micheal", "Jackson",   15, 11 };
		Student* Lamar    = new Student { "Lamar",   "Kendrick",  15, 11 };
		Student* Sarah    = new Student { "Sarah",   "Kojima",    15, 11 };
		Student* Anderson = new Student { "Anderson","Morpheus",  15, 11 };
		Student* Maddie   = new Student { "Maddie",  "Pearl",     15, 11 };
		Student* Ryan     = new Student { "Ryan",    "Relish",    15, 11 };
	}

	// Automate this!? | SHOULD NOT HAVE TO MARK EACH INDIVIDUAL VARIABLE AS A POINTER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// YEAR 7 =======================================
	std::vector<Student> Y7_Students{
		*Y7Students::Christie,
		*Y7Students::Jin,
		*Y7Students::Lars,
		*Y7Students::Marshall,
		*Y7Students::Bruce
	};
	// YEAR 8 =======================================
	std::vector<Student> Y8_Students{
		*Y8Students::Jake,
		*Y8Students::Johnny,
		*Y8Students::Serene,
		*Y8Students::Eddie,
		*Y8Students::Peter,
		*Y8Students::Miles,
		*Y8Students::Billy,
		*Y8Students::Nikola
	};
	// YEAR 9 =======================================
	std::vector<Student> Y9_Students{
		*Y9Students::Emma,
		*Y9Students::Amy,
		*Y9Students::John,
		*Y9Students::Calum,
		*Y9Students::Seto,
		*Y9Students::Yami,
		*Y9Students::Thomas,
		*Y9Students::Patrick
	};
	// YEAR 10 ======================================
	std::vector<Student> Y10_Students{
		*Y10Students::James,
		*Y10Students::Ali,
		*Y10Students::Josh,
		*Y10Students::Megan,
		*Y10Students::Veronica,
		*Y10Students::Lisa,
		*Y10Students::Janet,
		*Y10Students::Raymond,
		*Y10Students::Richard,
		*Y10Students::Bradley
	};
	// YEAR 11 ======================================
	std::vector<Student> Y11_Students{
		*Y11Students::Mandy,
		*Y11Students::Jason,
		*Y11Students::Steven,
		*Y11Students::Micheal,
		*Y11Students::Lamar,
		*Y11Students::Sarah,
		*Y11Students::Anderson,
		*Y11Students::Maddie,
		*Y11Students::Ryan
	};
	std::vector<std::vector<Student>> allStudents{Y7_Students, Y8_Students, Y9_Students, Y10_Students, Y11_Students};

	bool comp(const Student &s1, const Student &s2) {
		return(s1.GetSurname() < s2.GetSurname());
	}

	void SortStudents() { // Sort via surname
		std::sort(Students::allStudents[0].begin(), Students::allStudents[0].end(), comp);
	}
}

#endif StudentList_h