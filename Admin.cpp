#include "Admin.h"

Admin::Admin(String Fname, String Lname, String Uname, String Email, String Pass) {
	setFirstName(Fname);
	setLastName(Lname);
	setUsername(Uname);
	setEmail(Email);
	setPassword(Pass);
}

Type Admin::identify() const {
	return Type::admin;
}

void Admin::printInfoForPlayers() const {
	//or throw
	return;
}

void Admin::printInfoForAdmins() const {
	std::cout << getFirstName() << ' ' << getLastName() << std::endl;
	std::cout << "email:" << getEmail() << std::endl;
	std::cout << "username:" << getUsername() << std::endl;
}
