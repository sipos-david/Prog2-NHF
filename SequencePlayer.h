#ifndef SEQUENCEPLAYER_H
#define SEQUENCEPLAYER_H

#include "PlayerBase.h"

/**
 *	char-b�l k�sz�t MoveType enumeriz�ci�t, ha nem megfelel� a bemenet std::invalid_argument kiv�telt dob.
 *
 *	@param - ch a karakter 
 *	@return - MoveType enumeriz�ci�
 */
MoveType charToMoveType(const char ch);

/**
* PlayerBase-b�l lesz�rmazott oszt�ly. A heterog�n kollekci� r�sze. Egy bizonyos szekvenci-�t ism�tel. 
* Mag�t a szekvenci�t egy Stringben t�rolja (k, p, o) �s bel�l k�veti, hogy �ppen hol tart. 
* Ha egy szekvenci�nak v�ge, akkor el�lr�l kezdi. Van reset() f�ggv�nye amivel alaphely-zetbe �ll�that� hogy el�lr�l lehessen kezdni a szimul�ci�t.
*/
class SequencePlayer : public PlayerBase {
private:
	size_t currentSequenceCounter = 0;
	String sequenceContainer;
	size_t sequenceLength;

public:
	SequencePlayer(const size_t newId, const String& newName, const String& newSequence) : PlayerBase(newId, newName),
																						   sequenceContainer(newSequence),
																						   sequenceLength(newSequence.size()) {}

	void init() { reset(); }

	MoveType move();

	/**
	 *	Vissza�ll�tja "eredeti" �llapot�ba a p�ld�nyt.
	 *
	 *	@param - nincs
	 *	@return - nincs
	 */
	void reset() { currentSequenceCounter = 0; }

	String getSequence() const { return sequenceContainer; }

	PlayerBase* copy() const {
		SequencePlayer* copy = new SequencePlayer(this->getId(), this->getName(), this->sequenceContainer);
		return copy;
	}

	~SequencePlayer() {};
};

#endif // !SCISSORSPLAYER_H
