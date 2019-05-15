#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include "PlayerContainer.h"
#include "SimulationLog.h"

/**
 *	Ez az osztály felelõs a program és ember kommunikációjának lebonyolításáért.
 *
 *	Például a getFromUser… függvények bekérik a felhasználótól a megfelelõ adatot,
 *	majd ezt felhasználva a PlayerContainer felépíti a heterogén kollekciót.
 *
 *	A listMatchLogs() és a listPlayerLogs() kiírja a konzolba a játékosok és a meccsek eredmé-nyeit.
 */
class IOHandler {
private:

	PlayerContainer& container;
	SimulationLog& log;

	/**
	 *	A függvény egy szöveget vár, ami lehetõleg egy eldöntendõ kérdés, amit kiír standard inputra.
	 *	y,Y vagy i,I-t igennek veszi és az n,N-t nemnek majd visszatér a felhasznál álltal a standard inputra adott válasz függvényében.
	 *
	 *	@param  - const char* -> Egyszeri használatra kell a kérdés, felesleges neki MyString objektumot létrehozni.
	 *	@return - bool -> igaz ha igent, hamis nemet adott be a felhasználó
	 */
	bool getFromUserYesOrNoQuestion(const char* question);

	/**
	 *	Vissza adja a PlayerContainer méretét, amit az ID-ja lesz a keletkezo objektumnak. A függvény szerepe az hogy egyértelmûbbé tegye mi is történik.
	 *	Helyette lehetne használni PlayerContainer.size()-t is, de így látszik hogy az a szám a keletkezp objektum ID-ja lesz és nem pedig ezen indexû helyre tesszük a tárolóban.
	 *
	 *	@param - nincs
	 *	@return - size_t -> PlayerContainer.size() típusa
	 */
	size_t getIdForPlayer();

public:
	IOHandler(PlayerContainer& newContainer, SimulationLog& newLog) : container(newContainer), log(newLog) {}

	/**
	 *	A felhasználó álltal a stantard inputra megadott számot adja vissza. -> GameSimulator.simulationNumber olvasása.
	 *
	 *	@param - nincs
	 *	@return - size_t -> GameSimulator.simulationNumber típusa
	 */
	size_t getFromUserSimulationNumber();

	/**
	 *	A felhasználótol a stantard inputra bekeri, hogy legyen-e random játékos a szimulációban. Ha igen hozza adja a heterogén kollekcióhoz az új játékost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserRandomPlayer();

	/**
	 *	A felhasználótol a stantard inputra bekeri, hogy legyen-e kõ játékos a szimulációban. Ha igen hozza adja a heterogén kollekcióhoz az új játékost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserStonePlayer();

	/**
	 *	A felhasználótol a stantard inputra bekeri, hogy legyen-e papír játékos a szimulációban. Ha igen hozza adja a heterogén kollekcióhoz az új játékost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserPaperPlayer();

	/**
	 *	A felhasználótol a stantard inputra bekeri, hogy legyen-e olló játékos a szimulációban. Ha igen hozza adja a heterogén kollekcióhoz az új játékost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserScissorsPlayer();

	/**
	 *	A felhasználótol a stantard inputra bekeri, hogy legyen-e szekvencia játékos a szimulációban. Ha igen hozza adja a heterogén kollekcióhoz az új játékost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserSequancePlayer();

	/**
	 *	A standard inputra kilistázza a szimulácó meccseinek eredményeit.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void listMatchLogs();

	/**
	 *	A standard inputra kilistázza a szimulácó játékosainak eredményeit.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void listPlayerLogs();

	/**
	 *	A standard inputra kilistázza a szimulácó játékosait.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void listAllPlayers();

	~IOHandler() {}
};

#endif // !IO_HANDLER_H
