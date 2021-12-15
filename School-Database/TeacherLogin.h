#ifndef TEACHER_LOGIN_H
#define TEACHER_LOGIN_H
#include "Teacher.h"

class TeacherLogin {
public:
	TeacherLogin(const Teacher& teacher);

	void start();

	void stop();

private:
	void printMenu();
	void handleInput(char choice);
	bool _running;
	const Teacher& _teacher;
};

#endif // !TEACHER_LOGIN_H
