#include "GameSimulator.h"

void GameSimulator::getParameters() {
	this->simulationNumber = interface.getFromUserSimulationNumber();
	interface.getFromUserStonePlayer();
	interface.getFromUserPaperPlayer();
	interface.getFromUserScissorsPlayer();
	interface.getFromUserSequancePlayer();
}

void GameSimulator::simulation()
{
}

void GameSimulator::displayResults() {
	interface.listPlayerLogs();
	interface.listAllPlayers();
}

void GameSimulator::simulateMatches(Player* playerOne, Player* Two)
{
}

void GameSimulator::playMatch(Player* playerOne, Player* Two)
{
}
