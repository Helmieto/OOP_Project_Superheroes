#include "CommandExecutor.h"


CommandExecutor::~CommandExecutor() {
	executeCommand();
}

void CommandExecutor::addCommand(Command* _command) {
	command = _command;
}

void CommandExecutor::executeCommand() {
	command->execute();
}
