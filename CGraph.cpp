#include "CGraph.h"
#include "CException.h"
#include <iostream>
#include <cstdlib>

using namespace std;


/*Constructeur par défaut :
	-> Crée un objet graph, initialise les variables locales
	Entrée : Néant
	Sortie : retourne un objet graph
*/
CGraph::CGraph() {
	ptptEDGGRAListOfEdges = nullptr;
	uiGRANbOfNodes = 0;
	bGRAOriented = NULL;
}


/*Constructeur de recopie :
	-> Crée et recopie un objet graph
	Entrée : Graph qui va etre recopié
	Sortie : retourne un objet graph
*/
CGraph::CGraph(const CGraph& GRAParam) {


	uiGRANbOfNodes = GRAParam.uiGRANbOfNodes;
	bGRAOriented = GRAParam.bGRAOriented;
	unsigned int uiSize = GRAParam.uiGRANbOfNodes;
	unsigned int uiLoop = 0;
	ptptEDGGRAListOfEdges = new CNode * [uiSize];

	for (uiLoop = 0; uiLoop < uiSize; uiLoop++) {
		ptptEDGGRAListOfEdges[uiLoop] = GRAParam.ptptEDGGRAListOfEdges[uiLoop];

	}

}



/*Destructeur :
	-> Libére l'espace mémoire d'un graph
	Entrée : Néant
	Sortie : Néant
*/
CGraph::~CGraph() {
	delete[] ptptEDGGRAListOfEdges;
}


/*Méthode qui permet de voir si un sommet existe ou pas
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : retourne une booleene
*/
bool CGraph::GRASearchNode(unsigned int uiParam) {
	bool bFind = false;
	for (unsigned int uiLoop1 = 0; uiLoop1 < uiGRANbOfNodes; uiLoop1++) {

		if (ptptEDGGRAListOfEdges[uiLoop1]->NODGetNodeID() == uiParam) {
			bFind = true;
		}
		else {
			bFind = false;
		}

	}
	return bFind;
}



/*Méthode qui permet d'ajouter un sommet
	Entrée : uiParam pour voir si le numero de sommet existe
	Sortie : Néant
*/
void CGraph::GRAAddNode(unsigned int uiParam) {
	int iCompteur = 0;

	CNode* NODNode = new CNode();

	if (GRASearchNode(uiParam) == true) {
		CException EXCobject;
		EXCobject.EXCSetValue(Node_Doesnt_Exist);
		throw EXCobject;
	}

	uiGRANbOfNodes++;
	CNode** ptptNodeTmp = (CNode**)realloc(ptptEDGGRAListOfEdges, (uiGRANbOfNodes) * sizeof(CNode*));
	if (ptptNodeTmp != NULL) {
		ptptEDGGRAListOfEdges = ptptNodeTmp;
		ptptEDGGRAListOfEdges[uiGRANbOfNodes - 1] = NODNode;
	}

}



/*Méthode qui permet de supprimer un sommet
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : Néant
*/
void CGraph::GRADeleteNode(unsigned int uiParam) {
	unsigned int uiLoop = 0;
	bool found = false;
	for (uiLoop = 0; uiLoop < uiGRANbOfNodes; uiLoop++) {
		if (ptptEDGGRAListOfEdges[uiLoop]->NODGetNodeID() == uiParam) {
			found = true;

		}

	}

	if (found == false) {
		CException EXCobject;
		EXCobject.EXCSetValue(Node_Doesnt_Exist);
		throw EXCobject;
	}
	else {


		if (bGRAOriented) {

			for (unsigned int i = 0; i < uiGRANbOfNodes; i++) {
				if (ptptEDGGRAListOfEdges[i]->NODSearchLeavingEdge(uiParam) == true) {
					ptptEDGGRAListOfEdges[i]->NODDeleteLeavingEdges(uiParam);
				}
				if (ptptEDGGRAListOfEdges[i]->NODSearchArrivingEdge(uiParam) == true) {
					ptptEDGGRAListOfEdges[i]->NODDeleteLeavingEdges(uiParam);
				}
			}
		}
		else {
			for (unsigned int i = 0; i < uiGRANbOfNodes; i++) {
				if (ptptEDGGRAListOfEdges[i]->NODSearchLeavingEdge(uiParam) == true) {
					ptptEDGGRAListOfEdges[i]->NODDeleteLeavingEdges(uiParam);
					ptptEDGGRAListOfEdges[uiParam]->NODDeleteLeavingEdges(i);
				}
				if (ptptEDGGRAListOfEdges[i]->NODSearchArrivingEdge(uiParam) == true) {
					ptptEDGGRAListOfEdges[uiParam]->NODDeleteLeavingEdges(i);
				}
			}//trouver dans quelle position il est dans la liste supprimer avec delete decaler les elements
			unsigned int uipos = 0;
			for (unsigned int i = 0; i < uiGRANbOfNodes; i++) {
				if (ptptEDGGRAListOfEdges[i]->NODGetNodeID() == uiParam) {
					uipos = i;
				}
			}


			for (unsigned int i = uipos; i < uiGRANbOfNodes - 1; i++) {
				ptptEDGGRAListOfEdges[i] = ptptEDGGRAListOfEdges[i + 1];
			}


			uiGRANbOfNodes--;
			CNode** ptptEDGGRAListOfEdgesTemp = (CNode**)realloc(ptptEDGGRAListOfEdges, uiGRANbOfNodes * sizeof(CNode));

			if (ptptEDGGRAListOfEdgesTemp != nullptr) {


				ptptEDGGRAListOfEdges = ptptEDGGRAListOfEdgesTemp;
			}
		}

	}
}



/*Méthode qui permet de modifier un sommet
	Entrée : uiParam1 qui correspond au numero de sommet existant, uiParam2 qui correspond au nouveau numero de sommet
	Sortie : Néant
*/
void CGraph::GRAModifyNode(unsigned int uiParam1, unsigned int uiParam2) {

	unsigned int uiLoop = 0;
	bool found = false;
	for (uiLoop = 0; uiLoop < uiGRANbOfNodes; uiLoop++) {
		if (ptptEDGGRAListOfEdges[uiLoop]->NODGetNodeID() == uiParam1) {
			found = true;

		}

	}

	if (found == false) {
		CException EXCobject;
		EXCobject.EXCSetValue(Node_Doesnt_Exist);
		throw EXCobject;
	}
	else {

		unsigned int uipos = 0;
		for (unsigned int i = 0; i < uiGRANbOfNodes; i++) {
			if (ptptEDGGRAListOfEdges[i]->NODGetNodeID() == uiParam1) {
				uipos = i;
			}
		}
		ptptEDGGRAListOfEdges[uipos]->NODSetNodeID(uiParam2);
	}

}



/*Méthode qui permet d'afficher le graphe
	Entrée : Néant
	Sortie : Néant
*/
void CGraph::GRADisplayGraph() {


	if (bGRAOriented) {

		for (unsigned int uiLoop1 = 0; uiLoop1 < uiGRANbOfNodes; uiLoop1++) {

			for (unsigned int uiLoop2 = 0; uiLoop2 < uiGRANbOfNodes; uiLoop2++) {

				cout << ptptEDGGRAListOfEdges[uiLoop1]->NODGetNodeID() << " -> " << endl;

				if (ptptEDGGRAListOfEdges[uiLoop1]->NODSearchLeavingEdge(uiLoop2)) {
					cout << ptptEDGGRAListOfEdges[uiLoop1]->NODGetNodeID() << endl;
				}
			}
				
		}
	}

}



/*Surcharge de l'opérateur = :
	Entrée : Objet GRAParam de type CGraph
	Sortie : retourne un pointeur du graph
*/
CGraph& CGraph::operator=(CGraph GRAParam) {
	unsigned int uiLoop1 = 0;
	unsigned int uiLoop2 = 0;

	CNode** ptptEDGGRAListOfEdgesTemp = new CNode*[GRAParam.GRAGetNbOfNodes()];

	if (uiGRANbOfNodes > GRAParam.GRAGetNbOfNodes()) {
		for (uiLoop1 = 0; uiLoop1 < GRAParam.GRAGetNbOfNodes(); uiLoop1++) {
			ptptEDGGRAListOfEdgesTemp[uiLoop1] = GRAParam.ptptEDGGRAListOfEdges[uiLoop1];

		}
		for (uiLoop2 = GRAParam.GRAGetNbOfNodes(); uiLoop2 < uiGRANbOfNodes; uiLoop2++) {
			ptptEDGGRAListOfEdges[uiLoop2]->NODSetNodeID(-1);
		}
	}
	else {
		for (uiLoop1 = 0; uiLoop1 < GRAParam.GRAGetNbOfNodes(); uiLoop1++) {
			ptptEDGGRAListOfEdges[uiLoop1] = GRAParam.ptptEDGGRAListOfEdges[uiLoop1];

		}

	}

	uiGRANbOfNodes = GRAParam.GRAGetNbOfNodes();
	bGRAOriented = GRAParam.GRAGetOriented();






	delete[] ptptEDGGRAListOfEdges;

	ptptEDGGRAListOfEdges = ptptEDGGRAListOfEdgesTemp;

	return *this;
}




/*Méthode qui permet d'ajouter un arc
	Entrée : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
	Sortie : Néant
*/
void CGraph::NODAddEdge(unsigned int uiFrom, unsigned int uiTo) {

	for (unsigned uiBoucle = 0; uiBoucle < uiGRANbOfNodes; uiBoucle++) {

		if (uiFrom == ptptEDGGRAListOfEdges[uiBoucle]->NODGetNodeID()) {

			if (ptptEDGGRAListOfEdges[uiBoucle]->NODSearchLeavingEdge(uiTo)) {

				CException EXCobject;
				EXCobject.EXCSetValue(Edge_Already_Exist);
				throw EXCobject;
			}
			else {

				ptptEDGGRAListOfEdges[uiBoucle]->NODAddLeavingEdges(uiTo);
			}
		}

		if (uiTo == ptptEDGGRAListOfEdges[uiBoucle]->NODGetNodeID()) {

			if (ptptEDGGRAListOfEdges[uiBoucle]->NODSearchArrivingEdge(uiFrom)) {

				CException EXCobject;
				EXCobject.EXCSetValue(Edge_Already_Exist);
				throw EXCobject;
			}
			else {
				ptptEDGGRAListOfEdges[uiBoucle]->NODAddArrivingEdges(uiFrom);
			}
		}
	}


}




/*Méthode qui permet de supprimer un arc
	Entrée : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
	Sortie : Néant
*/
void CGraph::NODDeleteEdge(unsigned int uiFrom, unsigned int uiTo) {

	unsigned int uiLoop = 0;
	bool foundFrom = false;
	bool foundTo = false;
	for (uiLoop = 0; uiLoop < uiGRANbOfNodes; uiLoop++) {
		if (ptptEDGGRAListOfEdges[uiLoop]->NODGetNodeID() == uiFrom) {
			foundFrom = true;

		}

		if (ptptEDGGRAListOfEdges[uiLoop]->NODGetNodeID() == uiTo) {
			foundTo = true;

		}

	}

	if (foundFrom == false || foundTo == false) {
		CException EXCobject;
		EXCobject.EXCSetValue(Node_Doesnt_Exist);
		throw EXCobject;
	}

	unsigned int uiposFrom = 0;
	for (unsigned int i = 0; i < uiGRANbOfNodes; i++) {
		if (ptptEDGGRAListOfEdges[i]->NODGetNodeID() == uiFrom) {
			uiposFrom = i;
		}
	}

	unsigned int uiposTo = 0;
	for (unsigned int i = 0; i < uiGRANbOfNodes; i++) {
		if (ptptEDGGRAListOfEdges[i]->NODGetNodeID() == uiTo) {
			uiposTo = i;
		}
	}


	if (ptptEDGGRAListOfEdges[uiposFrom]->NODSearchLeavingEdge(uiTo) == false) {
		CException EXCobject;
		EXCobject.EXCSetValue(Edge_Doesnt_Exist);
		throw EXCobject;
	}
	else {
		if (bGRAOriented) {

			ptptEDGGRAListOfEdges[uiposFrom]->NODDeleteLeavingEdges(uiTo);
		}
		else {
			ptptEDGGRAListOfEdges[uiposFrom]->NODDeleteLeavingEdges(uiTo);
			ptptEDGGRAListOfEdges[uiposTo]->NODDeleteArrivingEdges(uiFrom);
		}
	}



}




/*Méthode qui permet de modifier un arc
	Entrée : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
	Sortie : Néant
*/
void CGraph::NODModifyEdge(unsigned int uiFrom, unsigned int uinewTo) {


	unsigned int uiLoop = 0;
	bool foundTo = false;
	bool found = false;
	for (uiLoop = 0; uiLoop < uiGRANbOfNodes; uiLoop++) {

		if (ptptEDGGRAListOfEdges[uiLoop]->NODGetNodeID() == uinewTo) {
			foundTo = true;

		}

	}

	if (foundTo == false) {
		CException EXCobject;
		EXCobject.EXCSetValue(Node_Doesnt_Exist);
		throw EXCobject;
	}

	for (uiLoop = 0; uiLoop < uiGRANbOfNodes; uiLoop++) {
		if (ptptEDGGRAListOfEdges[uiFrom]->NODSearchLeavingEdge(uiLoop) == true) {
			found = true;
		}
	}


	if (found == false) {
		CException EXCobject;
		EXCobject.EXCSetValue(Edge_Doesnt_Exist);
		throw EXCobject;
	}

	unsigned int uiposFrom = 0;
	for (unsigned int i = 0; i < uiGRANbOfNodes; i++) {
		if (ptptEDGGRAListOfEdges[i]->NODGetNodeID() == uiFrom) {
			uiposFrom = i;
		}
	}

	unsigned int uiposTo = 0;
	for (unsigned int i = 0; i < uiGRANbOfNodes; i++) {
		if (ptptEDGGRAListOfEdges[i]->NODGetNodeID() == uinewTo) {
			uiposTo = i;
		}
	}
	if (bGRAOriented) {
		ptptEDGGRAListOfEdges[uiposFrom]->NODModifyLeavingEdges(uinewTo);
	}
	else {
		ptptEDGGRAListOfEdges[uiposFrom]->NODModifyLeavingEdges(uinewTo);
		ptptEDGGRAListOfEdges[uinewTo]->NODModifyArrivingEdges(uiposFrom);
	}


}