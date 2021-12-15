#ifndef TEACHER_UI_H
#define TEACHER_UI_H
#include <vector>
#include <array>
#include <fstream>
#include "Teacher.h"
class Teacher;

class TeacherUI {
public:
	TeacherUI() = default;

	void start();

	void stop();

	void addTeacher(bool& teacherExists);

	void loginTeacher();

	void addToFile();

	void getDataFromFile();

	std::vector<Teacher>::iterator registerQuery(const std::string& id);

	std::vector<Teacher>::iterator loginQuery(const std::string& id, const std::string& pass);


	//friend std::istream& operator>>(std::istream& in, std::vector<Teacher>& teacherData);
	//	
	//friend std::ostream& operator<<(std::ostream& out, const std::vector<Teacher>& teacherData);

private:
	void printMenu();
	void handleInput(char choice);
	bool _running = true;
	std::vector<Teacher> _teacherData;
	
};

//std::istream& operator>>(std::istream& in, std::vector<Teacher>& teacherData) {
//	return in;
//}

#endif // !TEACHER_UI_H

