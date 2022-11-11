#ifndef CEdge_h
#define CEdge_h 

#include "CEdge.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class CEdge
{
private:
	unsigned int uiEDGDestination;

public:

	/*Constructeur par défaut :
	-> Crée un objet CEdge, initialise les variables locales
	Entrée : Néant
	Sortie : retourne un objet edge
	*/
	CEdge();


	/*Constructeur de confort :
	-> Crée un objet graph 
	Entrée : uiParam qui prend la destination de l'arc
	Sortie : Néant
	*/
	CEdge(unsigned int uiParam);


	/*Méthode qui permet de lire la destination de l'arc
	Entrée : Néant
	Sortie : retourne la destination de l'arc
	*/
	unsigned int EDGGetDestination() { return  uiEDGDestination; };


	/*Méthode qui permet de modifier la destination de l'arc
	Entrée : EDGParam qui correspond a la destination de l'arc
	Sortie : Néant
	*/
	void EDGSetDestination(unsigned int EDGParam) { uiEDGDestination = EDGParam; };

};

#endif