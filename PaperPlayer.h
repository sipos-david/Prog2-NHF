#ifndef PAPERPLAYER_H
#define PAPERPLAYER_H

#include "PlayerBase.h"

/**
 * PlayerBase-bõl leszármazott osztály. A heterogén kollekció része. A csak a papírt ismeri, ezért csak azt lép.
 */
class PaperPlayer : public PlayerBase {
public:
	PaperPlayer(const size_t newId, const String& newName) : PlayerBase(newId, newName) {}

	void init() {}

	MoveType move() {
		return paper;
	}

	PlayerBase* copy() const {
		PaperPlayer* copy = new PaperPlayer(this->getId(), this->getName());
		return copy;
	}

	~PaperPlayer() {};
};

#endif // !PAPERPLAYER_H
