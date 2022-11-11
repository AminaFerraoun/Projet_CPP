#include "COperation.h"
#include"CException.h"


#include <stdlib.h>
#include <iostream>

using namespace std;


/*Méthode qui permet d'inverser un graphe
Entrée : Objet GRAParam de type CGraph
Sortie : retourne l'objet graph
*/
CGraph COperation::OPEReverseGraph(CGraph GRAParam) {
    unsigned uiLoop1 = 0;
    unsigned uiLoop2 = 0;
    CGraph  GRAResult = CGraph(GRAParam);
    /*if (GRAParam.GRAGetOriented() == true) {
        for (uiLoop1 = 0; uiLoop1 < GRAParam.GRAGetNbOfNodes(); uiLoop1++) {
            for (uiLoop2 = 0; uiLoop2 < GRAParam.GRAGetNbOfNodes(); uiLoop2++) {
                if (GRAParam.GRAGetElement(uiLoop1).NODSearchLeavingEdge(GRAParam.GRAGetElement(uiLoop2).NODGetNodeID())) {
                    GRAParam.GRAGetElement(uiLoop1).NODDeleteLeavingEdges(GRAParam.GRAGetElement(uiLoop2).NODGetNodeID());
                    GRAParam.GRAGetElement(uiLoop2).NODAddLeavingEdges(GRAParam.GRAGetElement(uiLoop1).NODGetNodeID());

                }
            }
        }
    }*/
    return  GRAResult;

}