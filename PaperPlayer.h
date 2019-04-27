#ifndef PAPERPLAYER_H
#define PAPERPLAYER_H

#include "PlayerBase.h"

class PaperPlayer : public PlayerBase {
public:
	PaperPlayer(const size_t newId, const String& newName) : PlayerBase(newId, newName) {}
	MoveType move() {
		return paper;
	}
	PlayerBase* copy() const {}
	~PaperPlayer() {};
};

#endif // !PAPERPLAYER_H
