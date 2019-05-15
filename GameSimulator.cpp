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

	int sikeres = 0, osszes = 5;
	std::cout << "----- Kritikus fuggvenyek tesztelese -----" << std::endl;

	std::cout << "--- TEST 01 ---" << std::endl;
	bool testCheck = moveWinsCheck(stone,paper);

	if (!testCheck) {
		sikeres++;
		std::cout << "--- TEST 01 : SIKERES ---" << std::endl;
	}
	else {
		std::cout << "--- TEST 01 : HIBAS ---" << std::endl;
	}

	std::cout << "--- TEST 02 ---" << std::endl;
	testCheck = moveWinsCheck(paper, scissors);

	if (!testCheck) {
		sikeres++;
		std::cout << "--- TEST 02 : SIKERES ---" << std::endl;
	}
	else {
		std::cout << "--- TEST 02 : HIBAS ---" << std::endl;
	}

	Player* dummy1 = new Player(new ScissorsPlayer(0, "dummy1"));
	Player* dummy2 = new Player(new PaperPlayer(1, "dummy2"));
	std::cout << "--- TEST 03 ---" << std::endl;
	GameResult gameResCheck = playGame(dummy1, dummy2);

	if (gameResCheck == playerOneWins) {
		sikeres++;
		std::cout << "--- TEST 03 : SIKERES ---" << std::endl;
	}
	else {
		std::cout << "--- TEST 03 : HIBAS ---" << std::endl;
	}
	delete dummy1;
	delete dummy2;

	dummy1 = new Player(new StonePlayer(0, "dummy1"));
	dummy2 = new Player(new PaperPlayer(1, "dummy2"));
	std::cout << "--- TEST 04 ---" << std::endl;
	gameResCheck = playGame(dummy1, dummy2);

	if (gameResCheck == playerTwoWins) {
		sikeres++;
		std::cout << "--- TEST 04 : SIKERES ---" << std::endl;
	}
	else {
		std::cout << "--- TEST 04 : HIBAS ---" << std::endl;
	}
	delete dummy1;
	delete dummy2;

	dummy1 = new Player(new ScissorsPlayer(0, "dummy1"));
	 dummy2 = new Player(new ScissorsPlayer(1, "dummy2"));
	std::cout << "--- TEST 05 ---" << std::endl;
	gameResCheck = playGame(dummy1, dummy2);

	if (gameResCheck == draw) {
		sikeres++;
		std::cout << "--- TEST 05 : SIKERES ---" << std::endl;
	}
	else {
		std::cout << "--- TEST 05 : HIBAS ---" << std::endl;
	}
	delete dummy1;
	delete dummy2;

	std::cout << "------ " << sikeres << "/" << osszes<< " -----" << std::endl;

	switch (sikeres)
	{
		case 0:
			std::cout << "----- Nagyon baj ban -----" << std::endl;
			break;
		case 1:
			std::cout << "----- :,( -----" << std::endl;
			break;
		case 2:
			std::cout << "----- Elegseges -----" << std::endl;
			break;
		case 3:
			std::cout << "----- ??? -----" << std::endl;
			break;
		case 4:
			std::cout << "----- Talan -----" << std::endl;
			break;
		case 5:
			std::cout << "----- Szuper -----" << std::endl;
			break;
		default:
			break;
	}

	std::cout << "----- Teszteles vege -----" << std::endl;
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
