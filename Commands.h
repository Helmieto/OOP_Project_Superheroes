#pragma once
#include"Game.h"

class Command {
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};

//log in as admin
class Command1 : public Command {
	Game* game;
public:
	Command1(Game& _game);
	~Command1();
	void execute() override;
};

//login as player
class Command2 : public Command {
	Game* game;
public:
	Command2(Game& _game);
	~Command2();
	void execute() override;
};

//logout
class Command3 : public Command {
	Game* game;
public:
	Command3(Game& _game);
	~Command3();
	void execute() override;
};

//admin commands

//add admin
class Command4 : public Command {
	Game* game;
public:
	Command4(Game& _game);
	~Command4();
	void execute() override;
};

//add player
class Command5 : public Command {
	Game* game;
public:
	Command5(Game& _game);
	~Command5();
	void execute() override;
};

//delete player
class Command6 : public Command {
	Game* game;
public:
	Command6(Game& _game);
	~Command6();
	void execute() override;
};

//show all admins
class Command7 : public Command {
	Game* game;
public:
	Command7(Game& _game);
	~Command7();
	void execute() override;
};

//show all players
class Command8 : public Command {
	Game* game;
public:
	Command8(Game& _game);
	~Command8();
	void execute() override;
};

//add hero to shop
class Command9 : public Command {
	Game* game;
public:
	Command9(Game& _game);
	~Command9();
	void execute() override;
};

//player commands

//delete profile
class Command10 : public Command {
	Game* game;
public:
	Command10(Game& _game);
	~Command10();
	void execute() override;
};

//show all players
class Command11 : public Command {
	Game* game;
public:
	Command11(Game& _game);
	~Command11();
	void execute() override;
};

//show leaderboard
class Command12 : public Command {
	Game* game;
public:
	Command12(Game& _game);
	~Command12();
	void execute() override;
};

//show market
class Command13 : public Command {
	Game* game;
public:
	Command13(Game& _game);
	~Command13();
	void execute() override;
};

//show balance
class Command14 : public Command {
	Game* game;
public:
	Command14(Game& _game);
	~Command14();
	void execute() override;
};

//buy hero
class Command15 : public Command {
	Game* game;
public:
	Command15(Game& _game);
	~Command15();
	void execute() override;
};

//attack player
class Command16 : public Command {
	Game* game;
public:
	Command16(Game& _game);
	~Command16();
	void execute() override;
};

//change hero mode
class Command17 : public Command {
	Game* game;
public:
	Command17(Game& _game);
	~Command17();
	void execute() override;
};


