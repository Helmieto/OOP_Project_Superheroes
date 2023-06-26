#include "Game.h"


Game::Game() {
	addAdmin("Milen", "Temelkov", "menata", "email@abv.bg", "Aa1");
}

Game::~Game() {
	loggedUser.logout();
}

int Game::comparePowers(const int power1, const int power2) const {
	if (power1 < power2) {
		return -1;
	}
	return (power1 > power2);
}

void Game::resetCycle(int playersCount) {
	
	for (int i = 0; i < playersCount; i++) {
		players[i].resetTurns();
		players[i].winMoney(CYCLE_REWARD);
	}
}

bool Game::marketIsEmpty() const {
	return !shop.getSize();
}

bool Game::validUsername(const String& username) const{
	int length = username.length();
	if (length > 16) {
		return 0;
	}
	for (int i = 0; i < length; i++) {
		if (username[i] < 'a' || username[i] > 'z')
			return 0;
	}
	return 1;
}

bool Game::validPassword(const String& password) const {
	bool smallLetter = false, capLetter = false, number = false; //flags
	int length = password.length();
	for (int i = 0; i < length; i++) {
		if (password[i] >= 'a' || password[i] <= 'z')
			smallLetter = true;
		if (password[i] >= 'A' || password[i] <= 'Z')
			capLetter = true;
		if (password[i] >= '0' || password[i] <= '9')
			number = true;
	}
	return (smallLetter && capLetter && number);
}

bool Game::playerIsLoggedIn() const {
	return (loggedUser.loggedPlayer != nullptr);
}

bool Game::adminisLoggedIn() const {
	return (loggedUser.loggedAdmin != nullptr);
}

bool Game::playerHasTurns() const {
	return (loggedUser.loggedPlayer->getTurns());
}
//admin functions
void Game::adminLogin(const String& Uname, const String& Pass) {
	int adminsCount = admins.getSize();
	for (int i = 0; i < adminsCount; i++) {
		if (admins[i].checkUsername(Uname)) {
			if (admins[i].checkPassword(Pass)) {
				loggedUser.loggedAdmin = &admins[i];
				return;
			}
			else {
				throw 101; //wrong password
			}
		}
	}
	throw 102; //wrong username
}

void Game::addAdmin(const String& Fname, const String& Lname, const String& Uname, const String& Email, const String& Pass) {
	if (!validUsername(Uname)) {
		throw 201;//invalid username
	}
	if (!validPassword(Pass)) {
		throw 202;//invalid password
	}
	int adminsCount = admins.getSize();
	for (int i = 0; i < adminsCount; i++) {
		if (admins[i].getUsername() == Uname) {
			throw 203;//username is taken
		}
	}
	Admin temp(Fname, Lname, Uname, Email, Pass);
	admins.pushBack(std::move(temp));
}

void Game::addPlayer(const String& Fname, const String& Lname, const String& Uname, const String& Email, const String& Pass) {
	if (!validUsername(Uname)) {
		throw 201;//invalid username
	}
	if (!validPassword(Pass)) {
		throw 202;//invalid password
	}
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == Uname) {
			throw 203;//username is taken
		}
	}

	Player temp(Fname, Lname, Uname, Email, Pass, STARTING_MONEY);
	players.pushBack(std::move(temp));
}

void Game::deletePlayer(const String& Uname) {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == Uname) {
			players.popAt(i);
			return;
		}
	}
	throw 204;
}

void Game::showAdmins() const {
	int adminsCount = admins.getSize();
	for (int i = 0; i < adminsCount; i++) {
		if (loggedUser.loggedAdmin->getUsername() == admins[i].getUsername()) {
			continue; //doesn't print the logged admin info
		}
		admins[i].printInfoForAdmins();
		std::cout << std::endl;
	}
}

void Game::showPlayers() const {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		players[i].printInfoForAdmins();
		std::cout << std::endl;
	}
}

void Game::addSuperhero(const String& Fname, const String& Lname, const String& nickname,
	const unsigned short power, const unsigned short price, const Element& element) {
	
	int heroesCount = shop.getSize();
	for (int i = 0; i < heroesCount; i++) {
		if (shop[i].getFirstName() == Fname && shop[i].getLastName() == Lname) {
			throw 501;
		}
	}
	Superhero temp(Fname, Lname, nickname, power, price, element);
	shop.pushBack(std::move(temp));
}

//player functions
void Game::playerLogin(const String& Uname, const String& Pass) {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].checkUsername(Uname)) {
			if (players[i].checkPassword(Pass)) {
				loggedUser.loggedPlayer = &players[i];
				if (players[i].getTurns() != 3) {
					resetCycle(playersCount);
				}
				return;
			}
			else {
				throw 101; // wrong password
			}
		}
	}
	throw 102;//wrong username
}

void Game::deleteProfile() {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == loggedUser.loggedPlayer->getUsername()) {
			loggedUser.logout();
			players.popAt(i);
			return;
		}
	}
	
}

//prints player info for players
void Game::printP2PInfo() const {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		std::cout << i + 1 << ". ";
		players[i].printInfoForPlayers();
		std::cout << std::endl;
	}
}

void Game::showLeaderboard() {

	int playersCount = players.getSize();
	for (int i = 1; i < playersCount; i++) {
		Player currPlayer = players[i];

		int j = i - 1;
		while (j >= 0 && players[j].getBalance() < currPlayer.getBalance()) {
			players[j + 1] = players[j];
			j--;
		}

		players[j + 1] = currPlayer;
	}
	for (int i = 0; i < playersCount; i++) {
		std::cout << i + 1 << ". ";
		std::cout << players[i].getUsername() << ' ' << players[i].getBalance() << std::endl;
	}
	std::cout << std::endl;
}

void Game::showMarket() const {
	int heroesCount = shop.getSize();
	if (heroesCount == 0) {
		std::cout << "Market is empty!" << std::endl;
		return;
	}

	for (int i = 0; i < heroesCount; i++) {
		std::cout << i + 1 << ". ";
		shop[i].printInfo();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Game::showBalance() const {
	std::cout << loggedUser.loggedPlayer->getBalance() << "$" << std::endl;
}

void Game::buyHero(const String& Fname, const String& Lname) {

	int heroesCount = shop.getSize();
	for (int i = 0; i < heroesCount; i++) {
		if (shop[i].getFirstName() == Fname && shop[i].getLastName() == Lname) {
			loggedUser.loggedPlayer->buySuperhero(shop[i]);
			loggedUser.loggedPlayer->useTurn();
			shop.popAt(i);
			return;
		}
	}
	throw 701;//hero not found
}

void Game::attack(const String& Uname, const String& FnameAtck, const String& LnameAtck, const String& FnameDef, const String& LnameDef) {
	//find the player
	Player* attacked = nullptr;
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == Uname) {
			attacked = &players[i];
			break;
		}
	}
	
	if (!attacked) {
		throw 801;//player not found
	}


//find attacking hero
	int attackerIdx;
	Superhero* attacker = nullptr;
	int heroesCount1 = loggedUser.loggedPlayer->getHeroes().getSize();
	for (int i = 0; i < heroesCount1; i++) {
		if (loggedUser.loggedPlayer->getHeroes()[i].getFirstName() == FnameAtck &&
			loggedUser.loggedPlayer->getHeroes()[i].getLastName() == LnameAtck) {

			attacker = &loggedUser.loggedPlayer->getHeroes()[i];
			attackerIdx = i;
			break;
		}
	}

	if (!attacker) {
		throw 802;//atacking hero not found
	}

	int defenderIdx;
	Superhero* defender = nullptr;
	int heroesCount2 = attacked->getHeroes().getSize();

	//if the attacked player has no heroes
	if (heroesCount2 == 0) {
		int power = attacker->getPower();
		attacked->loseMoney(power);
		loggedUser.loggedPlayer->winMoney(FIGHT_WIN_REWARD);
		loggedUser.loggedPlayer->useTurn();
		return;
	}

	//find defending hero
	for (int i = 0; i < heroesCount2; i++) {
		if (attacked->getHeroes()[i].getFirstName() == FnameAtck &&
			attacked->getHeroes()[i].getLastName() == LnameAtck) {

			defender = &attacked->getHeroes()[i];
			defenderIdx = i;
			break;
		}
	}
	if (!defender) {
		throw 803;//defending hero not found
	}

	bool isInOffMode = (defender->getMode() == Mode::offencive);

	int attackerPower = attacker->getPower();
	int defenderPower = defender->getPower();

	if (ElementUtils::lessThan(attacker->getElement(), defender->getElement())) {

		int res = comparePowers(attackerPower, defenderPower * 2);

		if (res < 0) { // atacker wins
			if (isInOffMode) {
				int diff = attackerPower - defenderPower;
				attacked->loseMoney(diff);
				loggedUser.loggedPlayer->winMoney(diff);
			}
			attacked->getHeroes().popAt(defenderIdx);
		}
		else if (res > 0) { // defender wins

			int diff = defenderPower - attackerPower;
			attacked->winMoney(FIGHT_WIN_REWARD);
			loggedUser.loggedPlayer->loseMoney(2 * diff);

			loggedUser.loggedPlayer->getHeroes().popAt(attackerIdx);
		}
		else { // equal
			loggedUser.loggedPlayer->loseMoney(FIGHT_DRAW_LOSS);
		}
	}
	else if (ElementUtils::greaterThan(attacker->getElement(), defender->getElement())) {
		int res = comparePowers(attacker->getPower() * 2, defender->getPower());

		if (res < 0) { // atacker wins
			if (isInOffMode) {
				int diff = attackerPower - defenderPower;
				attacked->loseMoney(diff);
				loggedUser.loggedPlayer->winMoney(diff);
			}
			attacked->getHeroes().popAt(defenderIdx);
		}
		else if (res > 0) { // defender wins

			int diff = defenderPower - attackerPower;
			attacked->winMoney(FIGHT_WIN_REWARD);
			loggedUser.loggedPlayer->loseMoney(2 * diff);

			loggedUser.loggedPlayer->getHeroes().popAt(attackerIdx);
		}
		else { // equal
			loggedUser.loggedPlayer->loseMoney(FIGHT_DRAW_LOSS);
		}
	}
	else {
		int res = comparePowers(attacker->getPower(), defender->getPower());

		if (res < 0) { // atacker wins
			if (isInOffMode) {
				int diff = attackerPower - defenderPower;
				attacked->loseMoney(diff);
				loggedUser.loggedPlayer->winMoney(diff);
			}
			attacked->getHeroes().popAt(defenderIdx);
		}
		else if (res > 0) { // defender wins

			int diff = defenderPower - attackerPower;
			attacked->winMoney(FIGHT_WIN_REWARD);
			loggedUser.loggedPlayer->loseMoney(2 * diff);

			loggedUser.loggedPlayer->getHeroes().popAt(attackerIdx);
		}
		else { // equal
			loggedUser.loggedPlayer->loseMoney(FIGHT_DRAW_LOSS);
		}
	}
	loggedUser.loggedPlayer->useTurn();
}


void Game::changeMode(const String& Fname, const String& Lname) {
	int size = loggedUser.loggedPlayer->getHeroes().getSize();
	for (int i = 0; i < size; i++) {
		if (loggedUser.loggedPlayer->getHeroes()[i].getFirstName() == Fname && loggedUser.loggedPlayer->getHeroes()[i].getLastName() == Lname) {
			loggedUser.loggedPlayer->getHeroes()[i].changeMode();
			loggedUser.loggedPlayer->useTurn();
			return;
		}
	}
	throw 701;
}

void Game::exit() {
	loggedUser.logout();
}