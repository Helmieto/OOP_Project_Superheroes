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
	struct {
		Player* loggedPlayer = nullptr;
		Admin* loggedAdmin = nullptr;

		User* getLoggedUser() {
			if (loggedPlayer)
				return loggedPlayer;
			if (loggedAdmin)
				return loggedAdmin;
			//thorow
		}

		void logout() {
			if (loggedPlayer)
				loggedPlayer = nullptr;
			if (loggedAdmin)
				loggedAdmin = nullptr;
		}
	} loggedUser;

public:

	Game();
	~Game();
	//admin functions
	void adminLogin(const String& Uname, const String& Pass);
	void addAdmin(const String& Fname, const String& Lname, const String& Uname, const String& Email, const String& Pass);
	void addPlayer(const String& Fname, const String& Lname, const String& Uname, const String& Email, const String& Pass);
	void deletePlayer(const String& Uname);
	void showAdmins() const;
	void showPlayers() const;
	void addSuperhero(	const String& Fname, const String& Lname, const String& nickname,
						const unsigned short power, const unsigned short price, const Element& element);
				
	//player functions
	void userLogin(const String& Uname, const String& Pass);
	void deleteProfile();
	void printInfo2() const;
	void seeLeaderboard();
	void showMarket() const;
	void buyHero(const String& Fname, const String& Lname);
	void attack(const String& Uname);
	void changePosition(const String& Fname, const String& Lname);
	void exit();

};

