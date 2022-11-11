#ifndef CGraph_h
#define CGraph_h 

#include "CGraph.h"
#include "CNode.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#define Node_Already_Exist 1
#define Node_Doesnt_Exist 2
#define Edge_Already_Exist 3

class CGraph
{
private:
    CNode** ptptEDGGRAListOfEdges;
    unsigned int uiGRANbOfNodes;
    bool bGRAOriented;

public:

    /*Constructeur par d�faut :
        -> Cr�e un objet graph, initialise les variables locales
        Entr�e : N�ant
        Sortie : retourne un objet graph
    */
    CGraph();


    /*Constructeur de recopie :
        -> Cr�e et recopie un objet graph
        Entr�e : Graph qui va etre recopi�
        Sortie : retourne un objet graph
    */
    CGraph(const CGraph& GRAParam);


    /*Destructeur :
        -> Lib�re l'espace m�moire d'un graph
        Entr�e : N�ant
        Sortie : N�ant
    */
    ~CGraph();


    /*M�thode qui permet de lire le nombre de sommets
        Entr�e : N�ant
        Sortie : retourne le nombre de sommets
    */
    unsigned int GRAGetNbOfNodes()const { return uiGRANbOfNodes; };


    /*M�thode qui permet de modifier le nombre de sommets
        Entr�e : uiParam qui correspond au nombre de sommets
        Sortie : retourne le nombre de sommets
    */
    void GRASetNbOfNodes(unsigned int uiParam) { uiGRANbOfNodes = uiParam; };


    /*M�thode qui permet de voir si un sommet existe ou pas
        Entr�e : uiParam qui correspond au numero de sommet
        Sortie : retourne une booleene
    */
    bool GRASearchNode(unsigned int uiParam);


    /*M�thode qui permet de lire la booleene
        Entr�e : N�ant
        Sortie : retourne la booleene
    */
    bool GRAGetOriented() { return bGRAOriented; };


    /*M�thode qui permet de modifier la booleene
        Entr�e : bParam qui est une booleene
        Sortie : N�ant
    */
    void GRASetOriented(bool bParam) { bGRAOriented = bParam; };


    /*M�thode qui permet d'afficher le graphe
        Entr�e : N�ant
        Sortie : N�ant
    */
    void GRADisplayGraph();


    /*M�thode qui permet d'ajouter un sommet
        Entr�e : uiParam pour voir si le numero de sommet existe
        Sortie : N�ant
    */
    void GRAAddNode(unsigned int uiParam);


    /*M�thode qui permet de supprimer un sommet
        Entr�e : uiParam qui correspond au numero de sommet
        Sortie : N�ant
    */
    void GRADeleteNode(unsigned int uiParam);


    /*M�thode qui permet de modifier un sommet
        Entr�e : uiParam1 qui correspond au numero de sommet existant, uiParam2 qui correspond au nouveau numero de sommet
        Sortie : N�ant
    */
    void GRAModifyNode(unsigned int uiParam1, unsigned int uiParam2);



    /*Surcharge de l'op�rateur = :
        Entr�e : Objet GRAParam de type CGraph
        Sortie : retourne un pointeur du graph
    */
    CGraph& operator=(CGraph GRAParam);


    /*M�thode qui permet d'ajouter un arc
        Entr�e : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
        Sortie : N�ant
    */
    void NODAddEdge(unsigned int uiNODNodeFrom, unsigned int uiNODNodeTO);


    /*M�thode qui permet de supprimer un arc
        Entr�e : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
        Sortie : N�ant
    */
    void NODDeleteEdge(unsigned int uiNODNodeFrom, unsigned int uiNODNodeTO);


    /*M�thode qui permet de modifier un arc
        Entr�e : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
        Sortie : N�ant
    */
    void NODModifyEdge(unsigned int uiNODNodeFrom, unsigned int uiNODNodeTO);



};

#endif