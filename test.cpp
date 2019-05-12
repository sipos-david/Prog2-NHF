#define MEMTRACE
#include "memtrace.h"
#include "GameSimulator.h"

int main() {
	GameSimulator simulation;
	simulation.getParameters();
	simulation.simulation();
	simulation.displayResults();
}
