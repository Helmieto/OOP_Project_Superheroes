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

<<<<<<< HEAD
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
=======
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
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
<<<<<<< HEAD
	
=======
	loggedUser.logout(); 
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
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

<<<<<<< HEAD
void Game::attack(const String& Uname, const String& FnameAtck, const String& LnameAtck, const String& FnameDef, const String& LnameDef) {
	//find the player
	Player* attacked = nullptr;
=======
/*Как се определя дали едно нападение е успешно:

2.Ако играч нападне супергерой на друг играч, първо се сравняват техният тип сили. Всеки един тип сила побеждава друг, както следва:      
Огън->Земя->Вода->Огън. 
-Ако нападащият играч е с доминиращ тип сила, то точките на супергероя му в тази битка биват удвоени 
и се прилагат правилата за сравняване на сила, изброени по-долу. 

-В случай, че нападнатият играч е с доминиращия тип сила, 
то тогава точките на противниковия супергерой се намалят на половина и отново се сравнява силата на супергероите. 

-В случай, че типовете сили съвпадат и супергероят на нападнатия играч е в атакуващ режим, се сравнява силата на супергероите.

Победеният супергерой винаги бива унищожаван от колекцията на победения в битка играч. Сравняването на сила е както следва:

Ако супергероят на нападащия играч е с по-голяма сила от този на неговия опонент, то нападнатият играч губи пари с размер 
разликата на силата на супергероите, които се съревновават, а нападащият играч печели сума равна на същата разлика.

Ако супергероят на нападащия играч е с по-малко сила от този на нападнатия, то нападнатият печели сума z, 
а нападащият губи пари на стойност 2 пъти разликата на силите на супергероите, които се съревновават.

Ако супергероите са с равни сили, тогава нападнатия играч не променя и не губи пари, но нападащия губи сума k.
В случай, че нападащият играч напада супергерой, който е в дефанзивен режим, то тогава нападнатият не губи никакви пари 
(но може да изгуби героя си) и оценяването на победител е както в 2.
*/
void Game::attack(const String& Uname, const String& FnameAtck, const String& LnameAtck, const String& FnameDef, const String& LnameDef) {
	//find the player
	Player* attacked;
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == Uname) {
			attacked = &players[i];
			break;
		}
	}
<<<<<<< HEAD
	
	if (!attacked) {
		throw 801;//player not found
	}


//find attacking hero
	int attackerIdx;
	Superhero* attacker = nullptr;
=======
	if (!attacked) {}
		//throw
		

	//find attacking hero
	int attackerIdx;
	Superhero* attacker;
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
	int heroesCount1 = loggedUser.loggedPlayer->getHeroes().getSize();
	for (int i = 0; i < heroesCount1; i++) {
		if (loggedUser.loggedPlayer->getHeroes()[i].getFirstName() == FnameAtck &&
			loggedUser.loggedPlayer->getHeroes()[i].getLastName() == LnameAtck) {
<<<<<<< HEAD

=======
			
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
			attacker = &loggedUser.loggedPlayer->getHeroes()[i];
			attackerIdx = i;
			break;
		}
	}

<<<<<<< HEAD
	if (!attacker) {
		throw 802;//atacking hero not found
	}

	int defenderIdx;
	Superhero* defender = nullptr;
	int heroesCount2 = attacked->getHeroes().getSize();

	//if the attacked player has no heroes
=======
	
	int defenderIdx;
	Superhero* defender;
	int heroesCount2 = attacked->getHeroes().getSize();

	//1
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
	if (heroesCount2 == 0) {
		int power = attacker->getPower();
		attacked->loseMoney(power);
		loggedUser.loggedPlayer->winMoney(FIGHT_WIN_REWARD);
<<<<<<< HEAD
		loggedUser.loggedPlayer->useTurn();
=======
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
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
<<<<<<< HEAD
	if (!defender) {
		throw 803;//defending hero not found
	}

=======

	
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
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
<<<<<<< HEAD

			int diff = defenderPower - attackerPower;
			attacked->winMoney(FIGHT_WIN_REWARD);
			loggedUser.loggedPlayer->loseMoney(2 * diff);

=======
			
			int diff = defenderPower - attackerPower;
			attacked->winMoney(FIGHT_WIN_REWARD);
			loggedUser.loggedPlayer->loseMoney(2 * diff);
			
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
			loggedUser.loggedPlayer->getHeroes().popAt(attackerIdx);
		}
		else { // equal
			loggedUser.loggedPlayer->loseMoney(FIGHT_DRAW_LOSS);
		}
	}
	else if (ElementUtils::greaterThan(attacker->getElement(), defender->getElement())) {
		int res = comparePowers(attacker->getPower() * 2, defender->getPower());
<<<<<<< HEAD

=======
		
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
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
<<<<<<< HEAD

=======
		
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
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
<<<<<<< HEAD
	loggedUser.loggedPlayer->useTurn();
}


void Game::changeMode(const String& Fname, const String& Lname) {
=======
}


void Game::changePosition(const String& Fname, const String& Lname) {
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
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