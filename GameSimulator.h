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
	 *	A felhaszn�l� stantard inputon megadott adatai alapj�n fel�p�ti a p�ld�nyt a kiv�nt szimul�ci�hoz.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void getParameters();

	/*
	 *	Lefuttatja szimul�c�kat, �s log oszt�ly haszn�lat�val napl�zza azokat.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void simulation();


	/*
	 *	K��rja a standard inputra a szimul�ci�k eredm�nyeit az interface haszn�lat�val.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void displayResults();

	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H