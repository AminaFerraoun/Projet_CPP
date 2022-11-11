#include "CException.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/*Constructeur par d�faut :
		-> intitialise une exception
		Entr�e : N�ant
		Sortie : N�ant
*/
CException::CException() {
	uiEXCValue = 0;
	cEXCError = nullptr;
}


/*Constructeur de confort :
		-> intitialise une exception
		Entr�e : Valeur, chaine initiale
		Sortie : N�ant
*/
CException::CException(unsigned int uiVal, char* cErr) {
	uiEXCValue = uiVal;

	unsigned int uiTailleChaine = 0;

	/* Permet d'obtenir la taille de notre chaine initiale, afin de r�aliser une allocation m�moire correcte. */
	while (cErr != "\0") {
		uiTailleChaine++;
	}

	cEXCError = (char*)malloc(sizeof(char) * uiTailleChaine);
	cEXCError = cErr;
}



/*Constructeur de recopie :
	-> intitialise une exception
	Entr�e : exception � recopier
	Sortie : N�ant
*/
CException::CException(CException& param) {
	uiEXCValue = param.uiEXCValue;

	unsigned int uiTailleChaine = 0;

	/* Permet d'obtenir la taille de notre chaine initiale, afin de r�aliser une allocation m�moire correcte. */
	while (param.cEXCError != "\0") {
		uiTailleChaine++;
	}

	cEXCError = (char*)malloc(sizeof(char) * uiTailleChaine);
	cEXCError = param.cEXCError;

}



/*Destructeur :
		-> Libere l'espace m�moire
		Entr�e : N�ant
		Sortie : N�ant
*/
CException::~CException() {
	free(cEXCError);
}

CException& CException::operator=(CException EXCParam) {
	uiEXCValue = EXCParam.EXCGetValue();

	unsigned int uiTailleChaine = 0;

	/* Permet d'obtenir la taille de notre chaine initiale, afin de r�aliser une allocation m�moire correcte. */
	while (EXCParam.EXCGetError() != "\0") {
		uiTailleChaine++;
	}

	cEXCError = (char*)malloc(sizeof(char) * uiTailleChaine);
	cEXCError = EXCParam.EXCGetError();

	return *this;
}