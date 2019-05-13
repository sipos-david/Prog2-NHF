#ifndef GAMEBASE_H
#define GAMEBASE_H

#include <exception>

enum MoveType {
	stone = 0,
	paper = 1,
	scissors = 2
};

enum GameResult {
	playerOneWins = 0,
	playerTwoWins = 1,
	draw = 2
};

#endif