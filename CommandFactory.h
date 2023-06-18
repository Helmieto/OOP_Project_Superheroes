#pragma once
#include "Commands.h"

class CommandFactory
{
	CommandFactory() = default;
	CommandFactory(const CommandFactory&) = delete;
	CommandFactory& operator=(const CommandFactory&) = delete;

public:
	Command* getCommand(Game& game) const;
	static CommandFactory& getInstance();
};

