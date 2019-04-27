#ifndef SIMULATION_LOG_H
#define SIMULATION_LOG_H

#include "Player.h"

struct GameLog {
	Player* playerOne;
	Player* playerTwo;
	size_t playerOneWins;
	size_t playerTwoWins;
	size_t draws;
};

struct PlayerLog {
	Player* player;
	size_t allGamesPlayed;
	size_t gamesWon;
	size_t gamesDraw;
};

class SimulationLog {
private:
	GameLog* matchlogs;
	PlayerLog* playerLogs;
	size_t length;
public:
	SimulationLog(GameLog* newMatchLogs = nullptr, PlayerLog* newPlayerLogs = nullptr, size_t defaultLength = 0) : matchlogs(newMatchLogs), playerLogs(newPlayerLogs), length(defaultLength) {}
	void addGameLog();
	void addPlayerLog();
	~SimulationLog();
};

#endif // !SIMULATION_LOG_H
