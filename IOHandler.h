#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include "PlayerContainer.h"
#include "SimulationLog.h"

class IOHandler {
private:

	PlayerContainer& container;
	SimulationLog& log;

	/*
	 *	A függvény egy szöveget vár, ami lehetõleg egy eldöntendõ kérdés, amit kiír standard inputra.
	 *	y,Y vagy i,I-t igennek veszi és az n,N-t nemnek majd visszatér a felhasznál álltal a standard inputra adott válasz függvényében.
	 *
	 *	@param  - const char* -> Egyszeri használatra kell a kérdés, felesleges neki MyString objektumot létrehozni.
	 *	@return - bool -> igaz ha igent, hamis nemet adott be a felhasználó
	 */
	bool getFromUserYesOrNoQuestion(const char* question);

	/*
	 *	Vissza adja a PlayerContainer méretét, amit az ID-ja lesz a keletkezo objektumnak. A függvény szerepe az hogy egyértelmûbbé tegye mi is történik.
	 *	Helyette lehetne használni PlayerContainer.size()-t is, de így látszik hogy az a szám a keletkezp objektum ID-ja lesz és nem pedig ezen indexû helyre tesszük a tárolóban.
	 *
	 *	@param - nincs
	 *	@return - size_t -> PlayerContainer.size() típusa
	 */
	size_t getIdForPlayer();

public:
	IOHandler(PlayerContainer& newContainer, SimulationLog& newLog) : container(newContainer), log(newLog) {}

	/*
	 *	A felhasználó álltal a stantard inputra megadott számot adja vissza. -> GameSimulator.simulationNumber olvasása.
	 *
	 *	@param - nincs
	 *	@return - size_t -> GameSimulator.simulationNumber típusa
	 */
	size_t getFromUserSimulationNumber();

	void getFromUserRandomPlayer();
	void getFromUserStonePlayer();
	void getFromUserPaperPlayer();
	void getFromUserScissorsPlayer();
	void getFromUserSequancePlayer();
	void listMatchLogs();
	void listPlayerLogs();
	void listAllPlayers();
	~IOHandler() {}
};

#endif // !IO_HANDLER_H
