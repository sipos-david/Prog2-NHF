#include "PlayerContainer.h"

void PlayerContainer::playerAdd(Player* newPlayer) {
}

Player& PlayerContainer::operator[](size_t index){
	return players[index];
}

PlayerContainer::~PlayerContainer() {
}
