#ifndef GAMEBASE_H
#define GAMEBASE_H

#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <exception>

/**
 * A kõ, papír, olló enumeráció helyett akár objektum is lehetne. 
 * Ezzel megváltoznának a játé-kos függvények például ilyen objektumokból álló 
 * tömb lenne a szekvencia játékos belsejé-ben. Viszont úgy gondoltam, hogy a feladat a stratégiák letesztelése, 
 * így a hangsúly a belõlük összeálló heterogén kollekción van. Így enumerációként is lehet tekinteni a lépésekre.
 */
enum MoveType {
	stone = 0,
	paper = 1,
	scissors = 2
};

/**
 * Enumerizáció ami megadja hogy mi lett egy meccs kimenetele.
 */
enum GameResult {
	playerOneWins = 0,
	playerTwoWins = 1,
	draw = 2
};

#endif