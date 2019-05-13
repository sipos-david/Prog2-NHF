#ifndef SIMULATION_LOG_H
#define SIMULATION_LOG_H

#include "Player.h"

/**
 *	Egy meccssorozat eredményei tárolja. A két egymás ellen álló játékost és a nyerésük és a döntetlenek számát.
 *	Az összes meccs száma ezekbõl már könnyen kiszámítható, ezért nem kell tárolni azt, hiszen csak össze kell adni õket,
 *	és ez megadja a pontos eredmény, mivel egy meccsnek csak pontosan ez a 3 kimenetele lehet.
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
 *	Egy játékos összesített adatait tartalmazza. A játékosra mutató pointer tárolja. 
 *	Ennek az eredménynek a tárolása a PlayerBase osztályon belül is megvalósulhatott volna, 
 *	de úgy gondoltam, hogy a PlayerBase osztálynak és leszármazottjainak nem kell számontartania, 
 *	az eredményeit, csak az aktuális lépessel kell foglalkoznia.
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
 *	Ez az osztály felel a naplózásért. A mentett adatokhoz hozzáadja a megfelelõ eredményeket és a játszmák után módosítja azokat.
 *	Például az egy játékoshoz tartozó PlayerLog-ot frissíti a meccsek eredményeivel.
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
	 *	A kapott GameLog-ot eltárolja.
	 *
	 *	@param - GameLog*, az napló a meccsrõl amit el kell tárolni
	 *	@return - nincs
	 */
	void addMatchLog(GameLog* newGameLog);

	/**
	 *	A kapott játékos alapján készít egy PlayerLog-ot és eltárolja azt.
	 *
	 *	@param - Player*, a heterogén kollekció miatt pointer.
	 *	@return - nincs
	 */
	void addPlayerLog(Player* newPlayer);

	/**
	 *	Újraméretezi a matchLogs-ot.
	 *
	 *	@param - size_t add, ennyi új helyet hoz létre.
	 *	@return - nincs
	 */
	void resizeMatchLogs(size_t add);

	/**
	 *	Újraméretezi a playerLogs-ot.
	 *
	 *	@param - size_t add, ennyi új helyet hoz létre.
	 *	@return - nincs
	 */
	void resizePlayerLogs(size_t add);

	/**
	 *	A kívánt mértétre inicializálja a playerLogs-ot, a resizePlayerLogs() függvény segítségével.
	 *	Lehet nélküle is, de ennek a függvénynek szerepe a kód olvashatóbbá tétele.
	 *
	 *	@param - size_t playerNum, ennyi hely lesz a tárolóban.
	 *	@return - nincs
	 */
	void initPlayerLogs(size_t playerNum);

	/**
	 *	Visszaadja a matchLogs tömb méretét.
	 *
	 *	@param - size_t, ez lengthMatchLogs típusa.
	 *	@return - nincs
	 */
	size_t matchLogsSize();

	/**
	 *	Visszaadja a playerLogs tömb méretét.
	 *
	 *	@param - size_t, ez lengthPlayerLogs típusa.
	 *	@return - nincs
	 */
	size_t playerLogsSize();

	/**
	 *	Visszaadja a playerLogs tömb méretét.
	 *
	 *	@param - size_t, ez lengthPlayerLogs típusa.
	 *	@return - nincs
	 */
	PlayerLog* searchPlayerLog(Player* playerSearched);

	/**
	 *	Visszatér a matchLogs tömb index-edik elemérenek referenciájával.
	 *
	 *	@param - size_t, index
	 *	@return - nincs
	 */
	GameLog& itMatchLogs(size_t index);

	/**
	 *	Visszatér igazzal ha már van a bemenetnek megfelelõ MatchLog tárolva.
	 *
	 *	@param - 2 db játékosra mutató pointer
	 *	@return - igaz, ha megtalálta a megfelelõ MatchLog-ot.
	 */
	bool foundMatchLogs(Player* playerOne, Player* playerTwo);
	
	/**
	 *	Visszatér a palyerLogs tömb index-edik elemére mutató pointerrel.
	 *
	 *	@param - size_t, index
	 *	@return - nincs
	 */
	PlayerLog* itPlayerLogs(size_t index);

	~SimulationLog();
};

#endif // !SIMULATION_LOG_H
