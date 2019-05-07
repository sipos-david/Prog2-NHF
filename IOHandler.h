#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include "PlayerContainer.h"
#include "SimulationLog.h"

class IOHandler {
private:

	PlayerContainer& container;
	SimulationLog& log;

	/*
	 *	A f�ggv�ny egy sz�veget v�r, ami lehet�leg egy eld�ntend� k�rd�s, amit ki�r standard inputra.
	 *	y,Y vagy i,I-t igennek veszi �s az n,N-t nemnek majd visszat�r a felhaszn�l �lltal a standard inputra adott v�lasz f�ggv�ny�ben.
	 *
	 *	@param  - const char* -> Egyszeri haszn�latra kell a k�rd�s, felesleges neki MyString objektumot l�trehozni.
	 *	@return - bool -> igaz ha igent, hamis nemet adott be a felhaszn�l�
	 */
	bool getFromUserYesOrNoQuestion(const char* question);

	/*
	 *	Vissza adja a PlayerContainer m�ret�t, amit az ID-ja lesz a keletkezo objektumnak. A f�ggv�ny szerepe az hogy egy�rtelm�bb� tegye mi is t�rt�nik.
	 *	Helyette lehetne haszn�lni PlayerContainer.size()-t is, de �gy l�tszik hogy az a sz�m a keletkezp objektum ID-ja lesz �s nem pedig ezen index� helyre tessz�k a t�rol�ban.
	 *
	 *	@param - nincs
	 *	@return - size_t -> PlayerContainer.size() t�pusa
	 */
	size_t getIdForPlayer();

public:
	IOHandler(PlayerContainer& newContainer, SimulationLog& newLog) : container(newContainer), log(newLog) {}

	/*
	 *	A felhaszn�l� �lltal a stantard inputra megadott sz�mot adja vissza. -> GameSimulator.simulationNumber olvas�sa.
	 *
	 *	@param - nincs
	 *	@return - size_t -> GameSimulator.simulationNumber t�pusa
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
