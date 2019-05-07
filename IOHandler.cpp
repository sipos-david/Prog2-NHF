#include "IOHandler.h"

bool IOHandler::getFromUserYesOrNoQuestion(const char* question) {
	std::cout << question << std::endl;
	char tmp;   
	while (true) {
		std::cin >> tmp;
		if (tmp == 'i' || tmp == 'I' || tmp == 'y' || tmp == 'Y')
			return true;
		else if (tmp == 'n' || tmp == 'N')
			return false;
	}
}

size_t IOHandler::getFromUserSimulationNumber() {
	size_t tmp;
	std::cout << "Mennyi meccseet jatszanak a jatekosok?" << std::endl;
	std::cin >> tmp;
	return tmp;
}

size_t IOHandler::getIdForPlayer() {
	return container.size();
}

void IOHandler::getFromUserRandomPlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e random jatekos?"))
		container.playerAdd(new Player(new RandomPlayer(this->getIdForPlayer(), "random jatekos")));
}

void IOHandler::getFromUserStonePlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e ko jatekos?"))
		container.playerAdd(new Player(new StonePlayer(this->getIdForPlayer(), "ko jatekos")));
}

void IOHandler::getFromUserPaperPlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e papir jatekos?"))
		container.playerAdd(new Player(new PaperPlayer(this->getIdForPlayer(), "papir jatekos")));
}

void IOHandler::getFromUserScissorsPlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e ollo jatekos?"))
		container.playerAdd(new Player(new ScissorsPlayer(this->getIdForPlayer(), "ollo jatekos")));
}

void IOHandler::getFromUserSequancePlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e szekvencia jatekos?")) {

	}
}

void IOHandler::listMatchLogs()
{
}

void IOHandler::listPlayerLogs()
{
}

void IOHandler::listAllPlayers() {
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i].getId() << "\t" << container[i].getName() << std::endl;
}

