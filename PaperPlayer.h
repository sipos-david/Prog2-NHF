#ifndef PAPERPLAYER_H
#define PAPERPLAYER_H

#include "PlayerBase.h"

/**
 * PlayerBase-b�l lesz�rmazott oszt�ly. A heterog�n kollekci� r�sze. A csak a pap�rt ismeri, ez�rt csak azt l�p.
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
