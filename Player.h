#pragma once
#include"User.h"

class Player : public User {
	unsigned balance;
	Vector<Superhero> heroes;
	
public:
	Player() : balance(0) {}
	Player(String Fname, String Lname, String Uname, String Email, String Pass, unsigned bal);
	void setBalance(unsigned _balance);
	void buySuperhero(Superhero& a); //CHECK!!
	
	Vector<Superhero> getHeroes() const {
		return heroes;
	}
	unsigned getBalance() const;
	
	Type identify() const override;

	void printHeroes() const;
	void printInfoForPlayers() const override;
	void printInfoForAdmins() const override;
};

