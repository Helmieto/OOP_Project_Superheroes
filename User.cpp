#include "User.h"

void User::setFirstName(const String& otherName) {
	firstName = otherName;
}

void User::setLastName(const String& otherName) {
	lastName = otherName;
}

void User::setUsername(const String& otherName) {
	username = otherName;
}

void User::setEmail(const String& otherEmail) {
	email = otherEmail;
}

void User::setPassword(const String& otherPass) {
	password = otherPass;
}

String User::getFirstName() const {
	return firstName;
}

String User::getLastName() const {
	return lastName;
}

String User::getUsername() const {
	return username;
}

String User::getEmail() const {
	return email;
}

bool User::checkUsername(const String& otherName) const {
	return (username == otherName);
}
bool User::checkPassword(const String& otherPass) const {
	return (password == otherPass);
}
