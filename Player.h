#pragma once
#include"User.h"

class Player : public User {
	unsigned balance;
	Vector<Superhero> heroes;
	
public:
	
	Player(String Fname, String Lname, String Uname, String Email, String Pass, unsigned bal);
	void setBalance(unsigned _balance);
	void buySuperhero(Superhero& a); //CHECK!!
	
	unsigned getBalance() const;
	
	Type identify() const override;

	void printHeroes() const;
	void printInfoForPlayers() const override;
	void printInfoForAdmins() const override;
};

