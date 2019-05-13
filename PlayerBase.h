#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include "MyString.h"
#include "GameBase.h"

/**
 *	PlayerBase �s Player ak�r egy oszt�ly is lehetne, de m�gis �gy val�s�tottam meg �ket,
 *	hogy k�nnyebben kezelhet�ek legyenek. A PlayerBase felel az adattagok�rt,
 *	m�g a Player a m�veletek�rt, p�ld�ul m�sol�s, �rt�kad�s.
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