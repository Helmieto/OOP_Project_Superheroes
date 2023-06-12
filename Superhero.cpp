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

void Superhero::printElement() const {
	switch (element) {
	case Element::earth:
		std::cout << "Earth";
		break;
	case Element::fire:
		std::cout << "Fire";
		break;
	case Element::water:
		std::cout << "Water";
		break;
	default:
		break;
	}
}

void Superhero::printInfo() const {
	std::cout << "name:" << getFirstName() << ' ' << getLastName() << ' ';
	std::cout << "price:" << getPrice() << "$ ";
	std::cout << "type:"; printElement();
	std::cout << " power:" << getPower();

}

void Superhero::changeMode() {
	if (mode == Mode::offencive)
		setMode(Mode::defencive);
	else /*when hero is bought this function will set mode to offensive by default*/
		setMode(Mode::offencive);
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

