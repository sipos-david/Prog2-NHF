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
		case 'K':
			return stone;
		case 'p':
		case 'P':
			return paper;
		case 'o':
		case 'O':
			return scissors;
	}
	
	throw std::invalid_argument("charToMoveType : const char ch : nem megfelelõ karakter!");
}
