#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerBase.h"

#include "StonePlayer.h";
#include "PaperPlayer.h";
#include "ScissorsPlayer.h";
#include "RandomPlayer.h";
#include "SequencePlayer.h";

class Player {
private:
	PlayerBase* player;

public:
	Player(PlayerBase* newPlayer = nullptr) : player(newPlayer) {}

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

	size_t getId() {
		return this->player->getId();
	}

	String getName() {
		return this->player->getName();
	}

	PlayerBase* operator->() {
		return player;
	}

	PlayerBase const* operator->() const {
		return player;
	}

	~Player() {
		delete player;
	}
};

#endif