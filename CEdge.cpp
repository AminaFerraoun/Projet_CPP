#include "CEdge.h"
#include"CException.h"

#include <stdlib.h>
#include <iostream>

using namespace std;


/*Constructeur par d�faut :
-> Cr�e un objet CEdge, initialise les variables locales
Entr�e : N�ant
Sortie : retourne un objet edge
*/
CEdge::CEdge() {
	uiEDGDestination = 0;
}



/*Constructeur de confort :
-> Cr�e un objet graph
Entr�e : uiParam qui prend la destination de l'arc
Sortie : N�ant
*/
CEdge::CEdge(unsigned int uiParam) {
	uiEDGDestination = uiParam;
}
