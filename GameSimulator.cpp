#include "GameSimulator.h"

void GameSimulator::getParameters() {
	if (testMode)
		std::cout << "Tesztmod: ON" << std::endl;
	this->simulationNumber = interface.getFromUserSimulationNumber();
	interface.getFromUserStonePlayer();
	interface.getFromUserPaperPlayer();
	interface.getFromUserScissorsPlayer();
	interface.getFromUserRandomPlayer();
	interface.getFromUserSequancePlayer();
}

void GameSimulator::simulation() {
	for (size_t i = 0; i < players.size(); i++)
		for (size_t j = 0; j < players.size(); j++)
			if (i != j && notPlayedBefore(&(players[i]), &(players[j])))
				simulateMatches(&(players[i]), &(players[j]));
	log.initPlayerLogs(players.size());
	buildPlayerLogs();
}

void GameSimulator::displayResults() {
	interface.listAllPlayers();
	interface.listPlayerLogs();
	interface.listMatchLogs();
}

void GameSimulator::test() { 
	if (!testMode) {
		std::cout << " Tesztmod: ERROR: nem tesztpeldany" << std::endl;
		return;
	}
}

void GameSimulator::simulateMatches(Player* playerOne, Player* playerTwo) {
	playerOne->init();
	playerTwo->init();

	GameLog* currentGameLog = new GameLog(playerOne, playerTwo);

	for (size_t i = 0; i < simulationNumber; i++) {
		GameResult currentResult = playGame(playerOne, playerTwo);

		switch (currentResult) {
		case draw:
			currentGameLog->draws += 1;
			break;
		case playerOneWins:
			currentGameLog->playerOneWins += 1;
			break;
		case playerTwoWins:
			currentGameLog->playerTwoWins += 1;
			break;
		}
	}

	log.addMatchLog(currentGameLog);

}

GameResult GameSimulator::playGame(Player* playerOne, Player* playerTwo) {
	MoveType playerOneMove = playerOne->move();
	MoveType playerTwoMove = playerTwo->move();

	if (playerOneMove == playerTwoMove)
		return draw;

	if (moveWinsCheck(playerOneMove, playerTwoMove))
		return playerOneWins;
	else
		return playerTwoWins;
}

bool GameSimulator::moveWinsCheck(MoveType moveOne, MoveType moveTwo) {
	if (moveOne == stone && moveTwo == scissors)
		return true;
	else if (moveOne == paper && moveTwo == stone)
		return true;
	else if (moveOne == scissors && moveTwo == paper)
		return true;
	else
		return false;
}

size_t GameSimulator::getSeed() {
	if (testMode)
		return 10;
	else
		return std::time(nullptr);
}

bool GameSimulator::notPlayedBefore(Player* playerOne, Player* playerTwo)
{
	for (size_t i = 0; i < log.matchLogsSize();i++) {
		if (log.foundMatchLogs(playerOne,playerTwo) || log.foundMatchLogs(playerTwo, playerOne))
			return false;
	}
	return true;
}

void GameSimulator::buildPlayerLogs() {
	for (size_t i = 0; i < log.playerLogsSize(); i++) {
		log.itPlayerLogs(i)->player = &players[i];
		log.itPlayerLogs(i)->allGamesPlayed = getAllGamesPlayedSum(&players[i]);
		log.itPlayerLogs(i)->gamesDraw = getAllGamesDraw(&players[i]);
		log.itPlayerLogs(i)->gamesWon = getAllGamesWon(&players[i]);
	}
}

size_t GameSimulator::getAllGamesPlayedSum(Player* player) {
	size_t tmp = 0;
	for (size_t i = 0; i < log.matchLogsSize(); i++) {
		if (log.itMatchLogs(i).playerOne->getId() == player->getId() || log.itMatchLogs(i).playerTwo->getId() == player->getId())
			tmp += (log.itMatchLogs(i).draws + log.itMatchLogs(i).playerOneWins + log.itMatchLogs(i).playerTwoWins);
	}
	return tmp;
}

size_t GameSimulator::getAllGamesDraw(Player* player) {
	size_t tmp = 0;
	for (size_t i = 0; i < log.matchLogsSize(); i++) {
		if (log.itMatchLogs(i).playerOne->getId() == player->getId() || log.itMatchLogs(i).playerTwo->getId() == player->getId())
			tmp += log.itMatchLogs(i).draws;
	}
	return tmp;
}

size_t GameSimulator::getAllGamesWon(Player* player) {
	size_t tmp = 0;
	for (size_t i = 0; i < log.matchLogsSize(); i++) {
		if (log.itMatchLogs(i).playerOne->getId() == player->getId())
			tmp += log.itMatchLogs(i).playerOneWins;
		else if (log.itMatchLogs(i).playerTwo->getId() == player->getId())
			tmp += log.itMatchLogs(i).playerTwoWins;
	}
	return tmp;
}
