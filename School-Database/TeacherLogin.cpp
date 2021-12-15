#include "TeacherLogin.h"
#include "Echo.h"
#include "Teacher.h"

enum LoginOption : char {
	SHOW_INFO = '1',
	ADD_GRADE = '2',
	LOGOUT = 'q',
};

TeacherLogin::TeacherLogin(const Teacher& teacher) 
	: _teacher{ teacher }, _running{true}{
}

void TeacherLogin::start() {
	while (_running) {
		system("cls");
		printMenu();

		char choice;
		std::cin >> choice;
		handleInput(std::tolower(choice));
	}
}

void TeacherLogin::stop() {
	_running = false;
}

void TeacherLogin::handleInput(char choice) {
	switch (choice) {
	case SHOW_INFO:
		_teacher.showUserInfo();
		system("PAUSE");
		break;
	case ADD_GRADE:
		echo("ADDING GRADE");
		break;
	case LOGOUT:
		stop();
		break;
	default:
		break;
	}
}

void TeacherLogin::printMenu() {
	echo("--- Login Menu ---");
	echo("1. Show User Info");
	echo("2. Add grade");
	echo("q. Logout");
	echo("Please enter a choice (1, 2, or Q): ");
}