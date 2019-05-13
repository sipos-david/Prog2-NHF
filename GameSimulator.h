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
 *	Ez az oszt�ly a f�oszt�ly, a feladata a szimul�ci�k lefuttat�sa �s a k�l�nb�z� modulok �sz-szekapcsol�sa.
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
	*	A f�ggv�ny szimul�lja a simulationNumber-nyi j�t�kot, �s napl�za ez eredm�nyeket.
	*
	*	@param - 2 db j�t�kosra mutat� pointer, a heterog�n kollekci� miatt.
	*	@return - nincs
	*/
	void simulateMatches(Player* playerOne, Player* playerTwo);
	
	/**
	*
	*	A f�ggv�ny egy darab j�t�kot szimul�l, megh�vja a megfelel� virtu�lis f�ggv�nyeket.
	*
	*	@param - 2 db j�t�kosra mutat� pointer, a heterog�n kollekci� miatt.
	*	@return - A meccs kimenetel�vel visszat�r(GameResult enumriz�ci�).
	*/
	GameResult playGame(Player* playerOne, Player* playerTwo);

	/**
	*
	*	A f�ggv�ny megadja hogy egy l�p�s nyert-e a m�sikkal szemben.
	*
	*	@param - 2 db l�p�s(MoveType enumeriz�ci�).
	*	@return - Igazzal t�r vissza, ha a moveOne nyert, egy�bk�nt hamissal t�r vissza.
	*/
	bool moveWinsCheck(MoveType moveOne, MoveType moveTwo);

	/**
	*
	*	Ha a p�ld�ny tesztp�ld�ny akkor konstans, egy�bk�nt pseudo-random �rt�kkel t�r vissza.
	*
	*	@param - nincs
	*	@return - size_t 
	*/
	size_t getSeed();

	/**
	*
	*	Eld�nti hogy a k�t jat�kos j�tszott-e m�r egym�ssal, ha igen akkor nemmel t�r vissza ellenkez� esetben igazzal.
	*
	*	@param - 2 db j�t�kosra mutat� pointer, a heterog�n kollekci� miatt.
	*	@return - Igazzal t�r vissza, ha a k�t j�t�kos m�g nem j�tszott egym�ssal.
	*/
	bool notPlayedBefore(Player* playerOne, Player* playerTwo);

	/**
	 *	Fel�pti a PlayerLogokat, lehetne tenni a simulateMatches met�dusban is, de az a m�dszer t�bb konstruktor h�v�st eredm�nyezne, sok ellen�rz�st,
	 *	�gy �gy gondoltam el�ny�sebb lenne �gy, mivel mindenhol size_t a t�pus ez�rt nagyon nagy sz�mokn�l ez gyors�t a programon. 
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void buildPlayerLogs();

	/**
	*
	*	A f�ggv�ny visszat�r a megadott j�t�kos �sszes meccs�nek sz�m�val.
	*
	*	@param - Player*, a heterog�n kollekci� miatt.
	*	@return - size_t az �sszes j�t�k amit a player j�tszott.
	*/
	size_t getAllGamesPlayedSum(Player* player);

	/**
	*
	*	A f�ggv�ny visszat�r a megadott j�t�kos �sszes d�ntetlen meccs�nek sz�m�val.
	*
	*	@param - Player*, a heterog�n kollekci� miatt.
	*	@return - size_t az �sszes j�t�k amit a player j�tszott.
	*/
	size_t getAllGamesDraw(Player* player);

	/**
	*
	*	A f�ggv�ny visszat�r a megadott j�t�kos �sszes megnyert meccs�nek sz�m�val.
	*
	*	@param - Player*, a heterog�n kollekci� miatt.
	*	@return - size_t az �sszes j�t�k amit a player j�tszott.
	*/
	size_t getAllGamesWon(Player* player);
public:
	GameSimulator(bool testing = false) : players(),log(),interface(players,log),simulationNumber(0),testMode(testing) { std::srand(this->getSeed()); }

	/**
	 *	A felhaszn�l� stantard inputon megadott adatai alapj�n fel�p�ti a p�ld�nyt a kiv�nt szimul�ci�hoz.
	 *
	 *	@param - testing ha igaz, akkor a p�ld�ny tesztp�ld�ny vagyis az std::srand() fv h�v�sa a forr�sk�dba be�p�tett konstansal t�rt�nik, �gy lehet�s�g van a random j�t�kos tesztels�re is.
	 *	@return - nincs
	 */
	void getParameters();

	/**
	 *	Lefuttatja szimul�c�kat, �s log oszt�ly haszn�lat�val napl�zza azokat.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void simulation();


	/**
	 *	K��rja a standard inputra a szimul�ci�k eredm�nyeit az interface haszn�lat�val.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void displayResults();

	/**
	 *	A f�ggv�ny a tesztek�rt felel�s, ha a testMode hamis hiba �zenetet �r ki a standart kimenetre.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void test();

	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H
