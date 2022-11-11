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

	/*Constructeur par défaut :
	-> Crée un objet node, initialise les variables locales
	Entrée : Néant
	Sortie : retourne un objet node
	*/
	CNode();


	/*Constructeur de recopie :
	-> Crée et recopie un objet node
	Entrée : node qui va etre recopié
	Sortie : retourne un objet node
	*/
	CNode(const CNode& NODParam);


	/*Constructeur de confort :
	-> cree un objet node
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : Néant
	*/
	CNode(unsigned int uiParam);


	/*Destructeur :
	-> Libére l'espace mémoire d'un node
	Entrée : Néant
	Sortie : Néant
	*/
	~CNode();


	/*Méthode qui permet de lire le numero de sommet
	Entrée : Néant
	Sortie : retourne le numero de sommet
	*/
	unsigned int NODGetNodeID() { return uiNODNodeID; };


	/*Méthode qui permet de lire le nombre d'arc sortant
	Entrée : Néant
	Sortie : retourne le nombre d'arc sortant
	*/
	unsigned int NODGetNbEdgeLeavingNode() { return uiNODNbEdgeLeavingNode; };


	/*Méthode qui permet de lire le nombre d'arc arrivant
	Entrée : Néant
	Sortie : retourne le nombre d'arc arrivant
	*/
	unsigned int NODGetNbEdgeArrivingNode() { return uiNODNbEdgeArrivingNode; };


	/*Méthode qui permet de lire la liste des arcs sortant
	Entrée : Néant
	Sortie : retourne la liste des arcs sortant
	*/
	CEdge** NODGetLeavingNode() { return ptptEDGNODLeavingNodes; };


	/*Méthode qui permet de lire la liste des arcs arrivant
	Entrée : Néant
	Sortie : retourne la liste des arcs arrivant
	*/
	CEdge** NODGetArrivingNode() { return ptptEDGNODArrivingNodes; };


	/*Méthode qui permet de voir si l'arc sortant existe
	Entrée : uiParam qui prend la destination de l'arc
	Sortie : retourne une booleene
	*/
	bool NODSearchLeavingEdge(unsigned int uiParam);


	/*Méthode qui permet de voir si l'arc arrivant existe
	Entrée : uiParam qui prend la destination de l'arc
	Sortie : retourne une booleene
	*/
	bool NODSearchArrivingEdge(unsigned int uiParam);



	/*Méthode qui permet de modifier le numero de sommet
	Entrée : uiParam qui prend le numero de sommet
	Sortie : Néant
	*/
	void NODSetNodeID(unsigned int uiParam) { uiNODNodeID = uiParam; };


	/*Méthode qui permet de modifier le nombre d'arcs sortant
	Entrée : uiParam qui prend le nombre d'arcs sortant
	Sortie : Néant
	*/
	void NODSetNbEdgeLeavingNode(unsigned int uiParam) { uiNODNbEdgeLeavingNode = uiParam; };


	/*Méthode qui permet de modifier le nombre d'arcs arrivant
	Entrée : uiParam qui prend le nombre d'arcs arrivant
	Sortie : Néant
	*/
	void NODSetNbEdgeArrivingNode(unsigned int uiParam) { uiNODNbEdgeArrivingNode = uiParam; };


	/*Méthode qui permet d'ajouter un arc sortant
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : Néant
	*/
	void NODAddLeavingEdges(unsigned int uiParam);


	/*Méthode qui permet d'ajouter un arc arrivant
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : Néant
	*/
	void NODAddArrivingEdges(unsigned int uiParam);
	

	/*Méthode qui permet de supprimer un arc sortant
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : Néant
	*/
	void NODDeleteLeavingEdges(unsigned int uiParam);


	/*Méthode qui permet de supprimer un arc arrivant
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : Néant
	*/
	void NODDeleteArrivingEdges(unsigned int uiParam);


	/*Méthode qui permet de modifier un arc sortant
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : Néant
	*/
	void NODModifyLeavingEdges(unsigned int uiParam);


	/*Méthode qui permet de modifier un arc arrivant
	Entrée : uiParam qui correspond au numero de sommet
	Sortie : Néant
	*/
	void NODModifyArrivingEdges(unsigned int uiParam);
	

	/*Surcharge de l'opérateur = :
		Entrée : Objet NODParam de type node
		Sortie : retourne un pointeur du node
	*/
	CNode operator=(CNode& NODParam);





};

#endif
