#pragma once
#include"String.h"
#include"Vector.hpp"
#include"Superhero.h"

enum class Type {
	player, admin
};

class User {
	String firstName;
	String lastName;
	String username;
	String email;
	String password;
	
public:

	//User() = default;

	void setFirstName(const String& otherName);
	void setLastName(const String& otherName);
	void setUsername(const String& otherName);
	void setEmail(const String& otherEmail);
	void setPassword(const String& otherPass);

	String getFirstName() const;
	String getLastName() const;
	String getUsername() const;
	String getEmail() const;

	bool checkUsername(const String& otherName) const;
	bool checkPassword(const String& otherPass) const;

	virtual Type identify() const = 0;
	virtual void printInfoForPlayers() const = 0;
	virtual void printInfoForAdmins() const = 0;

	virtual ~User() = default;
};

