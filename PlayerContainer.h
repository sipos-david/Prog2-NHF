#ifndef PLAYERCONTAINER_H
#define PLAYERCONTAINER_H

#include "Player.h"
/** 
 *	Ez az oszt�ly felel�s a heterog�n kollekci��rt. Az IOHandler alapj�n � is k�sz�ti el azt, 
 *	majd felszabad�tja. Van indexel� oper�tora, ami publikus, hogy ezen kereszt�l lehessen el�rni a kollekci� tagjait.
 */
class PlayerContainer {
private:
	size_t length;
	Player* players;

public:
	PlayerContainer() : length(0), players(nullptr) {}

	void playerAdd(Player* newPlayer);

	size_t size() const;

	Player& operator[](size_t index);

	bool empty();

	void resize(size_t add);

	~PlayerContainer();
};

#endif // !PLAYERCONTAINER_H

