#include "PlayerContainer.h"

void PlayerContainer::playerAdd(Player* newPlayer) {
	this->resize(1);
	this->players[length - 1] = *newPlayer;
	/* A players(PlayerContainer)-be MASOLODIK a newPLayer értéke, fel kell szabadítani ezután */
	delete newPlayer;
}

Player& PlayerContainer::operator[](size_t index){
	if (index < length)
		return players[index];
	throw std::out_of_range("PlayerContainer::operator[] : tul indexeles");
}

PlayerContainer::~PlayerContainer() {
	delete[] players;
}

bool PlayerContainer::empty() {
	return this->length == 0;
}

void PlayerContainer::resize(size_t add) {
	Player* newPlayers = new Player[length + add];
	for (size_t i = 0; i < length; i++)
		newPlayers[i] = players[i];
	delete[] players;
	players = newPlayers;
	this->length += add;
}

size_t PlayerContainer::size() const{
	return this->length;
}
