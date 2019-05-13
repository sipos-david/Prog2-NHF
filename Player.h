#ifndef PLAYER_H
#define PLAYER_H

#include "StonePlayer.h"
#include "PaperPlayer.h"
#include "ScissorsPlayer.h"
#include "RandomPlayer.h"
#include "SequencePlayer.h"
#include "PlayerBase.h"

/**
 *	PlayerBase és Player akár egy osztály is lehetne, de mégis így valósítottam meg õket, 
 *	hogy könnyebben kezelhetõek legyenek. A PlayerBase felel az adattagokért,
 *	míg a Player a mûveletekért, például másolás, értékadás.
 */
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

	/**
	 *	Visszaadja a példány id-ját.
	 *
	 *	@param - nincs
	 *	@return - size_t, id típusa.
	 */
	size_t getId() {
		return this->player->getId();
	}

	/**
	 *	Visszaadja a nevét.
	 *
	 *	@param - nincs
	 *	@return - string, name típusa.
	 */
	String getName() {
		return this->player->getName();
	}

	/**
	 *	Visszaadja a lépést, követve a példány stratégiáját.
	 *
	 *	@param - nincs
	 *	@return - MoveType enumerizáció.
	 */
	MoveType move() {
		return player->move();
	}

	/**
	 *	Egy függvény, ami inicializálja, vagyis elõkészíti a példányt. Jelen állapotban csak a szekvencia játékos használja.
	 *
	 *	@param - nincs
	 *	@return - MoveType enumerizáció.
	 */
	void init() {
		player->init();
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
