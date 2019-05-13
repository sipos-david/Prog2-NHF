#ifndef PAPERPLAYER_H
#define PAPERPLAYER_H

#include "PlayerBase.h"

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
