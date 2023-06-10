#include "Superhero.h"

void Superhero::setFirstName(const String& otherName) {
	firstName = otherName;
}

void Superhero::setLastName(const String& otherName) {
	lastName = otherName;
}

void Superhero::setNickname(const String& otherName) {
	nickname = otherName;
}

void Superhero::setPower(const unsigned short other) {
	power = other;
}

void Superhero::setPrice(const unsigned short other) {
	price = other;
}

void Superhero::setElement(const Element& other) {
	element = other;
}

void Superhero::setMode(const Mode& other) {
	mode = other;
}


String Superhero::getFirstName() const {
	return firstName;
}

String Superhero::getLastName() const {
	return lastName;
}

String Superhero::getNickname() const {
	return nickname;
}

unsigned short Superhero::getPower() const {
	return power;
}

unsigned short Superhero::getPrice() const {
	return price;
}

Element Superhero::getElement() const {
	return element;
}

Mode Superhero::getMode() const {
	return mode;
}

Superhero::Superhero() : price(0), power(0) {}

Superhero::Superhero
(	String _firstName,
	String _lastName,
	String _nickname,
	unsigned short _power,
	unsigned short _price,
	Element _element) 

	: price(_price), power(_power) {
	setFirstName(_firstName);
	setLastName(_lastName);
	setNickname(_nickname);
	setElement(_element);
}

//Superhero::Superhero(const Superhero& other) = delete;
//Superhero& Superhero::operator=(const Superhero & other) = delete;
//Superhero::~Superhero() = default;