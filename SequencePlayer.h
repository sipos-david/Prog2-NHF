#ifndef SEQUENCEPLAYER_H
#define SEQUENCEPLAYER_H

#include "PlayerBase.h"

/**
 *	char-ból készít MoveType enumerizációt, ha nem megfelelõ a bemenet std::invalid_argument kivételt dob.
 *
 *	@param - ch a karakter 
 *	@return - MoveType enumerizáció
 */
MoveType charToMoveType(const char ch);

/**
* PlayerBase-bõl leszármazott osztály. A heterogén kollekció része. Egy bizonyos szekvenci-át ismétel. 
* Magát a szekvenciát egy Stringben tárolja (k, p, o) és belül követi, hogy éppen hol tart. 
* Ha egy szekvenciának vége, akkor elölrõl kezdi. Van reset() függvénye amivel alaphely-zetbe állítható hogy elölrõl lehessen kezdni a szimulációt.
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
	 *	Visszaállítja "eredeti" állapotába a példányt.
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
