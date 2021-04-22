#include <iostream>
#include <vector>
#include <algorithm>

#include "Student.h"
#include "StudentList.h"
#include "TeacherList.h"

void Interface();
void ViewStudentInterface();
void ViewStaffInterface();

void PrintStudentsYear() {
	// Year 7:
	std::cout << "========YEAR 7========\n";
	for(int i = 0; i < Students::Y7_Students.size(); i++)  {std::cout << Students::Y7_Students[i].GetName()  << " | Age: " << Students::Y7_Students[i].GetAge()  << '\n';}
	// Year 8:
	std::cout << "========YEAR 8========\n";
	for(int i = 0; i < Students::Y8_Students.size(); i++)  {std::cout << Students::Y8_Students[i].GetName()  << " | Age: " << Students::Y8_Students[i].GetAge()  << '\n';}
	// Year 9:
	std::cout << "========YEAR 9========\n";
	for(int i = 0; i < Students::Y9_Students.size(); i++)  {std::cout << Students::Y9_Students[i].GetName()  << " | Age: " << Students::Y9_Students[i].GetAge()  << '\n';}
	// Year 10:
	std::cout << "========YEAR 10========\n";
	for(int i = 0; i < Students::Y10_Students.size(); i++) {std::cout << Students::Y10_Students[i].GetName() << " | Age: " << Students::Y10_Students[i].GetAge() << '\n';}
	// Year 11:
	std::cout << "========YEAR 11========\n";
	for(int i = 0; i < Students::Y11_Students.size(); i++) {std::cout << Students::Y11_Students[i].GetName() << " | Age: " << Students::Y11_Students[i].GetAge() << '\n';}
	ViewStaffInterface();
}

void PrintStudentsAge() { // Sort by age
	std::vector<Student> allStudents;
	//for (unsigned int i = 0; i < students.size(); i++) {
		//std::cout << students[i].GetAge() << '\n';
	//}
	ViewStudentInterface();
}

void PrintStudentsName() {
	//for (unsigned int i = 0; i < students.size(); i++) {
		//std::cout << students[i].GetName() << '\n';
	//}
	ViewStudentInterface();
}

// Move these?
void AddStudent() {
	std::string firstname, surname;
	short age, year;
	std::cout << "Enter student details\n";
	std::cout << "FirstName:"; std::cin >> firstname;
	std::cout << "SurName:"; std::cin >> surname;
	std::cout << "Age:"; std::cin >> age;
	std::cout << "Year:"; std::cin >> year;
	Student* newStudent = new Student{ firstname, surname, age, year}; // Check object name conflict
	// Modify so constructor is all which is needed
	while (!newStudent->CheckAge()) {
		std::cout << "The age's and year do not match, ensure correct data has been entered";
		std::cout << "Age: "; std::cin >> age;
		std::cout << "Year: ";std::cin >> year;
	}
	Interface();
}

// Custom search function
void SearchStudent(std::vector<Student> &students) {

}

void RemoveStudent() {
	std::string input = ""; // Just have universal? So no need to assign more memory then needed
	std::cout << "Search for student via name: "; std::cin >> input;
	// Sort via name
	// Do binary search
}

void EditStudent() {
	std::cout << "Search for student via name: ";
	// DO map or faster search algorithm (Something which isn't linear)
}

void SearchStudent() {
	std::string input = "";
	std::vector<Student> allStudents{};
	std::cout << "Search for a specific student by name: "; std::cin >> input;
	// Inefficient??
	for(unsigned int i = 0; i < Students::Y7_Students.size(); i++)  allStudents.push_back(Students::Y7_Students[i]);
	for(unsigned int i = 0; i < Students::Y8_Students.size(); i++)  allStudents.push_back(Students::Y8_Students[i]);
	for(unsigned int i = 0; i < Students::Y9_Students.size(); i++)  allStudents.push_back(Students::Y9_Students[i]);
	for(unsigned int i = 0; i < Students::Y10_Students.size(); i++) allStudents.push_back(Students::Y10_Students[i]);
	for(unsigned int i = 0; i < Students::Y11_Students.size(); i++) allStudents.push_back(Students::Y11_Students[i]);
	std::sort(allStudents.begin(), allStudents.end()); // Won't work, no data to sort!

	// DO map or faster search algorithm (Something which isn't linear)
}

void ChangeCuric() {
}

void ViewStudentInterface() {
	system("cls");
	short input = 0;
	std::cout << "View by:\n" <<
			     "1)YEAR  2)AGE  3)NAME  4)SEARCH  or  5)BACK\n";
	std::cin >> input;
	system("cls");
	switch (input) {
		// Combine all functions into one?
		case 1: PrintStudentsYear(); break;
		case 2: PrintStudentsAge();  break;
		case 3: PrintStudentsName(); break;
		case 4: SearchStudent(); break;
		case 5: break;
	} 
	Interface();
}

void ViewStaffInterface() {
	system("cls");
	std::cout << "Principal: " << StaffList::principal.GetName() << '\n';
	std::cout << "English Teachers:\n";
	for (int i = 0; i < StaffList::englishTeachers.size(); i++)
		std::cout << StaffList::englishTeachers[i].GetName() << '\n';
	std::cout << "Science Teachers:\n";
	for (int i = 0; i < StaffList::scienceTeachers.size(); i++)
		std::cout << StaffList::scienceTeachers[i].GetName() << '\n';
	std::cout << "Maths Teachers:\n";
	for (int i = 0; i < StaffList::mathsTeachers.size(); i++)
		std::cout << StaffList::mathsTeachers[i].GetName() << '\n';
	std::cout << "Press enter to return: "; 
	std::cin.get();
	std::cin.get();
	Interface();
}

void AddStaff() {
	std::string firstname, surname;
	short age, year;
	std::cout << "Enter staff details\n";
	std::cout << "FirstName:"; std::cin >> firstname;
	std::cout << "SurName:"; std::cin >> surname;
	std::cout << "Age:"; std::cin >> age;
	std::cout << "Occupation: ";
}

void RemoveStaff() {
	std::cout << "Search for staff via name: ";
	// Much like the student search, implement a fast searching algorithmn for demonstration purposes.
	// Check if the staff is on a ciriculum
	// If so, check with the user.
	// If user is ok with it, remove from necessary vectors and delete object from memory.
}

void SwapTeachers() {
	// Teacher subjects must match.
	// If so, move the ciriculum around so they are swapped
}

void ManageInterface() {
	short input = 0;
	std::cout << "WHAT WOULD YOU LIKE TO MANAGE:\n" <<
				 "1)STUDENTS  2)STAFF  3)RETURN\n";
	std::cin >> input;
	if(input == 1) {
		system("cls");
		std::cout << "1) Add Student to databse\n" <<
			"2) Remove studeny from database\n" <<
			"3) Edit Student data\n" <<
			"4) Change Curiculum\n" <<
			"5) RETURN";
		std::cin >> input;
		switch(input) {
			case 1: AddStudent(); break;
			case 2: RemoveStudent(); break;
			case 3: EditStudent(); break;
			case 4: ChangeCuric(); break;
			case 5: ManageInterface(); break;
		}
	}
	else if(input == 2) {
		system("cls");
		std::cout << "1) Add Staff\n" <<
			"2) Remove Staff\n" <<
			"3) Swap Teachers\n" <<
			"4) RETURN\n";
		std::cin >> input;
		switch(input) {
			case 1: AddStaff();	break;
			case 2: RemoveStaff(); break;
			case 3: SwapTeachers(); break;
			case 4: ManageInterface(); break;
		}
	}
}

void Interface() {
	system("cls");
	short input = 0;
	std::cout << "===============-SCHOOL SYSTEM-===============\n" <<
			     "1)VIEW STUDENTS  2)VIEW STAFF  3)MANAGE  4)QUIT";
	short total = Students::Y7_Students.size() + Students::Y8_Students.size() + Students::Y9_Students.size() + Students::Y10_Students.size() + Students::Y11_Students.size();
	std::cout << "\nAmount of Students: " << total << '\n';
	// Add teachers
	std::cout << "Amount of Staff:\n";
	total = StaffList::englishTeachers.size() + StaffList::scienceTeachers.size() + StaffList::mathsTeachers.size();
	std::cin >> input;
	switch (input) {
		case 1: ViewStudentInterface(); break;
		case 2: ViewStaffInterface(); break;
		case 3: ManageInterface(); break;
		case 4: exit(0); break;
	}
}