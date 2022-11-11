#pragma once
#ifndef CException_h
#define CException_h 3

#include <iostream>
#include <cstdlib>

using namespace std;

#define Fichier_Introuvable 1
#define Valeur_Presente 2


class CException {
private:
	unsigned int uiEXCValue;
	char* cEXCError;

public:

	/*Constructeur par d�faut :
		-> intitialise une exception
		Entr�e : N�ant
		Sortie : N�ant
	*/
	CException();


	/*Constructeur de confort :
		-> intitialise une exception
		Entr�e : Valeur, chaine initiale
		Sortie : N�ant
	*/
	CException(unsigned int uiVal, char* cErr);


	/*Constructeur de recopie :
		-> intitialise une exception
		Entr�e : exception � recopier
		Sortie : N�ant
	*/
	CException(CException& param);


	/*Destructeur :
		-> Libere l'espace m�moire
		Entr�e : N�ant
		Sortie : N�ant
	*/
	~CException();

	//Accesseurs


	/*M�thode qui permet de lire la valeur
		Entr�e : N�ant
		Sortie : retourne la valeur
	*/
	unsigned int EXCGetValue() { return uiEXCValue; }


	/*M�thode qui permet d'afficher l'erreur
		Entr�e : N�ant
		Sortie : retourne l'erreur
	*/
	char* EXCGetError() { return cEXCError; }


	/*M�thode qui permet de modifier la valeur
		Entr�e : valeur
		Sortie : N�ant
	*/
	void EXCSetValue(unsigned int uiVal) { uiEXCValue = uiVal; }


	/*M�thode qui permet de modifier l'erreur
		Entr�e : erreur
		Sortie : N�ant
	*/
	void EXCSetError(char* cError) { cEXCError = cError; }

	CException& operator=(CException EXCParam);

};

#endif
