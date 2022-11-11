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

	/*Constructeur par d�faut :
	-> Cr�e un objet CEdge, initialise les variables locales
	Entr�e : N�ant
	Sortie : retourne un objet edge
	*/
	CEdge();


	/*Constructeur de confort :
	-> Cr�e un objet graph 
	Entr�e : uiParam qui prend la destination de l'arc
	Sortie : N�ant
	*/
	CEdge(unsigned int uiParam);


	/*M�thode qui permet de lire la destination de l'arc
	Entr�e : N�ant
	Sortie : retourne la destination de l'arc
	*/
	unsigned int EDGGetDestination() { return  uiEDGDestination; };


	/*M�thode qui permet de modifier la destination de l'arc
	Entr�e : EDGParam qui correspond a la destination de l'arc
	Sortie : N�ant
	*/
	void EDGSetDestination(unsigned int EDGParam) { uiEDGDestination = EDGParam; };

};

#endif