#include "CParser.h"
#include "CException.h"
#include <iostream>
#include <cstdlib>

using namespace std;


/* Analyseur syntaxique : Méthode qui permet de creer un graph a partir des données stockées grace à l'analyseur lexical
	Entrée : ptcParam qui correspond aux données stockées
	Sortie : retourne un objet graph
*/
CGraph* CParser::PARCreateGraph(const char** ptcParam) {

	CGraph* GRAGraph = new CGraph();
	int iNbNode = 0;
	int iNbEdge = 0;
	int iCount = 0;


	iNbNode = atoi(ptcParam[iCount]);//Conversion de caractere en valeur numerique
	cout << "Nombre de sommets : " << iNbNode << endl;
	iCount++;
	
	iNbEdge = atoi(ptcParam[iCount]);
	cout << "Nombre d'arcs : " << iNbEdge << endl;
	iCount++;

	cout << endl;

	for (iCount; iCount < iNbNode + 2; iCount++) {
		GRAGraph->GRAAddNode(atoi(ptcParam[iCount]));//Ajout d'un sommet dans le graph
		cout << "Numéro de sommet : " << atoi(ptcParam[iCount]) << endl;
	}
	cout << endl;
	int iCount2 = iCount + iNbEdge * 2;

	for (iCount; iCount < iCount2; iCount++) {
		int iArrivingNode = atoi(ptcParam[iCount]);
		iCount++;

		int iLeavingNode = atoi(ptcParam[iCount]);

		GRAGraph->NODAddEdge(iLeavingNode, iArrivingNode);//Ajout d'un arc dans le graph
		cout << "Arc arrivant : " << iArrivingNode << "   /    Arc sortant : " << iLeavingNode << endl;

		
	}

	return GRAGraph;
}