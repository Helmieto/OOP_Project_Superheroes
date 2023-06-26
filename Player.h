#pragma once
#include"User.h"

class Player : public User {
	unsigned balance;
	Vector<Superhero> heroes;
	int turnsRemaining;
public:
	Player() : balance(0), turnsRemaining(3) {}
	Player(String Fname, String Lname, String Uname, String Email, String Pass, unsigned bal);
	
	void buySuperhero(Superhero& a); //CHECK!!
<<<<<<< HEAD
	void winMoney(const unsigned amount);
	void loseMoney(const unsigned amount);
	void resetTurns();
	void useTurn();

	void setBalance(unsigned _balance);
	void setTurns(int _turns);

	Vector<Superhero> getHeroes() const;
	unsigned getBalance() const;
	int getTurns() const;

=======
	void destroyHero(const String& Fname, const String& Lname);
	void winMoney(const unsigned amount);
	void loseMoney(const unsigned amount);

	Vector<Superhero> getHeroes() const;
	unsigned getBalance() const;
	
>>>>>>> 11123104908f75a64170f523a4f3db16a17004d3
	void printHeroes() const;
	void printInfoForPlayers() const override;
	void printInfoForAdmins() const override;
};
