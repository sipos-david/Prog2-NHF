#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerBase.h"

class Player {
private:
	PlayerBase* player;

public:
	Player(PlayerBase* newPlayer) : player(newPlayer) {}

	Player(Player const& masolando) {
		player = masolando.player->copy();
	}

	Player& operator=(Player const& masolando) {
		if (this != &masolando) {
			delete player;
			player = masolando.player->copy();
		}
		return *this;
	}

	~Player() {
		delete player;
	}

	PlayerBase* operator->() {
		return player;
	}

	PlayerBase const* operator->() const {
		return player;
	}
};

#endif