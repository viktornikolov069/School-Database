#include "TeacherUI.h"
#include "UniversityUI.h"
#include "Echo.h"
#include "TeacherLogin.h"

enum Option : char {// TO DO: Place enums in Deffinitions header file
	LOGIN = '1',
	REGISTER = '2',
	MAIN_MENU = '3',
	EXIT = 'q',
};

void TeacherUI::start() {

	_running = true;
	getDataFromFile();
	while (_running) {
		system("cls");
		printMenu();

		char choice;
		std::cin >> choice;
		handleInput(std::tolower(choice));
	}
}

void TeacherUI::stop() {
	_running = false;
}

void TeacherUI::handleInput(const char choice) {
	bool teacherExists = false;
	switch (choice) {
	case Option::LOGIN:
		echo("Login Teacher");
		loginTeacher();
		break;
	case Option::REGISTER:
		addTeacher(teacherExists);
		if (teacherExists) {
			echo("This account already exists. Please try another email.");
			system("PAUSE");
			break;
		}
		addToFile();
		echo("You have registered successfully!");
		system("PAUSE");
		break;
	case Option::MAIN_MENU:
		echo("Main Menu call Teacher");
		stop();
		break;
	case Option::EXIT:
		echo("Exit call Teacher");
		stop();
		UniversityUI::stop(); // Is this a problem?
		break;
	default:
		break;
	}
}

void TeacherUI::loginTeacher() {
	system("cls");
	std::string id;
	std::string pass;
	echo("Enter email");
	std::cin >> id;
	echo("Enter password");
	std::cin >> pass;
	const std::vector<Teacher>::const_iterator it = loginQuery(id, pass);
	if (it != _teacherData.end()) {
		TeacherLogin login(*it);
		login.start();
		return;
	} 
	echo("Bad attempt. Try again");
	system("PAUSE");
	return;
}

void TeacherUI::addTeacher(bool& teacherExists) {
	system("cls");
	std::cin.ignore();
	echo("Enter Email");
	std::string id;
	getline(std::cin, id);
	const std::vector<Teacher>::iterator it = registerQuery(id); //check if this teacher already exists
	if (it != _teacherData.end()) { 
		teacherExists = true;
		return;
	}
	echo("Enter Name");
	std::string name;
	getline(std::cin, name);
	echo("Enter Faculty");
	std::string faculty;
	getline(std::cin, faculty);
	echo("Enter Password");
	std::string password;
	getline(std::cin, password);
	std::string checkPass;
	echo("Confirm Password");
	getline(std::cin, checkPass);
	while (checkPass != password) {
		echo("Passwords do not match");
		echo("Confirm password");
		getline(std::cin, checkPass);
	}
	_teacherData.emplace_back(id, name, faculty, password);
}

std::vector<Teacher>::iterator TeacherUI::registerQuery(const std::string& id) { 
// uses lambda expression to check if teacher exists when making a new account
	return std::find_if(_teacherData.begin(), _teacherData.end(),
		[&](const Teacher& t) { return t.getId() == id; });
}

std::vector<Teacher>::iterator TeacherUI::loginQuery(const std::string& id,
													 const std::string& pass) {
// uses lambda expression to check if teacher exists when trying to login
	return std::find_if(_teacherData.begin(), _teacherData.end(),
		[&](const Teacher& t) { return (t.getId() == id && t.getPassword() == pass); });
}

void TeacherUI::printMenu() {
	echo("---Teacher Menu---");
	echo("1. Loggin");
	echo("2. Register");
	echo("3. Main Menu");
	echo("e. Exit");
	echo("Please enter a choice (1, 2, 3 or Q): ");
}

void TeacherUI::addToFile() {
	std::fstream teacherFile;
	teacherFile.open("teacher.txt", std::ios::out | std::ios::app);
	if (!teacherFile) {
		std::cerr << "An ERROR ocurred while opening the TEACHER file" << std::endl;
		return;
	}
	if (_teacherData.empty()) {
		std::cerr << "Teacher Data is empty!!!";
		return;
	}
	
	teacherFile << _teacherData.back().getId() << '\t'
		<< _teacherData.back().getName() << '\t'
		<< _teacherData.back().getFaculty() << '\t'
		<< _teacherData.back().getPassword() << '\t'
		<< '\n';

	teacherFile.close();
	//_file << _teacherData;
	// _outFile.close
}

void TeacherUI::getDataFromFile() {
	std::fstream teacherFile;
	teacherFile.open("teacher.txt", std::ios::in);
	if (!teacherFile) {
		//std::cerr << "An ERROR ocurred while opening the TEACHER file" << std::endl;
		return;
	}
	constexpr auto arrSize = 4;
	std::array<std::string, arrSize> data;
	constexpr auto fileName = "teacher.txt";
	std::string info;
	
	while (!teacherFile.eof()) {
		for (int i = 0; i < arrSize; ++i) {
			getline(teacherFile, info, '\t');
			data[i] = info;
		}
		
		if (data[0].find('\n') != std::string::npos) {
			data[0].erase(data[0].begin());
		}
		_teacherData.emplace_back(data[0], data[1], data[2], data[3]);

	}
	teacherFile.close();
	_teacherData.pop_back();
}

// I TRIED TO OVERLOAD BUT I COULDN'T MAKE IT WORK

//std::istream& operator>>(std::istream& in, std::vector<Teacher> teacherData) {
//	std::vector<Teacher>& teacherData = obj.getTeacherData();
//	constexpr auto arrSize = 4;
//	std::array<std::string, arrSize> data;
//	constexpr auto fileName = "teacher.txt";
//	std::string info;
//	while (!in.eof()) {
//		for (int i = 0; i < arrSize; ++i) {
//			getline(in, info, '\t');
//			data[i] = info;
//		}
//		teacherData.emplace_back(data[0], data[1], data[2], data[3]);
//	}
//	teacherData.pop_back();
//	return in;
//}

//std::ostream& operator<<(std::ostream& out, const std::vector<Teacher>& teacherData) {
//	if (teacherData.empty()) {
//		return out;
//	}
//	out << teacherData.back().getId() << '\t'
//		<< teacherData.back().getName() << '\t'
//		<< teacherData.back().getFaculty() << '\t'
//		<< teacherData.back().getPassword() << '\t'
//		<< '\n';
//	return out;
//}