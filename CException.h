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

	/*Constructeur par défaut :
		-> intitialise une exception
		Entrée : Néant
		Sortie : Néant
	*/
	CException();


	/*Constructeur de confort :
		-> intitialise une exception
		Entrée : Valeur, chaine initiale
		Sortie : Néant
	*/
	CException(unsigned int uiVal, char* cErr);


	/*Constructeur de recopie :
		-> intitialise une exception
		Entrée : exception à recopier
		Sortie : Néant
	*/
	CException(CException& param);


	/*Destructeur :
		-> Libere l'espace mémoire
		Entrée : Néant
		Sortie : Néant
	*/
	~CException();

	//Accesseurs


	/*Méthode qui permet de lire la valeur
		Entrée : Néant
		Sortie : retourne la valeur
	*/
	unsigned int EXCGetValue() { return uiEXCValue; }


	/*Méthode qui permet d'afficher l'erreur
		Entrée : Néant
		Sortie : retourne l'erreur
	*/
	char* EXCGetError() { return cEXCError; }


	/*Méthode qui permet de modifier la valeur
		Entrée : valeur
		Sortie : Néant
	*/
	void EXCSetValue(unsigned int uiVal) { uiEXCValue = uiVal; }


	/*Méthode qui permet de modifier l'erreur
		Entrée : erreur
		Sortie : Néant
	*/
	void EXCSetError(char* cError) { cEXCError = cError; }

	CException& operator=(CException EXCParam);

};

#endif
