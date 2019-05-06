#ifndef GAME_SIMULATOR_H
#define GAME_SIMULATOR_H

#include "PlayerContainer.h"
#include "SimulationLog.h"
#include "IOHandler.h"


class GameSimulator {
private:
	PlayerContainer players;
	SimulationLog log;
	IOHandler inteface;
	size_t simulationNumber;
public:
	GameSimulator() : simulationNumber(0) {}
	void simulation();
	void simulateMatches(Player* playerOne, Player* Two);
	void initPlayersFromUser();
	void playMatch(Player* playerOne, Player* Two);
	~GameSimulator() {}
};

#endif // !GAME_SIMULATOR_H