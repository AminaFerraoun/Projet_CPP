#ifndef C_PARSER_H 
#define C_PARSER_H 


#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "CGraph.h"

#define Error_File 1
#define Error_TypeMatrix 2
#define Error_NbLines 3
#define Error_NbColumns 4
#define Error_ElementMatrix 5
#define Error_Buffer 6
#define Error_Openning_File 7



#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
#pragma warning(disable : 4430)



class CParser {

public:

	/* Analyseur syntaxique : M�thode qui permet de creer un graph a partir des donn�es stock�es grace � l'analyseur lexical
		Entr�e : ptcParam qui correspond aux donn�es stock�es
		Sortie : retourne un objet graph
	*/
    static CGraph* PARCreateGraph(const char** ptcParam);

};

#endif



