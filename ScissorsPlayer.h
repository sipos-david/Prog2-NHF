#ifndef SCISSORSPLAYER_H
#define SCISSORSPLAYER_H

#include "PlayerBase.h"
/**
*	PlayerBase-bõl leszármazott osztály. A heterogén kollekció része. A csak az ollót játsza.
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
