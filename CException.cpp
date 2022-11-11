#include "CException.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/*Constructeur par défaut :
		-> intitialise une exception
		Entrée : Néant
		Sortie : Néant
*/
CException::CException() {
	uiEXCValue = 0;
	cEXCError = nullptr;
}


/*Constructeur de confort :
		-> intitialise une exception
		Entrée : Valeur, chaine initiale
		Sortie : Néant
*/
CException::CException(unsigned int uiVal, char* cErr) {
	uiEXCValue = uiVal;

	unsigned int uiTailleChaine = 0;

	/* Permet d'obtenir la taille de notre chaine initiale, afin de réaliser une allocation mémoire correcte. */
	while (cErr != "\0") {
		uiTailleChaine++;
	}

	cEXCError = (char*)malloc(sizeof(char) * uiTailleChaine);
	cEXCError = cErr;
}



/*Constructeur de recopie :
	-> intitialise une exception
	Entrée : exception à recopier
	Sortie : Néant
*/
CException::CException(CException& param) {
	uiEXCValue = param.uiEXCValue;

	unsigned int uiTailleChaine = 0;

	/* Permet d'obtenir la taille de notre chaine initiale, afin de réaliser une allocation mémoire correcte. */
	while (param.cEXCError != "\0") {
		uiTailleChaine++;
	}

	cEXCError = (char*)malloc(sizeof(char) * uiTailleChaine);
	cEXCError = param.cEXCError;

}



/*Destructeur :
		-> Libere l'espace mémoire
		Entrée : Néant
		Sortie : Néant
*/
CException::~CException() {
	free(cEXCError);
}

CException& CException::operator=(CException EXCParam) {
	uiEXCValue = EXCParam.EXCGetValue();

	unsigned int uiTailleChaine = 0;

	/* Permet d'obtenir la taille de notre chaine initiale, afin de réaliser une allocation mémoire correcte. */
	while (EXCParam.EXCGetError() != "\0") {
		uiTailleChaine++;
	}

	cEXCError = (char*)malloc(sizeof(char) * uiTailleChaine);
	cEXCError = EXCParam.EXCGetError();

	return *this;
}