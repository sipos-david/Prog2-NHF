/**
 * \file mystring.h
 *
 * Ez a fájl tartalmazza a String osztály deklarációját és inline függvényeit.
 *
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

/**
 * String osztály.
 * A data-ban vannak a karakterek (a lezáró nullával együtt),
 * currentLength a hossz. A hosszba nem számít bele a lezáró nulla.
 */
class String {

    char *data;   			// pointer az adatra
    size_t currentLength;     // hossz lezáró nulla nélkül

public:

    /**
	 *	Hossz lekérdezése.
     * @return Sztring hossza
	 */
	size_t size() const { return currentLength; }

	/**
     * Default konstruktor
     * String() :data(0), currentLength(0) {}
     * helyett ""-val inicializáljuk a const char*-osban
	 */
	
	/**
     * C-sztringet ad vissza
     * @return pinter egy '\0'-val lezárt (C) sztringre
	 */
    const char* c_str() const { return data;}

	/**
     * Konstruktor egy char karakterből
     * @param c - karakter
	 */
    String(char c);

	/**
     * Konstruktor egy nullával lezárt char sorozatból
     * Ez a deafault is!
     * @param cPtrString - pointer egy C sztringre
	 */
    String(const char *cPtrString = "");

	/**
     * Másoló konstruktor
     * @param myString - String, amiből létrehozzuk az új String-et
	 */
    String(const String& stringCopied);

	/**
     * Destruktor
	 */
    virtual ~String() { delete[] data; }

	/**
     * Kiírunk egy Stringet (debug célokra)
     * Előtte kiírunk egy tetszőleges szöveget.
     * @param txt - nullával lezárt szövegre mutató pointer
	 */
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << currentLength << "], "
                  << (data ? data : "(NULL)") << std::endl;
    }

	/**
     * Értékadó operátor.
     * @param rhs_string - jobboldali String
     * @return baoldali (módosított) string (referenciája)
	 */
    String& operator=(const String& rhs_string);

	/**
     * Két Stringet összefűz
     * @param rhs_string - jobboldali String
     * @return új String, ami tartalmazza a két stringet egmás után
	 */
    String operator+(const String& rhs_string) const ;

	/**
     * Sztrinhez karaktert összefűz
     * @param rhs_c - jobboldali karakter
     * @return új String, ami tartalmazza a sztringet és a karaktert egymás után
	 */
    String operator+(char rhs_c) const { return *this + String(rhs_c);}
	
	/**
     * A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
     * @param index - charakter indexe
     * @return karakter (referencia)
     *         Indexelési hiba esetén const char* kivételt dob.
	 */
    char& operator[](unsigned int index);

	/**
     * A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
     * @param index - karakter indexe
     * @return karakter (referencia)
     *         Indexelési hiba esetén const char* kivételt dob (assert helyett).
	 */
    const char& operator[](unsigned int index) const;
};

// Globális függvények:

/**
 * kiír az ostream-re
 * @param os - ostream típusú objektum
 * @param stringOut - String, amit kiírunk
 * @return os
 */
std::ostream& operator<<(std::ostream& os, const String& stringOut);

/**
 * Beolvas az istream-ről egy szót egy string-be.
 * @param is - istream típusú objektum
 * @param stringIn - String, amibe beolvas
 * @return is
 */
std::istream& operator>>(std::istream& is, String& stringIn);

/**
 * Karakterhez sztringet fűz
 * @param ch - karakter
 * @param str - String
 * @return új String, ami tartalmazza a karaktert és a sztringet egymás után
 */
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif