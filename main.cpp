#include<iostream>
#include"Superhero.h"
#include"String.h"
#include"Player.h"
#include"Admin.h"
#include"Game.h"

using namespace std;
//will be in command class

/*bool Game::passIsSuitable(const String& pass) const {
	int length = pass.length();
	bool smallLetterFlag = 0, capLetterFlag = 0, numberFlag = 0;
	for (int i = 0; i < length; i++) {
		if (pass[i] >= 48 && pass[i] <= 57) {
			numberFlag = 1;
		}

		if (pass[i] >= 65 && pass[i] <= 90) {
			capLetterFlag = 1;
		}

		if (pass[i] >= 97 && pass[i] <= 122) {
			smallLetterFlag = 1;
		}

		if (smallLetterFlag && capLetterFlag && numberFlag) {
			return 1;
		}
	}
	return 0;
}

bool Game::usernameIsSuitable(const String& name) const {
	int length = name.length();
	if (length > 16) {
		return 0;
	}

	for (int i = 0; i < length; i++) {
		if (name[i] < 97 || name[i] > 122) {
			return 0;
		}
	}
	return 1;
}*/

void seeLeaderboard(Vector<Player> players) {
	//copy printInfo2 and sort it 
	int length = players.getSize();
	for (int i = 0; i < length; i++) {
		std::cout << i + 1 << ". ";
		players[i].printInfoForPlayers();
		std::cout << std::endl;
	}

	for (int i = 1; i < length; i++) {
		Player currPlayer = players[i];

		int j = i - 1;
		while (j >= 0 && players[j].getBalance() < currPlayer.getBalance()) {
			players[j + 1] = players[j];
			j--;
		}

		players[j + 1] = currPlayer;
	}
	for (int i = 0; i < length; i++) {
		std::cout << i + 1 << ". ";
		players[i].printInfoForPlayers();
		std::cout << std::endl;
	}
}

int main() {

	Element a = Element::fire;
	Element b = Element::water;
	Element c = Element::earth;

	cout << (a < b);
	/*Game a;

	a.adminLogin("menata", "Aa1");

	a.addPlayer("Gosho", "Losho", "Gosh1", "gosh@abv", "1Aa");
	a.addPlayer("Gosho1", "Losho", "Gosh2", "gosh@abv", "1Aa");
	a.showPlayers();

	a.addPlayer("Gosho2", "Losho", "Gosh3", "gosh@abv", "1Aa");
	a.addPlayer("Gosho3", "Losho", "Gosh4", "gosh@abv", "1Aa");
	a.showPlayers();

	a.addAdmin("Gosho", "Losho", "Gosh12", "gosh@abv", "1Aa");
	a.showAdmins();

	a.deletePlayer("Gosh2");
	a.showPlayers();

	a.addSuperhero("peter1", "petrov", "pecata1", 100, 200, Element::fire);
	a.addSuperhero("peter2", "petrov", "pecata2", 100, 200, Element::water);
	a.addSuperhero("peter3", "petrov", "pecata3", 100, 200, Element::earth);
	a.showMarket();

	a.exit();

	a.userLogin("Gosh3", "1Aa");
	a.buyHero("peter1", "petrov");
	a.seeLeaderboard();
	a.printInfo2();
	a.deleteProfile();

	a.showPlayers();
	a.adminLogin("Gosh12", "1Aa");
	a.showAdmins();
	a.exit();

	*/
	return 0;
}