#ifndef STONEPLAYER_H
#define STONEPLAYER_H

#include "PlayerBase.h"

/**
 * PlayerBase-bõl leszármazott osztály. A heterogén kollekció része. A csak követ játszó stra-tégiát használja.
 */
class StonePlayer : public PlayerBase {
public:

	StonePlayer(const size_t newId, const String& newName) : PlayerBase(newId, newName) {}

	void init() {}

	MoveType move() {
		return stone;
	}

	PlayerBase* copy() const {
		StonePlayer* copy = new StonePlayer(this->getId(), this->getName());
		return copy;
	}

	~StonePlayer() {};
};

#endif // !STONEPLAYER_H
