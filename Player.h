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
	void destroyHero(const String& Fname, const String& Lname);
	void winMoney(const unsigned amount);
	void loseMoney(const unsigned amount);

	Vector<Superhero> getHeroes() const;
	unsigned getBalance() const;
	
	void printHeroes() const;
	void printInfoForPlayers() const override;
	void printInfoForAdmins() const override;
};

