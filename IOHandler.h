#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include "PlayerContainer.h"
#include "SimulationLog.h"

class IOHandler {
private:
	PlayerContainer* container;
	SimulationLog* log;
public:
	IOHandler(PlayerContainer* newContainer = nullptr, SimulationLog* newLog = nullptr) : container(newContainer), log(newLog) {}
	void getFromUserSimulationNumber();
	void getFromUserRandomPlayer();
	void getFromUserStonePlayer();
	void getFromUserPaperPlayer();
	void getFromUserScissorsPlayer();
	void getFromUserSequancePlayer();
	void listMatchLogs();
	void listPlayerLogs();
	~IOHandler() {}
};

#endif // !IO_HANDLER_H
