#ifndef GAME_SIMULATOR_H
#define GAME_SIMULATOR_H

#include "PlayerContainer.h"
#include "SimulationLog.h"
#include "IOHandler.h"
#include "memtrace.h"


class GameSimulator {
private:
	PlayerContainer players;
	SimulationLog log;
	IOHandler interface;
	size_t simulationNumber;

	void simulateMatches(Player* playerOne, Player* Two);
	void playMatch(Player* playerOne, Player* Two);

public:
	GameSimulator() : simulationNumber(0),interface(players,log) {}

	/*
	 *	A felhasználó stantard inputon megadott adatai alapján felépíti a példányt a kivánt szimulációhoz.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void getParameters();

	/*
	 *	Lefuttatja szimulácókat, és log osztály használatával naplózza azokat.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void simulation();


	/*
	 *	Kíírja a standard inputra a szimulációk eredményeit az interface használatával.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void displayResults();

	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H