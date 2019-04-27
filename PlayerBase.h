#ifndef PLAYERBASEH
#define PLAYERBASE_H

#include "MyString.h"
#include "GameBase.h"

class PlayerBase {
private:
	size_t id;
	String name;
public:
	PlayerBase(const size_t newId, const String& newName) : id(newId), name(newName) {}
	virtual MoveType move() = 0;
	virtual PlayerBase* copy() const = 0;
	virtual ~PlayerBase() {};
};

#endif