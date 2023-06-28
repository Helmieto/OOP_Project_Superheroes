#include "Commands.h"

//log in as admin
Command1::Command1(Game& _game) {
	game = &_game;
}

Command1::~Command1() {
	game = nullptr;
}

void Command1::execute() {
	std::cout << std::endl;

	if (game->adminisLoggedIn()) {
		std::cout << "Another admin is already logged in!" << std::endl;
		return;
	}

	if (game->playerIsLoggedIn()) {
		std::cout << "Another player is already logged in!" << std::endl;
		return;
	}

	String uName, pass;
	
	std::cout << "Enter username and password!" << std::endl;
	std::cin >> uName >> pass;


	try {
		game->adminLogin(uName, pass);
		return;
	}
	catch (int code) {
		if (code == 101) {
			std::cout << "Wrong password!" << std::endl;
		}
		if (code == 102) {
			std::cout << "Wrong username!" << std::endl;
		}
	}
	
}


//login as a player
Command2::Command2(Game& _game) {
	game = &_game;
}

Command2::~Command2() {
	game = nullptr;
}

void Command2::execute() {
	std::cout << std::endl;

	if (game->adminisLoggedIn()) {
		std::cout << "Another admin is already logged in!" << std::endl;
		return;
	}

	if (game->playerIsLoggedIn()) {
		std::cout << "Another player is already logged in!" << std::endl;
		return;
	}

	String uName, pass;

	std::cout << "Enter username and password!" << std::endl;
	std::cin >> uName >> pass;
	std::cout << std::endl;

	try {
		game->playerLogin(uName, pass);
		return;
	}
	catch (int code) {
		if (code == 101) {
			std::cout << "Wrong password!" << std::endl;
		}
		if (code == 102) {
			std::cout << "Wrong username!" << std::endl;
		}
	}
	
}

//logout
Command3::Command3(Game& _game) {
	game = &_game;
}

Command3::~Command3() {
	game = nullptr;
}

void Command3::execute() {
	std::cout << std::endl;

	try {
		game->exit();
		std::cout << "You logged out successfully!" << std::endl;
		return;
	}
	catch (int code) {
		if (code == 103) {
			std::cout << "There is nobody logged in right now!" << std::endl;
		}
	}

	
}

//add admin
Command4::Command4(Game& _game) {
	game = &_game;
}

Command4::~Command4() {
	game = nullptr;
}

void Command4::execute() {
	std::cout << std::endl;

	if (!game->adminisLoggedIn()) {
		std::cout << "Log in as an admin to add another admin!" << std::endl;
		return;
	}

	std::cout << "Input first and last name, username, email and password of the admin" << std::endl;
	String fName, lName, uName, email, pass;
	std::cin >> fName >> lName >> uName >> email >> pass;

	try {
		game->addAdmin(fName, lName, uName, email, pass);
	}
	catch (int code) {
		if (code == 201) {
			std::cout << "Username should contain only small letters and be maximum 16 letters long!" << std::endl;
		}
		if (code == 202) {
			std::cout << "Password should contain at least one of the following:small letter, capital letter, number!" << std::endl;
		}
		if (code == 203) {
			std::cout << "This username is already taken" << std::endl;
		}
	}

	return;
}

//add player
Command5::Command5(Game& _game) {
	game = &_game;
}

Command5::~Command5() {
	game = nullptr;
}

void Command5::execute() {
	std::cout << std::endl;

	if (!game->adminisLoggedIn()) {
		std::cout << "Log in as an admin to add a player!" << std::endl;
		return;
	}
	std::cout << "Input first and last name, username, email and password of the player" << std::endl;
	String fName, lName, uName, email, pass;
	std::cin >> fName >> lName >> uName >> email >> pass;

	try {
		game->addPlayer(fName, lName, uName, email, pass);
	}
	catch (int code) {
		if (code == 201) {
			std::cout << "Username should contain only small letters and be maximum 16 letters long!" << std::endl;
		}
		if (code == 202) {
			std::cout << "Password should contain at least one of the following:small letter, capital letter, number!" << std::endl;
		}
		if (code == 203) {
			std::cout << "This username is already taken" << std::endl;
		}
	}

	return;
}

//delete player
Command6::Command6(Game& _game) {
	game = &_game;
}

Command6::~Command6() {
	game = nullptr;
}

void Command6::execute() {
	std::cout << std::endl;

	if (!game->adminisLoggedIn()) {
		std::cout << "Log in as an admin to delete a player!" << std::endl;
		return;
	}

	std::cout << "Input the username of the player:" << std::endl;
	String username;
	std::cin >> username;

	try {
		game->deletePlayer(username);
	}
	catch (int code) {
		if (code == 204) {
			std::cout << "Player with this username doesn't exist!" << std::endl;
		}
	}
	return;
}

//show all admins
Command7::Command7(Game& _game) {
	game = &_game;
}

Command7::~Command7() {
	game = nullptr;
}

void Command7::execute() {
	std::cout << std::endl;

	if (!game->adminisLoggedIn()) {
		std::cout << "Log in as an admin to see all admins!" << std::endl;
		return;
	}

	
	game->showAdmins();
	
	return;
}

//show all players
Command8::Command8(Game& _game) {
	game = &_game;
}

Command8::~Command8() {
	game = nullptr;
}

void Command8::execute() {
	std::cout << std::endl;

	if (!game->adminisLoggedIn()) {
		std::cout << "Log in as an admin to see all players!" << std::endl;
		return;
	}
	
	game->showPlayers();
	
	return;
}

//add hero to shop
Command9::Command9(Game& _game) {
	game = &_game;
}

Command9::~Command9() {
	game = nullptr;
}


void Command9::execute() {
	std::cout << std::endl;

	if (!game->adminisLoggedIn()) {
		std::cout << "Log in as an admin to add heroes to the shop!" << std::endl;
		return;
	}

	int stopAdding = 0;
	if (game->marketIsEmpty()) {
		std::cout << "Market is empty. Please add 3 heroes!" << std::endl;
		stopAdding = 3;
	}
	else {
		std::cout << "Add a hero!" << std::endl;
		stopAdding = 1;
	}

	int i = 0;
	while (i < stopAdding) {
		String fName, lName, nickname;
		int price, power, elemCode;
		std::cout << "Input first name, second name and  nickname of the hero!" << std::endl;
		std::cin >> fName >> lName >> nickname;
		std::cout << std::endl;

		while (true) {
			try {
				std::cout << "Input price:";
				std::cin >> price;
				std::cout << std::endl;
				if (price < 0) {
					throw 1;
				}
				break;
			}
			catch (int code) {
				if (code == 1) {
					std::cout << "Price should be a nonnegative number! Try again!" << std::endl;
				}
			}
		}

		while (true) {
			try {
				std::cout << "Input power:";
				std::cin >> power;
				std::cout << std::endl;
				if (power < 0) {
					throw 1;
				}
				break;
			}
			catch (int code) {
				if (code == 1) {
					std::cout << "Power should be a nonnegative number! Try again!" << std::endl;
				}
			}
		}

		while (true) {
			try {
				std::cout << "Input element code(1 - fire, 2 - earth, 3 - water):";
				std::cin >> elemCode;
				std::cout << std::endl;
				if (elemCode < 1 || elemCode > 3) {
					throw 1;
				}
				break;
			}
			catch (int code) {
				if (code == 1) {
					std::cout << "code should be either 1, 2 or 3! Try again!" << std::endl;
				}
			}
		}

		Element el;
		if (elemCode == 1) {
			el = Element::fire;
		}
		if (elemCode == 2) {
			el = Element::earth;
		}
		if (elemCode == 3) {
			el = Element::water;
		}

		try {
			game->addSuperhero(fName, lName, nickname, power, price, el);
			i++;
		}
		catch (int code) {
			if (code == 501) {
				std::cout << "This hero already exists! Try again!" << std::endl;
			}
		}
	}
}

//player functions

//delete profile
Command10::Command10(Game& _game) {
	game = &_game;
}

Command10::~Command10() {
	game = nullptr;
}

void Command10::execute() {
	std::cout << std::endl;

	if (!game->playerIsLoggedIn()) {
		std::cout << "Log in as a player to delete your profile!" << std::endl;
		return;
	}

	game->deleteProfile();
	return;
}

//show all players
Command11::Command11(Game& _game) {
	game = &_game;
}

Command11::~Command11() {
	game = nullptr;
}

void Command11::execute() {
	std::cout << std::endl;

	if (!game->playerIsLoggedIn()) {
		std::cout << "Log in as a player to see all players!" << std::endl;
		return;
	}

	game->printP2PInfo();
	return;
}

//show leaderboard
Command12::Command12(Game& _game) {
	game = &_game;
}

Command12::~Command12() {
	game = nullptr;
}

void Command12::execute() {
	std::cout << std::endl;

	if (!game->playerIsLoggedIn()) {
		std::cout << "Log in as a player to see leaderboard!" << std::endl;
		return;
	}

	game->showLeaderboard();
	return;
}

//show market
Command13::Command13(Game& _game) {
	game = &_game;
}

Command13::~Command13() {
	game = nullptr;
}

void Command13::execute() {
	std::cout << std::endl;

	if (!game->playerIsLoggedIn()) {
		std::cout << "Log in as a player to see the market!" << std::endl;
		return;
	}

	game->showMarket();
	return;
}

//show balance
Command14::Command14(Game& _game) {
	game = &_game;
}

Command14::~Command14() {
	game = nullptr;
}

void Command14::execute() {
	std::cout << std::endl;

	if (!game->playerIsLoggedIn()) {
		std::cout << "Log in as a player to see your balance!" << std::endl;
		return;
	}

	game->showBalance();
	return;
}

//buy hero
Command15::Command15(Game& _game) {
	game = &_game;
}

Command15::~Command15() {
	game = nullptr;
}

void Command15::execute() {
	std::cout << std::endl;

	if (!game->playerIsLoggedIn()) {
		std::cout << "Log in as a player to buy a hero!" << std::endl;
		return;
	}
	if (!game->playerHasTurns()) {
		std::cout << "Sorry, you have used all your turns!" << std::endl;
		return;
	}

	String fName, lName;
	
	std::cout << "Input the 2 names of the hero you want to buy!" << std::endl;
	std::cin >> fName >> lName;
	std::cout << std::endl;
	try {
		game->buyHero(fName, lName);
		return;
	}
	catch (int code) {
		if (code == 701) {
			std::cout << "Hero with this name doesn't exist! Try searching again!" << std::endl;
		}
	}
	
	
}

//attack player
Command16::Command16(Game& _game) {
	game = &_game;
}

Command16::~Command16() {
	game = nullptr;
}

void Command16::execute() {
	std::cout << std::endl;

	if (!game->playerIsLoggedIn()) {
		std::cout << "Log in as a player to be able to attack other players!" << std::endl;
		return;
	}

	if (!game->playerHasTurns()) {
		std::cout << "Sorry, you have used all your turns!" << std::endl;
		return;
	}
	String Uname, FnameAtck, LnameAtck, FnameDef, LnameDef;
	
	std::cout << "Input the nickname of the player you want to attack: ";
	std::cin >> Uname;
	std::cout << std::endl;

	std::cout << "Enter the names of the superhero you want to attack with: ";
	std::cin >> FnameAtck >> LnameAtck;
	std::cout << std::endl;

	std::cout << "Enter the names of the superhero you want to attack:";
	std::cin >> FnameDef >> LnameDef;
	std::cout << std::endl;

	try {
		game->attack(Uname, FnameAtck, LnameAtck, FnameDef, LnameDef);
		return;
	}
	catch (int code) {
		if (code == 800) {
			std::cout << "You cannot attack yourself!" << std::endl;
		}
		if (code == 801) {
			std::cout << "Player with this username doesn't exist! Try again!" << std::endl;
		}
		if (code == 802) {
			std::cout << "You don't have a hero with this name! Try again!" << std::endl;
		}
		if (code == 803) {
			std::cout << "Your oponent doesn't have a hero with this name! Try again!" << std::endl;
		}
	}
	
	return;
}


//change hero mode
Command17::Command17(Game& _game) {
	game = &_game;
}

Command17::~Command17() {
	game = nullptr;
}

void Command17::execute() {
	std::cout << std::endl;

	if (!game->playerIsLoggedIn()) {
		std::cout << "Log in as a player to change your hero mode!" << std::endl;
		return;
	}

	if (!game->playerHasTurns()) {
		std::cout << "Sorry, you have used all your turns!" << std::endl;
		return;
	}

	String fName, lName;
	
	std::cout << "Input the 2 names of the hero whose mode you want to change!" << std::endl;
	std::cin >> fName >> lName;
	std::cout << std::endl;
	try {
		game->changeMode(fName, lName);
		return;
	}
	catch (int code) {
		if (code == 701) {
			std::cout << "You don't have this hero! Try again!" << std::endl;
		}
	}
	
	
}