#include "Teacher.h"
#include <fstream>
#include "Echo.h"


Teacher::Teacher(const std::string& id, const std::string& name,
	 const std::string& faculty, const std::string& pass)
	: _faculty{ faculty }, User{ id, name, pass } {
}

void Teacher::showUserInfo() const {
	echo("User Email");
	echo(_id);
	echo("User Name");
	echo(_name);
	echo("User Faculty");
	echo(_faculty);
}


//std::istream& operator>>(std::istream& in, const Teacher& teacher) {
//	
//}


//std::ostream& operator<<(std::ostream& out, const Teacher& teacher) {
//	out << teacher.getId() << " " << teacher.getName() << " "
//		<< teacher.getFaculty() << " " << teacher.getPassword() << '\n';
//	return out;
//}