#include "memtrace.h"
#include "GameSimulator.h"

int main() {
	GameSimulator simulation, simulationTEST(true);

	simulationTEST.getParameters();
	simulationTEST.test();
	simulationTEST.simulation();
	simulationTEST.displayResults();
}
