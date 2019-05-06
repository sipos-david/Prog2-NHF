#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include "PlayerContainer.h"
#include "SimulationLog.h"

class IOHandler {
private:
	PlayerContainer& container;
	SimulationLog& log;
public:
	IOHandler(PlayerContainer& newContainer, SimulationLog& newLog) : container(newContainer), log(newLog) {}

	/*
	 *	A standard inputról bekéri a meccsek számát.
	 *	@param - nincs
	 *	@return - size_t -> GameSimulator.simulationNumber típusa
	 */
	size_t getFromUserSimulationNumber();

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
