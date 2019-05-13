#ifndef PLAYERCONTAINER_H
#define PLAYERCONTAINER_H

#include "Player.h"
/** 
 *	Ez az osztály felelõs a heterogén kollekcióért. Az IOHandler alapján õ is készíti el azt, 
 *	majd felszabadítja. Van indexelõ operátora, ami publikus, hogy ezen keresztül lehessen elérni a kollekció tagjait.
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

