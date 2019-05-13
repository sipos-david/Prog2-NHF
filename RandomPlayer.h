#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "PlayerBase.h"
#include <cstdlib>

/**
*	PlayerBase-b�l lesz�rmazott oszt�ly. A heterog�n kollekci� r�sze. 
*	A randomiz�lt j�t�kost val�s�tja meg, a cstdlib library-ban tal�lhat� rand() f�ggv�ny seg�ts�g�vel. 
*	az srand() meg-h�v�s��rt nem felel, a p�ld�nyos�t�sa el�tt biztos�tani kell a lefut�s�t.
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
