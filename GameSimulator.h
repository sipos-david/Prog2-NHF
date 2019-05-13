#ifndef GAME_SIMULATOR_H
#define GAME_SIMULATOR_H

#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <ctime>

#include "PlayerContainer.h"
#include "SimulationLog.h"
#include "IOHandler.h"

class GameSimulator {
private:
	PlayerContainer players;
	SimulationLog log;
	IOHandler interface;
	size_t simulationNumber;
	bool testMode;

	void simulateMatches(Player* playerOne, Player* playerTwo);
	GameResult playGame(Player* playerOne, Player* playerTwo);
	bool moveWinsCheck(MoveType moveOne, MoveType moveTwo);
	size_t getSeed();
	bool notPlayedBefore(Player* playerOne, Player* playerTwo);
	void buildPlayerLogs();
	size_t getAllGamesPlayedSum(Player* player);
	size_t getAllGamesDraw(Player* player);
	size_t getAllGamesWon(Player* player);
public:
	GameSimulator(bool testing = false) : players(),log(),interface(players,log),simulationNumber(0),testMode(testing) { std::srand(this->getSeed()); }

	/**
	 *	A felhaszn�l� stantard inputon megadott adatai alapj�n fel�p�ti a p�ld�nyt a kiv�nt szimul�ci�hoz.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void getParameters();

	/**
	 *	Lefuttatja szimul�c�kat, �s log oszt�ly haszn�lat�val napl�zza azokat.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void simulation();


	/**
	 *	K��rja a standard inputra a szimul�ci�k eredm�nyeit az interface haszn�lat�val.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void displayResults();

	void test();

	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H
