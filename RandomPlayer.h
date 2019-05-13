#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "PlayerBase.h"
#include <cstdlib>

/**
*	PlayerBase-bõl leszármazott osztály. A heterogén kollekció része. 
*	A randomizált játékost valósítja meg, a cstdlib library-ban található rand() függvény segítségével. 
*	az srand() meg-hívásáért nem felel, a példányosítása elõtt biztosítani kell a lefutását.
*/
class RandomPlayer : public PlayerBase {
public:
	RandomPlayer(const size_t newId, const String& newName) : PlayerBase(newId, newName) {}

	void init() {}

	MoveType move() {
		return MoveType(rand() % 3);
	}

	PlayerBase* copy() const {
		RandomPlayer* copy = new RandomPlayer(getId(), getName());
		return copy;
	}

	~RandomPlayer() {};
};

#endif // !RANDOMPLAYER_H
