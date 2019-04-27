#ifndef SCISSORSPLAYER_H
#define SCISSORSPLAYER_H

#include "PlayerBase.h"

class ScissorsPlayer : public PlayerBase {
public:
	ScissorsPlayer(const size_t newId, const String& newName) : PlayerBase(newId, newName) {}
	MoveType move() {
		return scissors;
	}
	PlayerBase* copy() const {}
	~ScissorsPlayer() {};
};

#endif // !SCISSORSPLAYER_H
