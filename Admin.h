#pragma once
#include"User.h"

class Admin : public User {
	
public:
	
	Admin(String Fname, String Lname, String Uname, String Email, String Pass);

	Type identify() const override;
	void printInfoForPlayers() const override;
	void printInfoForAdmins() const override;

};

