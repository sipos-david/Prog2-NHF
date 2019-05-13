#include "SimulationLog.h"
#include <iomanip>

void SimulationLog::addMatchLog(GameLog* newGameLog) {
	this->resizeMatchLogs(1);
	this->matchLogs[lengthMatchLogs - (size_t)1] = *newGameLog;
	delete newGameLog;
}

void SimulationLog::addPlayerLog(Player* newPlayer) {
	this->resizePlayerLogs(1);
	this->playerLogs[lengthPlayerLogs - (size_t)1].player = newPlayer;
}

void SimulationLog::resizeMatchLogs(size_t add) {
	GameLog* newMatchLogs;
	bool succes = false;
	while (!succes) {
		try {
			newMatchLogs = new GameLog[lengthMatchLogs + add];
			succes = true; // remeljuk sikerult
		}
		catch (std::bad_alloc & ba) {
			std::cerr << "SimulationLog::resizeMatchLogs : " << ba.what() << std::endl;
			succes = false;
			delete[] newMatchLogs;
		}
	}

	for (size_t i = 0; i < lengthMatchLogs; i++)
		newMatchLogs[i] = matchLogs[i];
	delete[] matchLogs;
	matchLogs = newMatchLogs;
	this->lengthMatchLogs += add;
}

void SimulationLog::resizePlayerLogs(size_t add) {
	PlayerLog* newPlayerLogs;
	bool succes = false;
	while (!succes) {
		try {
			newPlayerLogs = new PlayerLog[lengthPlayerLogs + add];
			succes = true; // remeljuk sikerult
		}
		catch (std::bad_alloc & ba) {
			std::cerr << "SimulationLog::resizePlayerLogs : " << ba.what() << std::endl;
			succes = false;
			delete[] newPlayerLogs;
		}
	}

	for (size_t i = 0; i < lengthPlayerLogs; i++)
		newPlayerLogs[i] = playerLogs[i];
	if (playerLogs != nullptr)
		delete[] playerLogs;
	playerLogs = newPlayerLogs;
	this->lengthPlayerLogs += add;
}

void SimulationLog::initPlayerLogs(size_t playerNum) {
	resizePlayerLogs(playerNum);
}

size_t SimulationLog::matchLogsSize() {
	return lengthMatchLogs;
}

size_t SimulationLog::playerLogsSize() {
	return lengthPlayerLogs;
}

PlayerLog* SimulationLog::searchPlayerLog(Player* playerSearched) {
	for (size_t i = 0; i < lengthPlayerLogs; i++) {
		if (itPlayerLogs(i)->player->getId() == playerSearched->getId())
			return itPlayerLogs(i);
	}

	addPlayerLog(playerSearched);
	return itPlayerLogs(lengthPlayerLogs - (size_t)1);
}

GameLog& SimulationLog::itMatchLogs(size_t index) {
	if (index < lengthMatchLogs)
		return matchLogs[index];
	throw std::out_of_range("SimulationLog::itMatchLogs() : tul indexeles");
}

bool SimulationLog::foundMatchLogs(Player* playerOne, Player* playerTwo) {
	for (size_t i = 0; i < lengthMatchLogs; i++)
		if (itMatchLogs(i).playerOne->getId() == playerOne->getId() && itMatchLogs(i).playerTwo->getId() == playerTwo->getId())
			return true;
	return false;
}

PlayerLog* SimulationLog::itPlayerLogs(size_t index) {
	 if (index < lengthPlayerLogs)
		return &playerLogs[index];
	throw std::out_of_range("SimulationLog::itPlayerLogs() : tul indexeles");
}

SimulationLog::~SimulationLog() {
	delete[] matchLogs;
	delete[] playerLogs;
}

std::ostream& operator<<(std::ostream& os, GameLog& log) {
	os << log.playerOne->getName() << "\t\tnyert: " << log.playerOneWins << "\t\t"
		<< log.playerTwo->getName() << "\t\tnyert: " << log.playerTwoWins << "\t\tdontetlen: " << log.draws;
	return os;
}

std::ostream& operator<<(std::ostream& os, PlayerLog& log) {
	double winPercentage;
	if (log.gamesWon == 0)
		winPercentage = 0;
	else
		winPercentage = (double)log.gamesWon / log.allGamesPlayed * 100;

	os << log.player->getName() << "\t\tosszes: " << log.allGamesPlayed << "\t\tnyert: " << log.gamesWon << "\t\tdontetlen: "
		<< log.gamesDraw << "\t\tvesztett: " << log.allGamesPlayed - log.gamesDraw - log.gamesWon << "\t\tnyeresi arany: "
		<< std::fixed << std::setprecision(4) << winPercentage << " %";
	return os;
}
