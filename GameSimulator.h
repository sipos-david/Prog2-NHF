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
	 *	A felhasználó stantard inputon megadott adatai alapján felépíti a példányt a kivánt szimulációhoz.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void getParameters();

	/**
	 *	Lefuttatja szimulácókat, és log osztály használatával naplózza azokat.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void simulation();


	/**
	 *	Kíírja a standard inputra a szimulációk eredményeit az interface használatával.
	 *
	 *	@param - nincs
	 *	@return -nincs
	 */
	void displayResults();

	void test();

	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H
