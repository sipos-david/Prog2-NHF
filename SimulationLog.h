#ifndef SIMULATION_LOG_H
#define SIMULATION_LOG_H

#include "Player.h"

struct GameLog {
	Player* playerOne;
	Player* playerTwo;
	size_t playerOneWins;
	size_t playerTwoWins;
	size_t draws;

	GameLog(Player* newPlayerOne = nullptr, Player* newPlayerTwo = nullptr) : playerOne(newPlayerOne), playerTwo(newPlayerTwo), playerOneWins(0), playerTwoWins(0), draws(0) {}
};

std::ostream& operator<<(std::ostream& os, GameLog& log);


struct PlayerLog {
	Player* player;
	size_t allGamesPlayed;
	size_t gamesWon;
	size_t gamesDraw;
	
	PlayerLog(Player* newPlayer = nullptr) : player(newPlayer), allGamesPlayed(0), gamesWon(0), gamesDraw(0) {}
	PlayerLog(PlayerLog& other) : player(other.player), allGamesPlayed(other.allGamesPlayed), gamesWon(other.gamesWon), gamesDraw(other.gamesDraw) {}
};

std::ostream& operator<<(std::ostream& os, PlayerLog& log);

class SimulationLog {
private:
	GameLog* matchLogs;
	PlayerLog* playerLogs;
	size_t lengthMatchLogs;
	size_t lengthPlayerLogs;
public:
	SimulationLog(GameLog* newMatchLogs = nullptr, PlayerLog* newPlayerLogs = nullptr, size_t defaultLength = 0) : matchLogs(newMatchLogs), playerLogs(newPlayerLogs), lengthMatchLogs(defaultLength), lengthPlayerLogs(defaultLength) {}
	void addMatchLog(GameLog* newGameLog);
	void addPlayerLog(Player* newPlayer);
	void resizeMatchLogs(size_t add);
	void resizePlayerLogs(size_t add);
	void initPlayerLogs(size_t playerNum);
	size_t matchLogsSize();
	size_t playerLogsSize();
	PlayerLog* searchPlayerLog(Player* playerSearched);
	GameLog& itMatchLogs(size_t index);
	bool foundMatchLogs(Player* playerOne, Player* playerTwo);
	PlayerLog* itPlayerLogs(size_t index);
	~SimulationLog();
};

#endif // !SIMULATION_LOG_H
