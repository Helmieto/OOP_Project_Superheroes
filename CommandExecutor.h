#pragma once
#include "Commands.h"

class CommandExecutor
{
	Command* command;
public:
	CommandExecutor() = default;
	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;
	~CommandExecutor();

	void addCommand(Command* _command);
	void executeCommand();
	
};

