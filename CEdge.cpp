#include "CEdge.h"
#include"CException.h"

#include <stdlib.h>
#include <iostream>

using namespace std;


/*Constructeur par défaut :
-> Crée un objet CEdge, initialise les variables locales
Entrée : Néant
Sortie : retourne un objet edge
*/
CEdge::CEdge() {
	uiEDGDestination = 0;
}



/*Constructeur de confort :
-> Crée un objet graph
Entrée : uiParam qui prend la destination de l'arc
Sortie : Néant
*/
CEdge::CEdge(unsigned int uiParam) {
	uiEDGDestination = uiParam;
}
