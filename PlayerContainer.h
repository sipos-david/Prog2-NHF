#ifndef PLAYERCONTAINER_H
#define PLAYERCONTAINER_H

#include "Player.h"

class PlayerContainer {
private:
	size_t length;
	Player* players;
public:
	PlayerContainer() : length(0), players(nullptr) {}
	void playerAdd(Player* newPlayer);
	Player& operator[](size_t index);
	~PlayerContainer();
};

#endif // !PLAYERCONTAINER_H

