#include<iostream>
#include"CommandExecutor.h"
#include"CommandFactory.h"

using namespace std;

int main() {
	
	CommandExecutor exec;
	Game game;

	while (true) {
		exec.addCommand(CommandFactory::getInstance().getCommand(game));
		exec.executeCommand();
	}
	return 0;
}