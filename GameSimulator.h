#ifndef GAME_SIMULATOR_H
#define GAME_SIMULATOR_H

#include "PlayerContainer.h"
#include "SimulationLog.h"
#include "IOHandler.h"


class GameSimulator {
private:
	PlayerContainer players;
	SimulationLog log;
	IOHandler interface;
	size_t simulationNumber;

	void simulateMatches(Player* playerOne, Player* Two);
	void initPlayersFromUser();
	void playMatch(Player* playerOne, Player* Two);

public:
	GameSimulator() : simulationNumber(0), interface(players,log) {}

	/*
	 *	Elõkészíti a példányosított objektumot a szimulációk leutátásra.
	 *	@param - nincs
	 *	@return - void
	 */
	void getParameters();

	void simulation();
	void displayResults();
	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H