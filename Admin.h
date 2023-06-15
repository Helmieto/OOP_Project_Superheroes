#pragma once
#include"User.h"

class Admin : public User {
	
public:
	Admin() = default;
	Admin(String Fname, String Lname, String Uname, String Email, String Pass);

	void printInfoForPlayers() const override;
	void printInfoForAdmins() const override;

};

