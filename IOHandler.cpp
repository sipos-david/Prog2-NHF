#include "IOHandler.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

bool IOHandler::getFromUserYesOrNoQuestion(const char* question) {
	std::cout << std::endl << question << std::endl;
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
	std::cout << "Mennyi meccset jatszanak a jatekosok?" << std::endl;
	std::cin >> tmp;
	return tmp;
}

size_t IOHandler::getIdForPlayer() {
	return container.size();
}

void IOHandler::getFromUserRandomPlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e random jatekos?"))
		container.playerAdd(new Player(new RandomPlayer(this->getIdForPlayer(), "random")));
}

void IOHandler::getFromUserStonePlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e ko jatekos?"))
		container.playerAdd(new Player(new StonePlayer(this->getIdForPlayer(), "ko")));
}

void IOHandler::getFromUserPaperPlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e papir jatekos?"))
		container.playerAdd(new Player(new PaperPlayer(this->getIdForPlayer(), "papir")));
}

void IOHandler::getFromUserScissorsPlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e ollo jatekos?"))
		container.playerAdd(new Player(new ScissorsPlayer(this->getIdForPlayer(), "ollo")));
}

void IOHandler::getFromUserSequancePlayer() {
	if (this->getFromUserYesOrNoQuestion("Legyen-e szekvencia jatekos?")) {
		String currentSequence ,baseName = "szekv.";
		int currentNum = 1;

		/* C-s fájlkezelés, mivel nem lehet használlni std::string-et */
		FILE* inputFile = fopen("sequences.txt", "r");

		if (inputFile == NULL) {
			std::cout << "sequences.txt :: error :: couldn't open!" << std::endl;
			return;
		}
			
		char in = fgetc(inputFile);
		while (in != EOF)
		{
			if (in == ';')
				container.playerAdd(new Player(new SequencePlayer(this->getIdForPlayer(), baseName + currentNum++, currentSequence)));
			else
				currentSequence = currentSequence + in;
			in = fgetc(inputFile);
		}
		fclose(inputFile);
	}
}

void IOHandler::listMatchLogs() {
	std::cout << std::endl << "----- MECCSEK EREDMENYEI -----" << std::endl;
	for (size_t i = 0; i < log.matchLogsSize(); i++)
		std::cout << log.itMatchLogs(i) << std::endl;
	std::cout << std::endl;
}

void IOHandler::listPlayerLogs() {
	std::cout << std::endl << "----- JATEKOSOK EREDMENYEI -----" << std::endl;
	for (size_t i = 0; i < log.playerLogsSize(); i++)
		std::cout << *log.itPlayerLogs(i) << std::endl;
	std::cout << std::endl;
}

void IOHandler::listAllPlayers() {
	std::cout << std::endl << "----- JATEKOSOK -----" << std::endl;
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i].getId() << "\t" << container[i].getName() << std::endl;
}
