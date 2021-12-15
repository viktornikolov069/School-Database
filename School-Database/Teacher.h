#ifndef TEACHER_H
#define TEACHER_H
#include "User.h"

class Teacher : User {
public:

	virtual void showUserInfo() const;
		
	Teacher(const std::string& id, const std::string& name,
		const std::string& pass, const std::string& faculty);

	std::string getId() const {
		return _id;
	}

	std::string getName() const {
		return _name;
	}

	std::string getPassword() const {
		return _password;
	}

	std::string getFaculty() const {
		return _faculty;
	}


	//friend std::istream& operator>>(std::istream& in, Teacher& teacher);

private:
	const std::string _faculty;
	//std::string _passCheck;
};

#endif // ! TEACHER_H
