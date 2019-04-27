/**
 *
 * \file MyString.cpp
 *
 * String osztály föggvényeinek definícióit tartalmazza
 *
 */

#ifdef _MSC_VER
	// MSC ne adjon figyelmeztető üzenetet a stringkezelő függvényekre.
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Stringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "MyString.h"

using std::cin;
using std::ios_base;

//Konstruktor: egy char karakterből (createStrFromChar)
String::String(char c) {
    currentLength = 1;
    data = new char[currentLength+1];
    data[0] = c;
    data[1] = '\0';
}


// Konstruktor: egy nullával lezárt char sorozatból (createStringFromCharStr)
String::String(const char *cPtrString) {
    currentLength = strlen(cPtrString);
    data = new char[currentLength+1];
    strcpy(data, cPtrString);
}

// Másoló konstruktor
String::String(const String& stringCopied) {
    currentLength = stringCopied.currentLength;
    data = new char[currentLength+1];
    strcpy(data, stringCopied.data);
}

// operator=
String& String::operator=(const String& rhs_string) {
    if (this != &rhs_string) {
        delete[] data;
        currentLength = rhs_string.currentLength;
        data = new char[currentLength+1];
        strcpy(data, rhs_string.data);
    }
    return *this;
}

/**
 * [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza.
 * indexhiba esetén dobjon egy const char * típusú hibát!
 */
char& String::operator[](unsigned int index) {
    if (index >= currentLength)
		throw "String: indexelesi hiba";
    return data[index];
}

const char& String::operator[](unsigned int index) const {
    if (index >= currentLength)
		throw "String: indexelesi hiba";
    return data[index];
}

// + operátor, ami két stringet ad össze (concatString)
String String::operator+(const String& rhs_string) const {
    String temp;		
    temp.currentLength = currentLength + rhs_string.currentLength;
    delete []temp.data;
    temp.data = new char[temp.currentLength+1];
    strcpy(temp.data, data);
    strcat(temp.data, rhs_string.data);
    return temp;	
}
// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& stringOut) {
    os << stringOut.c_str();
    return os;
}

// << operátor, ami beolvas az istreamről egy szót
std::istream& operator>>(std::istream& is, String& stringIn) {
    unsigned char ch;
    stringIn = String("");            // üres string, ehhez fűzünk hozzá
	std::ios_base::fmtflags fl = is.flags(); // eltesszük a régi flag-eket
	is.setf(ios_base::skipws);			// az elején eldobjuk a ws-t
    while (is >> ch) {
	    is.unsetf(ios_base::skipws);	// utána pedig már nem
        if (isspace(ch)) {
            is.putback(ch);             // na ezt nem kérjük
            break;
        } else {
            stringIn = stringIn + ch;               // végére fűzzük a karaktert
        }
    }
	is.setf(fl);						// visszaállítjuk a flag-eket
    return is;
}