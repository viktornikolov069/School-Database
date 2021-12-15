#include "UniversityUI.h"
#include "TeacherUI.h"
#include "Echo.h"

bool UniversityUI::_running;

enum Role : char { // TO DO: Place enums in Deffinitions header file
	TEACHER = '1',
	STUDENT = '2',
	ADMIN = '3',
	EXIT = 'q',
};

void UniversityUI::start() {
	_running = true;

	while (_running) {
		system("cls");
		printMenu();

		char choice;
		std::cin >> choice;

		handleInput(std::tolower(choice));
	}
}

void UniversityUI::stop() {
	_running = false;
}

void useTeacherUI() {
	TeacherUI teacher;
	teacher.start();
}

void UniversityUI::handleInput(const char choice) {
	switch (choice) {
	case Role::TEACHER:
		useTeacherUI();
		echo("teacher");
		break;
	case Role::STUDENT:
		echo("student");
		break;
	case Role::ADMIN:
		echo("admin");
		break;
	case Role::EXIT:
		echo("exit");
		stop();
		break;
	default:
		break;
	}
}

void UniversityUI::printMenu() {
	echo("--- Menu ---");
	echo("1. Teacher");
	echo("2. Student");
	echo("3. Admin");
	echo("e. Exit");
	echo("Please enter a choice (1, 2, 3, or Q): ");
}


//char choice;
//std::cin >> choice;
//switch (choice) {
//case '1':
//	TeacherUI.start();
//case '2':
//	StudentUI.start();
//	break;
//default:
//	UniversityUI::stop();
//	break;
//}