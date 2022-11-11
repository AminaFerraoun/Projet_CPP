#include "CNode.h"
#include"CException.h"
#include <iostream>
#include <cstdlib>


using namespace std;


/*Constructeur par défaut :
-> Crée un objet node, initialise les variables locales
Entrée : Néant
Sortie : retourne un objet node
*/
CNode::CNode() {

	uiNODNodeID = 0;
	uiNODNbEdgeLeavingNode = 0;
	uiNODNbEdgeArrivingNode = 0;
	ptptEDGNODLeavingNodes = nullptr;
	ptptEDGNODArrivingNodes = nullptr;

}


/*Constructeur de recopie :
-> Crée et recopie un objet node
Entrée : node qui va etre recopié
Sortie : retourne un objet node
*/
CNode::CNode(const CNode& NODParam) {

	uiNODNodeID = NODParam.uiNODNodeID;
	uiNODNbEdgeLeavingNode = NODParam.uiNODNbEdgeLeavingNode;
	uiNODNbEdgeArrivingNode = NODParam.uiNODNbEdgeArrivingNode;

	ptptEDGNODLeavingNodes = new CEdge * [uiNODNbEdgeLeavingNode];
	ptptEDGNODArrivingNodes = new CEdge * [uiNODNbEdgeArrivingNode];

	for (unsigned int uiLoop = 0; uiLoop < uiNODNbEdgeLeavingNode; uiLoop++) {
		ptptEDGNODLeavingNodes[uiLoop] = new CEdge;
	}

	for (unsigned int uiLoop = 0; uiLoop < uiNODNbEdgeArrivingNode; uiLoop++) {
		ptptEDGNODArrivingNodes[uiLoop] = new CEdge;
	}
}



/*Constructeur de confort :
-> cree un objet node
Entrée : uiParam qui correspond au numero de sommet
Sortie : Néant
*/
CNode::CNode(unsigned int uiParam) {
	uiNODNodeID = uiParam;
	uiNODNbEdgeLeavingNode = 0;
	uiNODNbEdgeArrivingNode = 0;
	ptptEDGNODLeavingNodes = nullptr;
	ptptEDGNODArrivingNodes = nullptr;
}



/*Destructeur :
-> Libére l'espace mémoire d'un node
Entrée : Néant
Sortie : Néant
*/
CNode::~CNode() {
	unsigned int uiLoop = 0;

	for (uiLoop = 0; uiLoop < uiNODNbEdgeLeavingNode; uiLoop++) {
		delete[] ptptEDGNODLeavingNodes[uiLoop];
	}

	delete ptptEDGNODLeavingNodes;

	for (uiLoop = 0; uiLoop < uiNODNbEdgeArrivingNode; uiLoop++) {
		delete[] ptptEDGNODArrivingNodes[uiLoop];
	}

	delete ptptEDGNODArrivingNodes;
}



/*Méthode qui permet de lire le nombre d'arc arrivant
Entrée : Néant
Sortie : retourne le nombre d'arc arrivant
*/
bool CNode::NODSearchArrivingEdge(unsigned int uiParam) {

	bool bFind = false;
	for (unsigned int uiLoop1 = 0; uiLoop1 < uiNODNbEdgeArrivingNode; uiLoop1++) {

		if (ptptEDGNODArrivingNodes[uiLoop1]->EDGGetDestination() == uiParam) {
			bFind = true;
		}
		else {
			bFind = false;
		}

	}
	return bFind;
}



/*Méthode qui permet de lire le nombre d'arc sortant
Entrée : Néant
Sortie : retourne le nombre d'arc sortant
*/
bool CNode::NODSearchLeavingEdge(unsigned int uiParam) {

	bool bFind = false;
	for (unsigned int uiLoop1 = 0; uiLoop1 < uiNODNbEdgeLeavingNode; uiLoop1++) {

		if (ptptEDGNODLeavingNodes[uiLoop1]->EDGGetDestination() == uiParam) {
			bFind = true;
		}
		else {
			bFind = false;
		}

	}
	return bFind;
}


/*Méthode qui permet d'ajouter un arc sortant
Entrée : uiParam qui correspond au numero de sommet
Sortie : Néant
*/
void CNode::NODAddLeavingEdges(unsigned int uiParam) {

	uiNODNbEdgeLeavingNode++;
	CEdge** ptptEDGTemp = (CEdge**)realloc(ptptEDGNODLeavingNodes, (uiNODNbEdgeLeavingNode) * sizeof(CEdge*));

	if (ptptEDGTemp != nullptr) {
		ptptEDGNODLeavingNodes = ptptEDGTemp;
	}

	ptptEDGNODLeavingNodes[uiNODNbEdgeLeavingNode - 1] = new CEdge(uiParam);



}


/*Méthode qui permet d'ajouter un arc arrivant
Entrée : uiParam qui correspond au numero de sommet
Sortie : Néant
*/
void CNode::NODAddArrivingEdges(unsigned int uiParam) {

	uiNODNbEdgeLeavingNode++;
	CEdge** ptptEDGTmp = (CEdge**)realloc(ptptEDGNODArrivingNodes, (uiNODNbEdgeArrivingNode) * sizeof(CEdge*));

	if (ptptEDGTmp != nullptr) {
		ptptEDGNODArrivingNodes = ptptEDGTmp;
	}

	ptptEDGNODArrivingNodes[uiNODNbEdgeArrivingNode - 1] = new CEdge(uiParam);


}



/*Méthode qui permet de supprimer un arc sortant
Entrée : uiParam qui correspond au numero de sommet
Sortie : Néant
*/
void CNode::NODDeleteLeavingEdges(unsigned int uiParam) {

	bool found = false;
	for (unsigned int uiLoop = 0; uiLoop < uiNODNbEdgeLeavingNode; uiLoop++) {

		if (ptptEDGNODLeavingNodes[uiLoop]->EDGGetDestination() == uiParam) {
			found = true;
		}

	}

	if (found == false) {
		CException EXCobject;
		EXCobject.EXCSetValue(Edge_Doesnt_Exist);
		throw EXCobject;

	}
	else {

		unsigned int uipos = 0;
		for (unsigned int uiLoop = 0; uiLoop < uiNODNbEdgeLeavingNode; uiLoop++) {

			if (ptptEDGNODLeavingNodes[uiLoop]->EDGGetDestination() == uiParam) {
				uipos = uiLoop;
			}

		}

		for (unsigned int i = uipos; i < uiNODNbEdgeLeavingNode - 1; i++) {
			ptptEDGNODLeavingNodes[i] = ptptEDGNODLeavingNodes[i + 1];
		}

		uiNODNbEdgeLeavingNode--;
		CEdge** ptptNODTemp = (CEdge**)realloc(ptptEDGNODLeavingNodes, uiNODNbEdgeLeavingNode * sizeof(CEdge*));

		if (ptptNODTemp != nullptr) {
			ptptEDGNODLeavingNodes = ptptNODTemp;
		}
	}

}


/*Méthode qui permet de supprimer un arc arrivant
Entrée : uiParam qui correspond au numero de sommet
Sortie : Néant
*/
void CNode::NODDeleteArrivingEdges(unsigned int uiParam) {

	bool found = false;
	for (unsigned int uiLoop = 0; uiLoop < uiNODNbEdgeArrivingNode; uiLoop++) {

		if (ptptEDGNODArrivingNodes[uiLoop]->EDGGetDestination() == uiParam) {
			found = true;
		}

	}

	if (found == false) {
		CException EXCobject;
		EXCobject.EXCSetValue(Edge_Doesnt_Exist);
		throw EXCobject;

	}
	else {

		unsigned int uipos = 0;
		for (unsigned int uiLoop = 0; uiLoop < uiNODNbEdgeArrivingNode; uiLoop++) {

			if (ptptEDGNODArrivingNodes[uiLoop]->EDGGetDestination() == uiParam) {
				uipos = uiLoop;
			}

		}

		for (unsigned int i = uipos; i < uiNODNbEdgeArrivingNode - 1; i++) {
			ptptEDGNODArrivingNodes[i] = ptptEDGNODArrivingNodes[i + 1];
		}

		uiNODNbEdgeArrivingNode--;
		CEdge** ptptNODTemp = (CEdge**)realloc(ptptEDGNODArrivingNodes, uiNODNbEdgeArrivingNode * sizeof(CEdge*));

		if (ptptNODTemp != nullptr) {
			ptptEDGNODArrivingNodes = ptptNODTemp;
		}
	}
}



/*Méthode qui permet de modifier un arc sortant
Entrée : uiParam qui correspond au numero de sommet
Sortie : Néant
*/
void CNode::NODModifyLeavingEdges(unsigned int uiParam) {

	if (uiParam != uiNODNodeID) {
		CException EXCobject;
		EXCobject.EXCSetValue(Edge_Doesnt_Exist);
		throw EXCobject;
	}

	uiNODNodeID = uiParam;
}


/*Méthode qui permet de modifier un arc arrivant
Entrée : uiParam qui correspond au numero de sommet
Sortie : Néant
*/
void CNode::NODModifyArrivingEdges(unsigned int uiParam) {

	if (uiParam != uiNODNodeID) {
		CException EXCobject;
		EXCobject.EXCSetValue(Edge_Doesnt_Exist);
		throw EXCobject;
	}

	uiNODNodeID = uiParam;
}


/*Surcharge de l'opérateur = :
	Entrée : Objet NODParam de type node
	Sortie : retourne un pointeur du node
*/
CNode CNode::operator=(CNode& NODParam) {

	uiNODNodeID = NODParam.NODGetNodeID();
	uiNODNbEdgeLeavingNode = NODParam.NODGetNbEdgeLeavingNode();
	uiNODNbEdgeArrivingNode = NODParam.NODGetNbEdgeArrivingNode();

	for (unsigned int uiLoop = 0; uiLoop < uiNODNbEdgeArrivingNode; uiLoop++) {

		ptptEDGNODArrivingNodes[uiLoop] = NODParam.ptptEDGNODLeavingNodes[uiLoop];
	}


	for (unsigned int uiLoop = 0; uiLoop < uiNODNbEdgeLeavingNode; uiLoop++) {

		ptptEDGNODLeavingNodes[uiLoop] = NODParam.ptptEDGNODLeavingNodes[uiLoop];

	}

	return *this;
}


