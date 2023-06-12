#include "Player.h"


Player::Player(String Fname, String Lname, String Uname, String Email, String Pass, unsigned bal) : balance(bal){
	setFirstName(Fname);
	setLastName(Lname);
	setUsername(Uname);
	setEmail(Email);
	setPassword(Pass);
}

void Player::setBalance(unsigned _balance) {
	balance = _balance;
}

void Player::buySuperhero(Superhero& a) {
	heroes.pushBack(a);
	return;
}

unsigned Player::getBalance() const {
	return balance;
}

Type Player::identify() const {
	return Type::player;
}

/*> 1. Slayer300 2500$
		1.1. Super Man Earth
		1.2. Fire Man Fire
>2. Go6ko 3200$
		2.1. Bat Man Earth
*/

void Player::printHeroes() const {
	int heroesCount = heroes.getSize();
	for (int i = 0; i < heroesCount; i++) {
		std::cout << '\t' << i + 1 << ". ";
		heroes[i].printInfo();
		std::cout << std::endl;
	}
}
void Player::printInfoForPlayers() const {
	std::cout << getUsername() << ' ' << getBalance() << "$" << std::endl;
	printHeroes();
}

void Player::printInfoForAdmins() const {
	std::cout << getFirstName() << ' ' << getLastName() << std::endl;
	std::cout << "email:" << getEmail() << std::endl;
	std::cout << "username:" << getUsername() << std::endl;
	std::cout << "heroes:" << std::endl;
	printHeroes();
}