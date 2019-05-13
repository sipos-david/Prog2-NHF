#ifndef STONEPLAYER_H
#define STONEPLAYER_H

#include "PlayerBase.h"

/**
 * PlayerBase-b�l lesz�rmazott oszt�ly. A heterog�n kollekci� r�sze. A csak k�vet j�tsz� stra-t�gi�t haszn�lja.
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
