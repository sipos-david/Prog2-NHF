#ifndef SCISSORSPLAYER_H
#define SCISSORSPLAYER_H

#include "PlayerBase.h"
/**
*	PlayerBase-b�l lesz�rmazott oszt�ly. A heterog�n kollekci� r�sze. A csak az oll�t j�tsza.
*/
class ScissorsPlayer : public PlayerBase {
public:

	ScissorsPlayer(const size_t newId, const String& newName) : PlayerBase(newId, newName) {}

	void init() {}

	MoveType move() {
		return scissors;
	}

	PlayerBase* copy() const {
		ScissorsPlayer* copy = new ScissorsPlayer(this->getId(), this->getName());
		return copy;
	}

	~ScissorsPlayer() {};
};

#endif // !SCISSORSPLAYER_H
