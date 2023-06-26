#pragma once
#include"Superhero.h"
#include"String.h"
#include"Vector.hpp"
#include"Player.h"
#include"Admin.h"

<<<<<<< HEAD
const unsigned FIGHT_WIN_REWARD = 400;
=======
const unsigned FIGHT_WIN_REWARD = 400; 
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
const unsigned FIGHT_DRAW_LOSS = 400;
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
			throw 103;//no logged user
		}

		void logout() {
			if (loggedPlayer != nullptr)
				loggedPlayer = nullptr;
<<<<<<< HEAD
			else if (loggedAdmin != nullptr)
=======
			if (loggedAdmin != nullptr)
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
				loggedAdmin = nullptr;
			else
				throw 103;//no logged user
		}
	} loggedUser;

	int comparePowers(const int power1, const int power2) const;
<<<<<<< HEAD
	void resetCycle(int playersCount);
	
	bool validUsername(const String& username) const;
	bool validPassword(const String& password) const;
=======

public:
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3

public:
	
	Game();
	~Game();

<<<<<<< HEAD
	//utilities
	bool marketIsEmpty() const;
	bool playerIsLoggedIn() const;
	bool adminisLoggedIn() const;
	bool playerHasTurns() const;

=======
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
	//admin functions
	void adminLogin(const String& Uname, const String& Pass); 
	void addAdmin(const String& Fname, const String& Lname, const String& Uname, const String& Email, const String& Pass); 
	void addPlayer(const String& Fname, const String& Lname, const String& Uname, const String& Email, const String& Pass);
	void deletePlayer(const String& Uname); 
	void showAdmins() const; 
	void showPlayers() const;
<<<<<<< HEAD
	void addSuperhero(const String& Fname, const String& Lname, const String& nickname,
		const unsigned short power, const unsigned short price, const Element& element);

	//player functions
	void playerLogin(const String& Uname, const String& Pass);
	void deleteProfile();
	void printP2PInfo() const;
	void showLeaderboard();
	void showMarket() const;
	void showBalance() const;
	void buyHero(const String& Fname, const String& Lname);
	void attack(const String& Uname, const String& FnameAtck, const String& LnameAtck, const String& FnameDef, const String& LnameDef); //to be tested
	void changeMode(const String& Fname, const String& Lname);
	
	
=======
	void addSuperhero(	const String& Fname, const String& Lname, const String& nickname,
						const unsigned short power, const unsigned short price, const Element& element); 
				
	//player functions
	void userLogin(const String& Uname, const String& Pass); 
	void deleteProfile(); 
	void printInfo2() const; 
	void seeLeaderboard(); 
	void showMarket() const;
	void buyHero(const String& Fname, const String& Lname); 
	void attack(const String& Uname, const String& FnameAtck, const String& LnameAtck, const String& FnameDef, const String& LnameDef); //to be tested
	void changePosition(const String& Fname, const String& Lname);
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
	void exit();

};
