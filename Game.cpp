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

//admin functions
void Game::adminLogin(const String& Uname, const String& Pass) {
	int adminsCount = admins.getSize();
	for (int i = 0; i < adminsCount; i++) {
		if (admins[i].checkUsername(Uname)) {
			if (admins[i].checkPassword(Pass)) {
				loggedUser.loggedAdmin = &admins[i];
				break;
			}
			else {
				//throw wrong password
			}
		}
	}
}

void Game::addAdmin(const String& Fname, const String& Lname, const String& Uname, const String& Email, const String& Pass) {
	Admin temp(Fname, Lname, Uname, Email, Pass);
	admins.pushBack(std::move(temp));
}

void Game::addPlayer(const String& Fname, const String& Lname, const String& Uname, const String& Email, const String& Pass) {
	Player temp(Fname, Lname, Uname, Email, Pass, STARTING_MONEY);
	players.pushBack(std::move(temp));
}

void Game::deletePlayer(const String& Uname) {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == Uname) {
			players.popAt(i);
			break;
		}
	}
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
	Superhero temp(Fname, Lname, nickname, power, price, element);
	shop.pushBack(std::move(temp));
}

//player functions
void Game::userLogin(const String& Uname, const String& Pass) {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].checkUsername(Uname)) {
			if (players[i].checkPassword(Pass)) {
				loggedUser.loggedPlayer = &players[i];
				break;
			}
			else {
				//throw wrong password
			}
		}
	}
}

void Game::deleteProfile() {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == loggedUser.loggedPlayer->getUsername()) {
			players.popAt(i);
			break;
		}
	}
	loggedUser.logout(); 
}

//prints player info for players
void Game::printInfo2() const {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		std::cout << i + 1 << ". ";
		players[i].printInfoForPlayers();
		std::cout << std::endl;
	}
}

void Game::seeLeaderboard() {

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
	for (int i = 0; i < heroesCount; i++) {
		std::cout << i + 1 << ". ";
		shop[i].printInfo();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Game::buyHero(const String& Fname, const String& Lname) {
	int heroesCount = shop.getSize();
	for (int i = 0; i < heroesCount; i++) {
		if (shop[i].getFirstName() == Fname && shop[i].getLastName() == Lname) {
			loggedUser.loggedPlayer->buySuperhero(shop[i]);
			shop.popAt(i);
			return;
		}
	}
	//throw
}

/*��� �� �������� ���� ���� ��������� � �������:

2.��� ����� ������� ���������� �� ���� �����, ����� �� ��������� ������� ��� ����. ����� ���� ��� ���� ��������� ����, ����� ������:      
����->����->����->����. 
-��� ���������� ����� � � ��������� ��� ����, �� ������� �� ���������� �� � ���� ����� ����� ������� 
� �� �������� ��������� �� ���������� �� ����, �������� ��-����. 

-� ������, �� ����������� ����� � � ����������� ��� ����, 
�� ������ ������� �� ������������� ���������� �� ������� �� �������� � ������ �� �������� ������ �� ������������. 

-� ������, �� �������� ���� �������� � ����������� �� ���������� ����� � � �������� �����, �� �������� ������ �� ������������.

���������� ���������� ������ ���� ���������� �� ���������� �� ��������� � ����� �����. ������������ �� ���� � ����� ������:

��� ����������� �� ��������� ����� � � ��-������ ���� �� ���� �� ������� �������, �� ����������� ����� ���� ���� � ������ 
��������� �� ������ �� ������������, ����� �� ������������, � ���������� ����� ������ ���� ����� �� ������ �������.

��� ����������� �� ��������� ����� � � ��-����� ���� �� ���� �� ����������, �� ����������� ������ ���� z, 
� ���������� ���� ���� �� �������� 2 ���� ��������� �� ������ �� ������������, ����� �� ������������.

��� ������������ �� � ����� ����, ������ ���������� ����� �� ������� � �� ���� ����, �� ��������� ���� ���� k.
� ������, �� ���������� ����� ������ ����������, ����� � � ���������� �����, �� ������ ����������� �� ���� ������� ���� 
(�� ���� �� ������ ����� ��) � ����������� �� ��������� � ����� � 2.
*/
void Game::attack(const String& Uname, const String& FnameAtck, const String& LnameAtck, const String& FnameDef, const String& LnameDef) {
	//find the player
	Player* attacked;
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == Uname) {
			attacked = &players[i];
			break;
		}
	}
	if (!attacked) {}
		//throw
		

	//find attacking hero
	int attackerIdx;
	Superhero* attacker;
	int heroesCount1 = loggedUser.loggedPlayer->getHeroes().getSize();
	for (int i = 0; i < heroesCount1; i++) {
		if (loggedUser.loggedPlayer->getHeroes()[i].getFirstName() == FnameAtck &&
			loggedUser.loggedPlayer->getHeroes()[i].getLastName() == LnameAtck) {
			
			attacker = &loggedUser.loggedPlayer->getHeroes()[i];
			attackerIdx = i;
			break;
		}
	}

	
	int defenderIdx;
	Superhero* defender;
	int heroesCount2 = attacked->getHeroes().getSize();

	//1
	if (heroesCount2 == 0) {
		int power = attacker->getPower();
		attacked->loseMoney(power);
		loggedUser.loggedPlayer->winMoney(FIGHT_WIN_REWARD);
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
}


void Game::changePosition(const String& Fname, const String& Lname) {
	int size = loggedUser.loggedPlayer->getHeroes().getSize();
	for (int i = 0; i < size; i++) {
		if (loggedUser.loggedPlayer->getHeroes()[i].getFirstName() == Fname && loggedUser.loggedPlayer->getHeroes()[i].getLastName() == Lname) {
			loggedUser.loggedPlayer->getHeroes()[i].changeMode();
			break;
		}
	}
}

void Game::exit() {
	loggedUser.logout();
}