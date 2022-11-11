#ifndef CNode_h
#define CNode_h 

#include "CEdge.h"
#include "CNode.h"
#include <iostream>
#include <cstdlib>

#define Edge_Doesnt_Exist 10

using namespace std;


class CNode
{
private:
	unsigned int uiNODNodeID;
	unsigned int uiNODNbEdgeLeavingNode;
	unsigned int uiNODNbEdgeArrivingNode;
	CEdge** ptptEDGNODLeavingNodes;
	CEdge** ptptEDGNODArrivingNodes;

public:

	/*Constructeur par d�faut :
	-> Cr�e un objet node, initialise les variables locales
	Entr�e : N�ant
	Sortie : retourne un objet node
	*/
	CNode();


	/*Constructeur de recopie :
	-> Cr�e et recopie un objet node
	Entr�e : node qui va etre recopi�
	Sortie : retourne un objet node
	*/
	CNode(const CNode& NODParam);


	/*Constructeur de confort :
	-> cree un objet node
	Entr�e : uiParam qui correspond au numero de sommet
	Sortie : N�ant
	*/
	CNode(unsigned int uiParam);


	/*Destructeur :
	-> Lib�re l'espace m�moire d'un node
	Entr�e : N�ant
	Sortie : N�ant
	*/
	~CNode();


	/*M�thode qui permet de lire le numero de sommet
	Entr�e : N�ant
	Sortie : retourne le numero de sommet
	*/
	unsigned int NODGetNodeID() { return uiNODNodeID; };


	/*M�thode qui permet de lire le nombre d'arc sortant
	Entr�e : N�ant
	Sortie : retourne le nombre d'arc sortant
	*/
	unsigned int NODGetNbEdgeLeavingNode() { return uiNODNbEdgeLeavingNode; };


	/*M�thode qui permet de lire le nombre d'arc arrivant
	Entr�e : N�ant
	Sortie : retourne le nombre d'arc arrivant
	*/
	unsigned int NODGetNbEdgeArrivingNode() { return uiNODNbEdgeArrivingNode; };


	/*M�thode qui permet de lire la liste des arcs sortant
	Entr�e : N�ant
	Sortie : retourne la liste des arcs sortant
	*/
	CEdge** NODGetLeavingNode() { return ptptEDGNODLeavingNodes; };


	/*M�thode qui permet de lire la liste des arcs arrivant
	Entr�e : N�ant
	Sortie : retourne la liste des arcs arrivant
	*/
	CEdge** NODGetArrivingNode() { return ptptEDGNODArrivingNodes; };


	/*M�thode qui permet de voir si l'arc sortant existe
	Entr�e : uiParam qui prend la destination de l'arc
	Sortie : retourne une booleene
	*/
	bool NODSearchLeavingEdge(unsigned int uiParam);


	/*M�thode qui permet de voir si l'arc arrivant existe
	Entr�e : uiParam qui prend la destination de l'arc
	Sortie : retourne une booleene
	*/
	bool NODSearchArrivingEdge(unsigned int uiParam);



	/*M�thode qui permet de modifier le numero de sommet
	Entr�e : uiParam qui prend le numero de sommet
	Sortie : N�ant
	*/
	void NODSetNodeID(unsigned int uiParam) { uiNODNodeID = uiParam; };


	/*M�thode qui permet de modifier le nombre d'arcs sortant
	Entr�e : uiParam qui prend le nombre d'arcs sortant
	Sortie : N�ant
	*/
	void NODSetNbEdgeLeavingNode(unsigned int uiParam) { uiNODNbEdgeLeavingNode = uiParam; };


	/*M�thode qui permet de modifier le nombre d'arcs arrivant
	Entr�e : uiParam qui prend le nombre d'arcs arrivant
	Sortie : N�ant
	*/
	void NODSetNbEdgeArrivingNode(unsigned int uiParam) { uiNODNbEdgeArrivingNode = uiParam; };


	/*M�thode qui permet d'ajouter un arc sortant
	Entr�e : uiParam qui correspond au numero de sommet
	Sortie : N�ant
	*/
	void NODAddLeavingEdges(unsigned int uiParam);


	/*M�thode qui permet d'ajouter un arc arrivant
	Entr�e : uiParam qui correspond au numero de sommet
	Sortie : N�ant
	*/
	void NODAddArrivingEdges(unsigned int uiParam);
	

	/*M�thode qui permet de supprimer un arc sortant
	Entr�e : uiParam qui correspond au numero de sommet
	Sortie : N�ant
	*/
	void NODDeleteLeavingEdges(unsigned int uiParam);


	/*M�thode qui permet de supprimer un arc arrivant
	Entr�e : uiParam qui correspond au numero de sommet
	Sortie : N�ant
	*/
	void NODDeleteArrivingEdges(unsigned int uiParam);


	/*M�thode qui permet de modifier un arc sortant
	Entr�e : uiParam qui correspond au numero de sommet
	Sortie : N�ant
	*/
	void NODModifyLeavingEdges(unsigned int uiParam);


	/*M�thode qui permet de modifier un arc arrivant
	Entr�e : uiParam qui correspond au numero de sommet
	Sortie : N�ant
	*/
	void NODModifyArrivingEdges(unsigned int uiParam);
	

	/*Surcharge de l'op�rateur = :
		Entr�e : Objet NODParam de type node
		Sortie : retourne un pointeur du node
	*/
	CNode operator=(CNode& NODParam);





};

#endif
