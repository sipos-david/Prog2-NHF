#ifndef STONEPLAYER_H
#define STONEPLAYER_H

#include "PlayerBase.h"

class StonePlayer : public PlayerBase {
public:
	StonePlayer(const size_t newId, const String& newName) : PlayerBase(newId, newName) {}
	MoveType move() {
		return stone;
	}
	PlayerBase* copy() const {}
	~StonePlayer() {};
};

#endif // !STONEPLAYER_H
