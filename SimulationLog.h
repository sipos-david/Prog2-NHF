#ifndef SIMULATION_LOG_H
#define SIMULATION_LOG_H

#include "Player.h"

/**
 *	Egy meccssorozat eredm�nyei t�rolja. A k�t egym�s ellen �ll� j�t�kost �s a nyer�s�k �s a d�ntetlenek sz�m�t.
 *	Az �sszes meccs sz�ma ezekb�l m�r k�nnyen kisz�m�that�, ez�rt nem kell t�rolni azt, hiszen csak �ssze kell adni �ket,
 *	�s ez megadja a pontos eredm�ny, mivel egy meccsnek csak pontosan ez a 3 kimenetele lehet.
 */
struct GameLog {
	Player* playerOne;
	Player* playerTwo;
	size_t playerOneWins;
	size_t playerTwoWins;
	size_t draws;

	GameLog(Player* newPlayerOne = nullptr, Player* newPlayerTwo = nullptr) : playerOne(newPlayerOne), playerTwo(newPlayerTwo), playerOneWins(0), playerTwoWins(0), draws(0) {}
};

std::ostream& operator<<(std::ostream& os, GameLog& log);

/**
 *	Egy j�t�kos �sszes�tett adatait tartalmazza. A j�t�kosra mutat� pointer t�rolja. 
 *	Ennek az eredm�nynek a t�rol�sa a PlayerBase oszt�lyon bel�l is megval�sulhatott volna, 
 *	de �gy gondoltam, hogy a PlayerBase oszt�lynak �s lesz�rmazottjainak nem kell sz�montartania, 
 *	az eredm�nyeit, csak az aktu�lis l�pessel kell foglalkoznia.
 */
struct PlayerLog {
	Player* player;
	size_t allGamesPlayed;
	size_t gamesWon;
	size_t gamesDraw;
	
	PlayerLog(Player* newPlayer = nullptr) : player(newPlayer), allGamesPlayed(0), gamesWon(0), gamesDraw(0) {}
};

std::ostream& operator<<(std::ostream& os, PlayerLog& log);

/**
 *	Ez az oszt�ly felel a napl�z�s�rt. A mentett adatokhoz hozz�adja a megfelel� eredm�nyeket �s a j�tszm�k ut�n m�dos�tja azokat.
 *	P�ld�ul az egy j�t�koshoz tartoz� PlayerLog-ot friss�ti a meccsek eredm�nyeivel.
 */
class SimulationLog {
private:
	GameLog* matchLogs;
	PlayerLog* playerLogs;
	size_t lengthMatchLogs;
	size_t lengthPlayerLogs;

public:
	SimulationLog(GameLog* newMatchLogs = nullptr, PlayerLog* newPlayerLogs = nullptr, size_t defaultLength = 0) : matchLogs(newMatchLogs), playerLogs(newPlayerLogs), lengthMatchLogs(defaultLength), lengthPlayerLogs(defaultLength) {}
	
	/**
	 *	A kapott GameLog-ot elt�rolja.
	 *
	 *	@param - GameLog*, az napl� a meccsr�l amit el kell t�rolni
	 *	@return - nincs
	 */
	void addMatchLog(GameLog* newGameLog);

	/**
	 *	A kapott j�t�kos alapj�n k�sz�t egy PlayerLog-ot �s elt�rolja azt.
	 *
	 *	@param - Player*, a heterog�n kollekci� miatt pointer.
	 *	@return - nincs
	 */
	void addPlayerLog(Player* newPlayer);

	/**
	 *	�jram�retezi a matchLogs-ot.
	 *
	 *	@param - size_t add, ennyi �j helyet hoz l�tre.
	 *	@return - nincs
	 */
	void resizeMatchLogs(size_t add);

	/**
	 *	�jram�retezi a playerLogs-ot.
	 *
	 *	@param - size_t add, ennyi �j helyet hoz l�tre.
	 *	@return - nincs
	 */
	void resizePlayerLogs(size_t add);

	/**
	 *	A k�v�nt m�rt�tre inicializ�lja a playerLogs-ot, a resizePlayerLogs() f�ggv�ny seg�ts�g�vel.
	 *	Lehet n�lk�le is, de ennek a f�ggv�nynek szerepe a k�d olvashat�bb� t�tele.
	 *
	 *	@param - size_t playerNum, ennyi hely lesz a t�rol�ban.
	 *	@return - nincs
	 */
	void initPlayerLogs(size_t playerNum);

	/**
	 *	Visszaadja a matchLogs t�mb m�ret�t.
	 *
	 *	@param - size_t, ez lengthMatchLogs t�pusa.
	 *	@return - nincs
	 */
	size_t matchLogsSize();

	/**
	 *	Visszaadja a playerLogs t�mb m�ret�t.
	 *
	 *	@param - size_t, ez lengthPlayerLogs t�pusa.
	 *	@return - nincs
	 */
	size_t playerLogsSize();

	/**
	 *	Visszaadja a playerLogs t�mb m�ret�t.
	 *
	 *	@param - size_t, ez lengthPlayerLogs t�pusa.
	 *	@return - nincs
	 */
	PlayerLog* searchPlayerLog(Player* playerSearched);

	/**
	 *	Visszat�r a matchLogs t�mb index-edik elem�renek referenci�j�val.
	 *
	 *	@param - size_t, index
	 *	@return - nincs
	 */
	GameLog& itMatchLogs(size_t index);

	/**
	 *	Visszat�r igazzal ha m�r van a bemenetnek megfelel� MatchLog t�rolva.
	 *
	 *	@param - 2 db j�t�kosra mutat� pointer
	 *	@return - igaz, ha megtal�lta a megfelel� MatchLog-ot.
	 */
	bool foundMatchLogs(Player* playerOne, Player* playerTwo);
	
	/**
	 *	Visszat�r a palyerLogs t�mb index-edik elem�re mutat� pointerrel.
	 *
	 *	@param - size_t, index
	 *	@return - nincs
	 */
	PlayerLog* itPlayerLogs(size_t index);

	~SimulationLog();
};

#endif // !SIMULATION_LOG_H
