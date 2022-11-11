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

    /*Constructeur par défaut :
        -> Crée un objet graph, initialise les variables locales
        Entrée : Néant
        Sortie : retourne un objet graph
    */
    CGraph();


    /*Constructeur de recopie :
        -> Crée et recopie un objet graph
        Entrée : Graph qui va etre recopié
        Sortie : retourne un objet graph
    */
    CGraph(const CGraph& GRAParam);


    /*Destructeur :
        -> Libére l'espace mémoire d'un graph
        Entrée : Néant
        Sortie : Néant
    */
    ~CGraph();


    /*Méthode qui permet de lire le nombre de sommets
        Entrée : Néant
        Sortie : retourne le nombre de sommets
    */
    unsigned int GRAGetNbOfNodes()const { return uiGRANbOfNodes; };


    /*Méthode qui permet de modifier le nombre de sommets
        Entrée : uiParam qui correspond au nombre de sommets
        Sortie : retourne le nombre de sommets
    */
    void GRASetNbOfNodes(unsigned int uiParam) { uiGRANbOfNodes = uiParam; };


    /*Méthode qui permet de voir si un sommet existe ou pas
        Entrée : uiParam qui correspond au numero de sommet
        Sortie : retourne une booleene
    */
    bool GRASearchNode(unsigned int uiParam);


    /*Méthode qui permet de lire la booleene
        Entrée : Néant
        Sortie : retourne la booleene
    */
    bool GRAGetOriented() { return bGRAOriented; };


    /*Méthode qui permet de modifier la booleene
        Entrée : bParam qui est une booleene
        Sortie : Néant
    */
    void GRASetOriented(bool bParam) { bGRAOriented = bParam; };


    /*Méthode qui permet d'afficher le graphe
        Entrée : Néant
        Sortie : Néant
    */
    void GRADisplayGraph();


    /*Méthode qui permet d'ajouter un sommet
        Entrée : uiParam pour voir si le numero de sommet existe
        Sortie : Néant
    */
    void GRAAddNode(unsigned int uiParam);


    /*Méthode qui permet de supprimer un sommet
        Entrée : uiParam qui correspond au numero de sommet
        Sortie : Néant
    */
    void GRADeleteNode(unsigned int uiParam);


    /*Méthode qui permet de modifier un sommet
        Entrée : uiParam1 qui correspond au numero de sommet existant, uiParam2 qui correspond au nouveau numero de sommet
        Sortie : Néant
    */
    void GRAModifyNode(unsigned int uiParam1, unsigned int uiParam2);



    /*Surcharge de l'opérateur = :
        Entrée : Objet GRAParam de type CGraph
        Sortie : retourne un pointeur du graph
    */
    CGraph& operator=(CGraph GRAParam);


    /*Méthode qui permet d'ajouter un arc
        Entrée : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
        Sortie : Néant
    */
    void NODAddEdge(unsigned int uiNODNodeFrom, unsigned int uiNODNodeTO);


    /*Méthode qui permet de supprimer un arc
        Entrée : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
        Sortie : Néant
    */
    void NODDeleteEdge(unsigned int uiNODNodeFrom, unsigned int uiNODNodeTO);


    /*Méthode qui permet de modifier un arc
        Entrée : uiNODNodeFrom qui est le numero sortant, uiNODNodeTO qui est le numero arrivant
        Sortie : Néant
    */
    void NODModifyEdge(unsigned int uiNODNodeFrom, unsigned int uiNODNodeTO);



};

#endif