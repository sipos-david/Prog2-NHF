//#define MEMTRACE
//#include "memtrace.h"
#include "GameSimulator.h"

int main() {
	GameSimulator simulation, simulationTEST(true);

	simulationTEST.getParameters();
	simulationTEST.simulation();
	simulationTEST.displayResults();

	simulation.getParameters();
	simulation.simulation();
	simulation.displayResults();
}
