#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include "MyString.h"
#include "GameBase.h"

/**
 *	PlayerBase és Player akár egy osztály is lehetne, de mégis így valósítottam meg õket,
 *	hogy könnyebben kezelhetõek legyenek. A PlayerBase felel az adattagokért,
 *	míg a Player a mûveletekért, például másolás, értékadás.
 */
class PlayerBase {
private:
	size_t id;
	String name;
public:
	PlayerBase(const size_t newId, const String& newName) : id(newId), name(newName) {}

	size_t getId() const{
		return id;
	}

	String getName() const{
		return name;
	}

	virtual void init() = 0;

	virtual MoveType move() = 0;

	virtual PlayerBase* copy() const = 0;

	virtual ~PlayerBase() {};
};

#endif