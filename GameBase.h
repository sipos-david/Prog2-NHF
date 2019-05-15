#ifndef GAMEBASE_H
#define GAMEBASE_H

#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <exception>

/**
 * A k�, pap�r, oll� enumer�ci� helyett ak�r objektum is lehetne. 
 * Ezzel megv�ltozn�nak a j�t�-kos f�ggv�nyek p�ld�ul ilyen objektumokb�l �ll� 
 * t�mb lenne a szekvencia j�t�kos belsej�-ben. Viszont �gy gondoltam, hogy a feladat a strat�gi�k letesztel�se, 
 * �gy a hangs�ly a bel�l�k �ssze�ll� heterog�n kollekci�n van. �gy enumer�ci�k�nt is lehet tekinteni a l�p�sekre.
 */
enum MoveType {
	stone = 0,
	paper = 1,
	scissors = 2
};

/**
 * Enumeriz�ci� ami megadja hogy mi lett egy meccs kimenetele.
 */
enum GameResult {
	playerOneWins = 0,
	playerTwoWins = 1,
	draw = 2
};

#endif