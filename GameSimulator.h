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
	GameSimulator() : simulationNumber(0) {}

	/*
	 *	A felhasználó stantard inputon megadott adatai alapján felépíti a példányt a kivánt szimulációhoz.
	 *	@param - nincs
	 *	@return -nincs
	 */
	void getParameters();

	void simulation();
	void displayResults();
	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H