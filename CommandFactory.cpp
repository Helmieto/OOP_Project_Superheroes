#include "CommandFactory.h"

CommandFactory& CommandFactory::getInstance()
{
	static CommandFactory factory;
	return factory;
}

Command* CommandFactory::getCommand(Game& game) const{
	
    while (true) {

        std::cout << std::endl;

        std::cout << "Input a command code!" << std::endl;
        int n;
        std::cin >> n;

        if (n == 1) {
            return new Command1(game);
        }
        if (n == 2) {
            return new Command2(game);
        }
        if (n == 3) {
            return new Command3(game);
        }
        if (n == 4) {
            return new Command4(game);
        }
        if (n == 5) {
            return new Command5(game);
        }
        if (n == 6) {
            return new Command6(game);
        }
        if (n == 7) {
            return new Command7(game);
        }
        if (n == 8) {
            return new Command8(game);
        }
        if (n == 9) {
            return new Command9(game);
        }
        if (n == 10) {
            return new Command10(game);
        }
        if (n == 11) {
            return new Command11(game);
        }
        if (n == 12) {
            return new Command12(game);
        }
        if (n == 13) {
            return new Command13(game);
        }
        if (n == 14) {
            return new Command14(game);
        }
        if (n == 15) {
            return new Command15(game);
        }
        if (n == 16) {
            return new Command16(game);
        }
        if (n == 17) {
            return new Command17(game);
        }
        std::cout << "This is not a valid command! Please try again!" << std::endl;
    }
	

}
