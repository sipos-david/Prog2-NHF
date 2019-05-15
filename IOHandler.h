#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include "PlayerContainer.h"
#include "SimulationLog.h"

/**
 *	Ez az oszt�ly felel�s a program �s ember kommunik�ci�j�nak lebonyol�t�s��rt.
 *
 *	P�ld�ul a getFromUser� f�ggv�nyek bek�rik a felhaszn�l�t�l a megfelel� adatot,
 *	majd ezt felhaszn�lva a PlayerContainer fel�p�ti a heterog�n kollekci�t.
 *
 *	A listMatchLogs() �s a listPlayerLogs() ki�rja a konzolba a j�t�kosok �s a meccsek eredm�-nyeit.
 */
class IOHandler {
private:

	PlayerContainer& container;
	SimulationLog& log;

	/**
	 *	A f�ggv�ny egy sz�veget v�r, ami lehet�leg egy eld�ntend� k�rd�s, amit ki�r standard inputra.
	 *	y,Y vagy i,I-t igennek veszi �s az n,N-t nemnek majd visszat�r a felhaszn�l �lltal a standard inputra adott v�lasz f�ggv�ny�ben.
	 *
	 *	@param  - const char* -> Egyszeri haszn�latra kell a k�rd�s, felesleges neki MyString objektumot l�trehozni.
	 *	@return - bool -> igaz ha igent, hamis nemet adott be a felhaszn�l�
	 */
	bool getFromUserYesOrNoQuestion(const char* question);

	/**
	 *	Vissza adja a PlayerContainer m�ret�t, amit az ID-ja lesz a keletkezo objektumnak. A f�ggv�ny szerepe az hogy egy�rtelm�bb� tegye mi is t�rt�nik.
	 *	Helyette lehetne haszn�lni PlayerContainer.size()-t is, de �gy l�tszik hogy az a sz�m a keletkezp objektum ID-ja lesz �s nem pedig ezen index� helyre tessz�k a t�rol�ban.
	 *
	 *	@param - nincs
	 *	@return - size_t -> PlayerContainer.size() t�pusa
	 */
	size_t getIdForPlayer();

public:
	IOHandler(PlayerContainer& newContainer, SimulationLog& newLog) : container(newContainer), log(newLog) {}

	/**
	 *	A felhaszn�l� �lltal a stantard inputra megadott sz�mot adja vissza. -> GameSimulator.simulationNumber olvas�sa.
	 *
	 *	@param - nincs
	 *	@return - size_t -> GameSimulator.simulationNumber t�pusa
	 */
	size_t getFromUserSimulationNumber();

	/**
	 *	A felhaszn�l�tol a stantard inputra bekeri, hogy legyen-e random j�t�kos a szimul�ci�ban. Ha igen hozza adja a heterog�n kollekci�hoz az �j j�t�kost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserRandomPlayer();

	/**
	 *	A felhaszn�l�tol a stantard inputra bekeri, hogy legyen-e k� j�t�kos a szimul�ci�ban. Ha igen hozza adja a heterog�n kollekci�hoz az �j j�t�kost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserStonePlayer();

	/**
	 *	A felhaszn�l�tol a stantard inputra bekeri, hogy legyen-e pap�r j�t�kos a szimul�ci�ban. Ha igen hozza adja a heterog�n kollekci�hoz az �j j�t�kost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserPaperPlayer();

	/**
	 *	A felhaszn�l�tol a stantard inputra bekeri, hogy legyen-e oll� j�t�kos a szimul�ci�ban. Ha igen hozza adja a heterog�n kollekci�hoz az �j j�t�kost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserScissorsPlayer();

	/**
	 *	A felhaszn�l�tol a stantard inputra bekeri, hogy legyen-e szekvencia j�t�kos a szimul�ci�ban. Ha igen hozza adja a heterog�n kollekci�hoz az �j j�t�kost.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void getFromUserSequancePlayer();

	/**
	 *	A standard inputra kilist�zza a szimul�c� meccseinek eredm�nyeit.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void listMatchLogs();

	/**
	 *	A standard inputra kilist�zza a szimul�c� j�t�kosainak eredm�nyeit.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void listPlayerLogs();

	/**
	 *	A standard inputra kilist�zza a szimul�c� j�t�kosait.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void listAllPlayers();

	~IOHandler() {}
};

#endif // !IO_HANDLER_H
