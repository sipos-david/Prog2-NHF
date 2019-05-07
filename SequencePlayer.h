#ifndef SEQUENCEPLAYER_H
#define SEQUENCEPLAYER_H

#include "PlayerBase.h"

MoveType charToMoveType(const char ch);

class SequencePlayer : public PlayerBase {
private:
	size_t currentSequenceCounter = 0;
	String sequenceContainer;
	size_t sequenceLength;

public:
	SequencePlayer(const size_t newId, const String& newName, const String& newSequence) : PlayerBase(newId, newName),
																						   sequenceContainer(newSequence),
																						   sequenceLength(newSequence.size()) {}

	MoveType move();

	void reset() { currentSequenceCounter = 0; }

	PlayerBase* copy() const {
		SequencePlayer* copy = new SequencePlayer(this->getId(), this->getName(), this->sequenceContainer);
		return copy;
	}

	~SequencePlayer() {};
};

#endif // !SCISSORSPLAYER_H
