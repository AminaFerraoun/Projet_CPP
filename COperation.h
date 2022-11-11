#ifndef COperation_h
#define COperation_h 

#include "COperation.h"
#include "CGraph.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class COperation
{
public :

    /*M�thode qui permet d'inverser un graphe
    Entr�e : Objet GRAParam de type CGraph
    Sortie : retourne l'objet graph
    */
	CGraph OPEReverseGraph(CGraph GRAParam);


};
#endif
