#pragma once
#include"User.h"

class Player : public User {
	unsigned balance;
	Vector<Superhero> heroes;
	int turnsRemaining;
public:
	Player() : balance(0), turnsRemaining(3) {}
	Player(String Fname, String Lname, String Uname, String Email, String Pass, unsigned bal);
	
	void buySuperhero(Superhero& a); 
	void destroySuperhero(int index);
	void changeHeroMode(int index);
	void winMoney(const unsigned amount);
	void loseMoney(const unsigned amount);
	void resetTurns();
	void useTurn();

	void setBalance(unsigned _balance);
	void setTurns(int _turns);

	Vector<Superhero> getHeroes() const;
	unsigned getBalance() const;
	int getTurns() const;

	void printHeroes() const;
	void printInfoForPlayers() const override;
	void printInfoForAdmins() const override;
};
