#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <map>

#include "Student.h"
#include "StudentList.h"
#include "TeacherList.h"

// Move to certain staff roles
std::string profileName = "SarahConnor";
std::string profilePass = "1990";
bool hasLoggedin = false;

void Interface();
void ViewStudentInterface();
void ViewStaffInterface();
bool Login();

void PrintStudentsYear() {
	std::cout << "========YEAR 7========\n";
	for(int i = 0; i < Students::Y7_Students.size(); i++)  {std::cout << Students::Y7_Students[i].GetName()  << " | Age: " << Students::Y7_Students[i].GetAge()  << '\n';}
	std::cout << "========YEAR 8========\n";
	for(int i = 0; i < Students::Y8_Students.size(); i++)  {std::cout << Students::Y8_Students[i].GetName()  << " | Age: " << Students::Y8_Students[i].GetAge()  << '\n';}
	std::cout << "========YEAR 9========\n";
	for(int i = 0; i < Students::Y9_Students.size(); i++)  {std::cout << Students::Y9_Students[i].GetName()  << " | Age: " << Students::Y9_Students[i].GetAge()  << '\n';}
	std::cout << "========YEAR 10========\n";
	for(int i = 0; i < Students::Y10_Students.size(); i++) {std::cout << Students::Y10_Students[i].GetName() << " | Age: " << Students::Y10_Students[i].GetAge() << '\n';}
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
	for (unsigned int i = 0; i < Students::allStudents.size(); i++) {
		std::cout << Students::allStudents[0][i].GetName() << '\n';
	}
	std::cin.get();
	std::cin.get();
	ViewStudentInterface();
}

void AddStudent() { // Insert student efficiently into all student vector, sorting again is too expensive
	std::string firstname, surname;
	short age, year;
	std::cout << "Enter student details\n";
	std::cout << "FirstName:"; std::cin >> firstname;
	std::cout << "SurName:"; std::cin >> surname;
	std::cout << "Age:"; std::cin >> age;
	std::cout << "Year:"; std::cin >> year;
	Student* newStudent = new Student{ firstname, surname, age, year}; // Check object name conflict
	Interface();
}

Student* SearchStudent() { // Check!
	std::string input = "";
	std::cout << "Search for a student by name: "; std::cin >> input;
	Students::SortStudents();
	for (unsigned int i = 0; i < Students::allStudents.size(); i++) {
		for (unsigned int j = 0; j < Students::allStudents.size(); j++) {
			std::cout << Students::allStudents[i][j].GetSurname() << '\n';
		}
		putchar('\n');
	}
	// Print all students with matching names

	// Temp linear search | Implement map/faster search algortithm | Look into pushing objects to map
	std::map<int, Student> sMap; // Figure out how to push elements to map, using method??

	for (int i = 0; i < Students::allStudents.size(); i++) {
		if (input == Students::allStudents[0][i].GetName())
			return &Students::allStudents[0][i]; // Check return!!!!
	}
}

void RemoveStudent() {
	std::string input = ""; // Just have universal? So no need to assign more memory then needed
	std::cout << "Search for student via name: "; std::cin >> input;
	Students::SortStudents(); // Inefficient to sort again?
}

void EditStudent() {
	std::cout << "You must confirm your login\n";
	Student *curStudent; // Heap allocate?
	if(Login()) {
		curStudent = SearchStudent();
	}
	short input = 0;
	std::cout << "What would you like to do: "
			  << "1) Change Data  2) Change Ciriculum\n";
	switch (input) {
		case 1: curStudent->ChangeDetails(); break;
		case 2: curStudent->SetCiriculum(); break;
	}
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
		std::cout << i << ") " << StaffList::englishTeachers[i].GetName() << '\n';
	std::cout << "Science Teachers:\n";
	for (int i = 0; i < StaffList::scienceTeachers.size(); i++)
		std::cout << i << ") " << StaffList::scienceTeachers[i].GetName() << '\n';
	std::cout << "Maths Teachers:\n";
	for (int i = 0; i < StaffList::mathsTeachers.size(); i++)
		std::cout << i << ") " << StaffList::mathsTeachers[i].GetName() << '\n';
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
	std::string input = "";
	// Have a single container instead???
	for (int i = 0; i < StaffList::englishTeachers.size(); i++) {
		if (input == StaffList::englishTeachers[i].GetName())
			StaffList::englishTeachers[i].~Staff(); // Check!
	}

	// Much like the student search, implement a fast searching algorithmn.
	// Check if the staff is on a ciriculum
	// If so, check with the user.
	// If user is ok with it, remove from necessary vectors and delete object from memory.
}

void SwapTeachers() {
	std::string name = "";
	std::cout << "Search via name: "; std::cin >> name;
	// Teacher subjects must match.
	// If so, move the ciriculum around so they are swapped
}

void ChangeCuric() {
	SearchStudent();
	Students::Y7_Students[0].SetCiriculum();
	// Call set ciriculum function on searched studen
	Students::Y7_Students[0].GetCiriculum();
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
			case 3: SwapTeachers(); break; // Add ciriculum as well
			case 4: ManageInterface(); break;
		}
	}
}

void Interface() {
	/*
	Students::SortStudents();
	for (unsigned int i = 0; i < Students::allStudents.size(); i++) {
		for (unsigned int j = 0; j < Students::allStudents.size(); j++) {
			std::cout << Students::allStudents[i][j].GetSurname() << '\n';
		}
		putchar('\n');
	}
	*/

	if(Login()) {
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
		system("cls");
		switch (input) {
			case 1: ViewStudentInterface(); break;
			case 2: ViewStaffInterface(); break;
			case 3: ManageInterface(); break;
			case 4: exit(0); break;
		}
	}
}

bool Login() {
	if (hasLoggedin)
		return true;
	else {
		short attempts = 0;
		std::string username = "", password = "";
		// Convert password to '*'
		while (attempts <= 3) {
			system("cls");
			std::cout << "Username: "; std::cin >> username;
			std::cout << "Password: "; std::cin >> password;
			if(username == profileName && password == profilePass) { // Check need!
				std::this_thread::sleep_for(std::chrono::seconds(1));
				hasLoggedin = true;
				return true;
			}
			else {
				std::cout << "You have entered an incorrect useranme or password!\nTry again (Press enter to continue)";
				std::cin.get();
				std::cin.get();
			}
		}
	}
	std::cout << "YOu have made too many attempts!\n EXITING...";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	return false;
}