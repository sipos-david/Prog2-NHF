#ifndef GAME_SIMULATOR_H
#define GAME_SIMULATOR_H

#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <ctime>

#include "PlayerContainer.h"
#include "SimulationLog.h"
#include "IOHandler.h"


/**
 *	Ez az osztály a fõosztály, a feladata a szimulációk lefuttatása és a különbözõ modulok ösz-szekapcsolása.
 */
class GameSimulator {
private:
	PlayerContainer players;
	SimulationLog log;
	IOHandler interface;
	size_t simulationNumber;
	bool testMode;

	/**
	*
	*	A függvény szimulálja a simulationNumber-nyi játékot, és naplóza ez eredményeket.
	*
	*	@param - 2 db játékosra mutató pointer, a heterogén kollekció miatt.
	*	@return - nincs
	*/
	void simulateMatches(Player* playerOne, Player* playerTwo);
	
	/**
	*
	*	A függvény egy darab játékot szimulál, meghívja a megfelelõ virtuális függvényeket.
	*
	*	@param - 2 db játékosra mutató pointer, a heterogén kollekció miatt.
	*	@return - A meccs kimenetelével visszatér(GameResult enumrizáció).
	*/
	GameResult playGame(Player* playerOne, Player* playerTwo);

	/**
	*
	*	A függvény megadja hogy egy lépés nyert-e a másikkal szemben.
	*
	*	@param - 2 db lépés(MoveType enumerizáció).
	*	@return - Igazzal tér vissza, ha a moveOne nyert, egyébként hamissal tér vissza.
	*/
	bool moveWinsCheck(MoveType moveOne, MoveType moveTwo);

	/**
	*
	*	Ha a példány tesztpéldány akkor konstans, egyébként pseudo-random értékkel tér vissza.
	*
	*	@param - nincs
	*	@return - size_t 
	*/
	size_t getSeed();

	/**
	*
	*	Eldönti hogy a két jatékos játszott-e már egymással, ha igen akkor nemmel tér vissza ellenkezõ esetben igazzal.
	*
	*	@param - 2 db játékosra mutató pointer, a heterogén kollekció miatt.
	*	@return - Igazzal tér vissza, ha a két játékos még nem játszott egymással.
	*/
	bool notPlayedBefore(Player* playerOne, Player* playerTwo);

	/**
	 *	Felépti a PlayerLogokat, lehetne tenni a simulateMatches metódusban is, de az a módszer több konstruktor hívást eredményezne, sok ellenõrzést,
	 *	így úgy gondoltam elõnyösebb lenne így, mivel mindenhol size_t a típus ezért nagyon nagy számoknál ez gyorsít a programon. 
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void buildPlayerLogs();

	/**
	*
	*	A függvény visszatér a megadott játékos összes meccsének számával.
	*
	*	@param - Player*, a heterogén kollekció miatt.
	*	@return - size_t az összes játék amit a player játszott.
	*/
	size_t getAllGamesPlayedSum(Player* player);

	/**
	*
	*	A függvény visszatér a megadott játékos összes döntetlen meccsének számával.
	*
	*	@param - Player*, a heterogén kollekció miatt.
	*	@return - size_t az összes játék amit a player játszott.
	*/
	size_t getAllGamesDraw(Player* player);

	/**
	*
	*	A függvény visszatér a megadott játékos összes megnyert meccsének számával.
	*
	*	@param - Player*, a heterogén kollekció miatt.
	*	@return - size_t az összes játék amit a player játszott.
	*/
	size_t getAllGamesWon(Player* player);
public:
	GameSimulator(bool testing = false) : players(),log(),interface(players,log),simulationNumber(0),testMode(testing) { std::srand(this->getSeed()); }

	/**
	 *	A felhasználó stantard inputon megadott adatai alapján felépíti a példányt a kivánt szimulációhoz.
	 *
	 *	@param - testing ha igaz, akkor a példány tesztpéldány vagyis az std::srand() fv hívása a forráskódba beépített konstansal történik, így lehetõség van a random játékos tesztelsére is.
	 *	@return - nincs
	 */
	void getParameters();

	/**
	 *	Lefuttatja szimulácókat, és log osztály használatával naplózza azokat.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void simulation();


	/**
	 *	Kíírja a standard inputra a szimulációk eredményeit az interface használatával.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void displayResults();

	/**
	 *	A függvény a tesztekért felelõs, ha a testMode hamis hiba üzenetet ír ki a standart kimenetre.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void test();

	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H
