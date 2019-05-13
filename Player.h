#ifndef PLAYER_H
#define PLAYER_H

#include "StonePlayer.h"
#include "PaperPlayer.h"
#include "ScissorsPlayer.h"
#include "RandomPlayer.h"
#include "SequencePlayer.h"
#include "PlayerBase.h"

/**
 *	PlayerBase �s Player ak�r egy oszt�ly is lehetne, de m�gis �gy val�s�tottam meg �ket, 
 *	hogy k�nnyebben kezelhet�ek legyenek. A PlayerBase felel az adattagok�rt,
 *	m�g a Player a m�veletek�rt, p�ld�ul m�sol�s, �rt�kad�s.
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
	 *	Visszaadja a p�ld�ny id-j�t.
	 *
	 *	@param - nincs
	 *	@return - size_t, id t�pusa.
	 */
	size_t getId() {
		return this->player->getId();
	}

	/**
	 *	Visszaadja a nev�t.
	 *
	 *	@param - nincs
	 *	@return - string, name t�pusa.
	 */
	String getName() {
		return this->player->getName();
	}

	/**
	 *	Visszaadja a l�p�st, k�vetve a p�ld�ny strat�gi�j�t.
	 *
	 *	@param - nincs
	 *	@return - MoveType enumeriz�ci�.
	 */
	MoveType move() {
		return player->move();
	}

	/**
	 *	Egy f�ggv�ny, ami inicializ�lja, vagyis el�k�sz�ti a p�ld�nyt. Jelen �llapotban csak a szekvencia j�t�kos haszn�lja.
	 *
	 *	@param - nincs
	 *	@return - MoveType enumeriz�ci�.
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
