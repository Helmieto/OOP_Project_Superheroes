#pragma once
#include"Superhero.h"
#include"String.h"
#include"Vector.hpp"
#include"Player.h"
#include"Admin.h"

const unsigned FIGHT_WIN_REWARD = 10; //FIX ME
const unsigned FIGHT_DRAW_LOSS = 10; //FIX ME
const unsigned CYCLE_REWARD = 300;
const unsigned STARTING_MONEY = 800;

class Game {
	Vector<Admin> admins;
	Vector<Player> players;
	Vector<Superhero> shop;
	User* loggedUser;

public:
	//admin functions
	//void adminLogin();
	void addAdmin(String Fname, String Lname, String Uname, String Email, String Pass);
	void addPlayer(String Fname, String Lname, String Uname, String Email, String Pass, unsigned bal);
	void deletePlayer(String Uname);
	void printInfo() const;
	void addSuperhero(	String Fname, String Lname, String nickname,
						unsigned short power, unsigned short price, Element element);
				
	//player functions
	//void userLogin();
	void deleteProfile();
	void printInfo2() const;
	void seeLeaderboard() const;
	void showMarket() const;
	void buyHero(String Fname, String Lname);
	void attack(String Uname);
	void changePosition(String Fname, String Lname);
	void exit();

};

//admin functions
void Game::addAdmin(String Fname, String Lname, String Uname, String Email, String Pass) {
	Admin temp(Fname, Lname, Uname, Email, Pass);
	admins.pushBack(std::move(temp));
}

void Game::addPlayer(String Fname, String Lname, String Uname, String Email, String Pass, unsigned bal) {
	Player temp(Fname, Lname, Uname, Email, Pass, STARTING_MONEY);
	players.pushBack(std::move(temp));
}

void Game::deletePlayer(String Uname) {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == Uname) {
			players.popAt(i);
			break;
		}
	}
}

void Game::printInfo() const {
	//later
}

void Game::addSuperhero(String Fname, String Lname, String nickname,
	unsigned short power, unsigned short price, Element element) {

}

//player functions
void Game::deleteProfile() {
	int playersCount = players.getSize();
	for (int i = 0; i < playersCount; i++) {
		if (players[i].getUsername() == loggedUser->getUsername()) {
			players.popAt(i);
			break;
		}
	}
	loggedUser = nullptr; //THIS IS BLUEPPRINT, WILL HAVE TO CHECK FOR MEMORY LEAKS
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

void Game::seeLeaderboard() const {
	//copy printInfo2 and sort it 
}

void Game::showMarket() const {
	int heroesCount = shop.getSize();
	for (int i = 0; i < heroesCount; i++) {
		std::cout << i + 1 << ". ";
		shop[i].printInfo();
		std::cout << std::endl;
	}
}

void Game::buyHero(String Fname, String Lname) {
	int heroesCount = shop.getSize();
	for (int i = 0; i < heroesCount; i++) {
		if (shop[i].getFirstName() == Fname && shop[i].getLastName() == Lname) {
			//loggedUser->buyHero(shop[i]); ???
			shop.popAt(i);
			break;
		}
	}
}

void Game::attack(String Uname) {

}
//FIX ME
void Game::changePosition(String Fname, String Lname) {
	/*int size = loggedUser->heroes.getSize();
	for (int i = 0; i < size; i++) {
		if (loggedUser->heroes[i].getFirstName() == Fname && loggedUser->heroes[i].getLastName() == Lname) {
			loggedUser->heroes[i].changeMode();
			break;
		}
	}*/
}

void Game::exit() {
	loggedUser = nullptr;
}