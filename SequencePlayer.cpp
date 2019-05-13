#include "SequencePlayer.h"

MoveType SequencePlayer::move() {
	if (sequenceContainer.size() == currentSequenceCounter)
		reset();
	return charToMoveType(sequenceContainer[currentSequenceCounter++]);
}

MoveType charToMoveType(const char ch)
{
	switch (ch) {
		case 'k':
			return stone;
		case 'p':
			return paper;
		case 'o':
			return scissors;
	}
	
	return stone;
}
