#include "Game.h"


Game::Game() {
	addAdmin("Milen", "Temelkov", "menata", "email@abv.bg", "Aa1");
}

Game::~Game() {
	loggedUser.logout();
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
		else {
			//throw wrong username
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
		else {
			//throw wrong username
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
	loggedUser.logout(); //THIS IS BLUEPPRINT, WILL HAVE TO CHECK FOR MEMORY LEAKS
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

void Game::attack(const String& Uname) {
	//tba
}
//FIX ME
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